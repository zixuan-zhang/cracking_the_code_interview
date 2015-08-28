#include "utils.h"

#include <cstddef>
#include <iostream>

using namespace std;

Node::Node()
{
    this->_next = NULL;
}

Node::Node(int value)
{
    this->_value = value;
    this->_next = NULL;
}

Node::~Node()
{
}

void Node::set_value(int value)
{
    this->_value = value;
}

void Node::set_next(Node* node)
{
    this->_next = node;
}

int Node::value()
{
    return this->_value;
}

Node* Node::next()
{
    return this->_next;
}

List::List()
{
    _header = new Node();
    _tail = _header;
}

List::~List()
{
}

void List::append(Node *node)
{
    this->_tail->set_next(node);
    this->_tail = node;
}

Node* List::header()
{
    return this->_header;
}

void List::show()
{
    Node* p = this->header()->next();
    while (p)
    {
        cout<<p->value()<<" ";
        p = p->next();
    }
    cout<<endl;
} 
