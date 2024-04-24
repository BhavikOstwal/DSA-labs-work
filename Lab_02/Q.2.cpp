#include<iostream>
using namespace std;

int comparisons=0;
void merge(int A[], int p, int q, int r){
		int n1 = q-p+1;
        int n2 = r-q;
        int L[n1+1],R[n2+1];
        for (int i = 0; i<n1; i++){
                L[i]=A[p+i];
        }
        for (int j = 0; j<n2; j++){
                R[j]=A[q+1+j];
        }
        L[n1] = 999999;
        R[n2] = 999999;
        int i = 0, j = 0;
		for (int k=p; k<r+1; k++){
			comparisons++;
			if (L[i]<R[j]){
				A[k]=L[i];
				i++;
			}
			else {
				A[k]=R[j];
				j++;
			}
		}
}

void merge_sort(int A[], int p, int r){
	if (p<r){
		int q = p + (r-p)/2;	
		merge_sort(A, p, q);
		merge_sort(A, q+1, r);
		merge(A, p, q, r);
	}
}

int main(){
	int A[] = {0,1,4,2};
    merge_sort(A, 0, sizeof(A)/sizeof(int)-1);
	
	// printing array A[] 
	for (int i=0; i<sizeof(A)/sizeof(int); i++){
		cout<<A[i]<<" ";
	}
	cout<<"\nComparisons: "<<comparisons<<endl;
    return 0;
}