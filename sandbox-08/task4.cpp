#include <cstdint>
#include <iostream>

struct Node {
    int value;
    Node* next;
};

void push_back(Node*& head, Node*& tail, int value) {
    Node* new_node = new Node{value, nullptr};
    if (head == nullptr) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    push_back(head, tail, 1);
    push_back(head, tail, 2);
    push_back(head, tail, 3);

    int length = 0;
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        std::cout << curr->value;
        if (curr->next != nullptr) {
            std::cout << ' ';
        }
        length++;
    }
    std::cout << '\n';
    std::cout << length << '\n';

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;

    return 0;
}
