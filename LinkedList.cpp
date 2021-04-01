#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList
{
    // head = Dau cua linked list
    // tail = Duoi cua linked list (duoi)
    Node *head, *tail;
    LinkedList() {
        head = NULL;
        tail = NULL;
    }
    void add(int n) {
        Node* tmp = new Node;
        tmp->data = n;
        tmp->next = NULL;
        if (head==NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tail;
            tail = tail->next;
        }
    }


};


int main() {

}