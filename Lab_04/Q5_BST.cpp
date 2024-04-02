#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int mydata){
        data = mydata;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class Binary_Search_Tree
{
    Node* root;

public:
    Binary_Search_Tree(){
        root = nullptr;
    }

    void Insert(int mydata)
    {
        Node* new_node = new Node(mydata);
        Node* tmp = root;
        Node* j = nullptr;
        if (root==nullptr)
        {
            root=new_node;
        }
        else
        {
            while (tmp)
            {
                j = tmp;
                if (new_node->data<=tmp->data)
                {
                    tmp = tmp->left;
                }
                else
                {
                    tmp = tmp->right;
                }
            }

            if (new_node->data<=j->data)
            {
                j->left = new_node;
                new_node->parent = j;
            }
            else
            {
                j->right = new_node;
                new_node->parent = j;
            }  
        }
    }

    void Inorder_trav(Node* rot)
    {
        if (rot!=nullptr)
        {
            Inorder_trav(rot->left);
            cout << rot->data << " ";
            Inorder_trav(rot->right);
        }
    }

    void Preorder_trav(Node* rot)
    {
        if (rot!=nullptr)
        {
            cout << rot->data << " ";
            Preorder_trav(rot->left);
            Preorder_trav(rot->right);
        }
    }

    void Postorder_trav(Node* rot)
    {
        if (rot!=nullptr)
        {
            Postorder_trav(rot->left);
            Postorder_trav(rot->right);
            cout << rot->data << " ";
        }
    }

    Node* Root()
    {
        Node* tmp = root;
        return tmp;
    }

    Node* Tree_min(Node* rot)
    {
        while (rot->left)
        {
            rot = rot->left;
        }
        return rot;
    }

    Node* Tree_successor(Node* mynode)
    {
        if (mynode->right)
        {
            return Tree_min(mynode->right);
        }

        Node* tmp = mynode->parent;
        while ((tmp) && (mynode!=tmp->left))
        {
            mynode = tmp;
            tmp = tmp->parent;
        }
        return tmp;
    }

};


int main() {
    Binary_Search_Tree BST;
    BST.Insert(4);
    BST.Insert(9);
    BST.Insert(7);
    BST.Insert(2);
    BST.Insert(3);

    BST.Preorder_trav(BST.Root());
    cout << endl;
    BST.Inorder_trav(BST.Root());
    cout << endl;
    BST.Postorder_trav(BST.Root());
    cout << endl;
    // cout << BST.Tree_min(BST.Root())->data << endl;
    // cout << BST.Tree_successor(BST.Root())->data << endl;
    return 0;
}