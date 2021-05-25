//template for Llist
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<iterator>
#include<string.h>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>



using namespace std;

int min3(int a, int b, int c){
    return min(a, min(b, c));
}

int max3(int a, int b, int c){
    return max(a, max(b, c));
}

bool comparator(int a, int b){
    return a > b;
}

class Node{
    public:
        int data;
        Node * next;
};

void reversePair(Node ** head){
    Node * temp = (*head);

    while(temp != NULL && temp->next != NULL){
        swap(temp->data, temp->next->data);
        temp = temp->next->next;
    }
}

void push(Node ** head, int new_data){
    Node * temp = new Node();
    temp->data = new_data;
    temp->next = (*head);
    (*head) = temp;
}

void printList(Node * head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


int main(){
    Node * head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    printList(head);
    reversePair(&head);
    printList(head);


    return 0;
}