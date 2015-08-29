/*
 * Question:
 *
 * You have two numbers represented by a linked list, where each node contains a single digit.
 * The digits are stored in reverse order, such that the 1’s digit is at the head of
 * the list  Write a function that adds the two numbers and returns the sum as a linked
 * list 
 * EXAMPLE
 * Input: (3 -> 1 -> 5) + (5 -> 9 -> 2)
 * Output: 8 -> 0 -> 8
 */

#include <iostream>
#include "utils.h"

using namespace std;

/*
 * Solution:
 *
 * 这道题的意思就是说，有两个链表，分别代表两个数。将这两个数相加，得到一个新的链表。
 * 然后链表中数字的位数顺序需要注意一下。
 *
 */

List* new_list(Node* header2)
{
    List* newList = new List();
    Node* p = header2;
    while (p)
    {
        newList->append(new Node(p->value()));
        p = p->next();
    }
    return newList;
}

List* list_addition(Node* header1, Node* header2)
{
    if (NULL == header1 && NULL == header2)
        return NULL;
    if (NULL == header1)
        return new_list(header2);
    if (NULL == header2)
        return new_list(header1);

    Node* p1 = header1;
    Node* p2 = header2;

    List* newList = new List();
    int remainder = 0; //余数
    int number;
    while (p1 && p2)
    {
        number = (p1->value() + p2->value() + remainder) % 10;
        newList->append(new Node(number));
        remainder = (p1->value() + p2->value() + remainder) / 10;
        p1 = p1->next();
        p2 = p2->next();
    }

    //如果list1位数更高
    while (p1)
    {
        number = (p1->value() + remainder) % 10;
        newList->append(new Node(number));
        remainder = (p1->value() + remainder) / 10;
        p1 = p1->next();
    }
    //如果list2位数更高
    while (p2)
    {
        number = (p2->value() + remainder) % 10;
        newList->append(new Node(number));
        remainder = (p1->value() + remainder) / 10;
        p2 = p2->next();
    }

    if (remainder)
        newList->append(new Node(1));

    return newList;
}

void test1()
{
    List list1, list2;
    list1.append(new Node(3));
    list1.append(new Node(1));
    list1.append(new Node(5));

    list2.append(new Node(5));
    list2.append(new Node(9));
    list2.append(new Node(2));

    List* newList = list_addition(list1.header()->next(), list2.header()->next());
    newList->show();
}

void test2()
{
    List list1, list2;
    list1.append(new Node(1));
    list1.append(new Node(9));
    list1.append(new Node(9));

    list2.append(new Node(9));

    List* newList = list_addition(list1.header()->next(), list2.header()->next());
    newList->show();
}

void test3()
{
    List list1, list2;
    list1.append(new Node(9));
    list1.append(new Node(9));
    list1.append(new Node(9));

    list2.append(new Node(9));
    list2.append(new Node(9));

    List* newList = list_addition(list1.header()->next(), list2.header()->next());
    newList->show();
}
int main()
{
    test1();
    test2();
    test3();
    return 0;
}
