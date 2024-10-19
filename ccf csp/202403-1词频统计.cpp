#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 110;
bool st2[N];
ll cnt[N],cnt2[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m,t,x;
	bool flag;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> t;
		flag = false;
		for(int j = 0;j < t;j++){
			cin >> x;
			cnt[x]++;
			if(!st2[x]) cnt2[x]++;
			st2[x] = true;
		}
		for(int j = 0;j <= 100;j++) st2[j] = false;
	}
	for(int i = 1;i <= m;i++){
		cout << cnt2[i] << " " << cnt[i] << "\n";
	}
	return 0;
}

/*
4 3
5 1 2 3 2 1
1 1
3 2 2 2
2 3 2
*/