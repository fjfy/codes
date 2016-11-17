#include<iostream>
using namespace std;
bool defs_search(int* a,int length,int key,int sum,int i)
{
	if(i==length)
		return sum==key;
	if(def_search(a,length,sum,++i))
		return true;
	if(def_search(a,length,sum+a[i]),++i)
		return true;
	else return false;

	
}
int main()
{
	int n,k;
	cout<<"n= "
	cin>>n;
	int* a=new int[n];
	cout<<"input the array: "<<endl;
	for(int i=0;i<n;++i)
		cin>>a[i];
	cout<<"k= ";
	cin>>k;
    bool f=defs_search(a,n,k,0,0);
    if(f)
    	cout<<"yes"<<endl;
    cout<<"no"<<endl;

	delete[] a;
	return 0;
}