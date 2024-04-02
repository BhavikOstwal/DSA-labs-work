#include<iostream>
using namespace std;


class BT
{
    int* arr = new int[30];
    int lst_ind = -1;

public:
    void set_root(int key)
    {
        arr[0]=key;
        lst_ind=0;
    }

    void set_left(int key, int parent)
    {
        if (!arr[parent])
            if (parent==-1)
            {

            }
            else
            {
                cout << "Can't set child at " << parent << "th ind" << endl;
            }
        else
        {
            arr[2*parent+1] = key;
            lst_ind=2*parent+1;
        }        
    }

    void set_right(int key, int parent)
    {
        if (!arr[parent])
        {
            cout << "Can't set child at " << parent << "th ind" << endl;
        }
        else
        {
            arr[2*parent+2] = key;
            lst_ind=2*parent+2;            
        }        
    }

    void deletion(int ind)
    {
        if (ind<0)
        {
            cout << "Can't delete" << endl;
        }

        else if (arr[ind])
        {
            if (arr[2*ind+2]!=0)
            {
                int tmp = 2*ind+2;

                while (arr[2*tmp+2]!=0)
                {
                    tmp = 2*tmp+2;
                }

                arr[ind] = arr[tmp];
                arr[tmp]=0;
            }
            else
            {
                int tmp = ind;
                while (arr[2*tmp+1]!=0)
                {
                    if (arr[2*(2*tmp+1)+2]==0)
                    {
                        tmp = 2*tmp+1;
                    }
                    else
                    {
                        tmp = 2*(2*tmp+1)+2;
                    }
                }
                arr[ind] = arr[tmp];
                arr[tmp]=0;
            }

        }
    }

    int Search(int myvalue)
    {
        int tmp = -1;

        while (arr[tmp+1]!=myvalue)
        {
            tmp++;
            if (tmp>30)
            {
                return -1;
            }
        }
        return tmp+1;
    }


    void print_BT()
    {
        for (int i = 0; i <= lst_ind; i++)
        {
            if (!arr[i])
            {
                cout << "-" << " ";
            }
            else
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

};

int main() {
    BT myBT;
    myBT.set_root(18);
    myBT.set_left(11,0);
    myBT.set_right(19,0);
    myBT.set_left(10,1);
    myBT.set_right(15,1);
    myBT.set_left(9,3);
    myBT.set_left(13,4);
    myBT.set_right(17,4);
    myBT.deletion(1);
    myBT.print_BT();
    cout << myBT.Search(4) << endl;
    
    return 0;
}