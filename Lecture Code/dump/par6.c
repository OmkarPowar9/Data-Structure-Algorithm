#include<stdio.h>

void heapify(int arr[])
{
    int i,j,v,n,k,heap;
    n=arr[0];
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=arr[k];
        heap=0;
        while(!heap && 2*k<=n)
        {
            j=2*k;
            if(j<n && arr[j] < arr[j=1])
               j=j+1;
            if(v>=arr[i])
              heap=1;
            else{
                arr[k]=arr[j];
                k=j;
            }
        }
        arr[k]=v;
    }

}
int main()
{
    int arr[100],n,i;
    printf("Enter n:\n");
    scanf("%d",&n);
    printf("Enter elements in array:\n");
    for(i=1;i<=n;i++)
    scanf("%d",&arr[i]);
    arr[0]=n;
    heapify(arr);
    printf("Array after Heapifying\n");
    for(i=0;i<n;i++)
    printf("%d",arr[i]);
    return 0;
}