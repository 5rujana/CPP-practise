// problem statement: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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

    Node * removeFromEnd(Node * head, int k){
        Node * fast = head;
        Node * slow = head;
        for(int i = 0; i < k; i++){
            fast = fast-> next;
        }

        if(fast == nullptr){
            Node * temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        while( fast->next !=NULL){
            slow = slow ->next;
            fast = fast -> next;
        }
        Node * deleteNode = slow -> next; 
        slow -> next = slow->next->next;
        delete deleteNode;
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
    int k;
    cin>>k;
    Solution sl;
    Node * head = sl.constructLL(ll);
    Node * temp = sl.removeFromEnd(head , k);
    sl.print(temp);
    return 0;
}