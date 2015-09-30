/*******************************************************************************
 *  @File  : ques8.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年09月30日 星期三 07时57分37秒
 ******************************************************************************/

/*
 * Question:
 *
 * You are given a binary tree in which each node contains a value  Design an algorithm
 * to print all paths which sum up to that value  Note that it can be any path in the tree
 * - it does not have to start at the root 
 *
 */

#include <iostream>
#include <map>
#include <vector>
#include "double_tree.h"
#include "utils.h"

using namespace std;

/*
 * Solution:
 *
 * 其中一种方法就是每个节点保存该由root到该节点的所有的value相加组合。
 * 也就是每个节点有一个map<Node*, vector<int> >的哈希。vector<int>中保存的就是可能出现的
 * value。
 * build完上述之后再去遍历每个节点的所有value，看看是否有该值。如果有的话则由下到上
 * 找到所有的节点并输出。
 *
 * 此方法依赖的是该树必须有parent的节点。
 *
 */

void build_map(map<DoubleNode*, vector<int> >& node2vec, DoubleNode* node)
{
    DoubleNode* parent = node->parent();
    vector<int> value_vec;
    value_vec.push_back(node->value());
    if (NULL != parent) 
    {
        map<DoubleNode*, vector<int> >::iterator iter = node2vec.find(parent);
        for (int i = 0; i < iter->second.size(); ++i)
        {
            value_vec.push_back(iter->second[i] + node->value());
        }
    }
    node2vec[node] = value_vec;
    if (NULL != node->left())
        build_map(node2vec, node->left());
    if (NULL != node->right())
        build_map(node2vec, node->right());
}

void record_path(DoubleNode* node, int layer)
{
    DoubleNode* pointer = node;
    vector<int> value_vec;
    for (int i = 0; i <= layer; ++i)
    {
        value_vec.push_back(pointer->value());
        pointer = pointer->parent();
    }
    for (int i = value_vec.size() -1 ; i >= 0; --i)
    {
        cout<<value_vec[i]<<" ";
    }
    cout<<endl;
}

int find_paths(int value)
{
    int array[] = {5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12};
    DoubleTree* tree = new DoubleTree();
    for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
    {
        tree->insert(array[i]);
    }

    map<DoubleNode*, vector<int> > node2vec;
    build_map(node2vec, tree->root());

    for (map<DoubleNode*, vector<int> >::iterator iter = node2vec.begin();
            iter != node2vec.end(); ++iter)
    {
        for (int i = 0; i < iter->second.size(); ++i)
        {
            if (iter->second[i] == value)
            {
                record_path(iter->first, i);                
            }
        }
    }
}

/*
 * Solution:
 *
 * 另外一种方法，就是遍历到每个节点的时候，保存root节点到该节点的path。
 * 然后由下往上遍历该path，看看有没有sum等于该value，如果有的话则输出
 * 该sub-path
 *
 */

void print_path(vector<int>& path_vec, int level)
{
    for (int i = level; i < path_vec.size(); ++i)
        cout<<path_vec[i]<<" ";
    cout<<endl;
}

void solution2(Node* node, vector<int>& path_vec, int sum)
{
    path_vec.push_back(node->value());
    int temp = 0;
    for (int i = path_vec.size() - 1; i >= 0; i--)
    {
        temp += path_vec[i]; 
        if (temp == sum)
            print_path(path_vec, i);
        if (temp > sum)
            break;
    }
    if (NULL != node->left())
    {
        solution2(node->left(), path_vec, sum);
        path_vec.pop_back();
    }
    if (NULL != node->right())
    {
        solution2(node->right(), path_vec, sum);
        path_vec.pop_back();
    }
}

void find_paths2(int sum)
{
    int array[] = {5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12};
    Tree* tree = new Tree();
    for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
    {
        tree->insert(array[i]);
    }
    vector<int> path_vec;
    solution2(tree->root(), path_vec, sum);
}

int main()
{
    //find_paths(8);
    find_paths2(8);
    return 0;
}
