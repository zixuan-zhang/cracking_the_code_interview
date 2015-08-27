/*
 * Question:
 *
 * Assume you have a method isSubstring which checks if one word is a substring of
 * another  Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using
 * only one call to isSubstring (i e , “waterbottle” is a rotation of “erbottlewat”) 
 */

#include <iostream>

using namespace std;

/*
 * Solution:
 *
 * rotate的意思是轮转。首先判断两个字符串长度是否相等，如果不等则肯定不是rotation。
 * 如果长度相等，则将其中一个字符串的后面append这个字符串，然后再调用isSubstring即可。
 *
 * 书中提供的答案检查了是否为空，我觉得没有这个必要。
 */

bool is_rotation(string str1, string str2)
{
    if (str1.length() != str2.length())
    {
        return false;
    }

    string double_str1 = str1 + str1;
    return isSubstring(double_str1, str2);
}
