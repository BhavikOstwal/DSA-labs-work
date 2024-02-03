#include<iostream>
using namespace std;


int main() {
    char arr[50];
    cin.getline(arr,50);
    cout<<arr<<endl;
    vector<int> len_arr;
    for (int i =0; i<50; i++){
        int j = i;
        while (arr[i] != ' ' )
        {
            i++;
        }
        len_arr.push_back(i-j);
    }

    int i = 0;
    while (arr[i] != ' '){
        int n = len_arr[i];
        char char_arr[n];
        char_arr[i] = arr[i];
        for (int j = 0; j < n; j++){
            cout<<char_arr[j]<<endl;
        }
        cout<<"one char set is printed"<<endl;
        i++;
    }
    return 0;
}
