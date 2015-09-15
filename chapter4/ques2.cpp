/*******************************************************************************
 *  @File  : ques2.cpp
 *  @Author: Zhang Zixuan
 *  @Email : zixuan.zhang.victor@gmail.com
 *  @Blog  : www.noathinker.com
 *  @Date  : 2015年09月07日 星期一 14时58分40秒
 ******************************************************************************/

/*
 * Question:
 *
 * Given a directed graph, design an algorithm to find out whether there is a route between two nodes
 */

#include <iostream>
#include <queue>
#include "graph.h"

using namespace std;

/*
 * Solution:
 *
 * 这道题其实也比较简单了。关键在于怎样构造这个有向图。有向图的构造用矩阵也可以，
 * 用链表也可以。在graph.h文件里，这里，我使用链表有向图类来实现这个功能。
 *
 * 首先，题目中只问这两个node间有没有route，所以有可能是从a到b，也有可能从b到a。
 * 只要满足一个即可。在算法中，使用visited[]来保存已经遍历过的node。
 */
bool is_connected(AdjListDirGraph<int>* graph, int from, int to)
{
    queue<int> vexQue;
    vexQue.push(from);
    int vexSize = graph->get_vex_num();
    bool *visited = new bool[vexSize];
    for (int i = 0; i < vexSize; ++i)
    {
        visited[i] = false;
    }
    visited[from] = true;
    while (!vexQue.empty())
    {
        int headVex = vexQue.front();      
        vexQue.pop();
        int nextVex = -1;
        while (true)
        {
            nextVex = graph->next_adj_vex(headVex, nextVex);
            cout<<headVex<<" next is "<<nextVex;
            if (to == nextVex)
            {
                cout<<" bingo!!!"<<endl;
                return true;
            }
            if (-1 == nextVex)
            {
                cout<<" the ends."<<endl;
                break;
            }
            if (!visited[nextVex])
            {
                cout<<" not visited."<<endl;
                visited[nextVex] = true;
                vexQue.push(nextVex);
            }
        }
    }
    return false;
}

void init(AdjListDirGraph<int>* graph)
{
    if (NULL == graph)
    {
        graph = new AdjListDirGraph<int>(5);
    }
    graph->insert_edge(0, 1);
    graph->insert_edge(0, 3);
    graph->insert_edge(1, 2);
    graph->insert_edge(4, 3);
}
int main()
{
    AdjListDirGraph<int>* graph = new AdjListDirGraph<int>(5);
    init(graph);
    graph->print_graph();

    bool isConnected = is_connected(graph, 0, 2);
    cout<<"The result is "<<isConnected<<endl;

    return 0;
}
