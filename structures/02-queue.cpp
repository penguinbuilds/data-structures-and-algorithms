#include <iostream>
using namespace std;

#define MAX 10

class queue {
private:
    int arr[MAX];
    int front;
    int rear;
public:
    queue();
    int isEmpty();
    int isFull();
    void enqueue(int item);
    void dequeue();
};

queue::queue() {
    front = -1;
    rear = -1;
}

int queue::isEmpty() {
    if (front == -1) {
        return 1;
    } else {
        return 0;
    }
}

int queue::isFull() {
    if (front == 0 && rear == MAX - 1) {
        return 1;
    } else {
        return 0;
    }
}

void queue::enqueue(int item) {
    if (isFull()) {
        cout << "More elements cannot be added as queue is full." << endl;
    } else {
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        arr[rear] = item;
        printf("Added %d to queue.\n", arr[rear]);
    }
}

void queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is already empty." << endl;
    } else {
        printf("Removed %d from queue.\n", arr[front]);
        if (front >= rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
}

int main() {

    queue q1;
    q1.dequeue();
    q1.enqueue(1);
    q1.dequeue();

    return 0;
}