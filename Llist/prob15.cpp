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

struct QNode{
    int data;
    struct QNode* next;
    QNode(int d){
        data = d;
        next = NULL;
    }
};


struct Queue{
    QNode *front, *rear;

    Queue(){
        front = rear = NULL;
    }

    void enQueue(int data){
        struct QNode * temp = new QNode(data);
        if(rear == NULL){
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void deQueue(){
        if(front == NULL)
            return;
        
        struct QNode * temp = front;
        front = front->next;
        
        if(front == NULL)
            rear = NULL;

        delete(temp);
    }
};

int main(){
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    q.deQueue();

    cout << (q.front)->data << endl;
    cout << (q.rear)->data << endl;
    return 0;
}