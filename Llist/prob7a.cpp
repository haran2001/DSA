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
        Node* next;
};


void push(Node** head, int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = (*head);
    (*head) = temp;
}

void removeLoop(Node* loop_node, Node* head){
    Node* ptr1 = head;
    Node* ptr2;

    while(1){
        ptr2 = loop_node;
        while(ptr2->next != ptr1 && ptr2->next != loop_node){
            ptr2 = ptr2->next;
        }
        if(ptr2->next == ptr1)
            break;
        ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
}



void printList(struct Node* node){
    while(node != NULL){
        cout << node->data << " ";
        node = node->next;
    }
}
int detectLoop(Node* head){
    Node* fastp = head;
    Node* slowp = head;

    while(fastp && slowp && fastp->next){
        if(fastp == slowp){
            removeLoop(slowp, head);
            return 1;
        }

        fastp = fastp->next->next;
        slowp = slowp->next;
    }

    return 0;
}

int main(){

    struct Node* head = NULL;
    push(&head, 50);
    push(&head, 15);
    push(&head, 4);
    push(&head, 10);
 
    head->next->next->next->next = head->next->next;
 
    detectLoop(head);
 
    cout << "Linked List after removing loop" << endl;
 
    printList(head);
 
    return 0;    
}