/*******************************************************************************
 *  @File  : ques5.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年09月30日 星期三 19时39分49秒
 ******************************************************************************/

/*
 * Question:
 *
 * Write a function to determine the number of bits required to convert integer A to
 * integer B 
 * Input: 31, 14
 * Output: 2
 *
 */

#include <iostream>

using namespace std;

int bits_convertion(int value1, int value2)
{
    int steps = 0;
    for (int i = 0; i < 32; ++i)
    {
        if ( ((value1>>i)&1) != ((value2>>i)&1) )
            steps += 1;
    }
    return steps;
}

int main()
{
    int res = bits_convertion(31, 14);
    cout<<res<<endl;
    return 0;
}
