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


int main(){
    cout << "Hello world" << endl;
    return 0;
}