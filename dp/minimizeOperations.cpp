#include<iostream>

using namespace std;


int minOperations(int n){
    int *dp = (int*)malloc((n+1) * sizeof(int));
    dp[1] = 0;

    for(int i=2; i<n+1; i++){
    
        dp[i] = INT_MAX;
    
      if(i%2 == 0){
        int x = dp[i/2];
     
        if(x + 1 < dp[i])
            dp[i] = x + 1;
        }
        
       if(i%3 == 0){
            int x = dp[i/3];
            if(x + 1 < dp[i])
                dp[i] = x + 1;
        }

        int x = dp[i-1];
        if(x + 1 < dp[i])
            dp[i] = x + 1;
    }

    return dp[n];

}


int main(){
    int n = 15;
    cout << minOperations(n) << endl;
    return 0;
}