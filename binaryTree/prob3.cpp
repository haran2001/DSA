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

class node{
    public:
        int data;
        node* left; 
        node* right; 

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    };
};

void bottomViewUtil(node* root){
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL){
        cout << root->data << " ";
        return;
    }

    bottomViewUtil(root->left);
    bottomViewUtil(root->right);
}

void bottomView(node * root){
    int data = root->data;
    bottomViewUtil(root);
}

int main(){
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);

    bottomView(root);
}