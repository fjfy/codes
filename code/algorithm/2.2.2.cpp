#include<queue>
#include<iostream>
using namespace std;
int main()
{
	int n;
	queue que;
	cin>>n;
	int* s=new int[n];
	int* t=new int[n];
	for(int i=0;i<n;++i)
		cin>>s[i];
	for(int i=0;i<n;++i)
		cin>>t[i];
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n-i;j++)
		{
			if(t[i]<t[j] && s[i]>t[que.front()])
				que.push(i);
			
		}

	return 0;
}