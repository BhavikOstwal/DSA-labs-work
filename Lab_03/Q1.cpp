#include<iostream>
#include<cmath>
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

class Stacks_via_LL
{
    Node* head;

public:
    Stacks_via_LL()
    {
        head = nullptr;
    };

    void Push(int mydata)
    {
        Node* new_node = new Node(mydata);
        new_node->next = head;
        head = new_node;
    }

    void Pop()
    {
        Node* tmp = head;

        if (tmp==nullptr)
        {
            cout<< "Stack is Empty!" <<endl;
            exit(1);
        }

        head = head->next;
        free(tmp);
    }

    int Peek()
    {   
        return head->data;
    }

    void Display()
    {
        Node* tmp = head;

        if (!tmp)
        {
            cout << "Stack is Empty!" << endl;
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

    bool is_Empty()
    {
        if (head==nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    ~Stacks_via_LL(){}
};

void legal_move(Stacks_via_LL& A, Stacks_via_LL& B, char src, char dest)
{

    if ((B.is_Empty()))
    {
        int to_move = A.Peek();
        B.Push(to_move);
        A.Pop();
        cout << "Moved " << to_move << " from " << src << " to " << dest << endl;
    }

    else if ((A.is_Empty()))
    {
        int to_move = B.Peek();
        A.Push(to_move);
        B.Pop();
        cout << "Moved " << to_move << " from " << dest << " to " << src << endl;
    }

    else if (A.Peek() < B.Peek())
    {
        int to_move = A.Peek();
        B.Push(to_move);
        A.Pop();
        cout << "Moved " << to_move << " from " << src << " to " << dest << endl;
    }

    else if ((A.Peek() > B.Peek()))
    {
        int to_move = B.Peek();
        A.Push(to_move);
        B.Pop();
        cout << "Moved " << to_move << " from " << dest << " to " << src << endl;
    }
}

void swapStacks(Stacks_via_LL& stack1, Stacks_via_LL& stack2) {
    Stacks_via_LL tmp = stack1;
    stack1 = stack2;
    stack2 = tmp;
}


void Solve_TOH(Stacks_via_LL& S, Stacks_via_LL& A, Stacks_via_LL& D, int n)
{
    if (n%2==0)
    {
        swapStacks(A, D);
    }

    for (int i = 1; i <= (1 << n)-1; i++)
    {
        if (i%3==1)
        {
            legal_move(S, D, 'S', 'D');
        }

        else if (i%3==2)
        {
            legal_move(S, A, 'S', 'A');
        }
        else
        {
            legal_move(A, D, 'A', 'D');
        }
    }
    
}


int main() {
    Stacks_via_LL S, A, D;


    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        S.Push(i);
    }
    Solve_TOH(S,A,D,n);
    return 0;
}