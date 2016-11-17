#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,length,ma,max_t=0;
	cin>>n;
	int* a = new int[n];
	for(int i=0; i<n; ++i)
		cin>>a[i];
	for(int i=0; i<n; i++)
		for(int j=i+1;j<n;j++)
			for(int k=j+1;k<n;k++)
			{
				length=a[i]+a[j]+a[k];
				ma=max(a[i],max(a[j],a[k]));
				if(ma<length-ma)
					max_t=max(length,0);
			}
	cout<<max_t<<endl;
	delete[] a;
	return 0;
}
