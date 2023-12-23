class Solution {
public:
    void moveZeroes(vector<int>& arr) {
      int zero=1;
	    int nonZero=0;
	    while(zero<arr.size() && nonZero<arr.size()){
	       if(arr[nonZero]==0)
	        {
	            if(arr[zero]!=0)
	            {
	                swap(arr[zero],arr[nonZero]);
	                nonZero++;
	            }
	            else
	            zero++;
	        }
	        else
	        {
	            zero++;
	            nonZero++;
	        }
	    }  
    }
};