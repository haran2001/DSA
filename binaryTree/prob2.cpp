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
        node* right;
        node* left;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


int isBSTUtil(node* root, int min, int max){
    if(root == NULL)
        return 1;

    if(root->data < min || root->data > max)
        return 0;
    
    return isBSTUtil(root->left, min, root->data - 1) &&
    isBSTUtil(root->right, root->data + 1, max);
}

int isBST(node* root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main(){
    node* root = new node(1);
    root->left = new node(1);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    cout << isBST(root) << endl;
    return 0;
}