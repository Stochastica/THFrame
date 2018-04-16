#include <iostream>

#include <boost/program_options.hpp>

#include "core/thframe.hpp"
#ifndef NDEBUG
	#include "test/test.hpp"
#endif

#define EXIT_NORMAL 0
#define EXIT_ERROR 1

int main(int argc, char* argv[])
{
	using namespace thf;

	// Parse Program options
	boost::program_options::variables_map options;
	{
		namespace bpo = boost::program_options;

#ifndef NDEBUG
		std::string testDesc = "Execute test [arg]\n";
		for (auto const& i: testInfo())
			testDesc += i.first + ": " + i.second + '\n';
#endif


		bpo::options_description desc("Options");
		desc.add_options()
			("help,h", "Show help and version")
#ifndef NDEBUG
		("test,t", bpo::value<std::string>(), testDesc.c_str())
#endif
			;
		bpo::store(bpo::parse_command_line(argc, argv, desc), options);

		if (options.count("help"))
		{
			std::cout << "Touhou Frame " << THFRAME_VERSION<< std::endl
			          << desc << std::endl;

			return EXIT_NORMAL;
		}
	}

	// Testing
#ifndef NDEBUG
	if (options.count("test"))
	{
		std::string testId = options["test"].as<std::string>();
		std::cout << "-----Executing Test " << testId << "-----\n";
		bool result = test(testId);
		if (result)
			std::cout << "----- Test successful -----\n";
		else
			std::cout << "----- Test failed ------\n";

		return EXIT_NORMAL;
	}
#endif

	// Execution

	std::cout << "Hello THFrame!\n";
	return EXIT_NORMAL;
}
