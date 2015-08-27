/*
Question: Implement an algorithm to determine if a string has all unique characters  What if you
	  can not use additional data structures?
*/

#include <iostream>
#include <string>

using namespace std;

/*
 * Solution1:
 *
 * 最简单直观的方法是从第二个字符开始，查找前面有没有重复的字符，如果有重复的字符，则不是unique
 * 这种方法时间复杂度为O(n^2)
 */

bool is_unique_regular(string str)
{
    for (int i = 1; i < str.length(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (str[i] == str[j])
            {
                return false;
            }
        }
    }
    return true;
}

/*
 * Solution2:
 *
 * 题目中说不能用多余的数据结构，意思是不能使用长度不定的数据。固定长度的数据肯定是可以的。如果
 * 这样的话，我们可以使用长度为256的bool变量来存储每个字符是否出现过，如果出现过则not unique。
 *
 * 另外，我们还可以通过使用位来保存每个字符是否出现过，如果字符串是ASCII，则需要256位。那使用长
 * 度为8的int型数组则可以每个位来保存字符是否出现过。这里，我采用这种方法。
 */
bool is_unique_bit(string str)
{
    int c_array[8] = {0};
    for (int i = 0; i < str.length(); ++i)
    {
        char c = str[i];
        int index_out = int(c) / 32;
        int index_in  = int(c) % 32;
        if (c_array[index_out] & (1 << index_in))
        {
            return false;
        }
        c_array[index_out] |= (1 << index_in);
    }
    return true;
}

int main()
{
    string str1 = "abcde";
    string str2 = "abzaz";
    string str3 = "a!1'b";
    string str4 = "a!1b!";
    cout<<is_unique_regular(str1)<<" "<<is_unique_bit(str1)<<endl;
    cout<<is_unique_regular(str2)<<" "<<is_unique_bit(str2)<<endl;
    cout<<is_unique_regular(str3)<<" "<<is_unique_bit(str3)<<endl;
    cout<<is_unique_regular(str4)<<" "<<is_unique_bit(str4)<<endl;

    return 0;
}
