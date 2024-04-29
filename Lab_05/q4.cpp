#include<iostream>
#include<limits>
using namespace std;


class Node
{
public:
	int data;
    Node* next;

    Node(int mydata)
    {
        data = mydata;
        next = nullptr;
    }
};

class SinglyLinkedList
{
    Node* head = nullptr;
    Node* tail = nullptr; 
public:
    void Insert(int mydata)
    {
        Node* new_node = new Node(mydata);
        if (head==nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        
        tail->next = new_node;
        tail = new_node;
        // cout<<(new_node->data)<<endl;
    }

    void Display()
    {
        Node* tmp = head;
        while(tmp!=nullptr)
        {
            cout<<tmp->data;
            if (tmp->next!=nullptr)
            {
                cout <<  " -> ";
            }
            tmp = tmp->next;
        }
        cout<<endl;
    }

    Node* Search(int key)
    {
        Node* tmp = head;
        while (tmp)
        {
            if (tmp->data==key)
            {
                return tmp;
            }
            tmp = tmp->next;
        }
        // cout << "Not in list" << endl;
        return nullptr;
    }

    Node* Head()
    {
        Node* tmp = head;
        return tmp;
    }
};

class Heap
{
    int heap_size;
    int length;

public:
    Heap(int sizeofarr)
    {
        heap_size = sizeofarr;
        length = sizeofarr;
    }

    int Parent(int index)
    {
        return (index-1)/2;
    }

    int Left(int index)
    {
        return 2*index+1;
    }

    int Right(int index)
    {
        return 2*index+2;
    }

    void print_arr(int A[])
    {
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    void print_heap(int A[])
    {
        for (int i = 0; i < heap_size; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    void Min_Heapify(int A[], int index)
    {
        int left = Left(index);
        int right = Right(index);
        int smallest = index;
        if (A[index]>A[left] && left<=heap_size-1)
        {
            smallest = left;
        }
        else if (A[index]>A[right] && right<=heap_size-1)
        {
            smallest = right;
        }
        if (smallest!=index)
        {
            swap(A[smallest], A[index]);
            print_heap(A);
            Min_Heapify(A, smallest);
        }
    }

    void Build_min_heap(int A[])
    {
        heap_size = length;
        // cout << heap_size<<endl;
        for (int i = (heap_size/2)-1; i >=0; i--)
        {
            Min_Heapify(A, i);
        }
    }

    int Extract_Min(int A[])
    {
        if (heap_size <= 0)
        {
            cout << "Heap underflow!" << endl;
            return -1;
        }
        int min = A[0];
        A[0] = A[heap_size - 1];
        heap_size--;
        Min_Heapify(A, 0);
        return min;
    }

    void Decrease_key(int A[], int index, int new_key)
    {
        if (A[index]<=new_key)
        {
            cout << "New key is larger" << endl;
        }
        else
        {
            A[index] = new_key;
            int i = index;
            while (i>0 && A[Parent(i)]>A[i])
            {
                swap(A[Parent(i)], A[i]);
                i = Parent(i);
            }
        }
    }

    void Insert_key(int A[], int new_key)
    {
        heap_size++;
        A[heap_size-1] = numeric_limits<int>::max();
        Decrease_key(A, heap_size-1, new_key);
    }

    Node* MergeK_lists(Node* node_arr[], SinglyLinkedList L1, SinglyLinkedList L2, SinglyLinkedList L3)
    {
        SinglyLinkedList Final_ls;
        int data_arr[] = {};
        for (int i = 0; i < heap_size; i++)
        {
            data_arr[i] = node_arr[i]->data;
        }
        Build_min_heap(data_arr);

        while (true)
        {
            int to_del = Extract_Min(data_arr);
            Final_ls.Insert(to_del);

            for (int i = 0; i < 3; i++)
            {
                Node* tmp = node_arr[i];
                if (L1.Search(to_del)->next)
                {
                    Insert_key(data_arr, L1.Search(to_del)->next->data);
                }
                else if (L2.Search(to_del)->next)
                {
                    Insert_key(data_arr, L2.Search(to_del)->next->data);
                }
                else if (L3.Search(to_del)->next)
                {
                    Insert_key(data_arr, L3.Search(to_del)->next->data);
                } 
            Min_Heapify(data_arr,0);
        }
        }
        return Final_ls.Head();
    }

};

int main()
{
    SinglyLinkedList L1;
    L1.Insert(4);
    L1.Insert(8);
    L1.Insert(9);

    SinglyLinkedList L2;
    L2.Insert(1);
    L2.Insert(5);
    L2.Insert(9);

    SinglyLinkedList L3;
    L3.Insert(3);
    L3.Insert(6);

    Node* node_arr[] = {L1.Head(), L2.Head() ,L3.Head()};
    Heap myhp(3);
    Node* finalhead = myhp.MergeK_lists(node_arr, L1, L2, L3);
    

    // printing
    while(finalhead!=nullptr)
        {
            cout<<finalhead->data;
            if (finalhead->next!=nullptr)
            {
                cout <<  " -> ";
            }
            finalhead = finalhead->next;
        }
        cout<<endl;
    
    
    // int arr[] = {4,1,3,2,16,9,10,14,8,7};
    // int size = sizeof(arr)/sizeof(int);
    // Heap myHeap(size);
    // myHeap.Build_min_heap(arr);
    // myHeap.print_heap(arr);
    return 0;
}