/*******************************************************************************
 *  @File  : ques6.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年09月29日 星期二 14时43分46秒
 ******************************************************************************/

/*
 * Question:
 *
 * Design an algorithm and write code to find the first common ancestor of two nodes
 * in a binary tree  Avoid storing additional nodes in a data structure  NOTE: This is not
 * necessarily a binary search tree 
 *
 */

#include <iostream>
#include <map>
#include "utils.h"

using namespace std;

/*
 * Solution1:
 *
 * 这道题的题意我不是特别理解。就在那句“Avoid storing additional nodes in a data
 * structure”。我的理解是每个节点只有左子节点和右子节点没有父节点这个additional
 *
 * 首先有一种方法就是用map来记录每个节点的父节点。有了这个map后再根据这个链去找到
 * first common ancestor
 *
 */

map<Node*, Node*> node2parent_map;
void build_map(Node* root)
{
    if (NULL != root->left())
    {
        node2parent_map[root->left()] = root;
        build_map(root->left());
    }
    if (NULL != root->right())
    {
        node2parent_map[root->right()] = root;
        build_map(root->right());
    }
}

Node* first_common_ancestor(Node* node1, Node* node2)
{
    Node* firstCommonAncestor;
    map<Node*, Node*>::iterator iter1 = node2parent_map.find(node1);

    while (iter1 != node2parent_map.end() )
    {
        map<Node*, Node*>::iterator iter2 = node2parent_map.find(node2);
        while (iter2 != node2parent_map.end())
        {
            if (iter1->second == iter2->second)
                return iter1->second;
            iter2 = node2parent_map.find(iter2->second);
        }
        iter1 = node2parent_map.find(iter1->second);
    }

    return NULL;
}

void driver()
{
    int array[] = {5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12};
    //int array[] = {1, 2, 3, 4};
    Tree* tree = new Tree();
    for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
    {
        tree->insert(array[i]);
    }
    build_map(tree->root());
    
    Node* node1 = tree->find_node(2);
    Node* node2 = tree->find_node(12);

    Node* result = first_common_ancestor(node1, node2);
    cout<<result->value()<<endl;
}

int main()
{
    driver();
    return 0;
}
