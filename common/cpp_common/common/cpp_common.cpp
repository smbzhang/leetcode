#include "cpp_common.h"

namespace leetcode {
namespace common {
//
//-----------------------------------------------------------------------
//  function : get_stings_from_file
/// @brief get string line by line from file
/// @return 
//----------------------------------------------------------------------- 
/*void get_string_from_file(const std::string file_name, std::string& str) {
    std::fstream fs(file_name.c_str());
    std::stringstream ss;
    ss << fs.rdbuf();
    str = ss.str();
}*/
//
//-----------------------------------------------------------------------
//  function : split
/// @brief split string with sep
/// @return vector<string>
//----------------------------------------------------------------------- 
/*std::vector<std::string> split(const std::string &str, char sep) {
    std::vector<std::string> ret;
    auto i = str.begin();
    while (i != str.end()) {
        while (i != str.end() && *i == sep) {
            ++i;
        }
        if (i != str.end()) {
            auto j = i;
            while (j != str.end() && *j != sep) {
                ++j;
            }
            ret.emplace_back(std::string(i, j));
            i = j;
        }
    }
    return ret;
}
*/
}
}

