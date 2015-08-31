/*******************************************************************************
 *  @File  : utils.h
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年08月31日 星期一 15时03分20秒
 ******************************************************************************/


class Stack
{
private:
    const int MAX_SIZE;
    int* array;
    int top;

public:
    Stack(int maxSize): MAX_SIZE(maxSize)
    {
        top = -1;
        array = new int[MAX_SIZE];
    }

    bool push(int value)
    {
        if (top + 1 == MAX_SIZE)
            return false;
        array[++top] = value;
        return true;
    }

    bool pop(int& value)
    {
        if (-1 == top)
            return false;
        value = array[top--];
        return true;
    }

    bool empty()
    {
        if (-1 == top)
            return true;
        return false;
    }
};
