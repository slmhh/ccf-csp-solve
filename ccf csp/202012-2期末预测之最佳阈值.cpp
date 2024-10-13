#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        ll n,m,k,cost = 0,t,las;
        cin >> n >> m >> k;
        vector<ll> a(k + 1);
        for(int i = 1;i <= k;i++){
            cin >> a[i];
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                cin >> t;
                las = t;
                for(int l = 1;l <= k;l++){
                    if(a[l] != t) swap(a[l],las);
                    else{
                        swap(a[l],las);
                        cost += l;
                        break;
                    }
                }
            }
        }
        cout << cost << "\n";
    }
    return 0; 
}