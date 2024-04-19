#include<iostream>
using namespace std;

#define n 20

class Node
{
public:
    int data;
    Node* children_arr[n];

    Node(int mydata){
        data = mydata;
    }
};


class Branch_Tree
{
    Node* root;

public:
    Branch_Tree()
    {
        root = nullptr;
    }

    void Insert_at_level(int mydata, )
    {
                
    }
};

int main() {
    
    return 0;
}