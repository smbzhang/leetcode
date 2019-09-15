package common

import (
    "io/ioutil"
    "strings"
    "strconv"
)

func GetStringFromFile(file_name string) string {
    bs, _ := ioutil.ReadFile(file_name)
    str := string(bs)
    return str
}

func Split(str string, sep string) []string {
    strs := strings.Split(str, sep)
    var ret []string
    for _, str := range(strs) {
        if str != "" {
            ret = append(ret, str)
        }
    }
    return ret
}

func StringToInt(strs []string) (nums []int, err error) {
    err = nil
    for i := 0; i < len(strs); i++ {
        i, err1 := strconv.Atoi(strs[i])
        if err1 != nil {
            err = err1
            return nums, err
        }
        nums = append(nums, i)
    }
    return nums, err
}
