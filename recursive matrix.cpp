#include <iostream>
#include<stdio.h>
#include<climits>
#include<bits/stdc++.h>
//overflow if INT_MAX
using namespace std;
int met[300][300];
int data[1000050];
int dp[1000050];
void recur(int a , int b , int top , int bottom , int left , int right){
    if(a == 0){
        met[top][left] = b;
        return;
    }
    recur(a-1,b,top,(top+bottom+1)/2-1,left,(right+left+1)/2-1);
    recur(a-1,b-1,top,(top+bottom+1)/2-1,(right+left+1)/2,right);
    recur(a-1,b+1,(top+bottom+1)/2,bottom,left,(right+left+1)/2-1);
    recur(a-1,b,(top+bottom+1)/2,bottom,(right+left+1)/2,right);
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int x = pow(2,n);
    recur(n,m,0,x-1,0,x-1);
    for(int i = 0 ; i < x ;i++){
        for(int j = 0 ; j < x ; j++){
            printf("%d ",met[i][j]);
    }
    cout << endl;
    }


}
