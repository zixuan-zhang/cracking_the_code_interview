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
    int _top;

public:
    Stack(int maxSize=100): MAX_SIZE(maxSize)
    {
        _top = -1;
        array = new int[MAX_SIZE];
    }

    bool push(int value)
    {
        if (_top + 1 == MAX_SIZE)
            return false;
        array[++_top] = value;
        return true;
    }

    bool pop(int& value)
    {
        if (-1 == _top)
            return false;
        value = array[_top--];
        return true;
    }

    int top()
    {
        return array[_top];
    }

    bool empty()
    {
        if (-1 == _top)
            return true;
        return false;
    }
};
