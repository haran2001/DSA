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
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int height(struct Node* root){
    if(root == NULL)
        return 0;
    return max(height(root->left) + 1, height(root->right) + 1);
}

void printGivenLevel(struct Node* root, int level, int ltr){
    if(root == NULL)
        return;
    if(level == 1)
        cout << root->data << endl;
    
    else{
        if(ltr){
            printGivenLevel(root->left, level-1, ltr);
            printGivenLevel(root->right, level-1, ltr);
        }
        else{
            printGivenLevel(root->right, level-1, ltr);
            printGivenLevel(root->left, level-1, ltr);
        }
    }
}


void printSpiral(struct Node* root){
    int h = height(root);
    int ltr = false;

    for(int i=1; i<=h; i++){
        printGivenLevel(root, i, ltr);
        cout << endl;
        ltr = !ltr;
    }
}


int main(){
    struct Node* root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);

    printSpiral(root);
    return 0;
}