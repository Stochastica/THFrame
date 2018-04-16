#include "test.hpp"

#include "testing.hpp"

namespace thf
{

std::map<std::string, std::string> testInfo()
{
	std::map<std::string, std::string> info;
	info["0"] = "Always success";
	return info;
}

/**
 * Dummy test
 */
bool test_0()
{
	std::cout << "Test 0\n";
	return true;
}

bool test(std::string id)
{
	TEST_FUNC(0);
	TEST_FINAL;
}

} // namespace thf
