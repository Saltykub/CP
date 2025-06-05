#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    int n,d;
    cin >> n >> d;
    vector<int> arr(1e6+1,0);
    while(n--){
        int x;
        cin >> x;
        arr[x]++;
    }
    vector<int> good(1e6+1,0);
    vector<pii> cnt;
    for(int i = 0; i <= 1e6; i++){
        int mi = 0;
        if(i-d >= 0){
            mi += arr[i-d];
        }
        if(i + d <= 1e6){
            mi += arr[i+d];
        }
        cnt.pb({arr[d]-mi,i});
    }
    sort(cnt.begin(),cnt.end(),[&](pii a, pii b){
        if(a.st == b.st){
            return arr[a.nd] < arr[b.nd];
        }
        return a.st < b.st;
    });
    int ans = 0;
    for(auto [val,i]:cnt){
        if(arr[i] == 0) continue;
        bool cl =  false,cr = false;
        if(i - d >= 0){
            if(arr[i-d] == 0) cl = true;
        }
        else {
            cl = true;
        }
        if(i + d <= 0){
            if(arr[i+d] == 0) cr = true;
        }
        else {
            cr = true;
        }
        if(cl & cr) continue;
        cout << i << " ";
        ans+=arr[i];
        arr[i] = 0;
       
    }
    cout << ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}