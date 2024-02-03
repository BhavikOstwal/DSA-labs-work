#include<iostream>
#include<vector>
using namespace std;

int main() {
    char arr[50];
    cin.getline(arr, 50);
    cout << arr << endl;

    vector<int> len_arr;
    for (int i = 0; i < 50; i++) {
        int j = i;
        while (arr[i] != ' ' && arr[i] != '\0') {
            i++;
        }
        len_arr.push_back(i - j);
    }

    int index = 0;
    for (int i = 0; i < len_arr.size(); i++) {
        int n = len_arr[i];
        char char_arr[n + 1]; // +1 for null terminator
        for (int j = 0; j < n; j++) {
            char_arr[j] = arr[index];
            index++;
        }
        char_arr[n] = '\0'; // Null-terminate the character array
        cout << char_arr << endl;
    }

    return 0;
}
