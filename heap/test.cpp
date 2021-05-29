//template for heap
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
#include<queue>


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
    Node* next;
};

struct Node* newNode(int data){
    struct Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}


struct compare{
    bool operator()(struct Node* a, struct Node* b){
        return a->data > b->data;
    }
};

struct Node* mergeKSortedLists(struct Node* arr[], int k){
    priority_queue<Node*, vector<Node*>, compare> pq;
    for(int i=0; i<k; i++)
        if(arr[i] != NULL)
            pq.push(arr[i]);
        
        if(pq.empty())
            return NULL;
        
        struct Node* dummy = newNode(0);
        struct Node* last = dummy;

        while(!pq.empty()){
            struct Node* curr = pq.top();
            pq.pop();

            last->next = curr;
            last = last->next;

            if(curr->next != NULL)
                pq.push(curr->next);
        }

    return dummy->next;
}   

void printList(struct Node* head){
    while(head != NULL){
        cout << head->data << endl;
        head = head->next;
    }
    cout << endl;
}

int main(){
    int k = 3, n= 3;
    struct Node** arr = (Node**)malloc(k * sizeof(struct Node*));
        arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);
 
    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);
 
    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);
 
    struct Node* head = mergeKSortedLists(arr, k);
 
    printList(head);
 
    return 0;
    return 0;
}