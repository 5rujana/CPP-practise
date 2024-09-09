// problem statement: https://leetcode.com/problems/odd-even-linked-list/description/
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

    Node * seggregate(Node * head){
        if(head == NULL || head -> next == NULL) return head;
        Node * odd = head;
        Node * even = head -> next;
        Node * temp = even;
        while(even != NULL && even -> next != NULL){
            odd -> next = odd -> next -> next;
            even -> next = even-> next->next;
            odd = odd -> next;
            even = even-> next;
            
        }
        odd-> next = temp;
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
    Node * temp = sl.seggregate(head);
    sl.print(temp);
    return 0;
}