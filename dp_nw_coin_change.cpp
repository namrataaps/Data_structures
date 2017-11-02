#include<bits/stdc++.h>
using namespace std;

int fun(int a[],int n,int key){

   int i,j,x,y;
   int table[key+1][n];

   for(i=0;i<n;i++){
    table[0][i]=1;
   }
   for(i=1;i<key+1;i++){

    for(j=0;j<n;j++){

        x=(i-a[j]>=0)?table[i-a[j]][j]:0;
        y=(j>=1)?table[i][j-1]:0;

        table[i][j]=x+y;
    }

   }


   return table[key][n-1];
}

int main(){

   int n,k,i;
   int a[100005];
   cin>>k>>n;

   for(i=0;i<n;i++){
    cin>>a[i];
   }
   cout<<fun(a,n,k);
   return 0;
}
