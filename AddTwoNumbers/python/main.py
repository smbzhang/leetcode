#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import sys

PYTHON_COMMON_PATH = os.path.abspath(os.path.join(os.path.dirname(os.path.realpath(__file__)), '../../common/python_common'))
if PYTHON_COMMON_PATH not in sys.path:
    sys.path.insert(0, PYTHON_COMMON_PATH)

from datastruct.datastruct import ListNode as ListNode
import common.common as common


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        ret = None
        pcur = ret
        num1 = 0
        num2 = 0
        carry = 0
        while l1 != None or l2 != None :
            if l1 == None:
                num1 = 0
            else:
                num1 = l1.val
            if l2 == None:
                num2 = 0
            else:
                num2 = l2.val
            mod = (num1 + num2 + carry) % 10
            carry = (num1 + num2 + carry) / 10
            node = ListNode(mod)
            if pcur == None:
                pcur = node
                ret = pcur
            else:
                pcur.next = node
                pcur = node
            if l1 != None:
                l1 = l1.next
            if l2 != None:
                l2 = l2.next
        if carry != 0:
            node = ListNode(carry)
            pcur.next = node
        return ret

if __name__ == '__main__':
    try:
        ret = common.get_List_from_file("list1.txt", " ")
        if ret["result"] != 0:
            print ret["msg"]
        l1 = ret["List"]
        common.printList(l1)
        ret = common.get_List_from_file("list2.txt", " ")
        if ret["result"] != 0:
            print ret["msg"]
        l2 = ret["List"]
        common.printList(l2)
        solution = Solution()
        ret = solution.addTwoNumbers(l1, l2)
        common.printList(ret)
    except Exception as ex:
        print ex
