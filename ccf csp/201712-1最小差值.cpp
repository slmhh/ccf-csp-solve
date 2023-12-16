#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,ans = 1001000;;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++){
        cin >> nums[i];
    }
    sort(nums.begin(),nums.end());
    for(int i = 1;i < n;i++){
        ans = min(ans,abs(nums[i] - nums[i - 1]));
    }
    cout << ans << "\n";
    return 0;
}