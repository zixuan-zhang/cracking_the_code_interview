/*
 * Question:
 *
 * Implement an algorithm to find the nth to last element of a singly linked list
 */
#include <iostream>
#include <cstddef>
#include "utils.h"
using namespace std;

/*
 * Solution1:
 *
 * 这道题是要找出在链表中离尾节点距离为n的节点。
 *
 * 其中一个思路是先遍历一遍，计算这个链表的长度，假设为m，那么离尾节点为n的节点就
 * 是离首节点为m - n - 1的节点。这里说的距离，不是节点索引相减，而是间隔数
 * 然后再从前往后便利一次找到该节点。
 *
 * 节点从前往后： 1, 2, 3, 4, 5, 6, ......, m-1, m
 * 节点从后往前： m, m-1, ..., m-n, ......, 3, 2, 1
 *
 * 拿个例子来说明：
 * 1, 2, 3, 4, 5, 6, 7
 * 这个链表共7个节点，离尾节点距离尾2的是5， 5离首节点距离尾4
 */

Node* find_nth_node_to_tail(Node* header, int n)
{
    if (NULL == header)
    {
        return NULL; // error
    }
    Node* p = header;
    int node_count = 0;
    while (p)
    {
        node_count++;
        p = p->next();
    }

    if (node_count <= n)
    {
        return NULL; // not enough nodes, parameter illegal
    }

    int node_to_header = node_count - 1 - n;
    
    p = header;
    int node_to_header_temp = 0;
    while (p)
    {
        if (node_to_header_temp == node_to_header)
        {
            return p;
        }
        p = p->next();
        node_to_header_temp++;
    }
}

/*
 * Solution2:
 *
 * 方法一是遍历两次链表，这里再提供一种方法遍历一次链表即可
 * 思路就是在遍历的时候有两个指针，分别叫做cur, pre。cur节点正常遍历。不过在遍历
 * 的时候开始计数，记到n的时候pre指针再跟上。这样的话pre和cur指针的距离尾n，当cur
 * 指针指向尾节点的时候，pre指针指向的是距离尾节点为n的节点上。
 *
 */
Node* find_nth_node_to_tail1(Node* header, int n)
{
    Node* cur = header;
    Node* pre = header;
    int count = 0;

    while (cur)
    {
        if (count > n)
        {
            pre = pre->next();
        }
        cur = cur->next();
        count++;
    }
    if (count <= n)
    {
        return NULL;
    }
    else
        return pre;
}

int main()
{
    List list;
    list.append(new Node(1));
    list.append(new Node(2));
    list.append(new Node(3));
    list.append(new Node(4));
    list.append(new Node(5));
    list.append(new Node(6));
    list.append(new Node(7));

    list.show();
    Node* p = find_nth_node_to_tail(list.header()->next(), 2);
    //Node* p = find_nth_node_to_tail1(list.header()->next(), 2);
    if (p)
        cout<<p->value()<<endl;
    return 0;
}
