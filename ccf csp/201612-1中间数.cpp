#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> nums;
    for(int i = 0;i < n;i++){
        ll t;
        cin >> t;
        nums.push_back(t);
    }
    sort(nums.begin(),nums.end());
    ll temp = nums[n / 2],cnt1 = 0,cnt2 = 0,i = 0;
    while(nums[i] < temp) cnt1++,i++;
    i = n - 1;
    while(nums[i] > temp) cnt2++,i--;
    if(cnt1 == cnt2) cout << temp << "\n";
    else cout << "-1\n";
    return 0;
}