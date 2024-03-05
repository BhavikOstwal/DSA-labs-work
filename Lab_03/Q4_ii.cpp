#include<iostream>
using namespace std;

#define row_mat 5
#define col_mat 6

class Node
{
public:
    int data, row, col;
    Node* next;

    Node(int row_ind, int col_ind, int my_data)
    {
        data = my_data;
        row = row_ind;
        col = col_ind;
    }
};

class Linked_list
{
    Node* head;
    Node* tail;

public:
    Linked_list()
    {
        head = nullptr;
        tail = nullptr;
    }

    void Insrt_T(int row_ind, int col_ind, int my_data)
    {
        Node* new_node = new Node(row_ind, col_ind, my_data);
        if ((!head)&&(!tail))
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void Display()
    {
        Node* tmp = head;
        if (tmp==nullptr)
        {
            cout << "Nothing to display!" << endl;
        }
        else
        {
            while (tmp)
            {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }
    }

    Node* Head()
    {
        Node* temp_hd = head;
        return temp_hd;
    }

};

void put_in_LL(Linked_list& LL, int A[row_mat][col_mat])
{
    for (int i = 0; i < row_mat; i++)
    {
        for (int j = 0; j < col_mat; j++)
        {
            if (A[i][j]!=0)
            {
                LL.Insrt_T(i,j,A[i][j]);
            }
        }
    }

}


void display_sparse(Linked_list& LL, Node* hd)
{
    Node* tmp = hd;
    while (tmp)
    {
        cout << tmp->row << " ";
        tmp = tmp->next;
    }
    cout << endl;
    free(tmp);
    
    tmp = hd;
    while (tmp)
    {
        cout << tmp->col << " ";
        tmp = tmp->next;
    }
    cout << endl;
    free(tmp);

    tmp = hd;
    while (tmp)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
    free(tmp);
}

int main() {
    int A1[row_mat][col_mat] =
    {
        {0 , 0 , 0 , 0 , 9, 0 }, 
        {0 , 8 , 0 , 0 , 0, 0 },
        {4 , 0 , 0 , 2 , 0, 0 },
        {0 , 0 , 0 , 0 , 0, 5 },
        {0 , 0 , 2 , 0 , 0, 0 }
    };

    Linked_list LL;

    // LL.Display();
    
    put_in_LL(LL,A1);    
    display_sparse(LL, LL.Head());
    
    return 0;
}