/******************************************************************************
 *  @Author: Zhang Zixuan
 *  @Email:  zixuan.zhang.victor@gmail.com
 *  @Blog:   www.noathinker.com
 *  @Date: 
 *****************************************************************************/

/*
 * Question:
 *
 * Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
 * column is set to 0 
 *
 */

#include <iostream>
#include <set>

using namespace std;

/*
 * Solution1:
 *
 * 这道题的意思是说如果在这个矩阵中，某一个元素的值为0，那么这个元素的行和列上的值都需要
 * 置为0
 *
 * 最简单粗暴的解法就是从上到下、从左到右遍历看看有没有值为0的元素。当然要注意需要记录下
 * 当前需要置为0的行和列。时间复杂度比较高为O(M*N*max(M,N))。
 *
 */
void solution(int matrix[4][3], int Row, int Column)
{
    set<int> row_set;
    set<int> column_set;
    for (int i = 0; i < Row; ++i)
    {
        for (int j = 0; j < Column; ++j)
        {
            if (matrix[i][j] == 0)
            {
                row_set.insert(i);
                column_set.insert(j);
            }
        }
    }

    // set to 0
    for (set<int>::iterator it = row_set.begin(); it != row_set.end(); ++it)
    {
        for( int column_index = 0; column_index < Column; ++column_index)
        {
            matrix[*it][column_index] = 0;
        }
    }
    for (set<int>::iterator it = column_set.begin(); it != column_set.end(); ++it)
    {
        for ( int row_index = 0; row_index < Row; ++row_index)
        {
            matrix[row_index][*it] = 0;
        }
    }
}

/*
 * Solution2:
 *
 * 书中的答案与我的方法类似，不过他使用了两个数组来保存需要置为0的行和列的索引。我是用
 * set保存的，在空间复杂度上我的较优；他的在时间复杂度上比我的稍好，我的时间复杂度多的
 * 地方在于插入set时候的比较。代码略。
 */

void display_matrix(int matrix[4][3])
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int matrix[4][3] = {
        {1, 0, 3},
        {2, 4, 4},
        {3, 0, 1},
        {0, 4, 2}
    };
    display_matrix(matrix);
    solution(matrix, 4, 3);
    display_matrix(matrix);
    return 0;
} 
