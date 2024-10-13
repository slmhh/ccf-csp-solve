#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 2e3 + 10;

vector<ll> edge[N],w,siz,wd;
ll n,m,sum = 0;
unordered_set<ll> del;

void dfs(ll p){
    siz[p] = 1;
    wd[p] = w[p];
    sum += w[p];
    for(auto i : edge[p]){
        if(del.count(i)) continue;
        dfs(i);
        wd[p] += wd[i];
        siz[p] += siz[i];
    }
}

bool find(ll x,ll p){
    if(p == x) return true;
    for(auto i : edge[p]){
        if(del.count(i)) continue;
        if(find(x,i)) return true;
    }
    return false;
}

void query(ll x){
    del.clear();
    ll cnt = n,root = 1;
    while(cnt != 1){
        sum = 0;
        for(int i = 1;i <= n;i++){
            wd[i] = -1;
            siz[i] = 0;
        }
        dfs(root);
        ll mi = 1e15,idx = -1;
        for(int i = 1;i <= n;i++){
            if(wd[i] != -1 && abs(sum - 2 * wd[i]) < mi){
                mi = abs(sum - 2 * wd[i]);
                idx = i;
            }
        }
        cout << idx << " ";
        if(find(x,idx)){
            root = idx;
            cnt = siz[idx];
        }
        else{
            del.insert(idx);
            cnt -= siz[idx];
        }
    }
    cout << "\n";
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    w.resize(n + 1,0);
    siz.resize(n + 1,0);
    wd.resize(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> w[i];
    }
    for(int i = 1;i <= n - 1;i++){
        ll p;
        cin >> p;
        edge[p].push_back(i + 1);
    }
    while(m--){
        ll x;
        cin >> x;
        query(x);
    }
    return 0;
}   