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
    struct Node* next;
};


void printNthFromLast(struct Node* head, int n){
    int len = 0, i;
    struct Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }

    if(len < n)
        return;
    temp = head;

    for(int i=1; i<len - n + 1; i++)
        temp = temp->next;

    cout << temp->data;

    return;
}


void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main(){
    struct Node* head = NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);
 
    printNthFromLast(head, 4);
    return 0;
}