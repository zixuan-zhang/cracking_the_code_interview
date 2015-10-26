/*******************************************************************************
 *  @File  : ques7.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月26日 星期一 13时01分57秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and
 * pennies (1 cent), write code to calculate the number of ways of representing n cents 
 *
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * Solution:
 *
 * 我觉得这道题的解法还是挺多的
 *
 */

class Solution
{
public:
    int cents[4];
    int centCatCnt;

    void _comb(int deep, int n, vector<vector<int> >& result, vector<int>& centsCnt)
    {
        if (deep == centCatCnt)
        {
            if (0 == n)
                result.push_back(centsCnt);
            return ;
        }
        //if (deep == centCatCnt -1)
        //{
            //centsCnt.push_back(n);
            //_comb(deep+1, 0, result, centsCnt);
            //centsCnt.pop_back();
            //return ;
        //}
        for (int i = 0; i * cents[deep] <= n; ++i)
        {
            centsCnt.push_back(i);
            _comb(deep+1, n - i * cents[deep], result, centsCnt);
            centsCnt.pop_back();
        }
    }

    vector<vector<int> > combination(int n)
    {
        vector<vector<int> > result;
        vector<int> centsCnt;
        _comb(0, n, result, centsCnt);
        return result;
    }

    Solution()
    {
        cents[0] = 25;
        cents[1] = 10;
        cents[2] = 5;
        cents[3] = 1;
        centCatCnt = 4;
    }
};

int main()
{
    Solution s;
    vector<vector<int> >result = s.combination(25);
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
