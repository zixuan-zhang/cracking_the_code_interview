/*******************************************************************************
 *  @File  : ques5.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年09月02日 星期三 18时06分17秒
 ******************************************************************************/

/*
 * Question:
 *
 * Implement a MyQueue class which implements a queue using two stacks 
 *
 */

#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
private:
    stack<int> mainStack;
    stack<int> coStack;

public:
    bool push_back(int value)
    {
        mainStack.push(value);
        return true;
    }

    bool pop(int& value)
    {
        if (mainStack.empty())
            return false;
        int temp;
        while (!mainStack.empty())
        {
            temp = mainStack.top();
            coStack.push(temp);
            mainStack.pop();
        }
        value = coStack.top();
        coStack.pop();

        while (!coStack.empty())
        {
            temp = coStack.top();
            mainStack.push(temp);
            coStack.pop();
        }
        return true;
    }

    bool empty()
    {
        return mainStack.empty();
    }
};

int main()
{
    MyQueue queue;
    for (int i = 0; i < 10; ++i)
        queue.push_back(i);
    int value;
    while (!queue.empty())
    {
        queue.pop(value);
        cout<<value<<" ";
    }
    cout<<endl;
    return 0;
}
