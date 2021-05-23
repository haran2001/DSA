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


void push(Node** head, int data){
    Node *temp = new Node();
    temp->data = data;
    temp->next = (*head);
    (*head) = temp;
}

int detectLoop(Node * head){
    Node * fast = head;
    Node * slow = head;

    while(slow && fast && fast->next){
        if(fast == slow)
            return 1;
        fast = fast->next->next;
        slow = slow->next;
    }

    return 0;

}

int main(){
    Node * head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    head->next->next->next = head;  
    
    cout << detectLoop(head) << endl;
    return 0;
}