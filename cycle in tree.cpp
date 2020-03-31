#include<bits/stdc++.h>

using namespace std;
vector<int> vec[100050];
int arr[100050];
int ans;
void dfs(int v, int p ,int dist){
    arr[v] = dist;
    for(int c : vec[v]){
        if(arr[c] != -1 && c != p) ans = abs(dist - arr[c]) +1;
        if(arr[c] == -1){
            dfs(c,v,dist+1);
        }
    }
}
int main(){
    int n,x,y;
    scanf("%d",&n);
    for(int i =1 ; i <= n ; i++){
        scanf("%d%d",&x,&y);
        vec[x].push_back(y);
        vec[y].push_back(x);
        arr[i] = -1;
    }
    dfs(0,-1,0);
    printf("%d",ans);
}
