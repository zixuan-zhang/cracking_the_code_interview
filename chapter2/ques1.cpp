/******************************************************************************
 *  @Author: Zhang Zixuan
 *  @Email:  zixuan.zhang.victor@gmail.com
 *  @Blog:   www.noathinker.com
 *  @Date: 
 *****************************************************************************/

/*
 * Question:
 *
 * Write code to remove duplicates from an unsorted linked list 
 * FOLLOW UP
 * How would you solve this problem if a temporary buffer is not allowed?
 */

#include "utils.h"
#include <cstddef>
#include <set>

using namespace std;

/*
 * Solution1:
 *
 * 这道题的意思就是删掉链表中重复出现的值，使每个元素唯一。
 * 在第一章中遇到了一道判断字符串中字符是否唯一的题。而这道题从unsorted可以
 * 看出Node的元素是值，首先假设不能使用额外的内存。
 *
 * 因此，这道题的解法就是先判断值是否出现过，如果出现过则删掉这个元素。这道
 * 题也就是考察链表中节点的删除操作。
 *
 */

void remove_duplication(Node* header)
{
    if (header == NULL)
        return;
    Node* pre = header;
    Node* cur = header->next();

    while (cur)
    {
        Node* runner = header;
        while (runner != cur)
        {
            if (runner->value() == cur->value())
            {
                pre->set_next(cur->next());
                break;
            }
            runner = runner->next();
        }
        if (runner == cur)
            pre = cur;
        cur = cur->next();
    }
}

/*
 * Solution2:
 *
 * 如果可以使用额外长度的变量。那么可以用一个set来保存已经出现过的值。然后如
 * 果再一次出现则删掉这个node。
 *
 */

void remove_duplication1(Node* header)
{
    if (header == NULL)
    {
        return ;
    }
    Node* pre = header;
    Node* cur = header->next();

    set<int> s;
    s.insert(header->value());

    while (cur)
    {
        if (s.find(cur->value()) != s.end())
        {
            pre->set_next(cur->next());
        }
        else
        {
            pre = cur;
            s.insert(cur->value());
        }
        cur = cur->next();
    }
}

int main()
{
    List list;
    list.append(new Node(3));
    list.append(new Node(3));
    list.append(new Node(4));
    list.append(new Node(3));
    list.append(new Node(5));
    list.append(new Node(6));
    list.append(new Node(6));

    list.show();

    remove_duplication1(list.header()->next());
    //remove_duplication(list.header()->next());
    list.show();
    return 0;
}
