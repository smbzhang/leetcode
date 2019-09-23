package main

import (
   "common"
   . "datastruct"
)

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    var pcur, ret *ListNode = nil, nil
    var num1, num2, carry int = 0, 0, 0
    for l1 != nil || l2 != nil {
        if (l1 == nil) {num1 = 0} else {num1 = l1.Val}
        if (l2 == nil) {num2 = 0} else {num2 = l2.Val}
        mod := (num1 + num2 + carry) % 10
        carry = (num1 + num2 + carry) / 10
        node := new(ListNode)
        node.Val = mod
        node.Next = nil
        if (pcur == nil) {
            pcur = node
            ret = node
        }else {
            pcur.Next = node
            pcur = node
        }
        if (l1 != nil) {l1 = l1.Next}
        if (l2 != nil) {l2 = l2.Next}
    }
    if (carry != 0) {
        node := new(ListNode)
        node.Val = carry
        node.Next = nil
        pcur.Next = node
    }
    return ret
}

func main() {
    l1 := common.GetListFromFile("list1.txt", " ")
    l2 := common.GetListFromFile("list2.txt", " ")
    common.PrintList(l1)
    common.PrintList(l2)

    l3 := addTwoNumbers(l1, l2)
    common.PrintList(l3)
}
