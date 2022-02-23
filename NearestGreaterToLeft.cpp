
//arr[] = {1,3,4,2}
//ans[] = {-1,-1,-1,4}
//BruteForce(O{n*n))
// vector<int> ans(n,-1);
// for(int i=0;i<n;i++){
//   for(int j=i-1;j>=0;j--){
//     if(arr[j]>arr[i]){
//       ans[i]=arr[j];
//       break;
//   }
// }
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	stack<int> s;
	vector<int> ans(n);
	
	for(int i=0;i<n;i++){
		if(s.empty())ans[i]=-1;
		else if(!s.empty() && s.top()>arr[i])ans[i]=s.top();
		else if(!s.empty() && s.top()<=arr[i]){
			while(!s.empty() && s.top()<=arr[i]){
				s.pop();
			}
			if(s.empty())ans[i]=-1;
			else ans[i] = s.top();
		}
		s.push(arr[i]);
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" "[i==n-1];
	}
    return 0;
}
