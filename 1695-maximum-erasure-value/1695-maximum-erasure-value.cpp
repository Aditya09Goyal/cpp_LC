class Solution {
public:
    int maximumUniqueSubarray(vector<int>& arr) {
        int n = arr.size() ; 
        int l = 0 , r = 0 , maxi = 0 ;
        unordered_set<int>st ; 
        int sum = 0 ; 
        while(r<n)
        {
            while(st.count(arr[r]))
            {
                st.erase(arr[l]);
                sum -= arr[l]; 
                l++; 
            }
            st.insert(arr[r]); 
            sum+= arr[r] ; 
            maxi=max(sum,maxi);
            r++;
        }
        return maxi ; 
    }
};