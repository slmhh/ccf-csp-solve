#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10,B = 30;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll sum = 0,n;
    cin >> n;
    while(n--){
        ll a,b;
        cin >> a >> b;
        sum += a * b;
    }
    cout << max(0LL,sum) << "\n";
    return 0;
}