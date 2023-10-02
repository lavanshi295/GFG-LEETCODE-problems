//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<int>dq;
        vector<int>ans;

        for(int i=0; i<n; i++){
            //check for the case of out of bound element
            if(!dq.empty() && dq.front() == i-k) dq.pop_front();

            //if the curr element is greater than prev then pop from deque
            while(!dq.empty() && arr[dq.back()] < arr[i]){
                dq.pop_back();
            }

            //and push the curr index
            dq.push_back(i);
            //if i is at the last element then push to ans
            if(i>= k-1) ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends