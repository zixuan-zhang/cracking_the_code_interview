/*******************************************************************************
 *  @File  : ques3.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月29日 星期四 13时38分21秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given  a  sorted  array  of  n  integers  that  has  been  rotated  an
 * unknown  number  of times, give an O(log n) algorithm that finds an element
 * in the array You may assume that the array was originally sorted in increasing
 * order
 * EXAMPLE:
 * Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14)
 * Output: 8 (the index of 5 in the array)
 *
 */

#include <iostream>

using namespace std;

/*
 * Solution:
 *
 * array originally sorted in increasing order
 *
 */
int rotated_array_search(int* array, int left, int right, int number)
{
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (array[mid] == number)
            return mid;
        if (array[mid] >= array[left])
        {
            //左面全部小于mid，右面有大有小
            if (array[mid] < number)
                left = mid + 1;
            else
            {
                if (array[left] <= number)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        else
        {
            //左面有大有小，右面全部大于mid
            if (array[mid] > number)
                right = mid - 1;
            else
            {
                if (array[left] <= number)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
    }
}

int main()
{
    int array[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    for (int i = 0; i < 12; ++i)
    {
        int index = rotated_array_search(array, 0, 11, array[i]);
        cout<<index<<endl;
    }

    return 0;
}
