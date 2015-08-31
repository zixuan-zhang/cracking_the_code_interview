/*******************************************************************************
 *  @File  : ques2.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年08月30日 星期日 17时58分04秒
 ******************************************************************************/

/*
 * Question:
 *
 * How would you design a stack which, in addition to push and pop, also has a function
 * min which returns the minimum element? Push, pop and min should all operate in
 * O(1) time 
 */

#include <iostream>
#include <climits>
#include <stack>

using namespace std;

/*
 * Solution:
 *
 * 这道题的意思是实现一个栈，这个栈的功能包括push(), pop(), min().并且这三个操作的时间
 * 负责度均为O(1)。需要怎样设计这个栈呢？
 *
 * 很明显需要有一个指针指向最小的值。当push的时候，如果push的value小于min，那么修改这
 * 指针的指向，否则不修改。当执行pop操作时，如果pop的不是最小值，那么不用管；如果pop
 * 的是最小值，那么就需要遍历整个栈搜索下一个最小的值，然后更新指针的指向。
 *
 * 这种方法pop时如果pop的是最小值，则需要O(n)的时间复杂度。
 *
 */
class SpecialStack
{
private:
    const int STACKMAX;
    int *array;

    int top;
    int _min;

public:
    SpecialStack(int stackMax=200):STACKMAX(stackMax)
    {
        array = new int[STACKMAX];
        top = -1;
        _min = INT_MAX;
    }

    bool is_empty()
    {
        return -1 == top;
    }

    bool push(int value)
    {
        if (top + 1 == STACKMAX)
            return false;
        array[++top] = value;
        if (value < _min)
            _min = value;
        return true;
    }

    bool pop(int& value)
    {
        if (is_empty())
            return false;
        value = array[--top];
        if (value == _min)
        {
            _min = INT_MAX;
            for (int i = 0; i <= top; ++i)
            {
                if (_min > array[i])
                    _min = array[i];
            }
        }
        return true;
    }

    bool min(int& value)
    {
        if (is_empty())
            return false;
        value = _min;
        return true;
    }
};

/*
 * Solution2:
 *
 * solution1并没有完全符合要求，那怎样使所有的push, pop, min操作的时间复杂度均为
 * O(1)呢？肯定是需要用空间来换时间。在这里，我们用一个内部栈来保存历史记录中最
 * 小值。
 *
 * 为了简化代码，内部栈我使用STL库
 *
 */

class StackWithMin
{
private:
    int top;
    const int STACKMAX;
    int* array;
    stack<int> innerStack;

public:
    StackWithMin(int stackMax=200):STACKMAX(stackMax)
    {
        array = new int[STACKMAX];
        top = -1;
    }

    bool push(int value)
    {
        if (top + 1 == STACKMAX)
            return false;
        array[++top] = value;
        if (innerStack.empty() || value <= innerStack.top())
            innerStack.push(value);
        return true;
    }

    bool pop(int& value)
    {
        if (-1 == top)
            return false;
        value = array[top--];
        if (value == innerStack.top())
            innerStack.pop();
        return true;
    }

    bool min(int& value)
    {
        if (-1 == top)
            return false;
        value = innerStack.top();
        return true;
    }
};

void test1()
{
    SpecialStack* stack = new SpecialStack();
    stack->push(3);
    stack->push(1);
    stack->push(4);
    stack->push(5);
    stack->push(-1);

    int value;
    if (stack->min(value))
        cout<<value<<endl;

    stack->pop(value);
    if (stack->min(value))
        cout<<value<<endl;
}

void test2()
{
    StackWithMin* stack = new StackWithMin();
    stack->push(3);
    stack->push(1);
    stack->push(4);
    stack->push(5);
    stack->push(-1);

    int value;
    if (stack->min(value))
        cout<<value<<endl;

    stack->pop(value);
    if (stack->min(value))
        cout<<value<<endl;
}

int main()
{
    test2();
    return 0;
}
