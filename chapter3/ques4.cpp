/*******************************************************************************
 *  @File  : ques4.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年09月02日 星期三 16时18分46秒
 ******************************************************************************/

/*
 * Question:
 *
 * In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different
 * sizes which can slide onto any tower  The puzzle starts with disks sorted in ascending
 * order of size from top to bottom (e g , each disk sits on top of an even larger one)  You
 * have the following constraints:
 * (A) Only one disk can be moved at a time 
 * (B) A disk is slid off the top of one rod onto the next rod 
 * (C) A disk can only be placed on top of a larger disk 
 * Write a program to move the disks from the first rod to the last using Stacks 
 *
 */

#include <iostream>
#include "utils.h"

using namespace std;

Stack s1, s2, s3;

void init(int n)
{
    for (int i = n; i > 0; --i)
    {
        s1.push(i);
    }
}

void show_stack_status()
{
    cout<<"new s1"<<endl;
    for (int i = 0; i <= s1._top; ++i)
    {
        cout<<s1.array[i]<<" ";
    }
    cout<<endl<<"new s2"<<endl;
    for (int i = 0; i <= s2._top; ++i)
    {
        cout<<s2.array[i]<<" ";
    }
    cout<<endl<<"new s3"<<endl;
    for (int i = 0; i <= s3._top; ++i)
    {
        cout<<s3.array[i]<<" ";
    }
    cout<<endl<<"---------------------"<<endl;
}

void hanoi(Stack& from, Stack& to, Stack& avalible, int n)
{
    int value;
    if (1 == n)
    {
        from.pop(value);
        to.push(value);
    //    show_stack_status();
        return ;
    }
    hanoi(from, avalible, to, n-1);
    from.pop(value);
    to.push(value);
    //show_stack_status();
    hanoi(avalible, to, from, n-1);
    //show_stack_status();
}

int main()
{
    int number = 30;
    init(number);
    hanoi(s1, s2, s3, number);
    show_stack_status();
    return 0;
}
