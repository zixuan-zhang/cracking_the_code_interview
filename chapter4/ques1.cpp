/*******************************************************************************
 *  @File  : ques1.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年09月06日 星期日 08时10分09秒
 ******************************************************************************/

/*
 * Question:
 *
 * Implement a function to check if a tree is balanced  For the purposes of this question,
 * a balanced tree is defined to be a tree such that no two leaf nodes differ in distance
 * from the root by more than one 
 *
 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include "utils.h"

using namespace std;


/*
 * Solution:
 *
 * 这道题的解法就是保存此树的叶子节点的深度的最大值和最小值，然后比较差是否大于1.
 * 这种方法的好处就是当判断有不符合的话就直接退出而不用把所有的叶子节点都遍历完。
 */
bool isBalance(Node* node, int& dMax, int& dMin, int depth)
{
    if (NULL == node->left() && NULL == node->right())
    {
        if (INT_MAX == dMax || INT_MIN == dMin)
        {
            dMax = dMin = depth;
            return true;
        }
        if (abs(dMin-depth) > 1 || abs(dMax-depth) > 1)
        {
            dMax = max(dMax, depth);
            dMin = min(dMin, depth);
            return false;
        }
        dMax = max(dMax, depth);
        dMin = min(dMin, depth);
        return true;
    }
    bool left_result = true;
    bool right_result = true;
    if (node->left())
        left_result = isBalance(node->left(), dMax, dMin, depth+1);
    if (node->right())
        right_result = isBalance(node->right(), dMax, dMin, depth+1);
    return left_result && right_result;
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
    // tree->pre_print(tree->root());

    int dMax = INT_MAX;
    int dMin = INT_MIN;
    int depth = 0;
    bool result = isBalance(tree->root(), dMax, dMin, depth=0);
    cout<<result<<" "<<dMax<<" "<<dMin<<endl;
}

int main()
{
    driver();
    return 0;
}
