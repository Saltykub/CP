#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;

int ask(string s, int a, int b) {
	cout << s << ' ' << a << ' ' << b << endl;
	int res;
	cin >> res;
	return res;
}

int pl(int a, int b) {
	int and_ = ask("and", a, b);
	int or_ = ask("or", a, b);
	return  and_ + or_;     
}

void solve (){
    int n,k;
    cin >> n >> k;
    int ab = pl(1,2), bc = pl(2,3), ca = pl(1,3);
    int a = (ab-bc+ca)/2;
    int b = ab-a, c = ca-a;
    vector<int> arr;
    arr.pb(a), arr.pb(b), arr.pb(c);
    for(int i = 4; i <= n; i++){
        int cal = pl(1,i);
        arr.pb(cal-a);
    }
    sort(arr.begin(),arr.end());
    cout << "finish " << arr[k-1] << endl;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}