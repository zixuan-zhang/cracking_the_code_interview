
class Node
{
private:
    int _value;
    Node* _next;

public:
    Node(int value);
    Node();
    virtual ~Node();
    void set_value(int value);
    void set_next(Node* node);
    int value();
    Node* next();
};

// 具有单独头部链表
class List
{
private:
    Node* _header;
    Node* _tail;

public:
    List();
    virtual ~List();
    void append(Node *node);
    Node* header();
    void show();
};
