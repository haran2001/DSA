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
    int key;
    struct Node* left, *right;
};

struct Node* newNode(int key){
    struct  Node* temp = new Node();
    temp->key = key;
    temp->left = NULL; 
    temp->right = NULL;
    return temp; 
}


bool findPath(struct Node* root, vector<int> &path, int k){
    if(root == NULL) return false;
    
    path.push_back(root->key);

    if(root->key == k)
        return true;
    
    if((root->left && findPath(root->left, path, k)) || (root->right && findPath(root->right, path, k)))
        return true;
    
    path.pop_back();
    return false;
}

int findLCA(Node * root, int n1, int n2){
    vector<int> path1, path2;
    if(!findPath(root, path1, n1) || !findPath(root, path2, n2))
        return -1;
    int i;
    for(int i=0; i<path1.size() && i<path2.size(); i++)
        if(path1[i] != path2[i])
            break;
    return path1[i-1];
}

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << findLCA(root, 4, 5) << endl;
    return 0;
}