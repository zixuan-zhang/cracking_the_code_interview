/*******************************************************************************
 *  @File  : utils.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年09月30日 星期三 16时44分31秒
 ******************************************************************************/
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
