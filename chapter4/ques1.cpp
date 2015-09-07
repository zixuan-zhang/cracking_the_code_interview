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
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

class Node
{
private:
    int data;
    Node* _left, _right;

public:
    Node()
    {
        _left = _right = NULL;
    }

    Node(int d)
    {
        _left = _right = NULL;
        data = d;
    }

    Node* left()
    {
        return _left;
    }
    
    Node* right()
    {
        return _right;
    }

    int value()
    {
        return data;
    }

    void set_left(Node* temp)
    {
        _left = temp;
    }

    void set_right(Node* temp)
    {
        _right = temp;
    }
}

class Tree
{
private:
    Node* _root;

public:
    Tree()
    {
        _root = NULL;
    }

    Node* root()
    {
        return _root;
    }

    void insert(int data)
    {
        if (NULL == _root)
        {
            _root = new Node(data);
        }
        else
        {
            Node* p = _root;
            while (true)
            {
                if ( data < p->value())
                {
                    if (NULL == p->left())
                    {
                        Node* temp = new Node(data);
                        p->set_left(temp);
                        break;
                    }
                    else
                    {
                        p = p->left();
                    }
                }
                else
                {
                    if (NULL == p->right())
                    {
                        Node* temp = new Node(data);
                        p->set_right(temp);
                        break;
                    }
                    else
                    {
                        p = p->right();
                    }
                }
            }
        }
    }
}

bool isBalance(Node* node, int& dMin, int& dMax, int depth)
{
    if (NULL == node)
    {
        if (INT_MAX == dMax || INT_MIN == dMin)
        {
            Max = Min = depth;
            return true;
        }
        if (abs(dMin, depth) > 1 || abs(dMax, depth) > 1)
            return false;
        dMax = max(dMax, depth);
        dMin = min(dMin, depth);
        return true;
    }
    return isBalance(node->left(), dMin, dMax, depth+1) &&
        isBalance(node->right(), dMin, dMax, depth+1)
}

void driver()
{
}

int main()
{
    int dMax = INT_MAX;
    int dMin = INT_MIN;
    int depth = 0;
    bool result = isBalance(root, dMax, dMin, depth=0);
    return 0;
}
