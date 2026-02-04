#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std; 
const int N=2e5+5;
int fw[N][26];
void up(int i,int val,int j){
    for(;i<=N;i+=(i&-i)){
        fw[i][j]+=val;
    }
    return;
}
int qs(int i,int j){
    int ans=0;
    for(;i>0;i-=(i&-i)){
        ans+=fw[i][j];
    }
    return ans;
}
void solve()
{ 
    int m,n;
    cin>>n>>m;
    string a,b; cin>>a>>b;
    vector<int> have[26];
   // for(int i=0;i<n;i++)cout<<i;
    for(int i=0;i<n;i++)have[a[i]-'a'].push_back(i);
    int curidx[26];
    memset(curidx,-1,sizeof curidx);
    bool can=true;
    int mn=b[0]-'a';
    int mx=b[0]-'a';
    curidx[mn]++;
    if(have[mn].size()==0){cout<<"NO\n";return;}
    int maxidx=have[mn][0];
    for(int i=1;i<m;i++){
        //check that it has or not 
        int c=b[i]-'a';
        if(curidx[c]+2>have[c].size()){cout<<"NO\n";return;}
        curidx[c]++;
        if(b[i]>=b[i-1]){
            mx=max(c,mx);
            mn=min(c,mn);
            while(true){
                if(qs(have[c][curidx[c]]+1,c)==0)break;
                curidx[c]++;
                if(curidx[c]+2>have[c].size()){cout<<"NO\n";return;}
            }
            maxidx=max(maxidx,have[c][curidx[c]]);
        }
        else {
            for(int j=mn;j<=mx;j++){
                 up(1,1,j);
                 up(maxidx+1,-1,j);
            }
            while(qs(have[c][curidx[c]],c)!=0){
                curidx[c]++;
                if(curidx[c]+2>have[c].size()){cout<<"NO\n";return;}
            }
            maxidx=have[c][curidx[c]];
            mn=c;
            mx=c;
        }
    }
    if(can)cout<<"YES";
    else cout<<"NO";
    cout<<"\n";
    for(int i=0;i<n;i++)for(int j=0;j<26;j++)fw[i][j]=0;
}  
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}