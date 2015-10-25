/*******************************************************************************
 *  @File  : ques5.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月25日 星期日 16时02分41秒
 ******************************************************************************/

/*
 * Question:
 *
 * Implement an algorithm to print all valid (e g , properly opened and closed) combinations of n-pairs of parentheses 
 * EXAMPLE:
 * input: 3 (e g , 3 pairs of parentheses)
 * output: ()()(), ()(()), (())(), ((()))
 *
 */

#include <iostream>
#include <string>

using namespace std;

void construct_string(int deep, int num, string& str)
{
    if (num == deep)
    {
        cout<<str<<endl;
        return ;
    }
    if ("" == str)
    {
        str = "()";
        construct_string(deep+1, num, str);
        return ;
    }
    string temp = "()";
    string temp1 = temp.insert(0, str);
    construct_string(deep+1, num, temp1);
    temp.erase(0, str.length());
    string temp2 = temp.insert(1, str);
    construct_string(deep+1, num, temp2);
    temp.erase(1, str.length());
    string temp3 = temp.insert(2, str);
    if (temp3 != temp1)
        construct_string(deep+1, num, temp3);
}

int main()
{
    string str = "";
    construct_string(0, 3, str);
    return 0;
}
