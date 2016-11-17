#include<iostream>
using namespace std;
class array
{
	int row;
	int col;
	char a[row][col];
	array()
	{
		cin>>row;
		cin>>col;
		
	}
};
int main()
{
	int n,k;
	cout<<"n= "
	cin>>n;
	array a;
	cout<<"input the array: "<<endl;
	for(int i=0;i<n;++i)
		cin>>a[i];
	cout<<"k= ";
	cin>>k;


	delete[] a;
	return 0;
}