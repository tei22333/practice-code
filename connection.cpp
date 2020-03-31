#include<bits/stdc++.h>

using namespace std;
vector<int> vec[1005];
int arr[1005];
int counti = 0;
void dfs(int left , int v){
    if(arr[v] == -10)counti++;
    arr[v] = left;
    if(left == 0)return;
    for(int i : vec[v]){
        if(arr[i] < left-1){
            dfs(left-1,i);
        }
    }
}
int main(){
    int n,e,k,x,y;
    scanf("%d%d%d",&n,&e,&k);
    for(int i = 0 ; i < e ; i++){
        scanf("%d%d",&x,&y);
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    int ans = -999999;
    for(int i = 0 ; i <= n ; i++){
        counti = 0;
        for(int j = 0 ; j <= n ; j++)arr[j] = -10;
        dfs(k,i);
        ans = max(ans,counti);
    }
    cout << ans;
    /*for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j< vec[i].size() ; j++) cout << vec[i][j] << " ";
        cout << endl;
    }*/

}
