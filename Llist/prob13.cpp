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


int findValue(Node * head){
    int res = 0;
    int exp = 0;
    while(head != NULL){
        res += (pow(10, exp) * head->data);
        exp++;
        head = head->next;
    }

    return res;
}


Node * add(Node * a, Node * b){
    int sum = findValue(a) + findValue(b);
    Node * res = NULL;
    while(sum > 0){
        push(&res, sum%10);
        sum /= 10;
    }
    return res;
}


int main(){
    Node * a = NULL;
    push(&a, 1);
    push(&a, 2);
    push(&a, 3);


    Node * b = NULL;
    push(&b, 1);
    push(&b, 0);
    push(&b, 0);

    Node * res = add(a, b);
    printList(res);
    return 0;
}