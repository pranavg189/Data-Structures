/* This is a Top Down Dynamic Programming (Memoization) Solution */

class Solution {
public:
    
    int result[1000]={0};
    
    Solution()
    {
        result[0]=result[1]=1;
    }
    
    int numTrees(int n) {
        int sum=0;
        
        if(result[n]!=0) return result[n];
        
        for(int i=1;i<=n;i++)
        {
            sum = sum + numTrees(n-i)*numTrees(i-1);
        }
        
       result[n] = sum;
       return sum;
    }
};