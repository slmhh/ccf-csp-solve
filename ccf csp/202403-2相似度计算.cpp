#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e4 + 10;
set<string> cnt1,cnt2,cnt3;
string change(string str){
	for(int i = 0;i < str.size();i++){
		str[i] = char(str[i] | 32); 
	}
	// cout << str << "\n";
	return str;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n,m,ans = 0;
	string str;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> str;
		str = change(str);
		cnt1.insert(str);
		cnt2.insert(str);
	}
	for(int i = 0;i < m;i++){
		cin >> str;
		str = change(str);
		cnt2.insert(str);
		if(cnt1.count(str) && cnt3.count(str) == 0){
			ans++;
		}
		cnt3.insert(str);
	}
	cout << ans << "\n" << cnt2.size() << "\n";
	return 0;
}

/*
3 2
The tHe thE
the THE
*/