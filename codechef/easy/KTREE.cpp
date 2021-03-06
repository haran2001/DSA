// https://www.codechef.com/problems/KTREE
#include "test.h"
#define ll long long int
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define endl "\n"
#define f first
#define se second
#define MOD 1000000007
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

const int N=5e5+3;
map<ll,int> m;
vector<int> a;
multiset<int> s;
vector<int> v[N];
ll k;
int n;
int msb;

void init()
{
    fab(0,n+1,i)
    v[i].clear();
    a.clear();
    m.clear();

}
void findmsb()
{
    fab(0,64,i)
    {
        if(k&(1LL<<i))
            msb=i;
    }

}

bool dfs( int src, int par)
{
    m[a[src-1]]++;
    bool ok=0;
    for(auto i: v[src])
    {
        if(i^par)
        {
            ok|=dfs(i,src);
        }
    }
    if(v[src].size()==1 && v[src][0]==par)
    {
        //this is a leaf node
        
        assert(m.size()>0);
        auto big=m.rbegin();
        auto small=m.begin();
        if(big->first > msb && (big->second)%2==0 )
            ok|=1;
        if(big->first==msb && (big->second)%2==1 )
            ok|=1;
        if(small->first > msb && m.size()!=1)
            ok|=1;
        if(small->first==msb)
            ok|=1;

        


    }
    m[a[src-1]]--;
    if(m.find(a[src-1])!=m.end() && m[a[src-1]]==0)
        m.erase(a[src-1]);
    return ok;


}


int main()
{ 
    quick;
    int t;
    cin>>t;
    
    while(t--)
    {
        cin>>n>>k;
        
        init();

        a= vector<int> (n);
        fab(0,n-1,i)
        {
            int x,y;
            cin>>x>>y;
            
            assert(x>0 && x<=n && y>0 && y<=n);
            v[x].pb(y);
            v[y].pb(x);

        }

        fab(0,n,i)
        {   cin>>a[i];
            a[i]--;
            
            assert(a[i]<64 );
            assert(a[i]>=0);
        }
        findmsb();
        
        bool ok=dfs(1,-1);
        cout<<(ok?"YES":"NO")<<endl;
    }


 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}