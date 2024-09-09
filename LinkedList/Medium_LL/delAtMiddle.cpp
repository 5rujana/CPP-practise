// problem statement: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
        int data;
        Node * next;
        Node(){
            next = NULL;
            data = 0;
        }

        Node(int data){
            this -> next = NULL;
            this -> data = data;
        }
};

class Solution{
    public:
    Node * constructLL(vector<int> ll){
        Node * head = new Node(ll[0]);
        Node * temp = head;
        for(int i = 1; i< ll.size();i++){
            temp -> next = new Node(ll[i]);
            temp = temp->next;
        }
        return head;
    }

Node * deleteAtMiddle(Node * head){
    Node * fast = head;
    Node * slow = head;
    Node * prevslow = NULL;
    while(fast != NULL && fast -> next != NULL){
        fast = fast->next->next;
        prevslow = slow;
        slow = slow->next;
    }
    prevslow -> next = slow -> next;
    return head;
} 

void print(Node * head){
            Node * temp = head;
            while(temp !=NULL){
                cout<< temp -> data;
                temp = temp-> next;
            }
    }
};

int main(){
    int size;
    cin>> size;
    vector<int> ll(size);
    for(int i = 0; i< size;i++){
        cin>> ll[i];
    }
    Solution sl;
    Node * head = sl.constructLL(ll);
    Node * temp = sl.deleteAtMiddle(head);
    sl.print(temp);
    return 0;
}