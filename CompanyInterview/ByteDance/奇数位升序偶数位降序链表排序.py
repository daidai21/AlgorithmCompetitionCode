#!/usr/bin/env python3
# -*- coding:utf-8 -*-
"""
题目描述：一个链表，奇数位升序偶数位降序，让链表变成升序的。
比如：1 8 3 6 5 4 7 2 9，最后输出1 2 3 4 5 6 7 8 9。

分析：
这道题可以分成三步：
    首先根据奇数位和偶数位拆分成两个链表。
    然后对偶数链表进行反转。
    最后将两个有序链表进行合并。
"""


class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


def showLinkedList(node):
    while node is not None:
        print(node.val, end="")
        if node.next is not None:
            print(" -> ", end="")
        node = node.next
    print()


# 按照奇偶拆分链表
def splitOddEven(root):
    oddRoot, evenRoot = None, None
    oddPtr, evenPtr = None, None
    idx = 1
    while root is not None:
        if idx == 1:
            oddRoot = oddPtr = root
        elif idx == 2:
            evenRoot = evenPtr = root
        elif idx % 2 == 1:
            oddPtr.next = root
            oddPtr = oddPtr.next
        elif idx % 2 == 0:
            evenPtr.next = root
            evenPtr = evenPtr.next
        root = root.next
        idx += 1
    # 跳出循环时要讲 oddPtr， evenPtr 下一个设为空 不然会连到之前的root链上
    oddPtr.next = None
    evenPtr.next = None
    return (oddRoot, evenRoot)


# 反转链表
def reverse(root):
    cur = None
    nxt = None
    while root:
        nxt = root.next
        root.next = cur
        cur = root
        root = nxt
    return cur


# 合并两个链表
def merge(node1, node2):
    res = Node(None)
    ptr = res
    while node1 is not None and node2 is not None:
        if node1.val < node2.val:
            ptr.next = Node(node1.val)
            node1 = node1.next
        else:
            ptr.next = Node(node2.val)
            node2 = node2.next
        ptr = ptr.next
    ptr.next = node1 if node1 is not None else node2
    return res.next


def solve(root):
    # 拆分奇偶链表
    oddRoot, evenRoot = splitOddEven(root)
    showLinkedList(oddRoot)
    showLinkedList(evenRoot)
    # 反转偶数链表
    evenRoot = reverse(evenRoot)
    showLinkedList(evenRoot)
    # 合并链表
    mergeList = merge(oddRoot, evenRoot)
    showLinkedList(mergeList)

    return mergeList


if __name__ == '__main__':
    # test
    node1 = Node(1)
    node2 = Node(8)
    node3 = Node(3)
    node4 = Node(6)
    node5 = Node(5)
    node6 = Node(4)
    node7 = Node(7)
    node8 = Node(2)
    node9 = Node(9)

    node1.next = node2
    node2.next = node3
    node3.next = node4
    node4.next = node5
    node5.next = node6
    node6.next = node7
    node7.next = node8
    node8.next = node9

    showLinkedList(node1)
    result = solve(node1)
    showLinkedList(result)
