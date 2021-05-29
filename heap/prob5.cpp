//template for heap
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<iterator>
#include<string.h>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<queue>


using namespace std;

int min3(int a, int b, int c){
    return min(a, min(b, c));
}

int max3(int a, int b, int c){
    return max(a, max(b, c));
}

bool comparator(int a, int b){
    return a > b;
}


class MinHeap{
    int* harr;
    int heap_size;
    int capacity;
public:
    MinHeap(int arr[], int n);
    void MinHeapify(int i);
    void buildHeap();
    int parent(int i){return (i-1)/2;}
    int left(int i){return 2*i + 1;}
    int right(int i){return 2*i + 2;}
    int getMin(){return harr[0];};
    int extractMin();
    void replace(int x){
        harr[0] = x;
        MinHeapify(0);
    }
};

MinHeap::MinHeap(int arr[], int n){
    harr = arr;
    heap_size = n;
}

void MinHeap::buildHeap(){
    int i =(heap_size-1)/2;
    while(i >=0 ){
        MinHeapify(i);
        i--;
    }
}

int MinHeap::extractMin(){
    if(heap_size == 0)
        return INT_MAX;
    int root = harr[0];

    if(heap_size > 1){
        harr[0] = harr[heap_size-1];
        MinHeapify(0);
    }

    heap_size--;
    return root;
}

void MinHeap::MinHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if(l < heap_size && harr[i] > harr[l])
        smallest = l;

    if(r < heap_size && harr[i] > harr[r])
        smallest = r;

    if(smallest != i){
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}


void KthLargest(int k){
    int count=0, x;
    int * arr = new int[k];
    MinHeap mh(arr, k);

    while(1){
        cout << "Enter element ";
        cin >> x;

        if(count < k-1){
            arr[count] = x;
            count++;
        }

        else{
            if(count == k-1){
                arr[count] = x;
                mh.buildHeap();
            }
        
            else{
                if(x>mh.getMin())
                    mh.replace(x);
            }

            cout <<"Kth largest element is " << mh.getMin() << endl;
            count++;
        }
    }
}

int main(){
    int k = 3;
    cout << "K is " << k << endl;
    KthLargest(k);
        return 0;
}