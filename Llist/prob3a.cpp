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


void push(Node** head, int data){
    Node * temp = new Node();
    temp->data = data;
    temp->next = (*head);
    (*head) = temp;
}

void rotate(Node** head, int k){
    if(k == 0)
        return;

    Node * current = (*head);
    int count=1;

    while(count < k && current != NULL){
        current = current->next;
        count++;
    }

    if(current == NULL)
        return;

    Node * kthNode = current;

    while(current->next != NULL){
        current = current->next;
    }
    current->next = (*head);
    (*head) = kthNode->next;
    kthNode->next = NULL;
}


void print(Node* node){
    while(node != NULL){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}


int main(){
    Node * head = NULL;
    push(&head, 60);
    push(&head, 50);
    push(&head, 40);
    push(&head, 30);
    push(&head, 20);
    push(&head, 10);

    print(head);
    rotate(&head, 4);

    print(head);

    return 0;
}