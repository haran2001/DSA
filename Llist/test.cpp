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

struct Node{
    int data;
    struct Node * next;
};

void removeLoop(struct Node*, struct Node*);

int detectAndRemoveLoop(struct Node* list){
    struct Node *slowp = list;
    struct Node *fastp = list;

    while(slowp && fastp && fastp->next){
        slowp = slowp->next;
        fastp = fastp->next->next;

        if(slowp == fastp){
            removeLoop(slowp, list);
            return 1;
        }
    }

    return 0;
}

void removeLoop(struct Node* loop_node, struct Node* head){
    struct Node* ptr1;
    struct Node* ptr2;

    ptr1 = head;
    while(1){
        ptr2 = loop_node;
        while(ptr2->next != loop_node && ptr2->next != ptr1)
            ptr2 = ptr2->next;
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

struct Node* newNode(int key){
     struct Node* temp = new Node();
    temp->data = key;
    temp->next = NULL;
    return temp;
}


int main(){
     struct Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    detectAndRemoveLoop(head);
 
    cout << "Linked List after removing loop" << endl;
 
    printList(head);
 
    return 0;
}