#include<iostream>
#include<climits>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int dp[10050];
    for(int i = 0 ; i < 10050 ; i++)dp[i] = INT_MAX;
    int data[10050];
    for(int i = 0 ; i < n ; i++){
        cin >> data[i];
    }
    dp[0] = data[0];
    for(int i = 1 ; i < n ; i++){
        if(i <= k) dp[i] = data[i];
        else{
            int pos = i-(k*2+1);
            if(pos < 0) pos = 0;
            for(int j = pos ; j < i ; j++){
                dp[i] = min(dp[i],data[i] + dp[j]);
            }
        }
    }
    int posx = max(0,n-k-1);
    int ans = INT_MAX;
    for(int i = posx ; posx < n ;posx++ ) ans = min(ans,dp[posx]);
    cout << ans;
}
