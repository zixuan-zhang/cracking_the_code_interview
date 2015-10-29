/*******************************************************************************
 *  @File  : ques2.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月29日 星期四 11时48分19秒
 ******************************************************************************/

/*
 * Question:
 *
 * Write a method to sort an array of strings so that all the anagrams are next to each 
 * other
 *
 */

#include <iostream>
#include <algorithm>

using namespace std;

/*
 * Solution:
 *
 * 这道题我个人认为没有说明白。他只是说明了把anagrams放在一起，那如果不是anagram
 * 应该怎样判定大小呢。
 * 所以姑且是认为把字符串内字符按字典排序，然后再比较大小这种方法吧。
 *
 */

bool cmp(string s1, string s2)
{
    sort(&s1[0], &s1[0] + s1.length());
    sort(&s2[0], &s2[0] + s2.length());
    return s1 < s2;
}

int main()
{
    string str[] = {
        "axyz", "abc", "yzax", "bac", "zyxa", "fg", "gf"
    };
    sort(str, str + 7, cmp);
    for (int i = 0; i < 7; ++i)
        cout<<str[i]<<" ";
    cout<<endl;
    return 0;
}
