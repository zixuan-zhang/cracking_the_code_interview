/******************************************************************************
 *  @Author: Zhang Zixuan
 *  @Email:  zixuan.zhang.victor@gmail.com
 *  @Blog:   www.noathinker.com
 *  @Date: 
 *****************************************************************************/

/*
 * Question:
 *
 * Given a circular linked list, implement an algorithm which returns node at the beginning of the loop
 * DEFINITION
 * Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an 
 * earlier node, so as to make a loop in the linked list
 * EXAMPLE
 * input: A -> B -> C -> D -> E -> C [the same C as earlier]
 * output: C
 *
 */
#include <iostream>
#include <set>
#include "utils.h"
using namespace std;

/*
 * Solution1:
 *
 * 关于这道题的分析，http://www.hawstein.com/posts/2.5.html分析的很好。
 * 第一种方法是从首节点遍历，保存每个节点的地址。然后，因为链表是存在环的，所以第一个遇到的第二次出现
 * 的则是环的开始。
 *
 */

Node* find_loop_header(Node* header)
{
    if (NULL == header)
        return NULL;
    set<Node*> node_set;
    Node* p = header;
    while (p)
    {
        if (node_set.find(p) == node_set.end())
            node_set.insert(p);
        else
            return p;
        p = p->next();
    }
    return NULL; //没有环
}

/*
 * Solution2:
 *
 * 这道题也是经典题了。除了记录之前的node外还有一种方法可以有效减少内存空间使用。
 * 具体分析请参考： 这里只将其实现。
 *
 */

Node* find_loop_header1(Node* header)
{
    if (NULL == header)
    {
        return NULL;
    }
    Node* fast = header;
    Node* slow = header;

    while (fast)
    {
        slow = slow->next();
        fast = fast->next()->next();
        if (fast == slow)
            break;
    }
    if (NULL == fast)
    {
        return NULL;
    }
    // slow and fast meets, set slow to header, run with equal step
    slow = header;
    while (slow != fast)
    {
        slow = slow->next();
        fast = fast->next();
    }
    return slow; // the header of the loop
}

int main()
{
    List list;
    list.append(new Node(1));
    list.append(new Node(2));
    list.append(new Node(3));
    list.append(new Node(4));
    Node* temp = new Node(5);
    list.append(temp);
    list.append(new Node(6));
    list.append(new Node(7));
    list.append(temp);

    //temp = find_loop_header(list.header()->next());
    temp = find_loop_header1(list.header()->next());
    cout<<temp->value()<<endl;
    return 0;
}
