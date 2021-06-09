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

#define ll long long int
const long long int INF = 2e18;
const int maxN = 1e5 + 69;

struct items{
    int x, y, v;
    bool operator < (const items& oth) const{
        return y < oth.y;
    }
};

struct SegmentTree{
    int n;
    vector<ll> st;
    vector<ll> lazy;

    SegmentTree(int n) : n(n), st(n*4, -INF), lazy(n * 4) {};
    SegmentTree() {}

    void change(ll v, int id){
        st[id] += v;
        lazy[id] += v;
    }
    
    void push(int id){
        change(lazy[id], 2*id);
        change(lazy[id], 2*id  + 1);

        lazy[id] = 0;
    }

    void update(int L, int R, ll v, int id, int l, int r){
        if(R < l || r < L) return;

        if(L <= l && r <= R){
            change(v, id);
            return;
        }

        push(id);

        int mid = (r + l)/2;
        update(L, R, v, id * 2, l, mid);
        update(L, R, v, id*2 + 1, mid + 1, r);

        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }

    void update(int L, int R, ll v){
        update(L, R, v, 1, 0, n);
    }
};


int n, k;
int m;
items a[maxN];
vector<int> vals;
SegmentTree st;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i].x >> a[i].y >> a[i].v;

        vals.pb(a[i].x);
        vals.pb(a[i].y);
    }


    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    m = vals.size();

    sort(a + 1, a + 1 + n);
    st = SegmentTree(m);

    ll ans = 0;
    int cur = 0;

    for(int r=0; r < m; r++){
        st.update(r, r, INF + 1ll * k* vals[r]);

        while(cur + 1 <= n && a[cur + 1].y <= vals[r]){
            cur++;

            if(a[cur].v > 0){
                int id = lower_bound(vals.begin(), vals.end(), a[cur].x) - vals.begin();
                st.update(0, id, a[cur].v);
            }
        }

        ans = max(ans, st.st[1] - 1ll * k * vals[r]);
    }

    cout << ans << "\n";
}
