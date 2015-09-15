/*************************************************************************
	> File Name: graph.h
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2015年09月08日 星期二 15时20分52秒
 ************************************************************************/


#include <climits>
#include <list>
#include <vector>
#include <iostream>

using namespace std;
#define DEFAULT_SIZE 20

template<class ElemType>
class AdjListGraphVexNode
{
protected:
    ElemType data;
    list<int> adjList;

public:
    AdjListGraphVexNode(ElemType e, list<int> adj);
    AdjListGraphVexNode();
    ~AdjListGraphVexNode();

    ElemType get_data() const;
    void set_data(ElemType e);

    list<int> get_adj_list() const;
    void set_adj_list(list<int> l);

    void insert_adj(int v);
};

template<class ElemType>
class AdjListDirGraph
{
protected:
    int numVex, numEdge;
    vector<AdjListGraphVexNode<ElemType> > vexTable;

public:
    AdjListDirGraph(ElemType es[], int vertexNum = DEFAULT_SIZE);
    AdjListDirGraph(int vertexNum = DEFAULT_SIZE);
    ~AdjListDirGraph();
    
    int get_vex_num() const;
    int get_edge_num() const;
    int first_adj_vex(int v) const;
    int next_adj_vex(int v1, int v2) const;
    void insert_edge(int v1, int v2);
    //void delete_edge(int v1, int v2);

    void print_graph() const;

};

// class: AdjListGraphVexNode implementation
template<class ElemType>
AdjListGraphVexNode<ElemType>::AdjListGraphVexNode()
{

}

template<class ElemType>
AdjListGraphVexNode<ElemType>::AdjListGraphVexNode(ElemType e, list<int> adj)
{
    data = e;
    adjList = adj;
}

template<class ElemType>
AdjListGraphVexNode<ElemType>::~AdjListGraphVexNode()
{

}

template<class ElemType>
ElemType AdjListGraphVexNode<ElemType>::get_data() const
{
    return data;
}

template<class ElemType>
void AdjListGraphVexNode<ElemType>::set_data(ElemType e)
{
    data = e;
}

template<class ElemType>
list<int> AdjListGraphVexNode<ElemType>::get_adj_list() const
{
    return adjList;
}

template<class ElemType>
void AdjListGraphVexNode<ElemType>::set_adj_list(list<int> l)
{
    adjList = l;
}

template<class ElemType>
void AdjListGraphVexNode<ElemType>::insert_adj(int v)
{
    adjList.push_back(v);
}


// class: AdjListDirGraph 
template<class ElemType>
AdjListDirGraph<ElemType>::AdjListDirGraph(ElemType es[], int vertexNum)
{
    numVex = vertexNum;
    numEdge = 0;
    vexTable.resize(numVex);
    for (int i = 0; i < numVex; ++i)
    {
        vexTable[i].set_data(es[i]);
    }
}

template<class ElemType>
AdjListDirGraph<ElemType>::AdjListDirGraph(int vertexNum)
{
    numVex = vertexNum;
    numEdge = 0;
    vexTable.resize(numVex);
}

template<class ElemType>
AdjListDirGraph<ElemType>::~AdjListDirGraph()
{

}

template<class ElemType>
int AdjListDirGraph<ElemType>::get_vex_num() const
{
    return numVex;
}

template<class ElemType>
int AdjListDirGraph<ElemType>::get_edge_num() const
{
    return numEdge;
}

template<class ElemType>
int AdjListDirGraph<ElemType>::first_adj_vex(int v) const
{
    if (vexTable[v].get_adj_list().empty())
        return -1;
    else
        return vexTable[v].get_adj_list().front();
}

template<class ElemType>
int AdjListDirGraph<ElemType>::next_adj_vex(int v1, int v2) const
{
    if (-1 == v2)
        return first_adj_vex(v1);
    list<int> adj_list = vexTable[v1].get_adj_list();
    int adj_vex = -1;
    for( list<int>::iterator it = adj_list.begin(); it != adj_list.end(); ++it)
    {
        if (*it == v2)
        {
            ++it;
            if (it != adj_list.end() )
                adj_vex = *(it);
            break;
        }
    }
    return adj_vex;
}

template<class ElemType>
void AdjListDirGraph<ElemType>::insert_edge(int v1, int v2)
{
    vexTable[v1].insert_adj(v2);
}

template<class ElemType>
void AdjListDirGraph<ElemType>::print_graph() const
{
    for ( int i = 0; i < numVex; ++i)
    {
        list<int> adj_list = vexTable[i].get_adj_list();
        cout<<"vertex "<<i<<": ";
        for (list<int>::iterator it = adj_list.begin(); it != adj_list.end(); ++it)
        {
            cout<<*it<<" ";
        }

        cout<<endl;
    }
}
