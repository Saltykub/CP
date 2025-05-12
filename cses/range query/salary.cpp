#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MX = 4e5 + 5;

ll bit[MX];
vector<int> vals;
int n, q;

void upd(int i, int val) {
	for (; i <= MX; i += i & (-i)) { bit[i] += val; }
}

void ad(int x, int b) {
	int ind = upper_bound(vals.begin(), vals.end(), x) - vals.begin();
	upd(ind, b);
}

ll sum(int x) {
	ll res = 0;
	for (; x; x -= x & (-x)) { res += bit[x]; }
	return res;
}

ll query(int x) {
	int ind = upper_bound(vals.begin(), vals.end(), x) - vals.begin();
	return sum(ind);
}

int main() {
	cin >> n >> q;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) { cin >> ar[i]; }
	vals = ar;
	vector<array<int, 3>> rec;
	for (int i = 0; i < q; i++) {
		char t;
		int a, b;
		cin >> t >> a >> b;
		rec.push_back({t == '?', a, b});
		if (t == '!') vals.push_back(b);
	}
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	for (int i = 0; i < n; i++) { ad(ar[i], 1); }
	for (auto u : rec) {
		u[1]--;
		if (u[0] == 0) {
			ad(ar[u[1]], -1);
			ar[u[1]] = u[2];
			ad(ar[u[1]], 1);
		} else {
			cout << query(u[2]) - query(u[1]) << '\n';
		}
	}
}
// #include<bits/stdc++.h>
// #define ll long long 
// #define pii pair<ll,ll>
// #define st first 
// #define nd second 
// #define pb push_back
// using namespace std;
// const int N=2e5+5;
// pair<char,pii> Q[N];
// set<ll> s;
// ll fw[3*N],arr[N];
// map<ll,ll> mp;
// void add(int i,int val){
//     for(;i<3*N;i+=(i&-i)){
//         fw[i]+=val;
//     }
// }
// ll qs(int i){
//     ll ret=0;
//     for(;i>0;i-=(i&-i)){
//         ret+=fw[i];
//     }
//     return ret;
// }
// int main(){
//     ios_base::sync_with_stdio(0);cin.tie(0);
//     int n,q;
//     cin>>n>>q;
//     for(int i=1;i<=n;i++){cin>>arr[i];s.insert(arr[i]);}
//     for(int i=1;i<=q;i++){
//         cin>>Q[i].st>>Q[i].nd.st>>Q[i].nd.nd;
//         if(Q[i].st=='?')s.insert(Q[i].nd.st);
//         s.insert(Q[i].nd.nd);
//     }
//     vector<int> compress;
//     compress.pb(0);
//     for(auto u:s)compress.pb(u);
//     sort(compress.begin(),compress.end());
//     int sz=compress.size();
//     for(int i=1;i<sz;i++){
//         mp[compress[i]]=i;
//     }
//     for(int i=1;i<=n;i++){
//         int idx=mp[arr[i]];
//         add(idx,1);
//     }
//     for(int i=1;i<=q;i++){
//         if(Q[i].st=='?'){
//             cout<<qs(mp[Q[i].nd.nd])-qs(mp[Q[i].nd.st]-1)<<"\n";
//            // cout<<qs(9)<<"debug\n";
//         }
//         else {
//             int temp = arr[Q[i].nd.st];
//             //cout<<temp;
//             add(mp[Q[i].nd.nd],1);
//             add(temp,-1);
//         }
//     }

// }