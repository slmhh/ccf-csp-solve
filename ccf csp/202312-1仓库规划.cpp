#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 2e5 + 10;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> a(n + 1,vector<ll>(m + 1));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1;i <= n;i++){
        ll ans = 0;
        for(int j = 1;j <= n;j++){
            if(i == j) continue;
            bool flag = true;
            int k;
            for(k = 1;k <= m;k++){
                if(a[i][k] >= a[j][k]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans = j;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}   