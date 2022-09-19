#include<bits/stdc++.h>
using namespace std;
void reverse(int a[],int n) {
    int b=0,e=n-1;
    while(b<=e)
        swap(a[b++],a[e--]);
}
int main()
{
	int t;
    cin>>t;
    while(t--)
   	{
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        reverse(a,n);
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
    return 0;
}