#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void addNodeToHead(Node *&, Node *&, int);
void deleteNode(Node *&, Node *&, int);
void insertNode(Node *&);
void deleteLinkedList(Node *&);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        addNodeToHead(head, newVal, tmp_val);
    }
    output(head);
    
    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    deleteNode(head, current, entry);
    output(head);

    insertNode(head);
    output(head);
    
    deleteLinkedList(head);
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void addNodeToHead(Node * &hd, Node * &nv, int val)
{
    // adds node at head
        if (!hd) { // if this is the first node, it's the new head
            hd = nv;
            nv->next = nullptr;
            nv->value = val;
        }
        else { // its a second or subsequent node; place at the head
            nv->next = hd;
            nv->value = val;
            hd = nv;
        }
}

void deleteNode(Node * &hd, Node * &ct, int ey)
{
    // traverse that many times and delete that node
    ct = hd;
    Node *prev = hd;
    for (int i = 0; i < (ey-1); i++)
        if (i == 0)
            ct = ct->next;
        else {
            ct = ct->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (ct) {  // checks for current to be valid before deleting the node
        prev->next = ct->next;
        delete ct;
        ct = nullptr;
    }
}

void insertNode(Node * &hd)
{
    // insert a node
    Node * current = hd;
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    int entry;
    Node *prev = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = hd;
    prev = hd;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
}

void deleteLinkedList(Node * &hd)
{
    Node * current = hd;
    while (current) {
        hd = current->next;
        delete current;
        current = hd;
    }
    hd = nullptr;
}