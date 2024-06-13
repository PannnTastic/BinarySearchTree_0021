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
            root = NULL; // inisialisasi root ke null
        }

        void insert(string element) // insert node in the binary search tree
        {
            node* newnode = new node(element, NULL, NULL);//alokasi memori untuk node baru
            newnode->info = element; //assign value to the data field of the new data
            newnode->leftchild = NULL; // make the left child of the new node point to null
            newnode->rightchild = NULL; // make the right child of the new node point to null

            node* parent = NULL;
            node* current = NULL;

            search(element, parent, current); //locatr the node which the parent of the node to be inserted

            if ( parent == NULL){// mark the new node as root if the parent is null ( tree is empty)
                root = newnode;
            }

            if (element < parent->info){ //if the value in the data field of the new node is less than parent
                parent->leftchild = newnode; // make the left child of the parent to the new node
            }

            else if (element > parent->info){// if the value is greater than parent
                parent->rightchild = newnode;
            }
        }

        void search ( string element, node*& parent, node*& current){
            current = root;
            parent = NULL;
            while((current != NULL) && current->info != element){
                parent = current;
                if(element < current->info){
                    current = current->leftchild;
                }
                else{
                    current= current->rightchild;
                }
            }
        }

        void inorder ( node* ptr){
            if (root == NULL){
                cout << "Tree Is Empty" << endl;
            }
            if (ptr != NULL){
                inorder(ptr->leftchild);
                cout << ptr->info << " ";
                inorder(ptr->rightchild);
            }
        }
        void preorder (node* ptr){
            if (root == NULL){
                cout << "Tree Is Empty" << endl;
            }
            if (ptr != NULL){
                cout << ptr->info << " ";
                preorder(ptr->leftchild);
                preorder(ptr->rightchild);
            }
        }
        void postorder (node* ptr){
            if (root == NULL){
                cout << "Tree Is Empty" << endl;
            }
            if (ptr != NULL){
                postorder(ptr->leftchild);
                postorder(ptr->rightchild);
                cout << ptr->info << " ";
            }
        }
};