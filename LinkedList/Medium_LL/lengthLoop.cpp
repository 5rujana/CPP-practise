// problem statement: https://www.geeksforgeeks.org/problems/find-length-of-loop/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-length-of-loop

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node() {
            next = NULL;
            data = 0;
        }

        Node(int data) {
            this->next = NULL;
            this->data = data;
        }
};

class Solution {
    public:
    Node* constructLL(vector<int> ll) {
        Node* head = new Node(ll[0]);
        Node* temp = head;
        for (int i = 1; i < ll.size(); i++) {
            temp->next = new Node(ll[i]);
            temp = temp->next;
        }
        return head;
    }

    int detectLoopLength(Node* head) {
        Node* fast = head;
        Node* slow = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow) {
                int loopLength = 1;
                Node* temp = slow;
                while (temp->next != slow) {
                    temp = temp->next;
                    loopLength++;
                }
                return loopLength; 
            }
        }
        return 0; 
    }
};

int main() {
    int size;
    cin >> size;
    vector<int> ll(size);
    for (int i = 0; i < size; i++) {
        cin >> ll[i];
    }

    Solution sl;
    Node* head = sl.constructLL(ll);

    int loopLength = sl.detectLoopLength(head);
    cout << loopLength << endl;

    return 0;
}
  
  