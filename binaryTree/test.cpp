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

struct node{
    int data;
    struct node* left;
    struct node* right;
};

void printGivenLevel(struct node* root, int level, int ltr);
int height(struct node* root);
struct node* newNode(int data);

void printSpiral(struct node* root){
    int h = height(root);
    int i;
    bool ltr = false;
    for(int i=1; i<=h; i++){
        printGivenLevel(root, i, ltr);
        ltr = !ltr;
    }
}


void printGivenLevel(struct node* root, int level, int ltr){
    if(root == NULL)
        return;
    if(level == 1)
        cout << root->data << " ";
    else if(level > 1){
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

int height(struct node* node){
    if(node == NULL)
        return 0;
    else{
        int lheight = height(node->left);
        int rheight = height(node->right);

        if(lheight > rheight)
            return (lheight + 1); 

        else
            return (rheight + 1);
    }
}

struct node* newNode(int data){
    struct node* temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main(){
    struct node* root = newNode(1);
    root->left = newNode(1);
    root->left = newNode(2);
    root->left = newNode(3);
    root->left = newNode(7);
    root->left = newNode(6);
    root->left = newNode(5);
    root->left = newNode(4);
    printSpiral(root);
    return 0;
}