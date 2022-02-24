#include <bits/stdc++.h>
using namespace std ;

stack<int> s;
stack<int> ss;

void push(int a){
	s.push(a);
	if(ss.empty() || a<=ss.top()){
		ss.push(a);
	}
}

int pop(){
	int a = s.top();
	s.pop();
	if(a==ss.top())ss.pop();
	return a;
}

int getmin(){
	if(ss.empty())return -1;
	return ss.top();
}

int main()
{
	int n=5;
//	cin>>n;
	int a[n]={19,18,20,16,29};
//	for(int i=0;i<n;i++)cin>>a[i];

	for(int i=0;i<n;i++){
		push(a[i]);
		int ans = getmin();
		cout<<"Minimum in stack after pushing "<<a[i]<<" into stack : "<<ans<<endl;
	}
	for(int i=0;i<n;i++){
		int val = pop();
		int ans = getmin();
		cout<<"Minimum in stack after poping "<<val<<" from stack : "<<ans<<endl;
	}
	return 0;
}
