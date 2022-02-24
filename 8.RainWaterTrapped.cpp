#include <bits/stdc++.h>
using namespace std ;

int main()
{
	int n=6;
//	cin>>n;
	int a[n]={3,0,0,2,0,4};
//	for(int i=0;i<n;i++)cin>>a[i];

	int leftmax[n],rightmax[n];
	//MAximum in left side of array
	int lval =a[0];
	leftmax[0]=0;
	for(int i=1;i<n;i++){
		if(a[i]>lval){
			
			lval=a[i];
		}
		leftmax[i]=lval;
	}
	//Maximum in right side of array
	int rval = a[n-1];
	rightmax[n-1]= 0;
	for(int i=n-2;i>=0;i--){
		if(a[i]>rval){
			
			rval=a[i];
		}
		rightmax[i]=rval;
	}
	
	int height[n],result=0;
	for(int i=0;i<n;i++){
		height[i] = min(leftmax[i],rightmax[i]) - a[i];
		cout<<height[i]<<endl;
		if(height[i]>0)result+=height[i];
	}
	cout<<"Rain Water Trapped : "<<result;
	return 0;
}
