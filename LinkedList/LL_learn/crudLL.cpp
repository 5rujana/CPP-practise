#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node * next;

        Node(){
            data = 0;
            next = NULL;
        }

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class Solution{
    public:
        Node * constructLL(vector<int> arr){
            if(arr.empty()){
                return NULL;
            }
            Node * head = new Node(arr[0]);
            Node * temp = head;
            for(int i = 1; i<arr.size();i++){
                temp-> next = new Node(arr[i]);
                temp = temp -> next;
            }
            return head;
        }

        Node * addNode(Node * head , int value){
            if(head == NULL){
                head = new Node(value);
                return head;
            }
            Node * temp = head;
            while(temp != NULL){
                temp = temp->next;
            }
            temp = new Node(value);
            return head;
        }

        Node * addAtK(Node * head , int k , int value){
            if(k == 1){
                Node *newNode = new Node(value);
                newNode->next = head;
                return newNode;
            }
            Node * temp = head;
            while(--k>1 && temp != NULL ){
                temp = temp-> next;
            }
            if (temp != NULL) {
            Node *newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
            }
            return head;
        }

        Node * deleteNode(Node * head){
            if(head->next == NULL){
                delete head;
                return NULL;
            }
            if(head == NULL){
                return NULL;
            }

            Node * temp = head;
            while(temp-> next != NULL){
                temp = temp->next;
            }
            delete temp;
            temp = NULL;
            return head;
        }

        Node * deleteatK(Node * head , int k ){
            if (head == NULL) {
                return NULL;
            }

            if(k == 1){
                Node *temp = head;
                head = head->next;
                delete temp;
                return head;
            }
            Node * temp = head;
            while(temp!= NULL && --k> 1){
                temp = temp-> next;
            }
            if (temp != NULL && temp->next != NULL) {
                Node *toDelete = temp->next;
                temp->next = toDelete->next;
                delete toDelete;
            }
            return head;
        }

        int readNode(Node * head){
            if (head == NULL) {
                return -1;  
            }
            Node * temp = head;
            while(temp != NULL){
                temp = temp->next;
            }
            return temp-> data;
        }
};

int main(){
    Solution sol;
    vector<int> arr = {1, 2, 3, 4};
    Node *head = sol.constructLL(arr);

    head = sol.addNode(head, 5);  // Adding 5 at the end

    head = sol.addAtK(head, 3, 10);  // Adding 10 at position 3

    head = sol.deleteNode(head);  // Delete the last node

    head = sol.deleteatK(head, 2);  // Delete the node at position 2

    cout << "Last node's data: " << sol.readNode(head) << endl; // Reading the last node's data
}