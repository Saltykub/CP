#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve()
{ 
   int n,m;
   cin>>n>>m;
   char tab[n][m];
   vector<int> vv,ii,kk,aa;
   for(int i=0;i<n;i++)
   {
     for(int j=0;j<m;j++)
        {
            cin>>tab[i][j];
            if(tab[i][j]=='v')vv.pb(j);
             if(tab[i][j]=='i')ii.pb(j);
              if(tab[i][j]=='k')kk.pb(j);
               if(tab[i][j]=='a')aa.pb(j);
        }
   }
   
   sort(vv.begin(),vv.end());
    sort(ii.begin(),ii.end());
     sort(kk.begin(),kk.end());
      sort(aa.begin(),aa.end());
   if(vv.empty()||ii.empty()||kk.empty()||aa.empty())cout<<"NO";
   else
   {
    int idxi=-1,idxk=-1;
   for(auto u:ii)
   {
     if(u>vv[0])
     {
        idxi=u;
        break;
     }
   }
   if(idxi>kk[kk.size()-1]||idxi==-1)cout<<"NO";
   else 
   {
        for(auto u:kk)
        {
            if(u>idxi)
            {
                idxk=u;
                break;
            }
        }
        if(idxk<aa[aa.size()-1]&&idxk!=-1)cout<<"YES";
        else cout<<"NO";

   }
   }
   cout<<"\n";
   
  
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