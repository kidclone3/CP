#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue
{
private:
    vector<int> a;
    int head, size;

public:
    MyCircularQueue(int k)
    {
        a.resize(k);
        head = size = 0;
    }

    bool enQueue(int value)
    {
        if (isFull()) return false;
        a[(head + size) % a.size()] = value;
        size++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty()) return false;
        head = (head + 1) % a.size();
        size--;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return a[head];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return a[(head + size) % a.size()];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == a.size();
    }
};

int main()
{
    //   Your MyCircularQueue object will be instantiated and called as such:
    int k = 3;
    int value = 5;
    MyCircularQueue *obj = new MyCircularQueue(k);
    bool param_1 = obj->enQueue(value);
    bool param_2 = obj->deQueue();
    int param_3 = obj->Front();
    int param_4 = obj->Rear();
    bool param_5 = obj->isEmpty();
    bool param_6 = obj->isFull();
    cout << param_1 << " " << param_2 << " " << param_3 << " " << param_4 << " " << param_5 << " " << param_6;
}