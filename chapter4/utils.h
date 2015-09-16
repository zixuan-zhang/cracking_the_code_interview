/*******************************************************************************
 *  @File  : utils.h
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年09月06日 星期日 08时24分04秒
 ******************************************************************************/

#include <cstddef>
#include <iostream>

using namespace std;

class Node
{
private:
    int data;
    Node* _left;
    Node* _right;

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
};

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

    void pre_print(Node* root)
    {
        if (root)
        {
            cout<<root->value()<<" ";
            pre_print(root->left());
            pre_print(root->right());
        }
    }
};
