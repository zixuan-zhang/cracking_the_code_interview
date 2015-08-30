/*
 * Question:
 *
 * Describe how you could use a single array to implement three stacks 
 *
 */

#include <iostream>

using namespace std;


/*
 * Solution:
 *
 * 这道题是问怎样用一个数据来实现三个栈。o
 * 我先在一个数组上实现两个栈。设数据Array的索引是[0, Max]。那么其中一个栈由0向
 * 大的方向增长；另一个栈由Max向小的方向增长。当两个栈相遇的时候，那么说明空间
 * 已经满了，不能再增长了。
 * 这种方式可以有效利用内存空间，减少浪费
 *
 */
class TwoStacksInOneArray
{
private:
    const int STACKMAX;
    int *array;

    int top1; //最上面的元素的索引
    int top2;

public:
    TwoStacksInOneArray():STACKMAX(200)
    {
        top1 = -1;
        top2 = STACKMAX;
        array = new int[STACKMAX];
    }
    bool push1(int value)
    {
        if (top1 + 1 == top2)
            return false; // stack is full
        array[++top1] = value;
        return true;
    }
    bool pop1(int &value)
    {
        if (-1 == top1)
            return false;
        value = array[top1--];
        return true;
    }

    bool push2(int value)
    {
        if (top2 - 1 == top1)
            return false;
        array[--top2] = value;
        return true;
    }
    bool pop2(int &value)
    {
        if (STACKMAX == top2)
            return false;
        value = array[top2++];
        return true;
    }
};

/*
 * Solution2:
 *
 * 那么怎样在一个Array中实现三个stack呢？
 * 其中一种方法是将Array平均分成三个部分，每个栈使用自己的部分。
 * 这有点像操作系统的理念。在操作系统中，所有的内存也像是一个Array，在操作系统中
 * 怎样实现多个栈呢？其中一种方式就是再分配定长的数组。
 *
 */

class ThreeStacksInOneArray
{
private:
    int STACKMAX;
    int* array;
    int max[3];
    int top[3]; //最顶元素索引
    int bottom[3];
public:
    ThreeStacksInOneArray():STACKMAX(200)
    {
        array = new int[STACKMAX];
        bottom[0] = 0;
        bottom[1] = STACKMAX / 3;
        bottom[2] = STACKMAX * 2 /3;

        top[0] = bottom[0] - 1; 
        top[1] = bottom[1] - 1;
        top[2] = bottom[2] - 1;

        max[0] = STACKMAX / 3;
        max[1] = STACKMAX * 2 / 3;
        max[2] = STACKMAX;
    }
    ~ThreeStacksInOneArray()
    {
        delete[] array;
    }

    bool push(int stackNum, int value)
    {
        if (top[stackNum] + 1 == max[stackNum])
            return false;
        array[++top[stackNum]] = value;
        return true;
    }
    bool pop(int stackNum, int& value)
    {
        if (top[stackNum] == bottom[stackNum] - 1)
            return false;
        value = array[top[stackNum]--];
        return true;
    }
};

/*
 * Solution3:
 *
 * 有没有一种方法可以不限制单独stack的大小，可以任意的push直到整个array的空间被
 * 填满呢？
 *
 * 办法还是有的，不过就需要更多的数据结构来维护。其中非常重要的一点是，如果采用
 * 这种方法，同一个stack中的元素不连续，也就是会出现在各个地方。为什么会出现这种
 * 情况呢？
 *
 * 例如执行push操作的时候，不断的向array申请元素。申请元素肯定是按一定的方向去
 * 找空的位置，在最开始的一段时间，stack1, stack2, stack3占据了array头部的一定
 * 空间。当stack1要pop的时候就会释放空间，这样的话就相当于有了碎片，就是不连续
 * 的了。那么这个碎片以后还是要用到的，可能被stack2申请，就造成了上面的那种情况。
 * 因此，在stack中，还要有单独的数据结构来保存此元素的前一个元素的位置。
 *
 * 另外，还有保存当前未被利用的元素位置。在这里，我使用bool数组来保存这个元素
 * 位置是否被占用。当push的时候，从freeList中从头向尾去寻找值为true的元素，这个
 * 位置就未被利用，然后将这个位置置false。pop的时候也是一样。freeList也可以用
 * 链表来保存，会占用更少的空间，而且也不用循环去找free的位置，因此时间复杂度
 * 上会更优。但是原理都是一样的，为了编码简单，我使用数据来保存。
 *
 * 以下是具体实现。
 *
 */
class Node
{
public:
    int value;
    int previous;
    Node()
    {
        previous = -1;
    }
    virtual ~Node(){}
};

class ThreeStacksOfArray
{
private:
    int STACKMAX;
    Node* array;
    bool* freeList;
    int top[3];

    int find_empty()
    {
        for (int i = 0; i < STACKMAX; ++i)
            if (true == freeList[i])
                return i;
        return -1; // means full
    }

public:
    ThreeStacksOfArray():STACKMAX(200)
    {
        array = new Node[STACKMAX];
        freeList = new bool[STACKMAX];
        for (int i = 0; i < STACKMAX; ++i)
            freeList[i] = true;
        for (int i = 0; i < 3; ++i)
            top[i] = -1;
    }

    ~ThreeStacksOfArray()
    {
        delete[] array;
        delete[] freeList;
    }

    bool push(int stackNum, int value)
    {
        //从freeList中找到一个空的位置
        int index = find_empty();
        if (-1 == index)
            return false;
        array[index].value = value;
        array[index].previous = top[stackNum];
        top[stackNum] = index;
        freeList[index] = false;
        return true;
    }

    bool pop(int stackNum, int& value)
    {
        if (-1 == top[stackNum])
            return false;
        value = array[top[stackNum]].value;
        freeList[top[stackNum]] = true;
        top[stackNum] = array[top[stackNum]].previous;
        return true;
    }
};

void test1()
{
    TwoStacksInOneArray* twoStacks = new TwoStacksInOneArray();
    twoStacks->push1(1);
    twoStacks->push1(2);
    twoStacks->push1(3);

    twoStacks->push2(4);
    twoStacks->push2(5);
    twoStacks->push2(6);

    int value;
    if (twoStacks->pop1(value))
        cout<<value<<endl;
    if (twoStacks->pop2(value))
        cout<<value<<endl;
}

void test2()
{
    int value;
    ThreeStacksInOneArray* threeStacks = new ThreeStacksInOneArray();
    threeStacks->push(0, 1);
    threeStacks->push(0, 2);
    threeStacks->push(0, 3);
    threeStacks->pop(0, value);
    threeStacks->pop(0, value);
    cout<<value<<endl;


    threeStacks->push(1, 1);
    threeStacks->push(1, 2);
    threeStacks->push(1, 3);
    threeStacks->pop(1, value);
    threeStacks->pop(1, value);
    cout<<value<<endl;

    threeStacks->push(2, 1);
    threeStacks->push(2, 2);
    threeStacks->push(2, 3);
    threeStacks->pop(2, value);
    threeStacks->pop(2, value);
    cout<<value<<endl;
}

void test3()
{
    int value;
    ThreeStacksOfArray* threeStacks = new ThreeStacksOfArray();
    threeStacks->push(0, 1);
    threeStacks->push(0, 2);
    threeStacks->push(0, 3);
    threeStacks->pop(0, value);
    threeStacks->pop(0, value);
    cout<<value<<endl;

    threeStacks->push(1, 1);
    threeStacks->push(1, 2);
    threeStacks->push(1, 3);
    threeStacks->pop(1, value);
    threeStacks->pop(1, value);
    cout<<value<<endl;

    // 预期效果，push199次，最后一次失败。value的输出值为196
    for (int i = 0; i < 199; ++i)
    {
        cout<<threeStacks->push(2, i)<<" ";
    }
    //threeStacks->push(2, 1);
    //threeStacks->push(2, 2);
    //threeStacks->push(2, 3);
    threeStacks->pop(2, value);
    threeStacks->pop(2, value);
    cout<<value<<endl;

}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}
