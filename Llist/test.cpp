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
#include<stack>



using namespace std;

int min3(int a, int b, int c){
    return min(a, min(b, c));
}

int max3(int a, int b, int c){
    return max(a, max(b, c));
}


class Node{
    public:
        int data;
        Node * next;
};



bool listComparator(Node* a, Node* b){
    return (a->data) < (b->data);
}

// bool listComparator(Node a, Node b){
//     return (a.data) < (b.data);
// }

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


// void sortList(Node** head, int n){
//     sort((*head), (*head)+n, listComparator);
// }


void sortList(Node* head, int n){
    sort((head), (head)+n, listComparator);
}


int main(){
    Node * head = NULL;

    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 0);
    printList(head);
    sortList(&head, 4);
    printList(head);
    return 0;
}