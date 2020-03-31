#include<bits/stdc++.h>

using namespace std;
int arr[105][105];
int cost[105][105];

struct poi{
    int x,y,val;
};
int main(){
    int r,c;
    scanf("%d%d",&r,&c);
    char ca[105];
    for(int i = 1 ; i <= r ; i++){
        scanf("%s",ca);
        for(int j = 0 ; j < c ; j++){
            cost[i][j+1] = 1000000;
            if(ca[j] == '.')arr[i][j+1] = 1;
            else arr[i][j+1] = 0;
        }
    }
    for(int i = 0 ; i <= r+1 ; i++)for(int j = 0 ; j <= c+1 ; j++)if(i == 0 || j == 0)arr[i][j]=0;
    queue<poi> q;
    q.push({r,c,0});
    //poi tem = q.front(); q.pop();
    while(!q.empty()){
        poi temp = q.front(); q.pop();
        //cout << temp.x << " "<<temp.y << endl;
        if(arr[temp.x][temp.y] == 0) continue;
        if(temp.val >= cost[temp.x][temp.y])continue;
        cost[temp.x][temp.y] = temp.val;
        q.push({temp.x+1 , temp.y , temp.val +1});
        q.push({temp.x , temp.y + 1 , temp.val +1});
        q.push({temp.x-1 , temp.y , temp.val +1});
        q.push({temp.x , temp.y-1 , temp.val +1});
    }

    if(cost[1][1] >= 1000000) printf("-1");
    else printf("%d",cost[1][1]);
}
