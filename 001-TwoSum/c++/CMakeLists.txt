PROJECT(leetcode)
cmake_minimum_required(VERSION 3.2)
add_compile_options(-g -std=c++11)

include_directories(
    ../../common/cpp_common
)
link_directories(
    /usr/local/lib
)

# 生成 libcpp_common.a 库
# set(LIBCPP_COMMON_SRC ../../common/cpp_common/common/cpp_common.cpp)
# add_library(cpp_common ${LIBCPP_COMMON_SRC})

# TwoSum 可执行文件
add_executable(TwoSum ./main.cpp)
# target_link_libraries(cpp_common)

