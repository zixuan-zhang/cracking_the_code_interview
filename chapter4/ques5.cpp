/*******************************************************************************
 *  @File  : ques5.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年09月17日 星期四 10时32分16秒
 ******************************************************************************/


#include <iostream>

#include "double_tree.h"

using namespace std;

/*
 * Solution:
 *
 * 经过观察，每个节点中序遍历的下个节点满足下面三个规则：
 * 1. 如果该节点有右子节点，找到该右子节点中最左的那个
 * 2. 如果没有右子节点，且此节点是父节点的左节点，那么该节点的父节点即是
 * 3. 如果该节点没有右子节点，且此节点是父节点的右节点。则向上找，直到找到一个
 *    节点n是他是它的父节点p的左节点，如果找不到，那么这个节点没有
 *
 */

DoubleNode* find_leftest_node(DoubleNode* root)
{
    DoubleNode* pointer = root;
    while (pointer->left())
        pointer = pointer->left();
    return pointer;
}

DoubleNode* find_left_parent(DoubleNode* node)
{
    DoubleNode* pointer = node;
    DoubleNode* parent = node->parent();
    while (parent)
    {
        if (parent->left() == pointer)
            break;
        pointer = pointer->parent();
        parent = parent->parent();
    }

    return parent;
}
// 找到value节点的下一个节点
DoubleNode* find_next_node_in_order(DoubleNode* root, int value)
{
    DoubleNode* p = root;
    while (p)
    {
        if (value == p->value())
            break;
        if (value < p->value())
        {
            p = p->left();
        }
        else
            p = p->right();
    }
    if (NULL == p)
        return NULL; //error, no value exists

    if (NULL != p->right())
        return find_leftest_node(p->right());

    if (p->parent()->left() == p)
        return p->parent();

    return find_left_parent(p);    
}

int main()
{
    int array[] = {5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12};
    //int array[] = {1, 2, 3, 4};
    DoubleTree* tree = new DoubleTree();
    for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
    {
        tree->insert(array[i]);
    }
    tree->in_order_print(tree->root());

    for (int i = 1; i <= 12; ++i)
    {
        DoubleNode* nextNode = find_next_node_in_order(tree->root(), i);
        if (NULL != nextNode)
            cout<<nextNode->value()<<endl;
        }
    return 0;
}
