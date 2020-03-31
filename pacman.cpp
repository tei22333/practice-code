#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int arr[105][105];
int mini[105][105];
int poc[105][105];
bool ans;
struct node{
    int x,y,z;
};
void dfs(int left ,int x, int y){
    if(arr[x][y] == -1) return ;
    arr[x][y] = -2;
    if(left == 0) return;
    if(left <= mini[x][y]) return;
    mini[x][y] = left;
    dfs(left-1 , x+1 , y);
    dfs(left-1 , x , y+1);
    dfs(left-1 , x-1 , y);
    dfs(left-1 , x , y-1);
}
void dfspoc(int left , int x , int y){
    if(arr[x][y] == -1) return ;
    if(arr[x][y] == 1){
        ans = true;
    }
    if(left == 0) return;
    if(left <= mini[x][y]) return;
    mini[x][y] = left;
    dfspoc(left-1 , x+1 , y);
    dfspoc(left-1 , x , y+1);
    dfspoc(left-1 , x-1 , y);
    dfspoc(left-1 , x , y-1);
}
bool possible(){
    int R,C,n,T,r,c;
    scanf("%d%d%d%d%d%d",&R,&C,&n,&T,&r,&c);
    int x,y,z;
    node data[n];
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d%d",&x,&y,&z);
        node temp = {x,y,z};
        data[i] = temp;
    }
    char s[1005];
    for(int i = 1 ; i <= R ; i++){
        scanf("%s",s);
        for(int j = 0 ; j < C ; j++){
            if(s[j] == '.') arr[i][j+1] = 1;
            mini[i][j+1] = -10000000;
            poc[i][j+1] = -10000000;
        }
    }
    for(int i = 0 ; i < n ; i++){
        dfs(T - data[i].x , data[i].y+1 , data[i].z +1);
    }
    ans = false;
    dfspoc(T , r+1,c+1);
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0 ; i < t; i++){
        for(int j = 0 ; j < 105 ; j++) for(int k = 0 ; k < 105 ; k++) arr[j][k] = -1;
        possible();
    }
}
