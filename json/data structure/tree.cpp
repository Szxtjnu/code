#include<iostream>
#include<cstdio>
using namespace std;

typedef int Elemtype;
typedef struct node{
    Elemtype data;
    struct node *left;
    struct node *right;
} Node;

typedef struct root{
    Node *root;
} Tree;

void Insert(Tree *tree, Elemtype value){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    if(tree->root == NULL){
        tree->root = node;
    }
    else{
        Node *temp = tree->root;
        while(temp != NULL){
            if(value < temp->data){
                if(temp->left == NULL){
                    temp->left = node;
                    return;
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->right == NULL){
                    temp->right = node;
                    return;
                }
                else{
                    temp = temp->right;
                }
            }
        }
    }
}

void traverse(Node *node){
    if(node!=NULL){
        traverse(node->left);
        cout << node->data << " " ;
        traverse(node->right);
    }
}

void distory_tree(Node * node){
    if(node != NULL){
        distory_tree(node->left);
        distory_tree(node->right);
        cout << "free node:" << node->data << endl;
        free(node);
        node = NULL;
    }
}

int main()
{
    int i = 0;
    Tree tree;
    tree.root = NULL;
    int n;
    cin >> n;
    for (i = 0; i < n; ++i){
        int temp;
        cin >> temp;
        Insert(&tree, temp);
    }
    traverse(tree.root);
    cout << endl;
    distory_tree(tree.root);
    return 0;
}