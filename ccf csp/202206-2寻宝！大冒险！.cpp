#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
const int N = 3e5 + 10;

map<PII,int> a;
ll s[110][110];
vector<PII> nums;
int main(){
     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
     ll n,L,S,x,y,cnt = 0;
     cin >> n >> L >> S;
     for(int i = 0;i < n;i++){
          cin >> x >> y;
          nums.push_back({x,y});
          a[{x,y}]++;
     }
     for(int i = S;i >= 0;i--){
          for(int j = 0;j <= S;j++){
               cin >> s[i][j];
          }
     }
     bool flag = true;
     for(auto p : nums){
          x = p.first,y = p.second;
          if(x + S >= L + 1 || y + S >= L + 1) continue;
          flag = true;
          for(ll i = 0;i <= S;i++){
               for(ll j = 0;j <= S;j++){
                    if((s[i][j] == 1 && !a[{x + i,y + j}]) || (s[i][j] == 0 && a[{x + i,y + j}])){
                         flag = false;
                         break;
                    }
               }
               if(!flag) break;
          }
          if(flag) cnt++;
     }
     cout << cnt << "\n";
     return 0; 
}