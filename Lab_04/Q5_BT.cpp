#include<iostream>
#include<queue>
using namespace std;

template <typename mydtype>
class Queue
{    
    mydtype* arr = new mydtype[20];

public:
    int head=0, tail=0;
    void Enqueue(mydtype x)
    {
        if ((tail+1==head)||((tail==20-1)&&(head==0)))
        {
            cout<<"Queue overflows"<<endl;
        }
        else
        {
            arr[tail] = x;
            if (tail==20-1)
            {
                tail=0;
            }
            else
            {
                tail++;
            }
            
        }
    }

    void Dequeue()
    {   
        if (head!=tail)
        {
            if (head+1!=20-1)
            {
                head++;
            }
            else
            {
                head = 0;
            }
        }
        else
        {
            cout<<"Queue underflows"<<endl;
        }
    }

    mydtype Front()
    {
        return arr[head];
    }
    
    // bool isEmpty()
    // {
    // }

};

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int my_data){
        data = my_data;
        left = nullptr;
        right = nullptr;
    }
};

class Binary_Tree
{
    Node* root;

public:
    Binary_Tree(){
        root = nullptr;
    }

    void Insert(int my_data)
    {
        Node* new_node = new Node(my_data);
        if (root==nullptr)
        {
            root = new_node;
            return;
        }
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* tmp = q.front();
            q.pop();

            if (tmp->left!=nullptr)
            {
                q.push(tmp->left);
            }
            else
            {
                tmp->left = new_node;
                return;
            }
            

            if (tmp->right!= nullptr)
            {
                q.push(tmp->right);
            }
            else
            {
                tmp->right = new_node;
                return;
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
};


int main() {
    Binary_Tree BT;
    BT.Insert(5);
    BT.Insert(7);
    BT.Insert(10);
    BT.Insert(18);
    BT.Insert(4);

    BT.Inorder_trav(BT.Root());
    cout << endl;
    BT.Preorder_trav(BT.Root());
    cout << endl;
    BT.Postorder_trav(BT.Root());
    cout << endl;
    return 0;
}