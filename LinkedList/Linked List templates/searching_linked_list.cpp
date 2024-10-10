//A Linked List of n elements and then search an element from the list

#include <bits/stdc++.h>
using namespace std;

struct LL{
    int data;
    LL *next;
};


LL *insert(LL *root,int data){
    //If there is nothing in the linked list, create a linked list
    if(root == NULL){
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
    cout<<root->data<<endl;
    display(root->next);
   

    // LL *cp = root;
    // while(cp!=NULL){//node khali thakle
    //     cout<<cp->data<<endl;
    //     cp = cp->next;
    // }


}

int search(LL *nn,int data){
    if(nn==NULL){
        return false;
    }
    else if(nn->data==data){
        return true;//1
    }
    else if(nn->data!=data){
        return search(nn->next,data);//
    }
    else return false;
}





int main(){

    LL *root = NULL;
    //assigning the root the node
    root = insert(root,1);
    root = insert(root,15);
    root = insert(root,33);
    
    //display(root);
    if(search(root, 15)==17) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;

    
    return 0;
}