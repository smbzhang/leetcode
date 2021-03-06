package main

import (
	"common"
	"fmt"
)

func twoSum(nums []int, target int) []int {
	var ret []int
	for i := 0; i < len(nums)-1; i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i]+nums[j] == target {
				ret = append(ret, i)
				ret = append(ret, j)
				return ret
			}
		}
	}
	return ret
}

func twoSum_2(nums []int, target int) []int {
	var ret []int
	var hmap map[int]int = make(map[int]int, len(nums))
	for i := 0; i < len(nums); i++ {
		hmap[nums[i]] = i
	}
	for i := 0; i < len(nums)-1; i++ {
		sub := target - nums[i]
		index, ok := hmap[sub]
		if ok && index != i {
			ret = append(ret, i)
			ret = append(ret, index)
			return ret
		}
	}
	return ret
}

func main() {
	str := common.GetStringFromFile("./data1.txt")
	strs := common.Split(str, "\n")

	nums, err := common.StringToInt(strs)
	if err != nil {
		fmt.Println(err.Error())
		return
	}
	ret := twoSum(nums, 9)
	fmt.Println(ret)
	ret = twoSum_2(nums, 9)
	fmt.Println(ret)
}
