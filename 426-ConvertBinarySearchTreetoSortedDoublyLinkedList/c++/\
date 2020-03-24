#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import sys

PYTHON_COMMON_PATH = os.path.abspath(os.path.join(os.path.dirname(os.path.realpath(__file__)), '../'))
if PYTHON_COMMON_PATH not in sys.path:
    sys.path.insert(0, PYTHON_COMMON_PATH)

from datastruct.datastruct import ListNode as ListNode

def get_string_from_file(file_name):
    ret = {}
    ret["string"] = ""
    ret["result"] = -1
    ret["msg"] = ""
    try:
        fd = open(file_name)
        string = fd.read()
        ret["string"] = string
        ret["result"] = 0
    except Exception as ex:
        ret["msg"] = ex
    finally:
        fd.close()
    return ret

def split(string, sep):
    ret = {}
    ret["array"] = []
    ret["result"] = -1
    ret["msg"] = ""
    strings = []
    try:
        strs = string.split(sep)
        for i in range(len(strs)):
            if strs[i] != "":
                strings.append(strs[i])
        ret["result"] = 0
        ret["array"] = strings
        return ret
    except Exception as ex:
        ret["array"] = ex
    return ret

def strings_to_ints(strs):
    ret = {}
    ret["array"] = []
    ret["result"] = -1
    ret["msg"] = ""
    array = []
    try:
        for i in range(len(strs)):
            array.append(int(strs[i]))
        ret["result"] = 0
        ret["array"] = array
        return ret
    except Exception as ex:
        ret["msg"] = ex
    return ret

def get_numbers_from_file(src_file, sep):
    result = {}
    result["array"] = []
    result["result"] = -1
    result["msg"] = ""
    array = []
    try:
        ret = get_string_from_file(src_file)
        if ret["result"] != 0:
            result["msg"] = ret["result"]
            return result
        ret = split(ret["string"], sep)
        if ret["result"] != 0:
            result["msg"] = ret["result"]
            return result
        ret = strings_to_ints(ret["array"])
        if ret["result"] != 0:
            result["msg"] = ret["result"]
            return result
        result["array"] = ret["array"]
        result["result"] = 0
        return result
    except Exception as ex:
        result["msg"] = ex
    return result

def numbers_to_List(array):
    result = {}
    result["List"] = None
    result["result"] = -1
    result["msg"] = ""
    List = None
    retList = List;
    try:
       for i in range(len(array)):
           node = ListNode(array[i])
           if List == None:
               List = node
               retList = List
               continue
           List.next = node
           List = node
       result["List"] = retList
       result["result"] = 0
       return result
    except Exception as ex:
        result["msg"] = ex
    return result

def get_List_from_file(src_file, sep):
    result = {}
    result["List"] = None
    result["result"] = -1
    result["msg"] = ""
    try:
        ret = get_numbers_from_file(src_file, sep)
        if ret["result"] != 0:
            result["msg"] = ret["result"]
            return result
        ret = numbers_to_List(ret["array"])
        if ret["result"] != 0:
            result["msg"] = ret["result"]
            return result
        result["List"] = ret["List"]
        result["result"] = 0
    except Exception as ex:
        result["msg"] = ex
    return result

def printList(List):
    try:
        string=""
        while List != None:
            string += str(List.val)
            string += " "
            List = List.next
        print string
    except Exception as ex:
        print ex

