#include<iostream>
using namespace std;

char tmp;

void split(const string& myString){
    char char_arr[myString.length()];
    char word_array[2];
    for (int i = 0; i < myString.length(); i++){
        char_arr[i] = myString[i];
        if (myString[i]==' '){
            // how to make an char array which can contain words
        }
    }

    // Printing the character array
    for (char a : myString){
        
    }
    cout<<"\n";
}
int main() {
    string inp_str = "Hello World!";
    split(inp_str);
    return 0;
}