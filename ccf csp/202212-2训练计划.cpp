#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

ll nums[110],pre[110],early[110],late[110];
int main(){
     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
     ll n,m,en = 1;
     cin >> n >> m;
     for(int i = 1;i <= m;i++) cin >> pre[i];
     for(int i = 1;i <= m;i++) cin >> nums[i];
     for(int i = 1;i <= m;i++){
          late[i] = n;
          if(pre[i] == 0) early[i] = 1;
          else{
               ll p = pre[i];
               early[i] = early[p] + nums[p];
          }
          en = max(en,early[i] + nums[i]);
     }
     for(int i = 1;i <= m;i++) cout << early[i] << " ";
     cout << "\n";
     if(en <= n + 1){
          for(int i = m;i >= 1;i--){
               late[i] = min(late[i],n + 1 - nums[i]);
               if(pre[i] != 0){
                    ll p = pre[i];
                    late[p] = min(late[p],late[i] - nums[p]);
               }
          }
          for(int i = 1;i <= m;i++) cout << late[i] << " ";
     }
     return 0; 
}