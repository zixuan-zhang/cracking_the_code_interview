/*******************************************************************************
 *  @File  : ques1.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月29日 星期四 10时36分00秒
 ******************************************************************************/

/*
 * Question:
 *
 * You are given two sorted arrays, A and B, and A has a large enough buffer at the end 
 * to hold B Write a method to merge B into A in sorted order
 *
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * Solution:
 *
 * 这道题可以从后往前开始比较，把较大的数逐步的放在指针所在位置处
 *
 */

class Solution
{
public:
    void merge_two_sorted_array(vector<int>& largeArray, int largeLen,
            vector<int> smallArray, int smallLen)
    {
        int index = smallLen + largeLen - 1;
        int largeIndex = largeLen - 1;
        int smallIndex = smallLen - 1;
        while (largeIndex >= 0 && smallIndex >=0)
        {
            if (largeArray[largeIndex] > smallArray[smallIndex])
            {
                largeArray[index--] = largeArray[largeIndex--];
            }
            else
            {
                largeArray[index--] = smallArray[smallIndex--];
            }
        }
        if (largeIndex >= 0)
            while (largeIndex >= 0)
                largeArray[index--] = largeArray[largeIndex--];
        else if (smallIndex >= 0) 
            while (smallIndex >= 0)
                largeArray[index--] = smallArray[smallIndex--];
    }
};

int main()
{
    vector<int> largeArray;
    largeArray.resize(10);
    vector<int> smallArray;
    for (int i = 0; i < 10; i += 2)
        largeArray[i/2] = i;
    for (int i = 1; i < 10; i += 2)
        smallArray.push_back(i);

    for (int i = 0; i < 5; ++i)
        cout<<largeArray[i]<<" ";
    cout<<endl;
    for (int i = 0; i < 5; ++i)
        cout<<smallArray[i]<<" ";
    cout<<endl;

    Solution s;
    s.merge_two_sorted_array(largeArray, 5, smallArray, 5);
    for (int i = 0; i < 10; i++)
        cout<<largeArray[i]<<" ";
    cout<<endl;
    return 0;
}
