//template for dp
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<iterator>
#include<string.h>
#include<unordered_set>
#include<algorithm>

using namespace std;

int maxSumIS(int arr[], int n)
{
	int i, j, max = 0;
    int * msis = new int[n];

    for(int i=0; i<n; i++)
        msis[i] = arr[i];

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && msis[i] < msis[j] + arr[i])
                msis[i] = msis[j] + arr[i];            
        }
    }
	
    return *max_element(msis, msis+n);
}


int main()
{
	int arr[] = {1, 101, 2, 3, 100, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);

    cout << maxSumIS(arr, n) << endl;
	return 0;
}

