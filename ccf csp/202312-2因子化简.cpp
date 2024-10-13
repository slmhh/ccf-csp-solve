#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 2e5 + 10;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        ll x,k,ans = 1;
        cin >> x >> k;
        for(int i = 2;i * i <= x;i++){
            if(x % i == 0){
                ll cnt = 0,temp = 1;
                while(x % i == 0){
                    cnt++;
                    x /= i;
                    temp *= i;
                }
                if(cnt >= k) ans *= temp;
            }
        }
        if(x != 1 && k == 1) ans *= x;
        cout << ans << "\n";
    }
    return 0;
}   