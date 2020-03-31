#include<stdio.h>
#include<iostream>
#include<climits>
using namespace std;
int data[12];
int dp[12][10050];
int x;
int it_h = false;
int recur(int n,int m){
    if(m < 0) return 1000000;
    if(n == x && m != 0) return 1000000;
    if(n == x && m == 0){
        it_h = true;
        return 0;
    }
    //wrong place!
    if(dp[n][m] != -1) return dp[n][m];
    //
    int ans = 1000000;
    for(int i = 1 ; i <= 100 ; i ++){
        ans = min((data[n] - i)*(data[n]-i) + recur(n+1,m-(i*i)) , ans);
        //cout << (data[n] - i)*(data[n]-i) << endl;
    }
    return dp[n][m] = ans;
}
int main(){
    for(int i =0;i<12;i++)for(int j=0 ; j < 10050 ; j++)dp[i][j] = -1;
    int m;
    scanf("%d%d",&x,&m);
    for(int i = 0 ; i < x ; i++){
        scanf("%d",&data[i]);
    }
    int ans = recur(0,m);
    if(ans >= 1000000)cout << -1;
    else cout << ans;
}
