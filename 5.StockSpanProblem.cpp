//arr[] = {100,80,60,70,60,75,85}
//ans[] = {1,1,1,2,1,4,6}
//Find the consecutive smallest or equal to it before ith element in arr.
//For i=0, only one element that is 100 itself, similarly for i=1,2,4
//For i=3, 60,70 both satisify the condition, therefore ans[3] =2
//For i=5, 60,70,60,75
//For i=6, 80,60,70,60,75,85
//Brute-Force(O(n*n))
// for(int i=0;i<n;i++){
//   for(int j=i-1;j>=0;j++){
//     if(arr[j]<arr[i])break;
//     else ans[i]++;
//   }
// }
//Optimized approach: This problem is similar to nearest greater to left. 
//We store indices of nearest greater to left in stack and then calculate the distance from i to stored index i.e (i - value in NGL)
#include <bits/stdc++.h>
using namespace std;

int main()
{

	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	stack<int> s;
	vector<int> ans(n);
	
	for(int i=0;i<n;i++){
		if(s.empty())ans[i]=i-(-1); //When stack is empty, NGL value is -1, : ans[i] = i - (-1);
		else if(!s.empty() && arr[s.top()]>arr[i])ans[i]=i - s.top();
		else if(!s.empty() && arr[s.top()]<=arr[i]){
			while(!s.empty() && arr[s.top()]<=arr[i]){
				s.pop();
			}
			if(s.empty())ans[i]=i-(-1);
			else ans[i] = i -s.top();
		}
		s.push(i);
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" "[i==n-1];
	}
    return 0;
}
