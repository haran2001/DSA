// https://www.codechef.com/problems/ICM0006
      #include "test.h"
        using namespace std;
        #define ll long long int
        #define pb push_back
        int cnt[100001][26];
        int ct[100001];
        int main(){
          int T=1;
          cin>>T;
          while(T--){
            ll n,k;
            cin>>n>>k;
            string s;
            cin>>s;
            ll len=s.size();
            vector<ll> div;
            for(ll i=1;i*i<=len;i++){
                if(len%i==0){
                    div.pb(i);
                    if(i*i!=len){
                        div.pb(len/i);
                    }
                }
            }
            ll ans=1e15;
            for(auto x:div){
              if(x*n-x+1<k)continue;
              int m=len/x;
              for(int i=0;i<m;i++){
                ct[i]=0;
                for(int j=0;j<26;j++){
                  cnt[i][j]=0;
                }
              }
              for(int i=0;s[i];i++){
                cnt[i%m][(s[i]-'a')]++;
                ct[i%m]=max(ct[i%m],cnt[i%m][(s[i]-'a')]);
              }
              ll count=0;
              for(int i=0;i<m;i++){
                count+=(x-ct[i]);
              }
              ans=min(ans,count);
        }
      cout<<ans<<"\n";
      }
     
      return 0;
    }