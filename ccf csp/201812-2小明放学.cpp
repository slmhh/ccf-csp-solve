#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 2e5 + 10;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll w[4],n;
    cin >> w[1] >> w[2] >> w[3] >> n;
    ll cnt = 0;
    w[0] = 0,w[1] += w[2],w[3] += w[1]; 
    for(int i = 1;i <= n;i++){
        ll op,t;
        cin >> op >> t;
        if(op == 0) cnt += t;
        else{
            ll temp = (cnt + w[op] - t) % w[3];
            cnt += max(w[1] - temp,0LL);
        }
    }
    cout << cnt << "\n";
    return 0;
}