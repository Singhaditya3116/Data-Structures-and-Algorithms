#include<stdio.h>

int main()
{
    int a,n,d;
    printf("Enter the starting number of an Ap\n");
    scanf("%d",&a);
    printf("Enter the nth item\n");
    scanf("%d",&n);
    printf("enter the common difference\n");
    scanf("%d",&d);

    int sum=a;
    int A[n];
    int index=0;
    A[index]=a;
    index++;
    for(int i=a;i<n;i++)
    {
        sum+=d;
        A[index]=sum;
        index++;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=A[i];
    }
    printf("The arithmetic sum is %d",ans);

}
