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
#include<assert.h>

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
 
struct mod_int {
    int val;
 
    mod_int(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
 
        if (v >= MOD)
            v %= MOD;
 
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
    }
 
    explicit operator int() const {
        return val;
    }
 
    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
 
    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n" : "=a" (quot), "=d" (rem): "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
 
    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
 
    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }
 
    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }
 
    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    mod_int operator++(int32_t) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int32_t) { mod_int before = *this; --*this; return before; }
 
    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }
 
    mod_int inv() const {
        return mod_inv(val);
    }
 
    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, mod_int &m) {
        return stream>>m.val;   
    }
};


const int N = 1e6+5;

mod_int dp[N];
mod_int dp2[N];
mod_int pre[N];
mod_int pre2[N];


void intend(int n = 1e6){
        
        dp[1] = dp2[1] = 0;
	    for(int i = 2; i <= n; i++){
    		pre[i] = pre[i - 1];
    		pre2[i] = pre2[i - 1];
    		if(i & 1){
    			dp[i] = 2*(pre[i - 1] - pre[i / 2]);
    			dp2[i] = 4*(pre[i - 1]-pre[i / 2]) + 2*(pre2[i - 1]-pre2[i / 2]);
    		}
    		else{
    			dp[i] = 2*(pre[i - 1] - pre[i / 2]) + dp[i / 2];
    			dp2[i] = 4*(pre[i - 1] - pre[i / 2]) + 2*dp[i / 2] + 2*(pre2[i - 1] -pre2[i / 2]) + dp2[i / 2];
    		}
		
    		dp[i] /= (i-1);
    		dp[i] += 1;
    		dp2[i] /= (i-1);
    		dp2[i] += 1;
    		pre[i] += dp[i];
    		pre2[i] += dp2[i];
	}
}



int solve(){
 		int t; cin >> t;
 		while(t--){
 			int n,m;
 			cin >> n >> m;
 			cout << dp2[n] + dp2[m] + 2*dp[n]*dp[m] << endl;
 		}
        

 return 0;
}
signed main(){
    int t = 1; //cin >> t;    
    intend();
    while(t--){
        solve();
    }
    return 0;
}