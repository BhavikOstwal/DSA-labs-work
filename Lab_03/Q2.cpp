#include<iostream>
using namespace std;

class Node
{
public:
    char data;
    Node* next;

    Node(char mydata)
    {
        data = mydata;
        next = NULL;
    }
};


class Stack_LL
{
public:
    Node* top;
    Stack_LL()
    {
        top = NULL;
    }

    void Push(char mydata)
    {
        Node* new_node = new Node(mydata);
        if (new_node==NULL)
        {
            cout << "Stack Overflow" << endl;
            exit(1);
        }
        
        new_node->next = top;
        top = new_node;
    }

    void Pop()
    {
        Node* tmp;    //--> We first assigned tmp to top, so that we do not loose the reference to previous node(to be deleted)
    
        if (top == NULL) {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else
        {
            tmp = top;
            top = top->next;
            free(tmp);
        }   
    }

    char Peek()
    {
        return top->data;
    }

    void Display()
    {
        Node* iterator = top;
        
        if (iterator==NULL)
        {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }

        while (iterator!=NULL)
        {
            cout <<  iterator->data;
            if (iterator->next!=NULL)
            {
                cout << "->";
            }
            iterator = iterator->next;
        }
        cout << endl;
    }

    bool isEmpty()
    {
        Node* checker = top;
        if (checker==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};

int main() {
    Stack_LL SLL; 
    string str;

    cout << "Enter here:\n";
    getline(cin, str);
    char check;
    for (int i = 0; i < str.length(); i++)
    {
        check = str[i];
        if ((check=='(')||(check==')')||(check=='{')||(check=='}')||(check=='[')||(check==']'))
        {
            if (!SLL.isEmpty() &&
            ((SLL.Peek()=='(' && check==')') ||
             (SLL.Peek()=='{' && check=='}') ||
             (SLL.Peek()=='[' && check==']')))
            {
                SLL.Pop();
            }

            else
            {
                SLL.Push(check);
            }
        }
    }

    (SLL.isEmpty())?  cout << "Balanced" << endl : cout << "Unbalanced" << endl;    
    return 0;
}