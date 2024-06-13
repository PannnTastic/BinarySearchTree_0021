#include <iostream>
#include <string>
using namespace std;

class node{
    public : 
    string info;
    node* leftchild;
    node* rightchild;

    //constructor node
    node(string i, node* l, node* r){
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class binarytree{
    public : 
        node* root;

        binarytree(){
            root = nullptr; // inisialisasi root ke null
        }

        void insert(string element) // insert node in the binary search tree
        {
            node* newnode = new node(element, nullptr, nullptr);//alokasi memori untuk node baru
            newnode->info = element; //assign value to the data field of the new data
            newnode->leftchild = nullptr; // make the left child of the new node point to null
        }
};