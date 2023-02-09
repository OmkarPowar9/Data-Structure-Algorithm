#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n1,n2,*ptr,i;
    printf("Enter n1:");
    scanf("%d",&n1);
    ptr=malloc(n1*sizeof(int));
    if(ptr=NULL)
    {
        printf("Memory not available");
        exit(0);
    }
    for(i=0;i<n1;i++)
    
        printf("%p\n",ptr+i);
        printf("Enter n2:");
        scanf("%d",&n2);
        realloc(ptr,n2*sizeof(int));
        for(i=0;i<n2;i++)
        printf("%p\n",ptr+i);
        free(ptr);

    


    return 0;







}