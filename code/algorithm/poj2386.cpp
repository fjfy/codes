#include<iostream>
using namespace std;
void dfs(char** a,int n,int m,int i,int j)
{
	a[i][j]='.';
	for(int dx=-1;dx<=1;dx++)
		for(int dy=-1;dy<=1;dy++)
		{
			int nx=i+dx;
			int ny=j+dy;
			if(nx<n && ny<m && nx>=0 && ny>=0 && a[i+dx][j+dy]=='W')	
				dfs(a,n,m,i+dx,j+dy);
		}
}
int main()
{
	int n,m,num=0;
	cout<<"n= ";
	cin>>n;
	cout<<"m=";
	cin>>m;
	char** a=new char*[n];
	for(int i=0;i<n;i++)
		a[i]=new char[m];
	cout<<"input the array: "<<endl;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin>>a[i][j];
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			if(a[i][j]=='W')
			{
				 num++;
				 dfs(a,n,m,i,j);
			}
		}
	cout<<"the number of water is "<<num<<endl;

	for(int i=0;i<n;i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
