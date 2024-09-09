// problem statemet: https://leetcode.com/problems/linked-list-cycle-ii/description/
#include<bits\stdc++.h>
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

   Node * startOfLoop(Node * head){
        if(head == NULL) return NULL;
        if(head-> next == NULL) return head;
        Node * fast = head;
        Node * slow = head;
        while(fast != NULL && fast -> next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                fast = head;
                while(fast!= slow){
                    slow = slow->next;
                    fast = fast -> next;
                }
            }
            return slow;
        }

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
    Node * loop = sl.startOfLoop(head);
    sl.print(loop);
    return 0;
}