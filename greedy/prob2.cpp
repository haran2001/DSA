//template for greedy
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<iterator>
#include<string.h>
#include<unordered_set>
#include<algorithm>
#include<vector>

using namespace std;

int min3(int a, int b, int c){
    return min(a, min(b, c));
}

struct meeting{
    int start;
    int end;
    int pos;
};

bool comparator(struct meeting m1, struct meeting m2){
    return (m1.end < m2.end);
}

void printMeetings(int s[], int f[], int n){
    meeting *meets = new meeting[n];

    for(int i=0; i<n; i++){
        meets[i].start = s[i];
        meets[i].end = f[i];
        meets[i].pos = i + 1;
    }

    sort(meets, meets+n, comparator);

    vector<int> m;
    m.push_back(meets[0].pos);

    int time_limit = meets[0].end;

    for(int j=1; j<n; j++){
        if(meets[j].start >= time_limit){
            m.push_back(meets[j].pos);
            time_limit = meets[j].end;
        }
    }

    for(int i=0; i<m.size(); i++)
        cout << m[i] << " ";
}


int main(){
        int s[] = { 1, 3, 0, 5, 8, 5 };
    int f[] = { 2, 4, 6, 7, 9, 9 };
    int n = sizeof(s) / sizeof(s[0]);
    printMeetings(s, f, n);
    return 0;

}