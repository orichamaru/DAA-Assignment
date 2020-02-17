//DAA - Assignment 2
//Part 2


// #include<stdio.h>
// #include<time.h>
// #include<stdlib.h>
// #include<math.h>
// #include <stdbool.h>
#include<bits/stdc++.h>
using namespace std;

bool binsearch(int A[] , int l, int u)
{
   if(l<=u)
   {
         int mid = (l+u)/2;
         if(A[mid]==0) return true;
         return binsearch(A,mid+1,u) || binsearch(A,l,mid-1);
   }
   return false;
}

int main()
{
   srand(time(0));
   // for(int p = 0; p < 200; p++)
   {
     // int n = (p+1)*50;
     for(int q=0;q<100;q++)
     {
         int n= rand()%2000 + 1000;
         float min_time_1=INT_MAX,max_time_1=-100,avg_time_1=0;
         float min_time=INT_MAX,max_time=-100,avg_time=0;
         // for(int p=0;p<100;p++) 
         // {
            float bstime = 0, lstime = 0;
            // printf("n is @%d@\n",n);
            for(int a = n/2; a< n; a++)       //a denotes size of chunk
            {  
               int A[n];
               for(int i = 0; i < n; i++) A[i]=-1;  //Initialising array with -1

               int count=0;    //Filling array with chunks of zero for five times
               while(count<5)
              {
                int k = rand()%n;
                count++;
                if(k<=n-a && (A[k]==0 || A[k+a]==0))
                {
                continue;
                }
                else if(k-1>=0 &&  A[k-1]==0 && A[k]!=0)
                {
                    continue;
                }
                else if(k<=n-a && A[k]!=0)
                {
                    int temp=rand()%10;
                for(int i=k; i < k+a+temp ; i++)
                {
                    A[i]=0;
                }
                }
            
              }
               for(int i = 0; i < n; i++)
              {
                if(A[i]==-1) A[i]=1;
              }    
            // printf("a is %d\n",a);
            // for(int i = 0; i < n; i++)
            //     printf("%d ",A[i]);
            // printf("\n");
            
            clock_t tim, tim1;

        
            //Optimized Search
            tim = clock();
            bool ans = binsearch(A,0,n-1);
            tim = clock() - tim;

            //Linear Search
            tim1 = clock();
            for(int i = 0; i < n; i++)
            {
                if(A[i]==0)
                    break;
            }
            tim1 = clock() - tim1;

            double tt = ((double)tim)/CLOCKS_PER_SEC;
            double tt1 = ((double)tim1)/CLOCKS_PER_SEC;

            if(min_time>tt){
                min_time=tt;
            }
            if(min_time_1>tt1){
                min_time_1=tt1;
            }
            if(max_time<tt){
                max_time=tt;
            }
            if(max_time_1<tt1){
                max_time_1=tt1;
            }
            avg_time+=tt;
            avg_time_1=tt1;

            // bstime +=tt;
            // lstime +=tt1;
            // if(ans==false)
            // {
            //     printf("Not Found\n");
            // }
            // else
            // {
            //     //printf("Found at %d\n",ans);
            //     printf("\n");
            //     printf("Binary Search time for searching %d 0's is %f\n",a,tt);
            //     printf("Linear Search time for searching %d 0's is %f\n",a,tt1);
            // }
        }
        
       // printf("Binary Search time for searching 0's is #%f#\n",(bstime*2)/n);
       // printf("Linear Search time for searching 0's is &%f&\n",(lstime*2)/n);
     // }
        cout << n << " " << min_time << " " << (avg_time)/(n/2 + 1) << " " << max_time << endl;  
        cout << n << " " << min_time_1 << " " << (avg_time_1)/(n/2 + 1) << " " << max_time_1 << endl;
     }
     
  }
}