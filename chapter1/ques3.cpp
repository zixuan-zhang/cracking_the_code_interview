/*
Question:

Design an algorithm and write code to remove the duplicate characters in a string
without using any additional buffer  NOTE: One or two additional variables are fine 
An extra copy of the array is not 
FOLLOW UP
Write the test cases for this method 
*/

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

/*
Test Case:

    a
    aa
    aba
    abcde
    abcda
    abcba
    abcdecd
*/

/*
Solution1:

从第二个字符开始向前查找此字符有没有出现过，如果有出现过，则从此字符的后一个字符开始
逐渐覆盖前一个字符，直到字符结束。时间复杂度为O(n^2)
*/

int duplicated_removal(char *str)
{
    if (NULL == str)
    {
        return 0;
    }
    char* step = str + 1;
    while (*step)
    {
        char* start = str;
        bool is_duplicated = false;
        while( start != step)
        {
            if (*start == *step)
            {
                is_duplicated = true;
                break;
            }
            start++;
        }
        if (is_duplicated)
        {
            char* backward = step;
            do
            {
                *(backward) = *(backward + 1);
                backward++;
            }while(*backward);
        }
        else
            step++;
    }
}

/*
Solution2:

上一个solution的方案是，如果遇到duplicated的字符，那么后面的字符将逐步往前移动。
书中的解答的方案是，有一个tail的位置，存放下一个没有出现过的字符。时间复杂度与
上一个解法一样，但是减少了移动的时间消耗，因此效率更好一些。
*/

int duplicated_removal1(char *str)
{
    if (NULL == str)
    {
        return 0;
    }
    int len = strlen(str);
    if (1 == len)
        return 0;
    int tail = 1;
    int i, j;
    for (i = 1; i < len; ++i)
    {
        for(j = 0; j < i; j++)
        {
            if (str[j] == str[i])
                break;
        }
        if (i == j)
        {
            str[tail] = str[i];
            tail++;
        }
    }    
    str[tail] = '\0';
    return 0;
}

/*
Solution3:

如果字符串为ASCII字符，并且可以使用固定长度的数组的话，可以用数组记录下该字符有没
有出现过，如果没出现过，则放在下一个字符位置处。这样的话时间复杂度为O(n)
可以使用位来代表字符，进一步减少空间。这里使用位运算进行处理，使用长度为8的int即可。
*/

int duplicated_removal2(char *str)
{
    if (NULL == str)
        return 0;
    int len = strlen(str);
    if (1 == len)
        return 0;
    int duplicated[8];
    int tail = 0;
    for (int i = 0; i < len; ++i)
    {
        int c = str[i] - 'a';
        int index_out = c % 32;
        int index_in = c / 32;
        if (!(duplicated[index_out] & (1 << index_in)))
        {
            str[tail++] = str[i];
            duplicated[index_out] |= (1 << index_in);
        }
    }
    str[tail] = '\0';
    return 0;
}

int main()
{
    string str;
    cin>>str;
    const char* c_str = str.c_str();
    char* str1 = new char[strlen(c_str) + 1];
    strcpy(str1, c_str);
    duplicated_removal2(str1);
    cout<<str1<<endl;
    return 0;
}
