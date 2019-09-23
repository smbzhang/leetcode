#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import sys

PYTHON_COMMON_PATH = os.path.abspath(os.path.join(os.path.dirname(os.path.realpath(__file__)), '../../common/python_common'))
if PYTHON_COMMON_PATH not in sys.path:
    sys.path.insert(0, PYTHON_COMMON_PATH)

import common.common as common

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        ret = []
        n = len(nums)
        for i in range(0, n - 1):
            for j in range(i + 1, n):
                if nums[i] + nums[j] == target:
                    ret.append(i)
                    ret.append(j)
                    return ret
        return ret
    def twoSum_2(self, nums, target):
        ret = []
        n = len(nums)
        hmap = {}
        for i in range(0, n):
            hmap[nums[i]] = i
        for i in range(0, n):
            sub = target - nums[i]
            if hmap.has_key(sub) and hmap[sub] != i:
                ret.append(i)
                ret.append(hmap[sub])
                return ret
        return ret


if __name__ == '__main__':
    try:
        solution = Solution()
        ret = common.get_string_from_file("./data1.txt")
        if ret["result"] != 0:
            print ret["msg"]
            exit
        string = ret["string"]
        
        ret = common.split(string, "\n")
        if ret["result"] != 0:
            print ret["msg"]
            exit
        strs = ret["array"]
        
        ret = common.strings_to_ints(strs)
        if ret["result"] != 0:
            print ret["msg"]
            exit
        array = ret["array"]
        ret = solution.twoSum(array, 9)
        print ret
        ret = solution.twoSum_2(array, 9)
        print ret
    except Exception as ex:
        print ex
