#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
	// your code goes here
	
	int n,m;
	cin>>n>>m;
	ll arr[n];
	for(int i=0;i<n;++i){
	    cin>>arr[i];
	}
	sort(arr,arr+n);
	
	queue<ll> q;
	int countM  =0 ,end = n-1;
	while(m--){
	    int currM;
	    cin>>currM;
	    int result;
	    for(;countM<currM;++countM){
	        if(end>=0 && (q.empty() || arr[end] >= q.front() )){
	            result = arr[end];
	            end--;
	        }
	        else{
	            result = q.front();
	            q.pop();
	        }
	         
	         q.push(result/2);   
	    }
	    cout<<result<<endl;
	}
	return 0;
}

