#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int soto[n];
    int x;
    for(int i = 0 ; i<n ; i++){
        scanf("%d",&x);
        arr[i]=x;
        soto[i]=x;
    }
    sort(arr,arr + n);
    int d[4][4];
    for(int i = 0 ; i < 4 ; i++)for(int j=0;j<4;j++)d[i][j]=0;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] != soto[i]) d[arr[i]][soto[i]]++;
    }
    int sum = 0 , ans = 0;
    /*for(int i = 1 ; i< 4 ; i++){
        for(int j = 1 ; j < 4 ; j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }*/
    for(int i = 1 ; i < 4 ; i++){
        for(int j = 1 ; j < 4 ; j++){
            if(d[i][j] > 0){
                x = min(d[i][j],d[j][i]);
                sum += d[i][j]-x;
                ans += x;
                d[i][j]-=x; d[j][i]-=x;
            }
        }
    }
    //cout << ans << " " << sum << endl;
    ans += (sum/3)*2;
    cout << ans;
}
