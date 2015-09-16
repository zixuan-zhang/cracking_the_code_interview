/*******************************************************************************
 *  @File  : ques3.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年09月16日 星期三 14时16分53秒
 ******************************************************************************/

/*
 *  Question:
 *
 *  Given a sorted (increasing order) array, write an algorithm to create a binary tree with
 *  minimal height 
 */

#include <iostream>
#include "utils.h"

using namespace std;

/*
 *  Solution:
 *
 *  可以采取递归的方法，每次取该数组的中间的那个值，插入到树中，然后再分别处理前半部分数组和
 *  后半部分数组。
 */

void build_tree(Tree* tree, int *array, int start, int end)
{
    if (start > end)
        return;
    if (start == end)
    {
        tree->insert(array[start]);
        return;
    }
    int mid = (start + end) / 2;
    tree->insert(array[mid]);
    build_tree(tree, array, start, mid-1);
    build_tree(tree, array, mid+1, end);
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Tree* tree = new Tree();
    build_tree(tree, array, 0, 9);
    tree->pre_print(tree->root());
    return 0;
}
