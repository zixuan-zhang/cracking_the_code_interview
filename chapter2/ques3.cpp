/******************************************************************************
 *  @Author: Zhang Zixuan
 *  @Email:  zixuan.zhang.victor@gmail.com
 *  @Blog:   www.noathinker.com
 *  @Date: 
 *****************************************************************************/

/*
 * Question:
 *
 * Implement an algorithm to delete a node in the middle of a single linked list, given
 * only access to that node 
 * EXAMPLE
 * Input: the node ‘c’ from the linked list a->b->c->d->e
 * Result: nothing is returned, but the new linked list looks like a->b->d->e
 *
 */

#include <iostream>
#include <cstddef>
#include "utils.h"

using namespace std;

/*
 * Solution
 *
 * 这道题的意思是，给出一个链表中中间的一个节点，要求删除这个节点。
 * 根据题目要求，这个节点不是头也不是尾，是中间的。因此只需要找到此节点的下一个节点，然后
 * 把下一个节点的值复制到这个节点上，然后删除掉下一个节点即可。
 *
 */
bool delete_node(Node* node)
{
    if (NULL == node || NULL == node->next())
        return false;
    node->set_value(node->next()->value());
    node->set_next(node->next()->next());
    return true;
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
    Node* temp1 = new Node(7);
    list.append(temp1);

    list.show();
    delete_node(temp);
    list.show();
    delete_node(temp1);
    list.show();

    return 0;
}
