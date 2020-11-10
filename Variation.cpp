#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	long count = 0;
	sort(arr,arr+n);
	int i=0, j=1 ;
	while(j<n){
	    if( (arr[j] - arr[i]) >= k){
	        count += n-j;
	        i++;
	    }
	    else{
	        j++;
	    }
	}
	
	cout<<count<<endl;
	return 0;
}

