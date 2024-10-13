#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> a(n + 1,vector<ll>(m + 1)),res(n + 1,vector<ll>(m + 1));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a[i][j];
            res[i][j] = a[i][j];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            ll cnt = 1,tj = j;
            while(tj + 1 <= m && a[i][tj] == a[i][tj + 1]){
                cnt++;
                tj++;
            }
            if(cnt >= 3){
                res[i][j] = 0;
                while(j + 1 <= m && a[i][j] == a[i][j + 1]){
                    res[i][j + 1] = 0;
                    j++;
                }
            }
        }
    }
    for(int j = 1;j <= m;j++){
        for(int i = 1;i <= n;i++){
            ll cnt = 1,ti = i;
            while(ti + 1 <= n && a[ti][j] == a[ti + 1][j]){
                cnt++;
                ti++;
            }
            if(cnt >= 3){
                res[i][j] = 0;
                while(i + 1 <= n && a[i][j] == a[i + 1][j]){
                    res[i + 1][j] = 0;
                    i++;
                }
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}