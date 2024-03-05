#include<iostream>
using namespace std;

// #include "Q4_common.h"
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

#define row_mat1 3
#define col_mat1 2
#define row_mat2 2
#define col_mat2 3

// int row_mat=3, col_mat=2;
void put_in_LL1(Linked_list& LL, int A[row_mat1][col_mat1])
{
    for (int i = 0; i < row_mat1; i++)
    {
        for (int j = 0; j < col_mat1; j++)
        {
            if (A[i][j]!=0)
            {
                LL.Insrt_T(i,j,A[i][j]);
            }
        }
    }
}

void put_in_LL2(Linked_list& LL, int A[row_mat2][col_mat2])
{
    for (int i = 0; i < row_mat2; i++)
    {
        for (int j = 0; j < col_mat2; j++)
        {
            if (A[i][j]!=0)
            {
                LL.Insrt_T(i,j,A[i][j]);
            }
        }
    }
}


void mat_mult_LL(Linked_list& A, Linked_list& B, Linked_list& AB)
{
    Node* temp_a = A.Head();
    Node* temp_b = B.Head();
    int to_add =0;
    while (temp_a)
    {   
        temp_b = B.Head();
        while (temp_b)
        {
            if (temp_a->col==temp_b->row)
            {
                AB.Insrt_T(temp_a->row, temp_b->col, (temp_a->data)*(temp_b->data));
            }
            temp_b = temp_b->next;
        }
        temp_a = temp_a->next;
    }
}


int main() {
    int mat1[3][2] = { {0, 1}, {2, 0}, {3, 3} };
    int mat2[2][3] = { {1, 1, 0}, {2, 0, 0} };

// Output: result[3][3] = { {3, 3, 3}, {6, 6, 6}, {9, 9, 9} }
    Linked_list M1, M2;

    put_in_LL1(M1, mat1);
    put_in_LL2(M2, mat2);

    display_sparse(M1,M1.Head());
    cout << endl;
    display_sparse(M2,M2.Head());
    cout << endl;

    Linked_list M1M2;
    // mat_mult_LL(M1, M2, M1M2);
    // display_sparse(M1M2, M1M2.Head());
    
    // cout << "Hello" << endl;
    return 0;
}