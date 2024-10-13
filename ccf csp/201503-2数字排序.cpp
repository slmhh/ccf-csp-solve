#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 3e5 + 10,mod = 998244353;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,t;
    cin >> n;
    vector<PII> a;
    vector<ll> cnt(1001,0);
    for(int i = 1;i <= n;i++){
        cin >> t;
        cnt[t]++;
    }
    for(int i = 0;i <= 1000;i++){
        if(cnt[i] != 0){
            a.push_back({-cnt[i],i});
        }
    }
    sort(a.begin(),a.end());
    for(int i = 0;i < a.size();i++){
        cout << a[i].second << " " << -a[i].first << "\n";
    }
    return 0; 
}