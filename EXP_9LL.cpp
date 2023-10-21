#include <iostream>

// Define a structure for a singly linked list node
struct Node {
    int data;
    Node* next;
};

// Define a structure for a doubly linked list node
struct DoubleNode {
    int data;
    DoubleNode* prev;
    DoubleNode* next;
};

class SingleLinkedList {
private:
    Node* head;

public:
    SingleLinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the beginning of the singly linked list
    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Function to delete a node from the singly linked list
    void deleteNode(int value) {
        if (head == nullptr) {
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    // Function to display the singly linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

class DoubleLinkedList {
private:
    DoubleNode* head;

public:
    DoubleLinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the beginning of the doubly linked list
    void insertAtBeginning(int value) {
        DoubleNode* newNode = new DoubleNode;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }

        head = newNode;
    }

    // Function to delete a node from the doubly linked list
    void deleteNode(int value) {
        DoubleNode* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }

                delete current;
                return;
            }
            current = current->next;
        }
    }

    // Function to display the doubly linked list
    void display() {
        DoubleNode* current = head;
        while (current != nullptr) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    SingleLinkedList sll;
    DoubleLinkedList dll;

    // Single Linked List
    sll.insertAtBeginning(10);
    sll.insertAtBeginning(20);
    sll.insertAtBeginning(30);
    sll.insertAtBeginning(40);
    sll.insertAtBeginning(50);

    std::cout << "Singly Linked List: ";
    sll.display();

    sll.deleteNode(30);
    std::cout << "After deleting 30: ";
    sll.display();

    // Double Linked List
    dll.insertAtBeginning(10);
    dll.insertAtBeginning(20);
    dll.insertAtBeginning(30);
    dll.insertAtBeginning(40);
    dll.insertAtBeginning(50);

    std::cout << "Doubly Linked List: ";
    dll.display();

    dll.deleteNode(30);
    std::cout << "After deleting 30: ";
    dll.display();

    return 0;
