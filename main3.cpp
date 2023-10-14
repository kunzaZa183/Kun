#include<stdio.h>
#include<math.h>
typedef long long ll;
 
int n,i,j,k;
int main(){
    scanf("%d",&n);
    for(i=0;i<2*n-1;i++){
        for(j=0;j<2*n-1;j++){
            if(j==0 || j==2*n-2 || i==j) printf("#");
            else printf(" ");
        }
        printf("\n");
    }
}