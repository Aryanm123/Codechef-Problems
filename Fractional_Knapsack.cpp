#include <bits/stdc++.h>
using namespace std;

struct Item{
	int value,weight;
};

bool compare(Item a,Item b){
	double x = (double)a.value/a.weight;
	double y = (double)b.value/b.weight;
	
	return x>y;
}

double fractKnapsack(Item arr[] ,int W,int n ){
	sort(arr,arr+n,compare);
	int currW = 0;
	double ans = 0;
	for(int i=0;i<n;i++){
		if((currW + arr[i].weight) <= W){
			currW += arr[i].weight;
			ans += arr[i].value;
		}
		else{
			int remWeight = W - currW;
			ans += arr[i].value * ( (double)remWeight/arr[i].weight) ;
			break;
		}
			
	}
	return ans;
}
int main(){
	int W  = 70;
	Item arr[] = { {60,20}, {70,15} ,{80,40}};
	cout<<"Maximum -> "<<fractKnapsack(arr,W,3);
	return  0;
}
