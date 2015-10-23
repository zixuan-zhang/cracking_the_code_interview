/*******************************************************************************
 *  @File  : ques3.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月23日 星期五 19时16分22秒
 ******************************************************************************/

/*
 * Question:
 *
 * Write a method that returns all subsets of a set 
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/*
 * Solution:
 *
 * 就以字符串为例好了
 *
 * "abc" 的subset包括： "", "a", "b", "c", "ab", "ac", "bc", "abc"
 *
 * 以递归的方式
 *
 */

void subset(string str, vector<char>& subStr, int deep)
{
    if (deep == str.size())
    {
        for (int i = 0; i < subStr.size(); ++i)
            cout<<subStr[i]<<" ";
        cout<<endl;
        return ;
    }

    //不append这个字符
    subset(str, subStr, deep+1);

    //append这个字符
    subStr.push_back(str[deep]);
    subset(str, subStr, deep+1);
    subStr.pop_back();
}

/*
 * Solution2:
 *
 * 其实这个问题可以分解为每个字符都有两种情况，选中和不被选中。因此总的时间
 * 复杂度是O(2^n)
 *
 * 这样的话其实可以由 range(2^n) 这种方法给每个字符的情况遍历一遍
 *
 */
void subset1(string str)
{
    int len = str.length();
    for (int i = 0; i < (int)pow(2, len); ++i)
    {
        vector<char> subset;
        for (int shift = 0; shift < len; ++shift)
        {
            if (((i >> shift)&1) == 1)
                subset.push_back(str[shift]);
        }
        for (int i = 0; i < subset.size(); ++i)
            cout<<subset[i]<<" ";
        cout<<endl;
    }
}

int main()
{
    string str = "abc";
    vector<char> subStr;
    subset(str, subStr, 0);
    subset1(str);

    return 0;
}
