#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int temp[10000];
int A[] = {10,8,5,3};
int flag = 0;

//With DP  - Complexity - O(n*4)
int dpfun(int n)
{
    int dp[n+1]={0};
    dp[0]=1;
    for(int i=1; i <= n; i++)
    {
      for(int j=0; j < 4; j++)
      {
        if(i >=A[j])
        {
            dp[i] += dp[i-A[j]];
        }
      }
    }
    return dp[n];
}


//Without DP - Complexity - Exponential
//Print Array
void printarray(int idx)
{
    for(int i = 0; i < idx; i++)
     cout<<temp[i]<<" ";
    cout<<endl;
    return;
}

//Main function without DP
void fun(int curr_idx , int idx, int n)
{ 
    if(flag == 1) return;
    if(n==0)
     {
        // do 
        // { 
        //   printarray(idx); 
        // } while (next_permutation(temp, temp + idx));
           
       for(int i = 0; i < idx; i++)
          cout<<temp[i]<<" ";
        flag++;
        return;
     }
    if(curr_idx==4 || n<0) return;

    //Moving ahead by taking it
    temp[idx] = A[curr_idx];
    fun(curr_idx, idx+1, n-A[curr_idx]);

    //Not taking it
    fun(curr_idx+1,idx,n);  
}


int main()
{
    int n;
    cout<<"Enter value of S";
    cin>>n;

    cout<<"\nTotal possible permutations are ";
    //With DP -> Complexity -> O(n*4) {Bottom to top}
    cout<<dpfun(n)<<"\n"<<endl;

    //without DP -> Complexity -> Exponential
    //cout<<"Following Permutations are possible\n";
    cout<<"\nQuestion with Maximum weightage is\n"; 
    fun(0,0,n);
    cout<<endl;
}