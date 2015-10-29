/*******************************************************************************
 *  @File  : ques7.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年10月29日 星期四 17时20分58秒
 ******************************************************************************/

/*
 * Question:
 *
 * A circus is designing a tower routine consisting of people standing atop one
 * another’s shoulders For practical and aesthetic reasons, each person must be
 * both shorter 
 * and lighter than the person below him or her Given the heights and weights of
 * each person in the circus, write a method to compute the largest possible
 * number of people in such a tower
 * EXAMPLE:
 * Input (ht, wt): (65, 100) (70, 150) (56, 90) (75, 190) (60, 95) (68, 110)
 * Output:  The  longest  tower  is  length  6  and  includes  from  top  to  bottom:
 * (56,  90) (60,95) (65,100) (68,110) (70,150) (75,190
 *
 */
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * Solution:
 *
 * 我的理解是，这道题的核心就是求最大递减子串长
 * 过程是：先按照height进行排序，然后求weight的最大递减子串长；然后再按照weight进行
 * 排序，然后求height的最大递减子串长
 *
 * 我不确定上面求出来的两个结果是否一样，所以再取两个结果的最大值即可
 *
 */

struct Person
{
    int height;
    int weight;
};

bool height_cmp(Person p1, Person p2)
{
    return p2.height < p1.height;
}

bool weight_cmp(Person p1, Person p2)
{
    return p1.weight < p2.weight;
}

int max_person(Person *persons, int number)
{
    sort(persons, persons+number, height_cmp);
    int* maxLen = new int[number];
    int result = 1;
    for (int i = 0; i < number; ++i)
        maxLen[i] = 1;
    for (int i = 1; i < number; ++i)
    {
        if (persons[i].weight < persons[i-1].weight)
            maxLen[i] = maxLen[i-1] + 1;
        else
        {
            for (int j = 0; j < i; j++)
            {
                if (persons[i].weight < persons[j].weight &&
                        maxLen[i] < maxLen[j] + 1)
                    maxLen[i] = maxLen[j] + 1;
            }
        }
        if (result < maxLen[i])
            result = maxLen[i];
    }
    return result;
}

int main()
{
    int number = 6;
    Person* persons = new Person[number];
    int heights[6] = {65, 70, 56, 75, 60, 68};
    int weights[6] = {100, 150, 90, 190, 95, 110};
    for (int i = 0; i < 6; ++i)
    {
        persons[i].height = heights[i];
        persons[i].weight = weights[i];
    }
    int result = max_person(persons, 6);
    cout<<result<<endl;
    return 0;
}
