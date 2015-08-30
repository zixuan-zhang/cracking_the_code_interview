/******************************************************************************
 *  @Author: Zhang Zixuan
 *  @Email:  zixuan.zhang.victor@gmail.com
 *  @Blog:   www.noathinker.com
 *  @Date: 
 *****************************************************************************/

/*
 * Question:
 *
 * Given an image represented by an NxN matrix, where each pixel in the image is 4
 * bytes, write a method to rotate the image by 90 degrees  Can you do this in place?
 */

#include <iostream>

using namespace std;

/*
 * Solution:
 *
 * 问题中说每个像素是4字节，那么我们可以将问题抽象为一个N*N的int矩阵，也就是二维int型
 * 数组。而操作就是将这个矩阵旋转90度，我们可以假设为逆时针旋转。
 * 如果需要顺时针的话则需要改变开始的位置为右下角即(N-1, N-1)，并且坐标之间的关系需要
 * 倒过来
 *
 * 这道题需要注意的是有三层循环：
 * 1. 环的循环，一共 N / 2次
 * 2. 在每个环内，每个边假设由M个像素块，则有M-1次循环
 * 3. 每个像素块需要rotate 90度，一共需要roate 4次
 *
 * 下一个需要注意的是坐标之间的转换关系，这个也很重要，根据观察
 */

void inner_rotate(int image[6][6], int N, int loop_count, int start_x, int start_y)
{
    if (loop_count * 2 == N)
    {
        return; //end
    }
    int uniq_pixel_count = N - 1 - start_x - start_y;
    for (int i = 0; i < uniq_pixel_count; ++i)
    {
        int x = start_x + i;
        int y = start_y;
        int new_x, new_y;
        int first_pixel = image[x][y];
        for (int j = 0; j < 3; j++)
        {
            new_x = y; //新坐标x的计算方法
            new_y = N - 1 - x; //新坐标y的计算方法
            image[x][y] = image[new_x][new_y];
            x = new_x;
            y = new_y;
        }
        new_x = y;
        new_y = N - 1 - x;
        image[x][y] = first_pixel;
    }
    inner_rotate(image, N, loop_count+1, start_x+1, start_y+1);
}

int rotate_matrix(int image[6][6], int N)
{
    if (N % 2 == 1)
    {
        return -1; // means illegal
    }
    inner_rotate(image, N, 0, 0, 0);
}

void display_image(int image[6][6], int N)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    int image[6][6] = {
        {0, 1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10, 11},
        {12, 13, 14, 15, 16, 17},
        {18, 19, 20, 21, 22, 23},
        {24, 25, 26, 27, 28, 29},
        {30, 31, 32, 33, 34, 35},
    };
    display_image(image, 6);
    rotate_matrix(image, 6);
    display_image(image, 6);
    return 0;
}
