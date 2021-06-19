// https://www.codechef.com/problems/MAXPOOL
#include "test.h"
using namespace std;
#define pb push_back
#define is insert
#define rep1(i,a,b) for(long long i=a;i<=b;i++)
#define F first
#define S second
#define file ifstream fin("input.txt");ofstream fout("output.txt");
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr(n) for(long long i=0;i<n;i++)
#define rep(i,a,b) for(long long i=a;i<b;i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;


ll ans[205][205],n,a;
set<ll>se,absent;
vector<pair<ll,ll> >pos[100000];


void fill_(ll x)
{
    ll i=0,j=0;

    for(auto p:pos[x])
    {
        i=max(i,p.F);
        j=max(j,p.S);
    }

    if(ans[i][j]!=0)
    {
        if(pos[x].size()==1)
        {
            i=pos[x][0].F;
            j=pos[x][0].S;
            if(ans[i+1][j]==0)
                i++;
            else if(ans[i][j+1]==0)
                j++;
            else if(ans[i+1][j+1]==0)
            {
                i++;
                j++;
            }
        }
        else if(pos[x].size()==2)
        {
            i=pos[x][0].F+1;
            j=pos[x][0].S+1;
        }
    }

    

    ans[i][j]=x;

    for(auto p:pos[x])
    {
        for(int i=p.F;i<(p.F+2);i++)
        {
            for(int j=p.S;j<(p.S+2);j++)
            {
                if(i<=n&&j<=n&&ans[i][j]==0)
                {
                    ans[i][j]=*absent.begin();
                    absent.erase(absent.begin());
                }
            }
        }
    }
}


void solve()
{
    se.clear();
    absent.clear();
    cin>>n;

    for(int i=0;i<=(n*n);i++)pos[i].clear();

    rep(i,0,n)rep(j,0,n)ans[i][j]=0;

    n--;

    rep(i,0,n)
    {
        rep(j,0,n)
        {
            cin>>a;
            se.is(a);
            pos[a].pb({i,j});
        }
    }

    for(int i=1;i<=((n+1)*(n+1));i++)
        if(se.find(i)==se.end())
            absent.is(i);


    for(auto x:se)
        fill_(x);

    rep(i,0,n+1)
    {
        rep(j,0,n+1)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
    #endif
    fast;
    ll t=1;
    cin>>t; 
    while(t--)
    solve();
    return 0;
}