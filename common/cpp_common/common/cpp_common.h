#ifndef CPP_COMMON_H
#define CPP_COMMON_H

#include <vector>
#include <sstream>
#include <fstream>

namespace leetcode {
namespace common {
//
//-----------------------------------------------------------------------
//  function : get_stings_from_file
/// @brief get string line by line from file
/// @return  vector<string>
//----------------------------------------------------------------------- 
//void get_string_from_file(const std::string file_name, std::string& str);
void get_string_from_file(const std::string file_name, std::string& str) {
    std::fstream fs(file_name.c_str());
    std::stringstream ss;
    ss << fs.rdbuf();
    str = ss.str();
}
//
//-----------------------------------------------------------------------
//  function : strings_to_number
/// @brief tansfor vector<string> to vector<T>
/// @return  vector<T>
//----------------------------------------------------------------------- 
template <class T>
void strings_to_numbers(const std::vector<std::string>& strs, std::vector<T>& numbers) {
    T num;
    numbers.clear();
    for (int i = 0; i < strs.size(); i++) {
        std::istringstream iss(strs[i]);
        iss >> num;
        numbers.push_back(num);
    }
} 
//
//-----------------------------------------------------------------------
//  function : split
/// @brief split string with sep
/// @return vector<string>
//----------------------------------------------------------------------- 
std::vector<std::string> split(const std::string &str, char sep) {
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

}
}

#endif
