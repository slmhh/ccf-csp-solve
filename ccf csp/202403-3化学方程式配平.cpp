#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 110 + 10;
const double eps = 1e-4;
double nums[N][N],w;
ll cnt = 0,n,sum,sfg;
string str,temp;
map<string,ll> m;

void guss(ll s,ll c){
	if(s > cnt || c >= n) return;
	if(s == cnt && c == n - 1) return;
	ll idx = 0;
	if(nums[s][c] == 0){
		for(int i = s + 1;i <= cnt;i++){
			if(nums[i][c] > eps || nums[i][c] < -eps){
				idx = i;
				break;
			}
		}
		if(idx == 0){
			guss(s + 1,c);
			return;
		}
		for(int i = 0;i < n;i++){
			w = nums[s][i];
			nums[s][i] = nums[idx][i];
			nums[idx][i] = w;
		}
	}
	for(int i = s + 1;i <= cnt;i++){
		double slm = -nums[i][c] / nums[s][c];
		nums[i][c] = 0;
		for(int j = c + 1;j < n;j++){
			nums[i][j] += slm * nums[s][j];
		}
	}
	guss(s + 1,c + 1);
	return;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll T;
	cin >> T;
	while(T--){
		m.clear();
		cnt = 0;
		cin >> n;
		
		//输入矩阵 
		for(int j = 0;j < n;j++){
			cin >> str;
			temp = "";
			for(int k = 0;k < str.size();k++){
				sfg = 0;
				if(str[k] >= '0' && str[k] <= '9'){
					while(k < str.size() && (str[k] >= '0' && str[k] <= '9')) sfg = sfg * 10 + (str[k] - '0'),k++;
					k--;
					if(!m[temp]) m[temp] = ++cnt;
					nums[m[temp]][j] = sfg;
					temp = "";
				}
				else temp += str[k];
			}
		}
		
//		for(int i = 1;i <= cnt;i++){
//			for(int j = 0;j < n;j++){
//				cout<< nums[i][j] << " ";
//			}
//			cout << "\n";
//		}
		
		
		guss(1,0);
		
	
		sum = 0;
		bool flag;
		for(int i = 1;i <= cnt;i++){
			flag = false;
			for(int j = 0;j < n;j++){
				if(nums[i][j] > eps || nums[i][j] < -eps){
					flag = true;
					break;
				}
			}
			if(flag) sum++;
		}
//		for(int i = 1;i <= cnt;i++){
//			for(int j = 0;j < n;j++){
//				cout<< nums[i][j] << " ";
//			}
//			cout << "\n";
//		}
//		cout << sum <<"\n";
		if(sum < n) cout << "Y\n";
		else cout << "N\n";
//		cout << "\n";
		
		for(int i = 1;i <= cnt;i++){
			for(int j = 0;j < n;j++){
				nums[i][j] = 0;
			}
		}
	}
	return 0;
}
/*
6
2 o2 o3
3 c1o1 c1o2 o2
2 n2o4 n1o2
4 cu1 h1n1o3 cu1n2o6 h2o1
4 al2s3o12 n1h5o1 al1o3h3 n2h8s1o4
4 c1o1 c1o2 o2 h2o1
*/


