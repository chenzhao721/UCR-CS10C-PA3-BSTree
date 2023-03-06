#include <iostream>
#include "BSTree.h"

using namespace std;

BSTree::BSTree():root(nullptr){};

void BSTree::insert(const string &newString)
{
    Node *newnode = new Node(newString);
    if(!root) {root=newnode; return;}

    Node *temp = root;
    while(1)
    {
        if(temp->data == newString) 
        {
            temp->count++;
            return;

        }

        else if(temp->data < newString)
        {
            if(!temp->right) 
            {
                temp->right = newnode;
                return;
            }
            else temp = temp->right;
        }

        else if(temp->data > newString)
        {
            if(!temp->left) 
            {
                temp->left = newnode;
                return;
            }
            else temp = temp->left;

        }

        else
        {
            cout<<"error string comparision!"<<endl;
            return;
        }
    }

}



void BSTree::remove(const string &key)
{
    Node *temp = root;
    Node *parent = nullptr;

    // search node with key value
    
    while(temp)
    {
        if(temp->data == key) 
        {
            if(temp->count>1) temp->count--; 
            else remove(temp, parent);
            return; 

        }

        else if(temp->data > key) {parent = temp; temp = temp->left;}
        else {parent = temp; temp = temp->right;}

    }

    // node not found
    //if(!temp) cout<<"cannot find node to remove"<<endl;
    
}


void BSTree::remove(Node *node, Node *parent)
{
    // leaf node
    if(!node->left && !node->right) 
    {
        if(node == root) {root = nullptr; return;}
        if(parent->left == node) parent->left = nullptr;
        else parent->right = nullptr;
    }

    //node with only left child
    else if(node->left && !node->right)
    {
        if(node == root) {root = node->left; return;}
        if(parent->left == node) parent->left = node->left;
        else parent->right = node->left;
    }

    // node with only right child
    else if(!node->left && node->right)
    {
        if(node == root) {root = node->right; return;}
        if(parent->left == node) parent->left = node->right;
        else parent->right = node->right;        
    }

    // node with both left and right child
    else
    {
        // find the largest node smaller than this node
        Node *max = node->left;
        Node *parent_max = node;
        while(max->right) 
        {
            parent_max = max;
            max = max->right;
        }

        node->data = max->data;
        remove(max, parent_max);

    }

}

bool BSTree::search(const string &str) const
{
    if(!root) return false;
    Node *cur = root;
    while(cur)
    {
        if(cur->data==str) return true;
        else if(cur->data<str) cur = cur->left;
        else cur = cur->right;   

    }

    return false;
}

string BSTree::largest() const
{
    if(!root) return "";
    Node *cur = root;
    while(cur->right){cur = cur->right;}
    return cur->data;
}

string BSTree::smallest() const
{
    if(!root) return "";
    Node *cur = root;
    while(cur->left){cur = cur->left;}
    return cur->data;
}

int BSTree::height(const string& str) const
{
    if(!root) return -1;
    Node *cur = root;
    int h = 0;
    while(cur)
    {
        if(cur->data==str) return h;
        else if(cur->data<str) cur = cur->left;
        else cur = cur->right;
        h++;   
    }

    return -1;

}

void BSTree::inOrder( ) const { 
    inOrder(root);
    cout<<endl;
}

void BSTree::preOrder( ) const { 
    preOrder(root);
    cout<<endl;
}

void BSTree::postOrder( ) const { 
    postOrder(root);
    cout<<endl;
}

void BSTree::inOrder(Node *node) const
{
    if(!node) return;
    inOrder(node->left);
    cout<<node->data<<"("<<node->count<<"), ";
    inOrder(node->right);
}

void BSTree::preOrder(Node *node) const
{
    if(!node) return;
    cout<<node->data<<"("<<node->count<<"), ";
    preOrder(node->left);
    preOrder(node->right);
}


void BSTree::postOrder(Node *node) const
{
    if(!node) return;
    postOrder(node->left);
    postOrder(node->right);
    cout<<node->data<<"("<<node->count<<"), ";
}





