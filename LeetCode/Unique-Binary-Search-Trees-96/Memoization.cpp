/* Key Idea: The number of unique BST's for a given number n is given by summation of 
 
            f(n-i)*f(i-1)  , for i= 1 to n

            where base cases are f(0)=f(1)=1

The solution is to be implemented either by Memoization or Dynamic Programming as number 
of sub-problems will increase at rapid rate, so just plain recursive solution will 
exceed time limit */


class Solution {
public:
    
    int result[1000]={0};
    
    Solution()
    {
        result[0]=result[1]=1;
    }
    
    int numTrees(int n) {
        int sum=0;
        
        for(int i=1;i<=n;i++)
        {
            if(result[n-i]==0) result[n-i]=numTrees(n-i);
            if(result[i-1]==0) result[i-1]=numTrees(i-1);
            
            sum = sum + result[n-i]*result[i-1];
        }
       
       return sum;
    }
};