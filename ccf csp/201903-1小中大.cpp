#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++){
        cin >> nums[i];
    }
    int a = nums[0],b = nums[n - 1],c;
    if(a < b){
        int temp = a;
        a = b;
        b = temp;
    }
    int i = n / 2;
    if(n & 1){
        printf("%d %d %d",a,nums[i],b);
    }
    else{
        c = nums[i] + nums[i - 1];
        if(c & 1) printf("%d %.1f %d",a,c / 2.0,b);
        else printf("%d %d %d",a,c / 2,b);
    }
    return 0;
}