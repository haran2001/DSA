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

int _getIntersection(int d, Node * head1, Node * head2);


int getCount(Node * head){
    Node * current = head;
    int count = 0;

    while(current != NULL){
        count++;
        current = current->next;
    }

    return count;
}


int _getIntersection(int d, Node* head1, Node* head2){

    for(int i=0; i<d; i++){
        if(head1 == NULL)
            return -1;
        head1 = head1->next;
    }

    while((head1 != NULL) && (head2 != NULL)){
        if(head1 == head2)
            return head1->data;

        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}


int getIntersection(Node * head1, Node * head2){
    int c1 = getCount(head1);
    int c2 = getCount(head2);

    int d;

    if(c1 > c2){
        d = c1 - c2;
        return _getIntersection(d, head1, head2);
    }

    else{
        d = c2 - c1;
        return _getIntersection(d, head2, head1);
    }
}

int main()
{

  
    Node* newNode;
  
    Node* head1 = new Node();
    head1->data = 10;
  
    Node* head2 = new Node();
    head2->data = 3;
  
    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;
  
    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;
  
    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;
  
    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;
  
    head1->next->next->next = NULL;
  
    cout << "The node of intersection is " << getIntersection(head1, head2);

    return 0;
}