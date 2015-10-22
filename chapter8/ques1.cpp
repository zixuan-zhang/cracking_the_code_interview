/*******************************************************************************
 *  @File  : fibonacci.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月22日 星期四 11时15分11秒
 ******************************************************************************/

/*
 * Question:
 *
 * Write a method to generate the nth Fibonacci number 
 *
 */

#include <iostream>

using namespace std;

int fibonacci(int n)
{
    if (0 == n || 1 == n)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    cout<<fibonacci(10)<<endl;
    return 0;
}
