//A Binary Search Tree of n elements and then display the elements (preorder, in order and post order) of the tree.
#include <bits/stdc++.h>
using namespace std;


//here Bst *root means a node is getting created
//struct
struct Bst{
    int data;
    Bst *left;
    Bst *right;
};

//preorder
void preorder(Bst *root){
    if(root==NULL) return;
    cout<<root->data<<endl;//root
    preorder(root->left);//left
    preorder(root->right);//right
}

//inorder
void inorder(Bst *root){
    if(root==NULL) return;
    inorder(root->left);//left
    cout<<root->data<<endl;//root
    inorder(root->right);//right
}

//postorder
void postorder(Bst *root){
    if(root==NULL) return;
    postorder(root->left);//
    postorder(root->right);
    cout<<root->data<<endl;
}


//insert element in the tree
Bst *insert(Bst *root, int data){
    if(root==NULL){
        root = new Bst();
        root-> data = data;//
        root->left = root->right = NULL;
    }
    else if(data<=root->data){
        root->left = insert(root->left,data);
    }
    else if(data>root->data){
        root->right = insert(root->right,data);
    }
    return root;//
}



int main(){
    Bst *root = NULL;

    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 55);
    root = insert(root, 2);
    root = insert(root, 13);
    root = insert(root, 15);
    root = insert(root, 144);


    cout<<"Preorder: "<<endl;
    preorder(root);
    cout<<endl<<endl;
    cout<<"Inorder: "<<endl;
    inorder(root);
    cout<<endl<<endl;
    cout<<"Postorder: "<<endl;
    postorder(root);
    cout<<endl<<endl;

    
    return 0;
}