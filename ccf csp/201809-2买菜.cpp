#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 1e6 + 10;

ll times[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m = 0;
    cin >> n;
    for(int i = 1;i <= 2 * n;i++){
        ll s,t;
        cin >> s >> t;
        m = max(m,t);
        times[s]++;
        times[t]--;
    }
    ll cnt = 0,pre = 0;
    for(int i = 1;i <= m;i++){
        pre += times[i];
        if(pre == 2){
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}