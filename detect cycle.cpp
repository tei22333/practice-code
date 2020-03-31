#include<bits/stdc++.h>

using namespace std;

vector<int> vec[1005];
int arr[1005];
bool cy;
void dfs(int v,int p){
    arr[v] = 1;
    for(int c : vec[v]){
        if(arr[c] == 1 && c != p){
            cy = true;
            return;
        }
        else if(arr[c] == -1){
            dfs(c,v);
        }
    }

}
void test(){
    int n,e,x,y;
    for(int i = 0 ; i <= n ; i++) vec[i].clear();
    scanf("%d%d",&n,&e);
    for(int i = 0 ;i < e ; i++){
        scanf("%d%d",&x,&y);
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    cy = false;
    for(int j = 0 ; j < 1005 ; j++) arr[j] = -1;
    for(int i = 0 ; i <= n ;i++ ){
        if(arr[i] == -1){
            dfs(i,-1);
        }
        if(cy) break;
    }
    if(cy) printf("YES\n");
    else printf("NO\n");
}
int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0 ; i < t ; i++){
        test();
    }
}
