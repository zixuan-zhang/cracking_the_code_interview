/*******************************************************************************
 *  @File  : ques6.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月29日 星期四 14时46分17秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a matrix in which each row and each column is sorted, write a method to find 
 * an element in it
 *
 */

#include <iostream>

using namespace std;

void search_element(int array[4][4], int row, int colum, int number, int& x, int& y)
{
    if (row <= 0 || colum <= 0)
    {
        x = -1;
        y = -1;
    }
    int i = 0;
    int j = colum - 1;
    while (i < row && j >= 0)
    {
        if (array[i][j] == number)
        {
            x = i;
            y = j;
            return ;
        }
        else if (array[i][j] < number)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    x = -1;
    y = -1;
}

int main()
{
    int array[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int x;
    int y;
    search_element(array, 4, 4, 14, x, y);
    cout<<x<<" "<<y<<endl;
    return 0;
}
