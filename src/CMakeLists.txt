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

add_executable(THFrame
	main.cpp
	)

target_link_libraries(THFrame ${PYTHON_LIBRARIES})
target_link_libraries(THFrame ${Boost_LIBRARIES})
target_link_libraries(THFrame ${CMAKE_THREAD_LIBS_INIT})
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

