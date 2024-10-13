#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 7e3 + 10;

ll nums[505][505];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n;
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> nums[i][j];
        }
    }
    ll i = 0,j  = 0;
    cout << nums[i][j] << " ";
    for(int k = 0;k < n - 1;k++){
        if(k & 1) i++;
        else j++;
        cout << nums[i][j] << " ";
        for(int l = 0;l <= k;l++){
            if(k & 1) i--,j++;
            else i++,j--;
            cout << nums[i][j] << " ";
        }
    }
    for(int k = n - 2;k >= 0;k--){
        if(k & 1) i++;
        else j++;
        cout << nums[i][j] << " ";
        for(int l = 0;l < k;l++){
            if(k & 1) i++,j--;
            else i--,j++;
            cout << nums[i][j] << " ";
        }
    }
    return 0; 
}