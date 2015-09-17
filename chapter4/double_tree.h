/*******************************************************************************
 *  @File  : doulbe_tree.h
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年09月17日 星期四 10时39分07秒
 ******************************************************************************/

#include <iostream>

using namespace std;

class DoubleNode
{
private:
    int data;
    DoubleNode* _parent;
    DoubleNode* _left;
    DoubleNode* _right;
public:
    DoubleNode()
    {
        _parent = _left = _right = NULL;
    }

    DoubleNode(int d): data(d)
    {
        _parent = _left = _right = NULL;
    }

    DoubleNode* left()
    {
        return _left;
    }

    DoubleNode* right()
    {
        return _right;
    }

    DoubleNode* parent()
    {
        return _parent;
    }

    int value()
    {
        return data;
    }

    void set_left(DoubleNode* temp)
    {
        _left = temp;
    }

    void set_right(DoubleNode* temp)
    {
        _right = temp;
    }

    void set_parent(DoubleNode* temp)
    {
        _parent = temp;
    }
};

class DoubleTree
{
private:
    DoubleNode* _root;

public:
    DoubleTree()
    {
        _root = NULL;
    }

    DoubleNode* root()
    {
        return _root;
    }

    void insert(int data)
    {
        if (NULL == _root)
            _root = new DoubleNode(data);
        else
        {
            DoubleNode* p = _root;
            while (true)
            {
                if ( data < p->value())
                {
                    if (NULL == p->left())
                    {
                        DoubleNode* temp = new DoubleNode(data);
                        p->set_left(temp);
                        temp->set_parent(p);
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
                        DoubleNode* temp = new DoubleNode(data);
                        p->set_right(temp);
                        temp->set_parent(p);
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

    void pre_order_print(DoubleNode* root)
    {
        if (root)
        {
            cout<<root->value()<<" ";
            pre_order_print(root->left());
            pre_order_print(root->right());
        }
    }

    void in_order_print(DoubleNode* root)
    {
        if (root)
        {
            in_order_print(root->left());
            cout<<root->value()<<" ";
            in_order_print(root->right());
        }
    }
};
