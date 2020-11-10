#include <bits/stdc++.h>
using namespace std;

vector<int> getVoters(int arr[],int n){
    sort(arr,arr+n);
    vector<int> voters;
    for(int i=0;i<n;){
        int count =0,j=i;
        while(j<n && (arr[j] == arr[i] )){
            count++;
            j++;
        }
        if(count>=2){
            voters.push_back(arr[i]);
            
        }
        i=j;
    }
    return voters;
}
int main() {
	// your code goes 
	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	int totalElements = n1+n2+n3;
	int arr[totalElements];
	for(int i=0;i<totalElements;i++){
	    cin>>arr[i];
	}
	vector<int> voters = getVoters(arr,totalElements);
	cout<<voters.size()<<endl;
	for(int i=0;i<voters.size();i++){
	    cout<<voters[i]<<endl;
	}
	return 0;
}

