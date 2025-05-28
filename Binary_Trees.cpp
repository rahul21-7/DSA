#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node(){
        right = NULL;
        left = NULL;
    }
    int val;
    Node* left;
    Node* right;
};

class binaryTree{
    Node* root;
    public:
    binaryTree(){
        root = NULL;
    }
    Node* getRoot(){
        return root;
    }

    void printTreeInorder(Node* root){
        if(root == NULL)
         return;
        
        printTreeInorder(root->left);
        cout<<root->val<<" ";
        printTreeInorder(root->right);
    }

    void printTreePreorder(Node* root){
        if(root == NULL)
         return;
        
         cout<<root->val<<" ";
         printTreePreorder(root->left);
        printTreePreorder(root->right);
    }

    void printTreePostorder(Node* root){
        if(root == NULL)
         return;
        
        printTreePostorder(root->left);
        printTreePostorder(root->right);
        cout<<root->val<<" ";
    }

    Node* buildTree(vector<int> arr){
        queue<Node*> q;
        root = new Node;
        root->val = arr[0];
        q.push(root);
        int idx = 1;
        Node* front = q.front();
        while(!q.empty() && idx<arr.size()){
            front = q.front();
            q.pop();
            if(idx<arr.size()){
                front->left = new Node;
                front->left->val = arr[idx++];
                q.push(front->left);
            }

            if(idx<arr.size()){
                front->right = new Node;
                front->right->val = arr[idx++];
                q.push(front->right);
            }

        }

        return root;
    }
};

int main(){
    binaryTree t;
    vector<int> arr = {1,2,3,4};
    t.buildTree(arr);
    t.printTreeInorder(t.getRoot());
}
