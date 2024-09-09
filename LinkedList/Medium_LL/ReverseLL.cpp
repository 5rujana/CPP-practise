// problem statement: https://leetcode.com/problems/reverse-linked-list/description/
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

    Node * reverse(Node * head){
        if(head == NULL) return NULL;
        if( head -> next == NULL) return head;
        Node * temp = head;
        Node * prev = NULL;
        while(temp != NULL){
            Node * temp_next = temp->next;
            temp -> next = prev;
            prev = temp;
            temp = temp_next;
        } 
        return prev;
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
    sl.print(head);
    return 0;
}