//Linked List of n elements and then display the list.

#include <bits/stdc++.h>
using namespace std;


struct LL{
    int data;
    LL *next;//address
};


LL *insert(LL *root,int data){
    //If there is nothing in the linked list, create a linked list
    if(root == NULL){//i
        root = new LL();
        root->data = data;
        root->next = NULL;
    }
    //for existing linked list
    else{
        //making a copy of the root node in the cp node
        LL *cp = root;//current node copy 
        while(cp->next != NULL){//finding the last node
            cp = cp->next;//go to next address
        }
        //creating a new node
        LL *new_node = new LL();
        new_node->data = data;
        new_node->next = NULL;

        //linking with the last node
        cp->next = new_node;
    }

    return root;
}

//root is the current data


void display(LL *root){
    // cout<<root->data<<endl;
    // if(root->next == NULL) return;
    // display(root->next);

    if(root==NULL) return;
    cout<<root->data<<" "<<root->next<<endl;
    display(root->next);
   

    // LL *cp = root;
    // while(cp!=NULL){//node khali thakle
    //     cout<<cp->data<<endl;
    //     cp = cp->next;
    // }


}



int main(){

    LL *root = NULL;
    //assigning the root the node
    root = insert(root,1);
    root = insert(root,15);
    root = insert(root,33);
    root = insert(root,366);
    
    display(root);
    
    return 0;
}