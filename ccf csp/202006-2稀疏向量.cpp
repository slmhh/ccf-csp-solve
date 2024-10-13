#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 1e6 + 10;

map<ll,ll> m;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,x,y,a,b,ans = 0;
    cin >> n >> a >> b;
    for(int i = 0;i < a;i++){
        cin >> x >> y;
        m[x] = y;
    }
    for(int i = 0;i < b;i++){
        cin >> x >> y;
        ans += m[x] * y;
    }
    cout << ans << "\n";
    return 0; 
}