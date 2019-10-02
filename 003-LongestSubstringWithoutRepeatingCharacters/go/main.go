package main

import (
    "fmt"
    "common"
    "strings"
)

func lengthOfLongestSubstring(s string) int {
    n := len(s)
    if (n <= 1) {return len(s)}
    var records []int = make([]int, n)
    records[n - 1] = 1
    for i := n -2; i >= 0; i-- {
        if (s[i] == s[i + 1]) {
            records[i] = 1;
        }else{
            if (!strings.Contains(s[i + 1: i + 1 + records[i +1]], string(s[i]))) {
                records[i] = records[i + 1] + 1;
            }else {
                index := strings.Index(s[i + 1: i + 1 + records[i +1]], string(s[i]))
                records[i] = index + 1
            }
        }
    }
    max := 0
    for _, num := range(records) {
        if num > max {max = num}
    }
    return max
}

func main() {
    content := common.GetStringFromFile("string.txt")
    strs := common.Split(content, "\n")
    for _, str := range(strs) {
        fmt.Println(str)
        length := lengthOfLongestSubstring(str)
        fmt.Println(length)
    }
}
