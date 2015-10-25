/*******************************************************************************
 *  @File  : 022_generate_parentheses.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月25日 星期日 16时43分02秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    void _generate(int left, int right, string& str, vector<string>& result)
    {
        if (left < 0 || right < left)
            return;
        if (left == 0 && right == 0)
        {
            result.push_back(str);
        }
        else
        {
            if (left > 0)
            {
                str += "(";
                _generate(left-1, right, str, result);
                str.erase(str.length()-1, 1);
            }
            if (right > 0)
            {
                str += ")";
                _generate(left, right-1, str, result);
                str.erase(str.length()-1, 1);
            }
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        if (0 == n)
            return result;
        string str = "";
        _generate(n, n, str, result);
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> result = s.generateParenthesis(4);
    cout<<result.size()<<endl;
    return 0;
}
