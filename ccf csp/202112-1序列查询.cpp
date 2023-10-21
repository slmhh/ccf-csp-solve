#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e3 + 10,B = 30;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,x,t,s,sum = 0;
    cin >> n >> x;
    t = 0;
    for(int i = 1;i <= n;i++){
        cin >> s;
        sum += (s - t) * (i - 1);
        t = s;
    }
    sum += (x - t) * n;
    cout << sum << "\n";
    return 0;
}