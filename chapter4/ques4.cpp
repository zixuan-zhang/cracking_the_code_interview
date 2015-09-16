/*******************************************************************************
 *  @File  : ques4.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年09月16日 星期三 14时53分09秒
 ******************************************************************************/

/*
 *  Question:
 *
 *  Given a binary search tree, design an algorithm which creates a linked list of all the
 *  nodes at each depth (i e , if you have a tree with depth D, you’ll have D linked lists) 
 *
 */

#include <iostream>
#include <vector>
#include <list>
#include "utils.h"

using namespace std;

/*
 * Solution:
 *
 * 这道题题设是二叉搜索树，其实不管甚么树都可以。在这里在递归的遍历节点的时候再加上个深度
 * 的变量，即当前的深度是多少。把当前节点插入到该深度的list中即可。在这里，使用了vector用
 * 来存储链表，使用list来存储节点值。
 *
 */

vector<list<int> > list_vec;

void create_links(Node* node, int depth)
{
    if (list_vec.size() == depth)
        list_vec.resize(depth + 1);
    list_vec[depth].push_back(node->value());
    if (NULL != node->left())
        create_links(node->left(), depth+1);
    if (NULL != node->right())
        create_links(node->right(), depth+1);
}


int main()
{
    int array[] = {5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12};
    //int array[] = {1, 2, 3, 4};
    Tree* tree = new Tree();
    for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
    {
        tree->insert(array[i]);
    }

    create_links(tree->root(), 0);
    for (int i = 0; i < list_vec.size(); ++i)
    {
        for (list<int>::iterator it = list_vec[i].begin();
                it != list_vec[i].end(); ++it)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    return 0;
}
