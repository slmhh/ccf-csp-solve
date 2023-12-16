#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n),ans(n);
    for(int i = 0;i < n;i++) cin >> nums[i];
    ans[0] = (nums[0] + nums[1]) / 2;
    ans[n - 1] = (nums[n - 2] + nums[n - 1]) / 2;
    for(int i = 1;i < n - 1;i++){
        ans[i] = (nums[i] + nums[i - 1] + nums[i + 1]) / 3;
    }
    for(auto i : ans) cout << i << " ";
    return 0;
}