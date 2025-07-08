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
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x:v) cin >> x;  
    vector<int> rev(v);
    reverse(rev.begin(),rev.end());
    if(rev == v){
        cout << "YES\n";
        return;
    }
    vector<int> tmp(v);
    sort(tmp.begin(),tmp.end());
    vector<int> palin;
    for(int i = 0; i < n; i++){
        if(v[i] <= tmp[k-1]) palin.pb(v[i]);
    }
    vector<int> vv(palin);
    reverse(vv.begin(),vv.end());
    if(vv == palin) {
        cout << "YES\n";
        return;
    } 
    int j = palin.size()-1, i = 0;
    int cnt = 0;
    while(i < j && i < n && j >= 0) {
        //cout << i << "\n";
        if(palin[i] != palin[j]){
            if(palin[i] == tmp[k-1]) {
                cnt++;
                i++;
            }
            else if(palin[j] == tmp[k-1]){
                j--;
                cnt++;
            }
            else {
                cout << "NO\n";
                return;
            }
        }
        else {
            i++;
            j--;
        }
    }
    if(palin.size()-cnt >= k-1){
        cout << "YES\n";
    }
    else cout << "NO\n";

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}