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
    int n,q;
    cin >> n >> q;
    vector<int> box(n+1,0);
    while(q--){
        int x;
        cin >> x;
        if(x) {
            box[x]++;
            cout << x << " ";
        }
        else {
            int cur = INT_MAX;
            int idx = 0;
            for(int i = 1; i <= n; i++){
                if(cur > box[i]){
                    cur = box[i];
                    idx = i;
                }
            }
            box[idx]++;
            cout << idx << " ";
        }
    }
   // for(int i = 1; i <= n; i++) cout << box[i] << " ";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}