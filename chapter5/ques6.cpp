/*******************************************************************************
 *  @File  : ques6.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年09月30日 星期三 19时53分25秒
 ******************************************************************************/

/*
 * Question:
 *
 * Write a program to swap odd and even bits in an integer with as few instructions as
 * possible (e g , bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc) 
 *
 */

int convertion(int value)
{
    return ((value & 0X55555555) << 1) | ((value & 0XCCCCCCCC) >> 1);
}

int main()
{
    int res = convertion(31);
    return 0;
}
