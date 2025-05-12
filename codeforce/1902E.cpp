#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=1e6+7;
unordered_map<string,ll> mp;
int trie[N][26] , cnt [N];
int idx=0;
void insert(string &s){
    int u=0;
    for(auto c:s){
        // no this char in trie
        if(!trie[u][c-'a']){
            trie[u][c-'a']=++idx;
        }
        u=trie[u][c-'a'];
        cnt[u]++;
    }
}
ll query(string &s){
    ll u=0,ret=0;
    for(auto c:s){
        if(trie[u][c-'a']){
            u=trie[u][c-'a'];
            ret+=cnt[u];
        }
        else break;
    }
    return ret;

}
void solve()
{   
    int n;
    cin>>n;
    ll ans=0;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
        //string temp="";
        int sz=s[i].size();
        // for(int j=0;j<sz;j++){
        //     temp+=s[i][j];
        //     mp[temp]++;
        // }
        insert(s[i]);
        ans+=sz;
    }
    ans*=2*n;
    for(int i=0;i<n;i++){
        reverse(s[i].begin(),s[i].end());
        int sz=s[i].size();
        // string temp="";
        // for(int j=0;j<sz;j++){
        //     temp+=s[i][j];
        //     ans-=2*mp[temp];
        // }
        ans-=2*query(s[i]);
    }
    cout<<ans;
}

int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}