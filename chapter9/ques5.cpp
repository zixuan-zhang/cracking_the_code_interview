/*******************************************************************************
 *  @File  : ques5.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月29日 星期四 14时34分42秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a sorted array of strings which is interspersed with empty strings,
 * write a method to find the location of a given string 
 * Example:  find  “ball”  in  [“at”,  “”,  “”,  “”,  “ball”,  “”,  “”,  “car”,
 *      “”,  “”,  “dad”,  “”,  “”]  will  return  4
 * Example: find “ballcar” in [“at”, “”, “”, “”, “”, “ball”, “car”, “”, “”,
 *      “dad”, “”, “”] will return -1
 *
 */

#include <iostream>

using namespace std;

int search(string* s, int low, int high, string x)
{
    if ("" == x)
        return -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int t = mid;
        while ("" == s[t] && t <= high)
            ++t;
        if (t > high)
            high = mid - 1;
        else
        {
            if (s[t] == x)
                return t;
            else if (s[t] < x)
                low = t + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    string s[13] = {
        "at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""
    };
    cout<<search(s, 0, 12, "ball")<<endl;
    return 0;
}
