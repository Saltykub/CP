#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N=2e5+10;
ll fw[3*N];
ll man[N];
priority_queue<ll,vector<ll>,greater<ll>> compress;
pair<char,pair<ll,ll>> quest[N];
map<ll,ll> idx,check;
void update(int i,int val)
{
    for(;i<=N;i+=i&-i)
    {
        fw[i]+=val;
    }
}
ll sum(ll i)
{   
    ll ans=0;
    for(;i>0;i-=i&-i)
    {
        ans+=fw[i];
    }
    return ans;
}
int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>man[i];
        if(check[man[i]]!=1)compress.push(man[i]);
        check[man[i]]=1;
    }
    // offline query 
    for(int i=1;i<=q;i++)
    {
        cin>>quest[i].st>>quest[i].nd.st>>quest[i].nd.nd;
        if(quest[i].st=='?')
        {
            if(check[quest[i].nd.st]!=1)compress.push(quest[i].nd.st);
            check[quest[i].nd.st]=1;
        }
        if(check[quest[i].nd.nd]!=1)compress.push(quest[i].nd.nd);
        check[quest[i].nd.nd]=1;
    }
    // compress 
    int ct=1;
    while(!compress.empty())
    {
    idx[compress.top()]=ct;
    compress.pop();
    ct++;
    }
    for(int i=1;i<=n;i++)update(idx[man[i]],1);
    for(int i=1;i<=q;i++)
    {
        if(quest[i].st=='!')
        {
            update(idx[man[quest[i].nd.st]],-1);
            update(idx[quest[i].nd.nd],1);
            man[quest[i].nd.st]=quest[i].nd.nd;
        }
        else 
        {   
            ll l=quest[i].nd.st,r=quest[i].nd.nd;
            cout<<sum(idx[r])-sum(idx[l]-1)<<"\n";
        }
    }
}