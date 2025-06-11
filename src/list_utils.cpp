#include "list_utils.h"
#include "list.h"
using namespace std;

int length(const LinkedList& list) {
    int count = 0;
    LinkedList::Node* current = list.getHead();

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

int sum(const LinkedList& list) {
    int total = 0;
    LinkedList::Node* current = list.getHead();

    while (current != nullptr) {
        total += current->data;
        current = current->next;
    }

    return total;
}

bool contains(const LinkedList& list, int k) {
    LinkedList::Node* current = list.getHead();

    while (current != nullptr) {
        if (current->data == k) {
            return true;
        }
        current = current->next;
    }

    return false;
}

void reverse(LinkedList& list) {
    LinkedList::Node* previous = nullptr;
    LinkedList::Node* current = list.getHead();
    LinkedList::Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    list.setHead(previous);
}

int nthFromEnd(const LinkedList& list, int n) {
    if (n < 0) {
        throw runtime_error("Invalid position");
    }

    LinkedList::Node* ahead = list.getHead();
    LinkedList::Node* behind = list.getHead();

    for (int i = 0; i < n; ++i) {
        if (ahead == nullptr) {
            throw runtime_error("Invalid position");
        }
        ahead = ahead->next;
    }

    if (ahead == nullptr) {
        throw runtime_error("Invalid position");
    }

    while (ahead->next != nullptr) {
        ahead = ahead->next;
        behind = behind->next;
    }

    return behind->data;
}
