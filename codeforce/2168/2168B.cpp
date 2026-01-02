#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void fi (){
    int n;
    cin >> n;
    vll v(n);
    for(auto &u:v) cin >> u;
    for(auto u:v){
        if(u == 1){
            cout << 0 << "\n";
            return;
        }
        if(u == n){
            cout << 1 << "\n";
            return;
        }
    }
}
int ask(int l, int r){
    cout << "? " << l << " " << r << endl;
    int ret;
    cin >> ret;
    return ret;
}
void se(){
    int n,x;
    cin >> n >> x;
    int l = 1, r = n, al, ar;
    while(l < r){
        int mid = (l+r)/2;
        int ch = ask(1,mid);
        if(ch == n-1){
            r = mid;
        }
        else l = mid+1;
    }
    ar = l;
    l = 1, r = n;
    while(l < r){
        int mid = (l+r+1)/2;
        int ch = ask(mid,n);
        if(ch == n-1){
            l = mid;
        }
        else r = mid-1;
    }
    al = r;
    if(x) cout << "! " << al << endl;
    else cout << "! " << ar << endl;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s;
    cin >> s;
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        if(s == "first") fi();
        else se();
    }
}