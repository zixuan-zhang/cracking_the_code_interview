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
#include "utils.h"
using namespace std;


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

    temp = find_loop_header1(list.header()->next());
    cout<<temp->value()<<endl;
    return 0;
}
