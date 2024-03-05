#pragma once

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
