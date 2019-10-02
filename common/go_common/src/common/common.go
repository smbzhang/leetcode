package common

import (
    "io/ioutil"
    "strings"
    "strconv"
    "datastruct"
    "fmt"
)

func GetStringFromFile(file_name string) string {
    bs, _ := ioutil.ReadFile(file_name)
    str := string(bs)
    return str[: len(str) - 1] // 去除文件最后的 \n
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

func GetIntSliceFromFile(src_file string, sep string) (nums []int) {
    content := GetStringFromFile(src_file)
    strs := Split(content, sep)
    array, _ := StringToInt(strs)
    return array
}

func IntSliceToList(nums []int) *datastruct.ListNode {
    var ret *datastruct.ListNode = nil
    var pcur *datastruct.ListNode = ret
    for _, num := range(nums) {
        node := new(datastruct.ListNode)
        node.Val = num
        node.Next = nil
        if (pcur == nil) {
            pcur = node
            ret = node
        }else {
            pcur.Next = node
            pcur = node
        }
    }
    return ret
}

func GetListFromFile(src_file, sep string) *datastruct.ListNode {
    nums := GetIntSliceFromFile(src_file, sep)
    list := IntSliceToList(nums)
    return list
}

func PrintList(list *datastruct.ListNode) {
    str := ""
    for list != nil {
        if str == "" {
            str = fmt.Sprintf("%d", list.Val)
        }else {
            str = fmt.Sprintf("%s %d", str, list.Val)
        }
        list = list.Next
    }
    fmt.Println(str)
}

