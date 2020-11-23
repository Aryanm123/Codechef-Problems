#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n){
	return i>=0 && i<n && j>=0 && j<n;
}

int ans  = 0;
void ratInMaze(vector<vector<int> > &arr,vector<vector<int> > &visited,int n,int i, int j){
	if(arr[n-1][n-1] == 1) return ;                       // destination is blocked
	
	if(i==n-1 && j==n-1) {
		ans++;
		return;
	}
	if(!isValid(i,j,n))   return;							// Out of bound
	
	visited[i][j] = 1;
	if(isValid(i-1,j,n) && visited[i-1][j] == 0 && arr[i-1][j] == 0){   		//upward
			ratInMaze(arr,visited,n,i-1,j);
	}
	if(isValid(i+1,j,n) && visited[i+1][j] == 0 && arr[i+1][j] == 0){   		//Downward
			ratInMaze(arr,visited,n,i+1,j);
	}
	if(isValid(i,j+1,n) && visited[i][j+1] == 0 && arr[i][j+1] == 0){   		//rightward
			ratInMaze(arr,visited,n,i,j+1);
	}
	if(isValid(i,j-1,n) && visited[i][j-1] == 0 && arr[i][j-1] == 0){   		//leftward
			ratInMaze(arr,visited,n,i,j-1);
	}
	
	visited[i][j] = 0;													// for backtracking
}
int main(int argc, char** argv) {
	
	int n;
	cin>>n;
	vector<vector<int> > arr(n,vector<int>(n,0));
	vector<vector<int> > visited(n,vector<int>(n,0));
	for(int i = 0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	
	ratInMaze(arr,visited,n,0,0);
	cout<<ans;
	return 0;
}
