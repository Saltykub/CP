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
    int n;
    cin >> n;
    n*=2;
    vector<int> arr(n);
    multiset<ll> s;
    for(int i = 0; i < n; i++) {cin >> arr[i]; s.insert(arr[i]);}
    sort(arr.begin(),arr.end());
    vector<pii> ans;
    auto mx = s.find(arr[n-1]);
    s.erase(mx);
    for(int i = 0; i < n-1; i++){
        ans.clear();
        multiset<ll> temp;
        temp = s;
        auto it = temp.find(arr[i]);
        temp.erase(it);
        ans.pb({arr[n-1],arr[i]});
        int cur = arr[n-1];
        for(int j = 0; j < (n-2)/2; j++){
            auto idxa = temp.end();
            idxa--;
            int a = *idxa;
            temp.erase(idxa);
            int b = cur-a;
            auto idxb = temp.find(b);
            if(idxb == temp.end()) break;
            ans.pb({a,b});
            cur = a;
            temp.erase(idxb);
        }
        if(temp.empty()){
            cout << "YES\n";
            cout << ans[0].st + ans[0].nd << "\n";
            for(auto u:ans) cout << u.st << " " << u.nd << "\n";
            return;
        }
    }
    cout << "NO\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}