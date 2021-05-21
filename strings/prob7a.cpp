//template for arrays
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<iterator>
#include<string.h>
#include<unordered_set>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<cmath>


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

bool solve(string str1, string str2){
    
    if(str1.length() != str2.length())
        return false;

    set<int> s1;
    set<int> s2;

    for(int i=0; i<str1.length(); i++){
        s1.insert(str1[i] - 'a');
    }

    for(int i=0; i<str2.length(); i++){
        s2.insert(str2[i] - 'a');
    }

    set<int>::iterator it1 = s1.begin();
    set<int>::iterator it2 = s2.begin();

    while(it1 != s1.end()){
    
        if((*it1) != (*it2))
            return false;
        it1++;
        it2++;
    
    }

    return true;

}

int main(){
    string str1 = "hello";
    string str2 = "ohell";

    cout << solve(str1, str2) << endl;
    return 0;
}