#include <bits/stdc++.h>
using namespace std ;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
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
		cout<<nsl[i]<<" "<<nsr[i]<<endl;
		nsl[i] = (nsr[i]-nsl[i]-1);
		ans = max(ans, nsl[i]*a[i]);
	}
	cout<<"Maximum area histogram: "<<ans;
	return 0;
}
