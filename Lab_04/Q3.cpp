#include<iostream>
using namespace std;

class child_arr
{
public:
    int data[10];
    child_arr* child_ptr;
    int* parent;
    int next_ind = 0;

    child_arr(int mydata)
    {
        data[0] = mydata;
        next_ind++;
    }
};

class Branch_Tree
{
    child_arr* root;

public:
    Branch_Tree()
    {
        root = nullptr;
    }

    void Insert_at_level()
    {
                
    }
};

int main() {
    
    return 0;
}