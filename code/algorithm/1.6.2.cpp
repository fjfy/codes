#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int L,n;
    cin>>L;
    cin>>n;
    int min_t=L,max_t=0;
    int* x=new int[n];
    for(int i=0;i<n;++i)
    	cin>>x[i];
    for(int i=0;i<n;i++)
    {
    	min_t=min(min_t,min(x[i],L-x[i]));
    	max_t=max(max_t,max(x[i],L-x[i]))
    }
    	

    cout<<"min="<<min<<endl;
    cout<<"max="<<max<<endl;
	return 0;
}