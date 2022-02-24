#include <bits/stdc++.h>
using namespace std ;

int mah(int n,int a[]){
	stack<int> s;
	int nsl[n],nsr[n];
	
	//Nearest Smallest Left
	for(int i=0;i<n;i++){
		if(s.empty())nsl[i]=-1;
		else if(!s.empty() && a[s.top()]<a[i])nsl[i]=s.top();
		else if(!s.empty() && a[s.top()]>=a[i]){
			while(!s.empty() && a[s.top()]>=a[i]){
				s.pop();
			}
			if(s.empty())nsl[i]=-1;
			else nsl[i] = s.top();
		}
		s.push(i);
	}
	
	stack<int> q;
	//Nearest Smallest Right
	for(int i=n-1;i>=0;i--){
		if(q.empty())nsr[i]=n;
		else if(!q.empty() && a[q.top()]<a[i])nsr[i]=q.top();
		else if(!q.empty() && a[q.top()]>=a[i]){
			while(!q.empty() && a[q.top()]>=a[i]){
				q.pop();
			}
			if(q.empty())nsr[i]=n;
			else nsr[i] = q.top();
		}
		q.push(i);
	}
	
	int ans=0;
	for(int i=0;i<n;i++){
		nsl[i] = (nsr[i]-nsl[i]-1);
		ans = max(ans, nsl[i]*a[i]);
	}
	return ans;
}

int main()
{
	int n=4,m=4;
//	cin>>n>>m;
	int a[n][m] = {{0,1,1,0},
					{1,1,1,1},
					{1,1,1,1},
					{1,1,0,0}};
//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++)
//			cin>>a[i][j];
//	}
	
	int hist[m] ={0},res[n],result=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==0)hist[j]=0;
			hist[j]+=a[i][j];			
		}
		res[i]=mah(m,hist);
		cout<<i+1<<" X "<<m<<" matrix's mah = "<<res[i]<<endl;
		result = max(result,res[i]);
	}
	cout<<"Maximum area rectangle in binary matrix: "<<result;
	return 0;
}
