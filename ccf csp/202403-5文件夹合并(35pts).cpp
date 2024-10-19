#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 5e5 + 10;

ll fa[N],w[N],h[N],n,m,op,x;
bool st[N];
void dfs(int p){
	if(st[p]) return;
	st[p] = true;
	dfs(fa[p]);
	h[p] = h[fa[p]] + 1;
	
}

void merge(ll x){
	ll sum = w[x],cnt = 0;
	set<ll> s;
	for(int i = 2;i <= n;i++){
		if(fa[i] == x){
			w[x] += w[i];
			fa[i] = 0;
			s.insert(i);
		}
	}
	for(int i = 1;i <= n;i++){
		if(s.count(fa[i])){
			cnt++;
			fa[i] = x;
		}
	}
	cout << cnt << " " << w[x] << "\n"; 
	return;
}


int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 2;i <= n;i++) cin >> fa[i];
	for(int i = 1;i <= n;i++) cin >> w[i];
	h[1] = 1;
	st[1] = true;
//	for(int i = 2;i <= n;i++){
//		s[fa[i]].insert(i);
//	}
	for(int i = 2;i <= n;i++){
		dfs(i);
	}
	while(m--){
		cin >> op >> x;
		if(op == 1){
			merge(x);
		}
		if(op == 2){
			if(n <= 1e4){
				memset(st,false,sizeof(st));
				st[1] = true;
				h[1] = 1;
				
//				cout << "fa[4] = " << h[1] << "\n";
				dfs(x);
			}
			cout << h[x] << "\n";
		}
	}
	return 0;
}

/*
4 6
1 1 3
100 0 200 300
2 1
2 4
1 1
2 4
1 1
1 1
*/