//Find middle element
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
    struct Node* next;
};

void printMiddle(struct Node* head){
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;
    
    if(head != NULL){
        while(fast_ptr != NULL && fast_ptr->next != NULL){
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }

        printf("Middle element is %d\n", slow_ptr->data);
    }
}

void push(struct Node** head, int data){
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

void printList(struct Node* ptr){
    while(ptr != NULL){
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}


int main(){
    struct Node* head = NULL;
    for(int i=5; i>0; i--){
        push(&head, i);
        printList(head);
        printMiddle(head);
    }

    return 0;
}