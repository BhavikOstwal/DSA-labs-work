#include<iostream>
using namespace std;


void split(const string& myString){
    char char_arr[myString.length()];
    char word_array[2];
    int t = 0;
    for (int i = 0; i < myString.length(); i++){
        char_arr[i] = myString[i];
        // if (myString[i]==' '){
        //     word_array[i] = char_arr[i];
        //     t=i;
        // }
    }

    // Printing the character array
    for (char a : myString){
        cout<<a<<"-";
    }
    cout<<"\n";
}
int main() {
    string inp_str = "Hello World!";
    split(inp_str);
    return 0;
}