#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<pair<int,int> > intervals;
	    for(int i=0;i<n;i++){
	        int start,end;
	        cin>>start>>end;
	        intervals.push_back(make_pair(start,end));
	    }
	    sort(intervals.begin(),intervals.end());
	    while(m--){
	        int currTime;
	        cin>>currTime;
	        int position = lower_bound(intervals.begin(),intervals.end(),make_pair(currTime,0)) - intervals.begin();
	        if(position == 0){                                              //Special case
	            int ans  = intervals[0].first - currTime;
	            cout<<ans<<endl;
	        }
	        else{
	            int  ans =-1;
	            if(intervals[position-1].second > currTime)               //Comparing with just previous position
	                ans  = 0;
	            else if(position < intervals.size())                        //position b/w intervals
	                ans = intervals[position].first - currTime ;
	                
	           cout<<ans<<endl;                                             //default value is -1 if position is out of bound
	        }
	                                                  
	        
	    }
	}
	return 0;
}

