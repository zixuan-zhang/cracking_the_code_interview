/*******************************************************************************
 *  @File  : ques6.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月25日 星期日 20时28分43秒
 ******************************************************************************/

/*
 * Question:
 *
 * Implement the “paint fill” function that one might see on many image editing
 * programs  That is, given a screen (represented by a 2 dimensional array of
 * Colors), a point, and a new color, fill in the surrounding area until you hit
 * a border of that color ’
 *
 */

#include <iostream>

using namespace std;

/*
 * Solution:
 *
 * 用递归就可以了，很简单
 *
 */

void paint_fill(int** screen, int m, int n, int x, int y, int color)
{
    if (x <0 || n >=m || y < 0 || y >= n)
        return;
    if (screen[x][y] == color)
        return;
    else
    {
        screen[x][y] = color;
        paint_fill(screen, m, n, x-1, y, color);
        paint_fill(screen, m, n, x+1, y, color);
        paint_fill(screen, m, n, x, y-1, color);
        paint_fill(screen, m, n, x, y+1, color);
    }
}

int main()
{
    return 0;
}
