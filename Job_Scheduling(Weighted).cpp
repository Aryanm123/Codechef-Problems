#include <bits/stdc++.h>
using namespace std;

struct Job{
	int start,finish,profit;
};

bool compare(Job a,Job b){
	return a.finish<b.finish;
}
int findMax(Job arr[],int n){
	sort(arr,arr+n,compare);
	int *dp  =  new int[n];
	dp[0] = arr[0].profit;
	
	for(int i=1;i<n;i++){
		int including = arr[i].profit;
		int leftNonConflict = -1;
		for(int j=i-1;j>=0;j--){
			if(arr[j].finish <= arr[i].start){
				leftNonConflict  = j;
				break;
			}
		}
		if(leftNonConflict != -1){
			including += dp[leftNonConflict];
		}
		dp[i] = max(including,dp[i-1]);
	}
	int ans = dp[n-1];
	delete []dp;
	return ans;
	
}
int main(){
	Job arr[] = {{2,5,50},{1,2,20},{6,7,70},{2,50,400}};
	cout<<"Maximum profit -> "<<findMax(arr,4)<<endl;
	return 0;
}
