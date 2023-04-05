//top down heap
#include<stdio.h>
#define max 10
int main()
{
    int a[max],i,c,p,n,elt;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);

    for(i=1;i<n;i++)
    {
        elt=a[i];
        c=i;
        p=(c-1)/2;
        while(c>0 && a[p]<elt)
        {
            a[c]=a[p];
            c=p;
            p=(c-1)/2;

        }
        a[c]=elt;
    }
    printf("Elements of heap:");
    
}