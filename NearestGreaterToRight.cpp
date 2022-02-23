//arr[] = {1,3,4,2}
//ans[] = {3,4,-1,-1}
//BruteForce(O{n*n))
for(int i=0;i<n;i++){
  for(int j=i+1;j<n;j++){
    if(arr[j]>arr[i])ans[i]=arr[j];
  }
}
   
