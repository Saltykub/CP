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
    int n;
    cin >> n;
    vector<double> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end());

    auto cal = [&](double d){
        ll cnt = 1;
        int k = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] > v[k] + 2*d){
                k = i;
                cnt++;
            }
        }
        if(cnt <= 3) return true;
        return false;
    };

    ll l = 0, r = 1e15;
    while(l < r){
        ll mid = (l+r)/2;
        double d = 1.0*mid/(1e6);
        if(cal(d)) r = mid;
        else l = mid+1;
        //cout << l << " " << r << "\n";
    }
    double d = 1.0*l/1e6;
    cout << fixed << setprecision(6) << d << "\n";
    cout << v[0]+d << " ";
    ll cnt = 1;
    int k = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] > v[k] + 2*d){
            cout << v[i] + d << " ";
            k = i;
            cnt++;
        }
    }
    while(cnt != 3){
        cout << 0 << " ";
        cnt++;
    }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}