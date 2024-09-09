#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node() {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
public:
    Node* constructDLL(vector<int> arr) {
        if (arr.empty()) return NULL;

        Node* head = new Node(arr[0]);
        Node* temp = head;
        for (int i = 1; i < arr.size(); i++) {
            Node* newNode = new Node(arr[i]);
            newNode->prev = temp;
            temp->next = newNode;
            temp = temp->next;
        }
        return head;
    }

    Node* addNode(Node* head, int value) {
        if (head == NULL) {
            head = new Node(value);
            return head;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        Node* newNode = new Node(value);
        temp->next = newNode;
        newNode->prev = temp;
        return head;
    }

    Node* addAtK(Node* head, int k, int value) {
        Node* newNode = new Node(value);
        if (k == 1) {
            newNode->next = head;
            if (head != NULL) {
                head->prev = newNode;
            }
            return newNode;
        }

        Node* temp = head;
        while (temp != NULL && --k > 1) {
            temp = temp->next;
        }

        if (temp != NULL) {
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
        return head;
    }

    Node* deleteNode(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            delete head;
            return NULL;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        delete temp;
        return head;
    }

    Node* deleteAtK(Node* head, int k) {
        if (head == NULL) return NULL;
        if (k == 1) {
            Node* temp = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            delete temp;
            return head;
        }

        Node* temp = head;
        while (temp != NULL && --k > 1) {
            temp = temp->next;
        }

        if (temp != NULL && temp->next != NULL) {
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            if (nodeToDelete->next != NULL) {
                nodeToDelete->next->prev = temp;
            }
            delete nodeToDelete;
        }
        return head;
    }

    int read(Node* head) {
        if (head == NULL) {
            return -1;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        return temp->data;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = sol.constructDLL(arr);

    head = sol.addNode(head, 6);
    head = sol.addAtK(head, 3, 10);
    head = sol.deleteNode(head);
}
