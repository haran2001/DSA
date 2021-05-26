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

class Node{
    public:
        int data;
        Node* left;
        Node* right;
};


Node* newNode(int data){
    Node* temp = new Node();
    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;
    return temp;
}

void getVerticalUtil(Node* root, int hd, map<int, vector<int>> &m){
    if(root == NULL)
        return;
    
    m[hd].push_back(root->data);

    getVerticalUtil(root->left, hd-1, m);
    getVerticalUtil(root->right, hd+1, m);
}


void printVertical(Node* root){
    map<int, vector<int>> m;
    getVerticalUtil(root, 0, m);

    map<int, vector<int>>::iterator it;
    for(it=m.begin(); it != m.end(); it++){
        for(int i=0; i<it->second.size(); i++)
            cout << it->second[i] << endl;
        cout << endl; 
    }
}

int main(){
    Node * root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    printVertical(root);
    return 0;
}