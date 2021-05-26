//template for BinaryTree
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

struct Node{
    int data;
    Node* left = NULL;
    Node* right = NULL;
};


struct Node* newNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void leftViewUtil(struct Node* root, int level, int * max_level){
    if(root == NULL)
        return;
    
    if(*max_level < level){
        cout << root->data << " ";
        *max_level = level;
    }

    leftViewUtil(root->left, level+1, max_level);
    leftViewUtil(root->right, level+1, max_level);
}


void leftView(Node* root){
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}


int main(){
    Node * root= newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    leftView(root);   
    return 0;
}