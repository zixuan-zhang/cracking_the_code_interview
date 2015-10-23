/*******************************************************************************
 *  @File  : ques4.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月23日 星期五 19时36分31秒
 ******************************************************************************/

/*
 * Question:
 *
 * Write a method to compute all permutations of a string 
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * Solution:
 *
 */

void perm(string str, bool flag[], int deep, vector<char>per)
{
    int len = str.length();
    if (deep == len)
    {
        for (int i = 0; i < per.size(); ++i)
            cout<<per[i]<<" ";
        cout<<endl;
    }
    for (int i = 0; i < len; ++i)
    {
        if (not flag[i])
        {
            flag[i] = true;
            per.push_back(str[i]);
            perm(str, flag, deep+1, per);
            per.pop_back();
            flag[i] = false;
        }
    }
}

/*
 * Solution:
 *
 * 用插值法
 *
 */
void perm1(string str, int deep, string& per)
{
    if (deep == str.size())
    {
        cout<<per<<endl;
        return ;
    }
    for (int i = 0; i <= per.size(); ++i)
    {
        per.insert(i, &str[deep], 1);
        perm1(str, deep+1, per);
        per.erase(i, 1);
    }
}

int main()
{
    string str = "abc";
    //bool flag[3] = {0};
    //vector<char> per;
    //perm(str, flag, 0, per);

    string per = "";
    perm1(str, 0, per);
    return 0;

}
