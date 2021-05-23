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

struct Node{
    int data;
    struct Node* next;

    Node(int data){
        this->data = data;
        struct Node* next;
    }

};

struct LinkedList{
    Node* head;
    LinkedList() {head = NULL;}

    void reverse(){
        Node *current = head, *prev = NULL, *next = NULL;

        while(current != NULL){
            next = current->next;
            current->next = prev;


            prev = current;
            current = next;
        }
        head = prev;
    }


    void print(){
        struct Node* temp = head;

        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }


    void push(int data){
        struct Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }


};

int main(){
    LinkedList ll;
    ll.push(10);
    ll.push(20);
    ll.push(30);


    cout << "Current list ";
    ll.print();

    cout << endl;
    ll.reverse();

    cout << "Reversed list " << endl;
    ll.print();

    return 0;
}