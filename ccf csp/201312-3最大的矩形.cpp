#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
   int n,ans = 0;
   cin >> n;
   vector<int> nums(n);
   for(int i= 0;i < n;i++){
        cin >> nums[i];
   }
   for(int i = 0;i < n;i++){
        int l = i,r = i;
        while(l >= 0 && nums[l] >= nums[i]) l--;
        while(r < n && nums[r] >= nums[i]) r++;
        ans = max(ans,(r - l - 1) * nums[i]);
        //cout << nums[i] << " " << r - l  << "\n";
   }
   cout << ans << "\n";
    return 0;
}