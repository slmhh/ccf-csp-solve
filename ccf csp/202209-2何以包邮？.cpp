#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3e5 + 10;

//01背包
ll bag[N],book[35];
int main(){
     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
     ll n,m,sum = 0;
     cin >> n >> m;
     for(int i = 0;i < n;i++){
          cin >> book[i];
          sum += book[i];
     }
     for(int i = 1;i <= sum;i++) bag[i] = -1e18;
     for(int i = 0;i < n;i++)
          for(int j = sum;j >= book[i];j--)
               bag[j] = max(bag[j],bag[j - book[i]] + 1);
     
     ll ans = n;
     for(int i = m;i <= sum;i++){
          if(bag[i] >= 0){
               ans = i;
               break;
          }
     }
     cout << ans << "\n";
     return 0; 
}