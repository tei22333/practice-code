#include<iostream>
#include<climits>
using namespace std;
int dp[105][105];
int mid[105][105];
int num[105];
int recur(int left , int right){
    if(left == right){
        return 0;
    }
    if(dp[left][right] != -1){
        return dp[left][right];
    }
    if(right - left == 1){
        return dp[left][right] = mid[left][right] * num[left] * num[right+1];
    }
    int mini = INT_MAX;
    for(int i = left ; i < right ;i++){
        if(recur(left,i)+recur(i+1,right)+(num[left]*num[right+1]*mid[i][i+1]) < mini){
            mini = recur(left,i)+recur(i+1,right)+(num[left]*num[right+1]*mid[i][i+1]);
        }
    }
    return dp[left][right] = mini;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0 ; i < 105 ; i++){
            for(int j = 0 ; j < 105 ; j++) {
                    mid[i][j] = 0;
                    dp[i][j] = -1;
                    num[i] = 0;
            }
    }
    int n,x;
    cin >> n;
    for(int i = 0 ; i<n+1 ;i++){
        cin >> x;
        num[i] = x;
        if(i > 0) mid[i-1][i] = x;
    }
    //cout << recur[0][n-1];
    int ans = recur(0,n-1);
    cout << ans;
    //cout << recur(0,0) + recur(1,2) + (num[0]*num[3]*mid[0][1]) << endl;
    /*for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << dp[i][j] << " " ;
        }
        cout << endl;
    }*/
}
