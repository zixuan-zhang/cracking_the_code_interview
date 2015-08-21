/*
 * Quetion:
 *
 * Write a method to replace all spaces in a string with ‘%20’ 
 */

#include <iostream>
#include <string>

using namespace std;


/*
 * Solution1:
 *
 * 根据题目，将' '变成'%20'肯定不是在原地址空间进行的变化，所以申请一段新
 * 的内存空间是必须的。那申请多少空间呢？如果使用C++的String不用申请，直接
 * 加就行;如果使用C语言，则可以先统计有多少空格，然后再计算所需要的空间
 */
string* replace_space(string from)
{
    string* to = new string;
    for (int i = 0; i <= from.length(); ++i)
    {
        string temp;
        if (from[i] == ' ')
        {
            temp = "%20";
        }
        else
        {
            temp = from[i];
        }
        *to += temp;
    }
    return to;
}

/*
 * Solution2:
 * 原书中给的解法是按照在原地址空间做的替换，这就要求原地址空间是足够的
 * 在替换的时候必须从后往前替换，如果从前往后替换会替换掉原字符串
 */

int replace_space1(char from[], int length)
{
    if (NULL == from)
        return -1; //illegal
    int spaceCount = 0;
    for (int i = 0; i < length; ++i)
    {
        if (from[i] == ' ')
            spaceCount += 1;
    }
    int newLength = length + 2 * spaceCount;
    int index = newLength - 1;
    for (int i = length - 1; i >= 0; --i)
    {
        if (from[i] == ' ')
        {
            from[index--] = '0';
            from[index--] = '2';
            from[index--] = '%';
        }
        else
            from[index--] = from[i];
    }
    from[newLength] = '\0';
    return 0;
}

void solution1_test()
{
    string from = "ab ba ";
    string* to = replace_space(from);
    cout<<*to<<endl;
}

void solution2_test()
{
    char str[100] = "ab cb a ";
    int length = 8;
    replace_space1(str, 8);
    cout<<str<<endl;
}

int main()
{
    solution1_test();
    solution2_test();
    return 0;
}
