/*******************************************************************************
 *  @File  : ques3.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年09月30日 星期三 16时28分32秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given an integer, print the next smallest and next largest number that have the same
 * number of 1 bits in their binary representation 
 *
 */

#include <iostream>
#include "utils.h"

using namespace std;

/*
 * next smallest 就是从右往左找到，直到找到0和1，并且这个0在1的右面第一位。然后将这两个
 * 位replace
 *
 */
bool next_smaller(int value, int& nextSmaller)
{
    int index = 100;
    for (int i = 0; i < 31; ++i)
    {
        if ( (((value >> i) & 1) == 0) && ( ((value >> (i+1)) & 1) == 1) )
        {
            index = i;
            break;
        }
    }
    if (100 == index)
       return false; 
    int temp1 = 1 << index;
    int temp2 = ~(1 << (index+1));
    nextSmaller = value | temp1;
    nextSmaller &= temp2;
    return true;
}

bool next_largest(int value, int& nextLargest)
{
    int index_1 = 100;
    int index_0 = 100;
    for (int i = 0; i < 32; ++i)
    {
        if ( ((value >> i) & 1) == 1)
        {
            index_1 = i;
            break;
        }
    }

    if (100 == index_1)
        return false;

    for (int i = index_1 + 1; i < 32; ++i)
    {
        if ( ((value>>i) & 1) == 0)
        {
            index_0 = i;
            break;
        }
    }

    if (100 == index_0)
        return false;

    int temp1 = ~(1 << index_1);
    int temp2 = 1 << index_0;

    nextLargest = value & temp1;
    nextLargest |= temp2;
    return true;
}

int main()
{
    int value = 24;
    int small;
    int large;
    cout<<next_smaller(value, small)<<endl;
    cout<<small<<endl;
    cout<<next_largest(value, large)<<endl;
    cout<<large<<endl;
    return 0;
}
