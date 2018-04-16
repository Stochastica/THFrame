#ifndef THFRAME_TEST_TEST_HPP_
#define THFRAME_TEST_TEST_HPP_

#include <map>
#include <string>

namespace thf
{

/**
 * @brief Returns a map of possible test id's and their descriptions.
 */
std::map<std::string, std::string> testInfo();

/**
 * Execute test [id].
 *
 */
bool test(std::string id);

} // namespace thf

#endif // !THFRAME_TEST_TEST_HPP_
