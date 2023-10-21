//STACK USING ARRAY
#include <iostream>
using namespace std;
class Stack {
private:
    int* arr;
    int capacity;
    int top;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (isFull()) {
           cout << "Stack overflow. Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow. Cannot pop from an empty stack." << endl;
            return -1; // You can return a specific value to indicate an error.
        }
        return arr[top--];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
bool isFull() {
        return top == capacity - 1;
    }
    // Function to get the top element of the stack
    int topele() {
        if (isEmpty()) {
            cout << "Stack is empty." << std::endl;
            return -1; // You can return a specific value to indicate an error.
        }
        return arr[top];
    }
};

int main() {
    Stack stack(5); // Create a stack with a capacity of 5

    stack.push(10);
    stack.push(20);
    stack.push(30);

   cout << "Top element: " << stack.topele() << endl;

    cout << "Popped element: " << stack.pop() << endl;

    cout << "Top element: " << stack.topele() << endl;

    return 0;
}
//STACK USING LL
#include <iostream>
using namespace std;
// Define a structure for a singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    Stack() {
        top = nullptr;
    }

    // Function to push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << std::endl;
            return -1; // You can return a specific value to indicate an error.
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to get the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << std::endl;
            return -1; // You can return a specific value to indicate an error.
        }
        return top->data;
    }

    // Function to display the stack
    void display() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << std::endl;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.peek() << std::endl;

    cout << "Popped element: " << stack.pop() << std::endl;

    cout << "Top element: " << stack.peek() << std::endl;

   cout << "Stack contents: ";
    stack.display();

    return 0;
}

//QUEUE USING ARRAY
#include <iostream>
using namespace std;

// Define a structure for a singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Function to add an element to the rear of the queue (enqueue)
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to remove an element from the front of the queue (dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << std::endl;
            return -1; // You can return a specific value to indicate an error.
        }
        int dequeuedValue = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        return dequeuedValue;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to display the queue
    void display() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << std::endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

   cout << "Dequeued element: " << queue.dequeue() << std::endl;

    queue.enqueue(40);

   cout << "Queue contents: ";
    queue.display();

    return 0;
}
//QUEUE USING LL
#include <iostream>
using namespace std;
class Queue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int size;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    // Function to add an element to the rear of the queue (enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << std::endl;
            return;
        }
        rear = (rear + 1) % capacity; // Circular queue
        arr[rear] = value;
        size++;
    }

    // Function to remove an element from the front of the queue (dequeue)
    int dequeue() {
        if (isEmpty()) {
           cout << "Queue is empty. Cannot dequeue." << std::endl;
            return -1; // You can return a specific value to indicate an error.
        }
        int dequeuedValue = arr[front];
        front = (front + 1) % capacity; // Circular queue
        size--;
        return dequeuedValue;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Function to display the queue
    void display() {
        int index = front;
        for (int i = 0; i < size; i++) {
            cout << arr[index] << " ";
            index = (index + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    Queue queue(5); // Create a queue with a capacity of 5

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Dequeued element: " << queue.dequeue() << std::endl;

    queue.enqueue(4);

    std::cout << "Queue contents: ";
    queue.display();

    return 0;
}
