#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int arr[4];
    for(int i = 0; i < 4; i++) cin >> arr[i];
    int ans1 = 1, ans2 = 1;
    if(arr[0]+2*arr[1] == arr[2]) ans1++;
    if(arr[0] + arr[1] + arr[2] == arr[3]) ans1++;
    if(arr[2] + arr[2]-arr[1] == arr[3]) ans2++;
    cout << max(ans1,ans2) << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}