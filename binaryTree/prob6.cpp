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
        Node* nextRight;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
            this->nextRight = NULL;
        }
};


void connectReccur(Node * root){
    if(!root)
        return;

    if(root->left)
        root->left->nextRight = root->right;
    if(root->right)
        root->right->nextRight = (root->nextRight)?root->nextRight->left:NULL;
    connectReccur(root->left);   
    connectReccur(root->right);   
}

void connect(Node* root){
    root->nextRight = NULL;
    connectReccur(root);
}


int main()
{
  
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
  
    connect(root);
  
    cout << "Following are populated nextRight pointers in the tree"
            " (-1 is printed if there is no nextRight)\n";
    cout << "nextRight of " << root->data << " is "
         << (root->nextRight ? root->nextRight->data : -1) << endl;
    cout << "nextRight of " << root->left->data << " is "
         << (root->left->nextRight ? root->left->nextRight->data : -1) << endl;
    cout << "nextRight of " << root->right->data << " is "
         << (root->right->nextRight ? root->right->nextRight->data : -1) << endl;
    cout << "nextRight of " << root->left->left->data << " is "
         << (root->left->left->nextRight ? root->left->left->nextRight->data : -1) << endl;
    return 0;
}