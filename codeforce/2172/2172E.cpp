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
vector<string> p1, p2, p3;
void permu(){
    string s1 = "12", s2 = "123", s3 = "1234";
    p1.pb(s1);
    while(next_permutation(all(s1))){
        p1.pb(s1);
    }
    p2.pb(s2);
    while(next_permutation(all(s2))){
        p2.pb(s2);
    }
    p3.pb(s3);
    while(next_permutation(all(s3))){
        p3.pb(s3);
    }
    //for(auto u:p2) cout << u << "\n";
}
void solve (){
    string s;
    int i,j;
    cin >> s >> i >> j;
    i--; j--;
    set<char> cal;
    vector<string> p = p1;
    if(s == "123") p = p2;
    if(s == "1234") p = p3; 
    string a = p[i], b = p[j];
    int x = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b[i]){
            x++;
        }
    }
    cout << x << "A" << a.size()-x << "B" << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    permu();
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}