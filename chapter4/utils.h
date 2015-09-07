/*******************************************************************************
 *  @File  : utils.h
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年09月06日 星期日 08时24分04秒
 ******************************************************************************/

#include <cstddef>

class Node
{
private:
    int data;
    Node* _left;
    Node* _right;

public:
    Node(int d)
    {
        data = d;
        _left = NULL;
        _right = NULL;
    }
    virtual ~Node()
    {

    }
    Node* left()
    {
        return _left;
    }
    Node* right()
    {
        return _right;
    }
};
