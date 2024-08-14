//A Binary Search Tree of n elements and then search an element from the tree.

//structure is a user defined data type
#include <bits/stdc++.h>
using namespace std;
//creating node datatype of the binary tree, node is the container of data type
struct Bst 
{   
    int data;
    Bst *left;
    Bst *right;
};
//creating new node in the tree
Bst *create_node(int data){
    Bst* new_node = new Bst();//we are creating a new node here
    new_node->data = data;//int data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}
//struct Bst = Bst* = data type like int 


//Inserting data 
Bst *insert(int data, Bst *root){
    //If the tree is empty then create the node
    if(root == NULL){
        root = create_node(data);
    }
    // if data to be inserted is greater, insert in right subtree. 
    //20>=15
    else if(data>= root->data){
        root->right = insert(data, root->right);//root->right = address of the data
    }
    //10>=15
    else if(data<root->data){
        root->left = insert(data, root->left);
    }
    return root;
}
//searching in the tree
// data = the value we are looking for
int search(Bst* root, int data){
    //If there are 0 elements in the tree
    if(root == NULL){
        return false;
    }
    //root er j value I guess
    else if(root->data == data){
        return true;
    }
    //searching in right subtree, data-r man beshi thakle data 
    else if(data>= root->data){
        return search(root->right,data);
    }
    else if(data< root->data){
        return search(root->left,data);
    }
    return false;

}



int main(){

    Bst *root = NULL;//creating an empty tree
    root = insert(15,root);
    root = insert(8,root);
    root = insert(4,root);
    root = insert(11,root);
    root = insert(23,root);
    root = insert(16,root);
    root = insert(27,root);

    int n=27;
    if(search(root,n)==1) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl; 


    //cout<<root->right<<endl;

    return 0;
}
