#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 5e5 + 10;
map<ll,ll> w;
map<ll,PII> idx;
vector<ll> temp;
ll c,m,q,x,y,cnt,t,last;

void insert(ll l,ll p){
	idx[p].first = l;
	idx[p].second = idx[l].second;
	idx[idx[l].second].first = p;
	idx[l].second = p;
}

void del(ll p){
	idx[idx[p].first].second = idx[p].second;
	idx[idx[p].second].first = idx[p].first; 
}

void didida(int x){
	w[x]++;
	ll l = idx[x].first,r =idx[x].second,resr = 0,resl = 0,slm;
	if(w[x] >= 5){
		w[x] = 0;
		cnt--;
		resr++;
		resl++;
		del(x);
	}
	while((resr > 0 || resl > 0) && (l >= 1 || r <= c)){
		while(l >= 1 && resl > 0){
			w[l] += resl;
			resl = 0;
			if(w[l] >= 5){
				w[l] = 0;
				resl++;
				resr++;
				cnt--;
				slm = idx[l].first;
				del(l);
				l = slm;
			}
		}
		if(l < 1) resl = 0;
		if(r <= c && resr > 0){
			w[r] += resr;
			resr = 0;
			if(w[r] >= 5){
				w[r] = 0;
				resl++;
				resr++;
				cnt--;
				slm = idx[r].second;
				del(r);
				r = slm;
			}
		}
		else if(r > c) resr = 0;
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> m >> q;
	idx[0] = make_pair(-1,c + 1);
	idx[c + 1] = make_pair(0,c + 2);
	last = 0;
	for(int i = 0;i < m;i++){
		cin >> x >> y;
		w[x] = y;
		temp.push_back(x);
	}
	
	sort(temp.begin(),temp.end());
	for(int i = 0;i < temp.size();i++){
		insert(last,temp[i]);
		last = temp[i];
	}
	
	cnt = m;
	
	while(q--){
		cin >> t;
		didida(t);
		cout << cnt << "\n";
	}
	return 0;
}

/*
5 5 2
1 2
2 4
3 4
4 4
5 2
3
1
*/