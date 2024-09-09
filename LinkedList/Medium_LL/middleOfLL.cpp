// problem statement: https://leetcode.com/problems/middle-of-the-linked-list/description/

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

    int middleNode(Node * head){
        if(head == NULL) return -1;
        Node * fast =head ;
        Node * slow = head;
        while(fast != NULL && fast->next !=NULL ){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->data;
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
    int middle = sl.middleNode(head);
    cout << middle << endl;
    return 0;
}