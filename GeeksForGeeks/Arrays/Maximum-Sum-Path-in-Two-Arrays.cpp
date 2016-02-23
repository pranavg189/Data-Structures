/* Problem Statement:

Given two sorted arrays such the arrays may have some common elements.
Find the sum of the maximum sum path to reach from beginning of any array to end of any of the two arrays.
We can switch from one array to another array only at common elements.
Expected time complexity is O(m+n) where m is the number of elements in ar1[] and n is the number of elements in ar2[].

*/

#include <stdio.h>

int max_num(int a,int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int max_sum_path(int ar1[],int ar2[],int n,int m)
{
    int result=0;

    int sum1=0,sum2=0;

    int i=0,j=0;

    while(i < n && j < m)
    {
        if(ar1[i]<ar2[j])
            sum1 += ar1[i++];

        else if(ar2[j]<ar1[i])
            sum2 += ar2[j++];

        else
        {

            result += max_num(sum1,sum2);

            while(i < m  && j < n && ar1[i]==ar2[j])
            {
                result += ar1[i];
                i++;
                j++;
            }

            sum1=0,sum2=0;

        }
    }

    while(i<n)
        sum1 += ar1[i++];

    while(j<m)
        sum2 += ar2[j++];

    result += max_num(sum1,sum2);

    return result;
}

int main()
{
    int ar1[]={2,3,7,10,12,15,30,34};
    int ar2[]={1,5,7,8,10,15,16,19};
    int n=sizeof(ar1)/sizeof(ar1[0]);
    int m=sizeof(ar2)/sizeof(ar2[0]);
    int result = max_sum_path(ar1,ar2,n,m);
    printf("Max path sum is %d\n",result);
    return 0;
}
