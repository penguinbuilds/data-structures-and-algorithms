#include <iostream> 
using namespace std;

#define MAX 100

class stack
{
private:
    int top;
    int arr[MAX];
public:
    stack();
    int isEmpty();
    int isFull();
    void push(int item);
    void pop();
    void printStack();
};

stack::stack() {
    top = -1;
}

int stack::isEmpty() {
    if (top == -1)
    {
        return 1;
    } else
    {
        return 0;
    }    
}

int stack::isFull() {
    if (top == MAX - 1)
    {
        return 1;
    } else
    {
        return 0;
    }    
}

void stack:: push(int item) {
    if (isFull())
    {
        cout << "Stack is already full!" << endl;
    } else
    {
        top++;
        arr[top] = item;
        cout << "Element pushed to stack." << endl;
    }  
}

void stack::pop() {
    if (isEmpty())
    {
        cout << "Stack is already empty!" << endl;
    } else
    {
        cout << "Element popped: " << arr[top] << endl;
        top--;
    }  
}

void stack::printStack() {
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
    } else
    {
        for (int i = top; i > -1; i--)
        {
            cout << arr[i] << endl;
        }
        
    }  
}


int main() {

    stack s;
    cout << s.isEmpty() << endl;
    s.push(1024);
    s.push(73);
    s.pop();
    s.push(512);
    s.push(256);
    s.push(128);
    s.push(64);
    s.push(32);
    s.printStack();

    return 0;
}