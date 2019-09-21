#ifndef CPP_COMMON_H
#define CPP_COMMON_H

#include <vector>
#include <sstream>
#include <fstream>
#include "../datastruct/data_struct.h"

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

template <typename T>
void get_vector_from_file(const std::string src_file, const char sep, std::vector<T> &array) {
    std::string content;
    get_string_from_file(src_file, content);
    std::vector<std::string> strs = split(content, sep);
    strings_to_numbers(strs, array);
}

void vector_to_list(const std::vector<int> array, ListNode **head) {
    ListNode *list = *head;
    for (auto tmp : array) {
        if (list == NULL) {
            list = new ListNode(tmp);
            *head = list;
            continue;
        }
        ListNode *node = new ListNode(tmp);
        list->next = node;
        list = node;
    }
}

void get_list_from_file(const std::string& src_file, const char sep, ListNode **list) {
    std::vector<int> array;
    get_vector_from_file(src_file, sep, array);
    vector_to_list(array, list);
}

void print_list(ListNode *list) {
    std::cout << "------------------------------ list-begin ------------------------------" << std::endl;
    while (list != NULL) {
        std::cout << list->val << " ";
        list = list->next;
    }
    std::cout << std::endl;
    std::cout << "------------------------------  list-end  ------------------------------" << std::endl;

}


}
}

#endif
