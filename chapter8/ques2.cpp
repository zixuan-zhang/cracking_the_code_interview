/*******************************************************************************
 *  @File  : ques2.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月22日 星期四 11时20分12秒
 ******************************************************************************/

/*
 * Question:
 *
 * Imagine a robot sitting on the upper left hand corner of an NxN grid  The
 * robot can only move in two directions: right and down  How many possible
 * paths are there for the robot?
 *
 * FOLLOW UP
 * Imagine certain squares are “off limits”, such that the robot can not step
 * on them Design an algorithm to get all possible paths for the robot 
 *
 */

#include <iostream>
#include <vector>

using namespace std;

const int N = 5;

void robot_move(int i, int j, vector<int>& row, vector<int>& col)
{
    row.push_back(i);
    col.push_back(j);
    if (N - 1 == i && N - 1 == j)
    {
        //print
        for (int i = 0; i < row.size(); ++i)
        {
            cout<<row[i]<<","<<col[i]<<" ";
        }
        cout<<endl;
        return ;
    }
    if (i + 1 < N)
    {
        robot_move(i+1, j, row, col);
        row.pop_back();
        col.pop_back();
    }
    if (j + 1 < N)
    {
        robot_move(i, j+1, row, col);
        row.pop_back();
        col.pop_back();
    }
}

int main()
{
    vector<int> row;
    vector<int> col;
    robot_move(0, 0, row, col);
    return 0;
}
