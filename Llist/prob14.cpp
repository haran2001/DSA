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

bool comparator(int a, int b){
    return a > b;
}

class Node{
    public:
        int data;
        Node * next;
};

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


bool isPalindrome(Node * head){
    stack<int> s;
    Node * ptr = head;

    while(ptr != NULL){
        s.push(ptr->data);
        ptr = ptr->next;
    }

    ptr = head;

    while(ptr != NULL){
        int i = s.top();
        s.pop();
        if(i != ptr->data)
            return false;
        ptr = ptr->next;
    }

    return true;
}


int main(){
    Node * head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);


    cout << isPalindrome(head) << endl;
    return 0;
}