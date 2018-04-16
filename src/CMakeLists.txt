cmake_minimum_required(VERSION 3.5)

# --Libraries--

# Threads
find_package(Threads REQUIRED)

# Python
set(Python_ADDITIONAL_VERSIONS 3.5)
find_package(PythonLibs 3.5 REQUIRED)
if (${PYTHONLIBS_FOUND})
	include_directories(${PYTHON_INCLUDE_DIRS})
	link_directories(${PYTHON_LIBRARIES})
endif()

# Boost
find_package(Boost 1.61.0 COMPONENTS
	filesystem thread timer python3 program_options
	REQUIRED)
if (${Boost_FOUND})
	include_directories(${Boost_INCLUDE_DIRS})
	link_directories(${Boost_LIBRARY_DIR})
endif()

# OpenGL
find_package(OpenGL REQUIRED)
if (${OPENGL_FOUND})
	include_directories(${OPENGL_INCLUDE_DIR})
	link_directories(${OPENGL_LIBRARIES})
endif()
# GLFW
find_package(glfw3 REQUIRED)
# GLEW
find_package(GLEW REQUIRED)
if (${GLEW_FOUND})
	include_directories(${GLEW_INCLUDE_DIRS})
endif()
# OpenAL
find_package(OpenAL REQUIRED)
if (${OPENAL_FOUND})
	include_directories(${OPENAL_INCLUDE_DIR})
	link_directories(${OPENAL_LIBRARY})
endif()
# PNG
find_package(PNG REQUIRED)
if (${PNG_FOUND})
	include_directories(${PNG_INCLUDE_DIRS})
endif()
# FreeType
find_package(Freetype REQUIRED)
if (${FREETYPE_FOUND})
	include_directories(${FREETYPE_INCLUDE_DIRS})
endif()

# --Compilation Objects--

# Testing (Debug only)
if (CMAKE_BUILD_TYPE MATCHES Debug)
	set(SourceTest
		test/test.cpp
		)
else ()
	set(SourceTest )
endif ()

message("${SourceTest}")

add_executable(THFrame
	main.cpp
	${SourceTest}
	)

target_link_libraries(THFrame ${PYTHON_LIBRARIES})
target_link_libraries(THFrame ${Boost_LIBRARIES})
target_link_libraries(THFrame ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(THFrame
	${OPENGL_LIBRARIES}
	glfw
	${GLEW_LIBRARIES}
	${OPENAL_LIBRARY}
	${FREETYPE_LIBRARIES}
	${PNG_LIBRARIES}
	)
if (UNIX)
	target_link_libraries(THFrame m)
endif()
target_compile_features(THFrame PRIVATE
	cxx_range_for
	cxx_noexcept
	cxx_rvalue_references
	cxx_override
	cxx_lambdas
	cxx_final
	cxx_deleted_functions
	cxx_delegating_constructors
	cxx_auto_type
	cxx_constexpr
	cxx_lambda_init_captures
	)

