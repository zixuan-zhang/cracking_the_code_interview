/*******************************************************************************
 *  @File  : ques2.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月01日 星期四 19时19分31秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a (decimal - e g  3 72) number that is passed in as a string, print the
 * binary representation  If the number can not be represented accurately in 
 * binary, print “ERROR”
 *
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string convert_binary(string value)
{
    int position = value.find('.', 0);
    int integer = atoi(value.substr(0, position).c_str());
    double decimal = atof(value.substr(position, value.length() - position).c_str());
    string strInteger = "";
    string strDecimal = "";
    while (integer > 0)
    {
        if (integer & 1)
            strInteger += "1";
        else
            strInteger += "0";
        integer >>= 1;
    }

    while (decimal > 0)
    {
        if (strDecimal.length() > 32)
            return "ERROR";
        decimal *= 2;
        if (decimal >= 1)
        {
            strDecimal += "1";
            decimal -= 1;
        }
        else
            strDecimal += "0";
    }
    return strInteger + "." + strDecimal;
}

int main()
{
    string value = "19.25";
    cout<<convert_binary(value)<<endl;
    return 0;
}
