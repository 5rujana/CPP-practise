// problem statement : https://leetcode.com/problems/sort-list/description/
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
    Node * mid(Node * head){
        Node * fast = head;
        Node * slow = head;
        while(fast != NULL && fast -> next != NULL){
            fast = fast->next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    Node * merge( Node * list1 , Node * list2){
        Node * dummy = new Node(0);
        Node * tail = dummy;
        while( list1 && list2){
            if(list1-> data < list2 -> data){
                tail -> next = list1;
                list1 = list1-> next;
            }else{
                tail -> next = list2;
                list2 = list2 -> next;
            }
            tail = tail -> next;
        }
        tail-> next = list1 ? list2 : list2;
        
        Node * mergedHead = dummy -> next;
        delete dummy;
        return mergedHead;  
    }

    Node * mergeSort(Node * head){
        if(head == NULL || head -> next == NULL) return head;

        Node * middle = mid(head);
        Node * left = head;
        Node * right = middle->next;
        middle -> next = NULL;
        left = mergeSort(left);
        right = mergeSort(right);
        Node * merged = merge(left,right);
        return merged;

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
    Node * temp = sl.mergeSort(head);
    sl.print(temp);
    return 0;
}

