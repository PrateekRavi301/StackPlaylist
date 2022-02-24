#include <bits/stdc++.h>
using namespace std ;

stack<int> s;
int min_ele=-1;

void push(int a){
	if(s.empty()){
		min_ele=a;
		s.push(a);
	}else if(a>=s.top()){
		s.push(a);
	}else{
		s.push(2*a - min_ele);
		min_ele = a;
	}
	
}

int pop(){
	if(s.empty())return -1;
	int a = s.top();
	if(a>=min_ele){
		s.pop();
	}else if(a<min_ele){
		min_ele = 2*min_ele -a;
		s.pop();
	}
}

int top(){
	if(s.empty())return -1;
	else{
		if(s.top()>min_ele){
			return s.top();
		}else{
			return min_ele;
		}
	}
}
int getmin(){
	if(s.empty())return -1;
	return min_ele;
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
