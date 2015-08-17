/*
Question: Write code to reverse a C-Style String  (C-String means that “abcd” is represented as
	  five characters, including the null character )
*/

#include <iostream>
#include <string.h>
using namespace std;

/*
Solution1:

假定在原字符串地址内进行反转
我的思路是先计算出这个字符串的长度，然后两头的字符位置关系就明确了，然后再进行反转
*/
int reverse(char str[])
{
    if (NULL == str)
    {
        return -1; // means error
    }
    char* pointer = str;
    int char_count = strlen(str);
    char temp;
    for (int i = 0; i <= (char_count - 1) / 2; ++i)
    {
        temp = str[i];
        str[i] = str[char_count - 1 - i];
        str[char_count - 1 - i] = temp;
    }
    return 0;
}

/*
Solution2:

答案的思路是找到手尾字符的地址，然后让两个指针中间相遇
*/
int reverse1(char str[])
{
    if (NULL == str)
    {
        return 0;
    }
    char* start = str;
    char* end = str;
    while (*end)
    {
        end++;
    }
    end--;
    char temp;
    while (start != end)
    {
        temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
    return 0;
}

int main()
{
    char str[5] = "abcd";
    reverse(str);
    cout<<str<<endl;
    char str1[6] = "abcde";
    reverse1(str1);
    cout<<str1<<endl;
    return 0;
}
