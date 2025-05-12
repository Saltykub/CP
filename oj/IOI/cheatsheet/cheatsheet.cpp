#include "cheatsheet.h"
#include "stub.cpp"
#include <vector>
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int> write_cheatsheet(int N, vector<int> A){
	int sum=1;
	int mx=0;
	map<int,bool> mp;
	vector<int> R;
	R.pb(A[0]);
	for(auto u:A)
	{
		mx=max(mx,u);
		mp[u]=true;
	}

	for(int i=1;i<N;i++)
	{
		if(mp[A])
		{
			R.pb(mx+sum);
			sum++;
		}
		else 
		{
			R.pb(A[i]);
		}
	}
	R.pb(mx);
	return R;
}

vector<int> recover_answer(int N, vector<int> R){
   int mx=R[N];
   vector<int> ans;
   for(int i=0;i<N;i++)
   {
	 if(R[i]-mx>0)
	 {
		ans.pb(ans.back());
	 }
	 else 
  	 {
	 ans.pb(R[i]);
  	 }
   }
  
   return ans;
}
