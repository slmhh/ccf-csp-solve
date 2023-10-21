#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10,B = 30;

ll nums[300];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m,l,t;
    cin >> n >> m >> l;
    for(int i = 0;i < n;i++){
        for(int j  = 0;j < m;j++){
            cin >> t;
            nums[t]++;
        }
    }
    for(int i = 0;i < l;i++) cout << nums[i] << " ";
    return 0;
}