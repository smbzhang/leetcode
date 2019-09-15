#!/usr/bin/env python
# -*- coding: utf-8 -*-

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
    ret["strs"] = ""
    ret["result"] = -1
    ret["msg"] = ""
    strings = []
    try:
        strs = string.split(sep)
        for i in range(len(strs)):
            if strs[i] != "":
                strings.append(strs[i])
        ret["result"] = 0
        ret["strs"] = strings
        return ret
    except Exception as ex:
        ret["msg"] = ex
    return ret

def strings_to_ints(strs):
    ret = {}
    ret["array"] = ""
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

