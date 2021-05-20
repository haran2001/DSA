//template for arrays
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

char *removeUtil(char *str, char *last_removed){
    if(str[0] == '\0' || str[1] == '\0')
        return str;
        
    if(str[0] == str[1]){
        *last_removed = str[0];
        while(str[1] && str[0] == str[1])
            str++;
        return removeUtil(str, last_removed);
    }

    char * rem_str = removeUtil(str+1, last_removed);
    if(rem_str[0] && rem_str[0] == str[0]){
        *last_removed = str[0];
        return (rem_str+1);
    }

    if(rem_str[0] == '\0' && *last_removed == str[0])
        return rem_str;

    rem_str--;
    rem_str[0] = str[0];
    return rem_str;

}


char* remove(char * str){
    char last_removed = '\0';
    return removeUtil(str, &last_removed);
}

int main(){
    char str1[] = "geeksforgeeg";
    cout << remove(str1) << endl;
 
    char str2[] = "azxxxzy";
    cout << remove(str2) << endl;
 
    char str3[] = "caaabbbaac";
    cout << remove(str3) << endl;
 
    char str4[] = "gghhg";
    cout << remove(str4) << endl;
 
    char str5[] = "aaaacddddcappp";
    cout << remove(str5) << endl;
 
    char str6[] = "aaaaaaaaaa";
    cout << remove(str6) << endl;
 
    char str7[] = "qpaaaaadaaaaadprq";
    cout << remove(str7) << endl;
 
    char str8[] = "acaaabbbacdddd";
    cout << remove(str8) << endl;
 
    char str9[] = "acbbcddc";
    cout << remove(str9) << endl;
 
    return 0;
}