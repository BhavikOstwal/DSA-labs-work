#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void bucketsort(vector<float> & arr){
    vector<float>sortedArr;
    for(float num: arr){
        sortedArr.insert(lower_bound(sortedArr.begin(),sortedArr.end(),num))
    }
    arr=sortedArr;
}
int main(){
    vector<float>arr={0.234,0.345,0.3421,0.456,0.876};
    bucketsort(arr);
    for(float num:arr)cout<<num<<" ";
}
