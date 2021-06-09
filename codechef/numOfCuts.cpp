//template for backtracking
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
#include<numeric>

#define all(v) v.begin(), v.end()
#define sz(v) (int)(v.size())
#define rz(v, n) v.resize((n) + 1);
#define pb push_back
#define fi first
#define se second
#define vi vector <int>
#define pi pair <int, int>
#define vpi vector <pi>
#define vvi vector <vi>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
const int inf = 1e9;
const int N = 2e5 + 1;


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


const int MOD = 998244353;

struct mod_int{
    int val;

    mod_int(long long v){
        if(v < 0)
            v = v%MOD + MOD;

            if(v >= MOD)
                v %= MOD;
            val = v;
    }

    static int mod_inv(int a, int m = MOD){
        int g = m, r = a, x = 0, y = 1;
        while(r != 0){
            int q = g/r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        return x < 0 ? x +m: x;
    }

    explicit operator int () const{
        return val;
    }

    mod_int& operator += (const mod_int &other){
        val += other.val;
        if(val >= MOD) val -= MOD;
        return *this;
    }

    mod_int& operator -= (const mod_int &other){
        val -= other.val;
        if(val< 0) val += MOD;
        return *this;
    }
    
    static unsigned fast_mod(uint64_t x, unsigned m = MOD){
        #if !defined(_WIN32) || defined(_WIN64)
            return x % m;
        #endif

        unsigned x_high = x >> 32, x_low = (unsigned) x;
        unsigned qout, rem;
        asm();
    }

};

int main(){
    cout << "Hello world" << endl;
    return 0;
}