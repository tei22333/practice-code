#include<iostream>

using namespace std;
int data[10050];
int test(int n){
    int max_value[10050] = {0};
    for(int i = 1 ; i <= n ; i++){
        if(i <= 2){
            max_value[i] = max(max_value[i-1],data[i]);
        }
        else{
            max_value[i] = max(max_value[i-2] + data[i] , max_value[i-1]);
        }
    }
    return max_value[n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    data[0] = 0;
    for(int i = 1 ; i <= n ; i++){
        cin >> data[i];
    }
    int ans = test(n);
    cout << ans;
}
