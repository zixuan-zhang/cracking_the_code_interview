/*******************************************************************************
 *  @File  : ques3.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年08月31日 星期一 14时42分37秒
 ******************************************************************************/

/*
 * Question:
 *
 * Imagine a (literal) stack of plates  If the stack gets too high, it might topple
 * Therefore, in real life, we would likely start a new stack when the previous
 * stack exceeds some threshold  Implement a data structure SetOfStacks that mimics
 * this. SetOfStacks should be composed of several stacks, and should create a new 
 * stack once the previous one exceeds capacity  SetOfStacks push() and SetOfStacks
 * pop() should behave identically to a single stack (that is, pop() should return
 * the same values as it would if there were just a single stack) 
 * FOLLOW UP
 * Implement a function popAt(int index) which performs a pop operation on a specific
 * sub-stack 
 *
 */

#include <iostream>
#include "utils.h"

using namespace std;

/*
 * Solution:
 *
 * 就说下我的思路吧。
 * SetOfStack肯定有TOTALSIZE和SIGNLESIZE这两个参数，分别代表总的栈size和单个栈size.
 * 有了这两个参数，我们就可以直到最大的栈数量。然后可以用数组stackPosition来保存栈
 * 的位置。（栈在内存中的位置不需要连续）。也可以用链表来保存，用数组更简单。
 * 使用stackCount来保存目前栈的总数，用curStack来保存当前栈的编号。
 * 当push的时候，根据stackPosition[curStack]找到当前栈，然后调用这个栈的push操作。
 * 如果push失败则说明此栈已经满了，需要申请新的栈。
 * 同理，pop的时候，根据stackPosition[curStack]找到当前栈，然后调用这个栈的pop操作
 * 如果pop失败，则说明这个栈为空，curStack--, stackCount--
 *
 *
 */

class SetOfStack
{
private:
    int curStackCount;
    int maxStackCount;
    int curStack;

    Stack** stackPosition;
    const int TOTAL_SIZE;
    const int SINGLE_SIZE;

public:
    SetOfStack(int totalSize = 1000, int singleSize = 90):
        TOTAL_SIZE(totalSize), SINGLE_SIZE(singleSize)
    {
        curStackCount = 1;
        maxStackCount = TOTAL_SIZE / SINGLE_SIZE + 1;
        curStack = -1;
        stackPosition = new Stack*[maxStackCount];
    }

    bool push(int value)
    {
        if (-1 == curStack)
        {
            Stack* newStack = new Stack(min(SINGLE_SIZE, 
                        TOTAL_SIZE - curStackCount * SINGLE_SIZE));
            stackPosition[++curStack] = newStack;
            cout<<"stack "<<curStack<<" created"<<endl;
        }
        Stack* thisStack = stackPosition[curStack];
        if (!thisStack->push(value))
        {
            // thisStack is full, new Stack
            if (curStackCount == maxStackCount 
                    || curStackCount * SINGLE_SIZE >= TOTAL_SIZE)
                return false;
            Stack* newStack = new Stack(min(SINGLE_SIZE, 
                        TOTAL_SIZE - curStackCount * SINGLE_SIZE));
            stackPosition[++curStack] = newStack;
            cout<<"stack "<<curStack<<" created"<<endl;
            curStackCount += 1;
            newStack->push(value);
        }
        return true;
    }

    bool pop(int& value)
    {
        if (-1 == curStack)
            return false;
        Stack* thisStack = stackPosition[curStack];
        if (!thisStack->pop(value))
        {
            //SetOfStack is empty
            return false;
        }
        else
        {
            if (thisStack->empty())
            {
                delete thisStack;
                cout<<"stack "<<curStack<<" delete"<<endl;
                curStack--;
                curStackCount--;
            }
        }
    }

    bool empty()
    {
        if (-1 == curStack)
            return false;
        return true;
    }
};

int main()
{
    SetOfStack stack(10, 3);
    for (int i = 0; i < 20; ++i)
    {
        stack.push(i);
        cout<<i<<endl;
    }

    int value;
    for (int i = 0; i < 20; ++i)
    {
        stack.pop(value);
        cout<<i<<" "<<value<<endl;
    }
    return 0;
}
