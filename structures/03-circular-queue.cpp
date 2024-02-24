#include <iostream>
using namespace std;

#define MAX 5

class circularQueue {
private:
    int arr[MAX];
    int front;
    int rear;
public:
    circularQueue();
    int isEmpty();
    int isFull();
    void enqueue(int item);
    void dequeue();
};

circularQueue::circularQueue() {
    front = -1;
    rear = -1;
}

int circularQueue::isEmpty() {
    if (front == -1) {
        return 1;
    } else {
        return 0;
    }    
}

int circularQueue::isFull() {
    if (front == 0 && rear == MAX - 1) {
        return 1;
    } else if (front == rear + 1) {
        return 1;
    } else {
        return 0;
    }
}

void circularQueue::enqueue(int item) {
    if (isFull()) {
        cout << "Queue is already full." << endl;
    } else {
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = item;
        printf("Added %d to queue.\n", arr[rear]);
    }
}

void circularQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is already empty." << endl;
    } else {
        printf("Removed %d from queue.\n", arr[front]);
        if (front == rear) {
            rear = -1;
            front = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }    
}

int main() {

    circularQueue cq1;
    cq1.dequeue();
    cq1.enqueue(2);
    cq1.enqueue(4);
    cq1.enqueue(6);
    cq1.enqueue(8);
    cq1.enqueue(10);
    cq1.enqueue(12);
    cq1.dequeue();
    cq1.enqueue(12);

    return 0;
}