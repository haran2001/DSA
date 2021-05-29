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
    struct Node* next;
};


struct Node* newNode(int data){
    struct Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}


Node* mergeKLists(Node* arr[], int last){
    for(int i=1; i<last; i++){
        while(true){
            Node* head_0 = arr[0], *head_i = arr[i];

            if(head_i == NULL)
                break;
            
            if(head_0->data >= head_i->data){
                arr[i] = head_i->next;
                head_i->next = head_0;
                arr[0] = head_i;
            }
            else
                while(head_0->next != NULL){
                    if(head_0->next->data >= head_i->data){
                        arr[i] = head_i->next;
                        head_i->next = head_0->next;
                        head_0->next = head_i;
                        break;
                    }
                    head_0 = head_0->next;

                    if(head_0->next == NULL){
                        arr[i] = head_i->next;
                        head_i->next = NULL;
                        head_0->next = head_i;
                        head_0->next->next = NULL;
                        break;
                    }
                }
            
        }
    }
        return arr[0];

}



void printList(struct Node* head){
    while(head != NULL){
        cout << head->data << endl;
        head = head->next;
    }
    cout << endl;
}

int main(){
int k = 3;
 
    // Number of elements in each list
    int n = 4;
 
    // an array of pointers storing the
    // head nodes of the linked lists
    Node** arr = (Node**)malloc(k* sizeof(struct Node*));
 
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
 
    // Merge all lists
    Node* head = mergeKLists(arr, k - 1);
 
    printList(head);
 
    return 0;}