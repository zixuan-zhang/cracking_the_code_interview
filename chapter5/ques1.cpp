/*******************************************************************************
 *  @File  : ques1.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年09月30日 星期三 10时29分22秒
 ******************************************************************************/

/*
 * Question:
 *
 * You are given two 32-bit numbers, N and M, and two bit positions, i and j  Write a
 * method to set all bits between i and j in N equal to M (e g , M becomes a substring of
 * N located at i and starting at j) 
 * EXAMPLE:
 * Input: N = 10000000000, M = 10101, i = 2, j = 6
 * Output: N = 10001010100
 *
 */

#include <iostream>

using namespace std;

void print_bit(int num)
{
    for (int i = 31; i >= 0; --i)
    {
        int temp = (num >> i) & 1;
        cout<<temp<<" ";
    }
    cout<<endl;
}

void transfer(int num1, int num2, int i, int j)
{
    int temp1 = num2 << i;
    int res = num1 | temp1;
    return res;
}

int main()
{
    int num1 = 0X400;
    int num2 = 0X15;
    transfer(num1, num2, 2, 6);
    return 0;
}
