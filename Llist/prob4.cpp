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


Node * reverse(Node* head, int k){
    Node * current = head;
    Node *next = NULL, *prev = NULL;
    int count = 0;

    while(count < k && current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }


    if(next != NULL)
        head->next = reverse(next, k);

    return prev;
}

void push(Node** head, int data){
    Node * temp = new Node();
    temp->data = data;
    temp->next = (*head);
    (*head) = temp;
}

void printList(Node * node){
    while(node != NULL){
        cout << node->data << " ";
        node = node->next;
    }

    cout << endl;
}

int main(){
    Node* head = NULL;
 
    /* Created Linked list
       is 1->2->3->4->5->6->7->8->9 */
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    cout << "Given linked list \n";
    printList(head);
    head = reverse(head, 3);
 
    cout << "\nReversed Linked list \n";
    printList(head);
 
    return (0);}