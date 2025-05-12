#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=2e5+10;
int main(){
    ll n, x, ans = 0, cur = 0;
    cin >> n >> x;
    ll arr[n];
    for(int i = 0; i < n; i++)cin>>arr[i];
    for(int i = 0,j = 0; i < n, j < n; i++){
        cur+=arr[i];
        if(cur == x) ans++;
        while(cur > x){
            cur-=arr[j];
            if(cur == x)ans++;
            j++;
        }
    }
    cout<<ans;
}