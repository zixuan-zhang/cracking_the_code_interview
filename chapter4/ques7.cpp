/*******************************************************************************
 *  @File  : ques7.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年09月29日 星期二 21时15分53秒
 ******************************************************************************/

/*
 * Question:
 *
 * You have two very large binary trees: T1, with millions of nodes, and T2, with
 * hundreds of nodes  Create an algorithm to decide if T2 is a subtree of T1 
 *
 */

#include <iostream>
#include "utils.h"

using namespace std;

/*
 * Solution:
 *
 * 这道题就是简单的先找到相同的根，然后再去判断剩下的节点是否一样
 *
 */

bool equal(Node* node1, Node* node2)
{
    if (NULL == node1 && NULL == node2)
        return true;
    if (NULL == node2)
        return true;
    if (NULL == node1)
        return false;
    if (node1->value() != node2->value())
        return false;
    else
    {
        return equal(node1->left(), node2->left()) &&
            equal(node1->right(), node2->right());
    }
}

bool subtree(Node* node1, Node* node2)
{
    if (NULL == node1 && NULL == node2)
        return true;
    if (NULL == node2)
        return true;
    if (NULL == node1)
        return false;
    if (node1->value() == node2->value())
    {
        if (equal(node1, node2))
            return true;
    }
    return subtree(node1->left(), node2) || subtree(node1->right(), node2);
}

bool contain_tree(Node* node1, Node* node2)
{
    return subtree(node1, node2);
}

void driver()
{
    int array1[] = {5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12};
    Tree* tree1 = new Tree();
    for (int i = 0; i < sizeof(array1) / sizeof(int); ++i)
    {
        tree1->insert(array1[i]);
    }

    int array2[] = {8, 7, 9, 11};
    Tree* tree2 = new Tree();
    for (int i = 0; i < sizeof(array2) / sizeof(int); ++i)
    {
        tree2->insert(array2[i]);
    }

    bool res = contain_tree(tree1->root(), tree2->root());
    cout<<res<<endl;

}

int main()
{
    driver();
    return 0;
}
