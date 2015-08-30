/******************************************************************************
 *  @Author: Zhang Zixuan
 *  @Email:  zixuan.zhang.victor@gmail.com
 *  @Blog:   www.noathinker.com
 *  @Date: 
 *****************************************************************************/

/*
 * Quetion:
 *
 * Write a method to decide if two strings are anagrams or not.
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

/*
 * Solution1:
 *
 * anagram的意思是变位词。意思是构成两个单词的字母相同，但是顺序不同。
 * 可以将这两个字符串按照字典顺序排序，然后比较排序候的两个字符串是否相同。
 * 
 */

bool is_string_anagram(string str1, string str2)
{
    if (str1.length() != str2.length())
    {
        return false;
    }
    vector<char> str_vec1;
    vector<char> str_vec2;
    for (int i = 0; i < str1.length(); ++i)
    {
        str_vec1.push_back(str1[i]);
    }
    for (int i = 0; i < str2.length(); ++i)
    {
        str_vec2.push_back(str2[i]);
    }

    sort(str_vec1.begin(), str_vec1.end());
    sort(str_vec2.begin(), str_vec2.end());

    for (int i = 0; i < str_vec1.size(); ++i)
    {
        if (str_vec1[i] != str_vec2[i])
        {
            return false;
        }
    }

    return true;
}

/*
 * Solution2:
 *
 * 第二种方法假设字符串为ASCII，这样可以使用256长度的数组来保存每个字符出
 * 现的次数，然后比较两个数组是否相同
 * 这种方法时间复杂度是O(n)
 */

bool is_string_anagram1(string str1, string str2)
{
    int str_cnt1[256] = {0};
    int str_cnt2[256] = {0};
    for (int i = 0; i < str1.length(); ++i)
    {
        str_cnt1[str1[i]] += 1;
    }
    for (int i = 0; i < str2.length(); ++i)
    {
        str_cnt2[str2[i]] += 1;
    }
    for (int i = 0; i < 256; ++i)
    {
        if (str_cnt1[i] != str_cnt2[i])
        {
            return false;
        }
    }
    return true;
}

/*
 * Solution3:
 *
 * 第三种方法是第二种方法的变种，可以减少一定的空间，参考：
 * http://www.hawstein.com/posts/1.4.html
 * 思想是，第一个字符串的时候统计字符时字符出现次数增加，第二个字符串时出
 * 现的字符减少，最后一个循环看是否全部都为0.
 * 代码略
 */

int main()
{
    string str1, str2;
    cin>>str1>>str2;
    bool is_anagram = is_string_anagram1(str1, str2);
    cout<<"is anagram? "<<is_anagram<<endl;
    return 0;
}
