#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import sys

PYTHON_COMMON_PATH = os.path.abspath(os.path.join(os.path.dirname(os.path.realpath(__file__)), '../../common/python_common'))
if PYTHON_COMMON_PATH not in sys.path:
    sys.path.insert(0, PYTHON_COMMON_PATH)

import common.common as common

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        if n <= 1:
            return len(s)
        records = [0] * n
        records[n - 1] = 1
        for i in range(n-2, -1, -1):
            if s[i] == s[i + 1]:
                records[i] = 1
            else:
                index = s[i + 1: ].find(s[i], i + 1, i + 1 + records[i + 1])
                if index == -1:
                    records[i] = records[i + 1] + 1
                else:
                    records[i] = index + 1
        max = 0
        for i in range(n):
            if records[i] > max:
                max = records[i]
        return max
 

if __name__ == '__main__':
    try:
        solution = Solution()
        ret = common.get_string_from_file("./string.txt")
        if ret["result"] != 0:
            print ret["msg"]
            exit
        string = ret["string"]
        ret = common.split(string, "\n")
        if ret["result"] != 0:
            print ret["msg"]
            exit
        strs = ret["array"]
        for i in range(len(strs)):
            print strs[i]
            print solution.lengthOfLongestSubstring(strs[i]) 
        
    except Exception as ex:
        print ex
