#include<stdio.h>
void swap(int *a1,int *a2)
{
    int temp;
    temp=*a1;
    *a1=*a2;
    *a2=temp;

}
int main()
{
    int i,j,n;
    printf("enter the length of array you want=");
    scanf("%d",&n);
     int arr[n];
    for ( i = 0; i < n; i++)
    {
        printf("enter the data of index %d:",i);
        scanf("%d",&arr[i]);
    }
    for ( i = 0; i < n-1; i++)
    {
        int min=i;
        for ( j = i+1; j < n; j++)
        {
            if (arr[j]<arr[min])
            {
                min=j;
            }
        }
        if (min!=i)
        {
            swap(&arr[i],&arr[min]);
        }
        
    }
    printf("the sorted array is:");
    for ( i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    
    
}