#include <iostream>
#include <memory>
using namespace std;

struct Node {
    int data;
    shared_ptr<Node> next;
    shared_ptr<Node> prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoubleyLinkedList {
public:
    DoubleyLinkedList(int value) {
        head = make_shared<Node>(value);
    }

    void append(int value) {
        auto newNode = make_shared<Node>(value);
        if (head == nullptr) {
            return;
        }

        auto temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
        return;
    }

    // remove from the last element, similair to pop in stack
    void pop() {
        if (head == nullptr) {
            return;
        }

        if (head->next == nullptr) {
            return;
        }

        auto temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        return;
    }

    void print() {
        auto temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

private:
    shared_ptr<Node> head;
};

int main() {
    DoubleyLinkedList list(10);

    list.append(20);
    list.print();
    list.append(30);
    list.print();
    list.append(40);
    list.print();
    
    list.pop();
    list.print();

    return 0;
}