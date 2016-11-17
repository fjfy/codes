#include<iostream>
#include<algorithm>
using namespace std;
bool binary_search(int* a,int length,int key)
{
	int l,r,len;
	l=0;
	r=length;
	while(r-l>=0)
	{
		len=(l+r)/2;
		if(a[len]==key)
			return true;
		else if(a[len]<key)
			l=len+1;
		else r=len;
	}
	return false;

}
int main()
{
	int n,m,x;
	bool f=false;
	cout<<"input n:"<<endl;
	cin>>n;
	cout<<"input m:"<<endl;
	cin>>m;
	int* k=new int[n];
	for(int i=0;i<n;i++)
		cin>>k[i];
	int* kk=new int[n*n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			kk[i*n+j]=k[i]+k[j];
	sort(kk,kk+n*n);
	for(int a=0;a<n;a++)
	   	for(int b=0;b<n;b++)
	   		{
	   			x=m-k[a]-k[b];
	   			if(binary_search(kk,n*n,x))
	   				f=true;
	   		}
	if(f==true)
		cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	delete[] k;
	delete[] kk;
	return 0;
}
