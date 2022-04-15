/******************************************************************************

Counting Sort

*******************************************************************************/
#include <iostream>
using namespace std;
int getmax(int a[],int n)
{
    int max = a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max = a[i];
        }
    }
    return max;
}
void countsort(int a[],int n)
{
    int output[n+1];
    int max = getmax(a,n);
    int count[max+1];
    for(int i=0;i<=max;i++)
    {
        count[i] = 0;
    }
    for(int i=0;i<n;i++)
    {
        count[a[i]]++;
    }
    for(int i=1;i<=max;i++)
    {
        count[i] += count[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        output[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }
    for(int i=0;i<n;i++)
    {
        a[i] = output[i];
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    countsort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
