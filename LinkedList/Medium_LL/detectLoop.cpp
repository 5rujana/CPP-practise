// problem statement: https://leetcode.com/problems/linked-list-cycle/description/
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

    bool detectLoop(Node * head){
        Node * fast = head;
        Node * slow = head;

        while(fast !=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
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
    bool loop = sl.detectLoop(head);
    if(loop) cout<< "true" << endl;
    else cout<< " false" << endl;
    return 0;
}