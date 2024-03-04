#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int mydata){
        data = mydata;
        next =nullptr;
        prev =nullptr;
    }
};

class Doubly_LL
{
private:
    Node* head;
    Node* tail;

public:
    Doubly_LL()
    {
        head = nullptr;
        tail = nullptr;
    }

    void Insrt_at_T(int mydata)
    {
        Node* new_node = new Node(mydata);
        if (head==nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->prev = tail;
            tail->next = new_node;
            new_node->next = nullptr;
            tail = new_node;
        }
    }

    void Display()
    {
        Node* itr = head;
        
        if (!itr)
        {
            cout << "Linked list contains no nodes" << endl;
            exit(1);
        }
        
        
        while (itr)
        {
            cout << itr->data;
            if (itr->next!= nullptr)
            {
                cout << "->";
            }
            itr = itr->next;
        }
        cout << endl;    
    }

    Node* Head_ptr()
    {
        return head;
    }
};

int main() {
    Doubly_LL DLL;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        DLL.Insrt_at_T(tmp);
    }

    cout << "Original linked list: ";
    DLL.Display();
    //Insertion sort on DLL

    Node* ref_ptr = DLL.Head_ptr();
    Node* swp_ptr;
    int while_loop_conter=0;
    ref_ptr = ref_ptr->next;
    // cout << ref_ptr->data;
    while(ref_ptr!=nullptr)
    {
        int key = ref_ptr->data;
        Node* J = ref_ptr->prev;

        while ((J!=nullptr)&&(J->data>key))
        {
            J->next->data = J->data;
            // DLL.Display();
            swp_ptr = J;    //--> can't access J->next if J is null ptr, so to put key in J->next, we stored this pointer in a variable named swp_ptr
            J = J->prev;
            while_loop_conter++;
        }
        if (while_loop_conter>0){
            swp_ptr->data = key;
        }
        while_loop_conter=0;
        // DLL.Display();

        // while loop updation
        ref_ptr = ref_ptr->next;
    }

    cout << "Sorted linked list: ";
    DLL.Display();
    
    return 0;
}

    // DLL.Insrt_at_T(34);
    // DLL.Display();
    // DLL.Insrt_at_T(3);
    // DLL.Display();
    // DLL.Insrt_at_T(4);
    // DLL.Display();