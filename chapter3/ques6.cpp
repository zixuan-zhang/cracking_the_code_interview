/*******************************************************************************
 *  @File  : ques6.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年09月05日 星期六 18时53分15秒
 ******************************************************************************/

/*
 * Question:
 *
 * Write a program to sort a stack in ascending order  You should not make any assumptions about how the stack is implemented  The following are the only functions that
 * should be used to write this program: push | pop | peek | isEmpty 
 *
 */

#include <iostream>
#include <stack>

using namespace std;


void sort(stack<int> s1)
{
    stack<int> s2;
    while (!s1.empty())
    {
        int data = s1.top();
        s1.pop();
        while (!s2.empty() && data < s2.top())
        {
            s1.push(s2.top());
            s2.pop();
        }
        s2.push(data);
    }
    while (!s2.empty())
    {
        cout<<s2.top()<<" ";
        s2.pop();
    }
}

int main()
{
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(5);
    s.push(2);
    s.push(4);
    sort(s);
    return 0;
}
