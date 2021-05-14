#include<bits/stdc++.h>
using namespace std;

struct node {
    int val = -1;
    node *next = NULL; 
};
class MyLinkedList {
private:
    node *head, *tail;
public:
    
    /** Initialize your data structure here. */
    MyLinkedList() {
        // head = NULL;
        // tail = NULL;
        head = new node();
        tail = new node();
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        node *now = head;
        for (int i = 0; i < index; ++i) {
            if (now->next == NULL) return -1;
            else {
                now = now->next;
            }
        }
        return now->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node *tmp = new node();
        tmp->val = val;
        tmp->next = head;
        head = tmp;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node *tmp = new node();
        tmp->val = val;
        // tmp->next = tail;
        tail->next = tmp;
        tail = tmp;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        node *now = head;
        for (int i = 0; i < index; ++i) {
            if (now->next == NULL && (index - i > 2)){
                return;
            }
            now=now->next;
        }
        if (head->val == -1) {
            head->val = val;
            return;
        }
        node *node_add;
        node_add->val = val;
        if (now = NULL) {
            tail = node_add;
        }
        if (now->next == NULL) {
            tail->next = node_add;
            tail = node_add;
        }
        else {
            node *tmp = now->next;
            now->next = node_add;
            node_add->next=tmp;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        node *now = head;
        for (int i = 0; i < index; ++i) {
            if (now->next == NULL) return;
            now=now->next;
        }
        // now->next = now->next->next;
        now = now->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


int main() {
    MyLinkedList a;
    // a.addAtIndex(0, 1);
    // a.addAtIndex(1, 1);
    // a.addAtIndex(2, 1);
    // a.addAtIndex(3, 1);
    a.addAtTail(1);
    a.addAtTail(1);
    a.addAtTail(1);
    a.addAtTail(1);
    a.addAtTail(1);
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        cout << a.get(i) << " ";
    }
     
}