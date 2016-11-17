//you can use a array to release some step
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int c1,c5,c10,c50,c100,c500,a;
	cin>>c1;
	cin>>c5;
	cin>>c10;
	cin>>c50;
	cin>>c100;
	cin>>c500;
	cin>>a;
	int r;
	int i500=a/500;
	i500=min(i500,c500);
	r=a-i500*500;
	int i100=r/100;
	i100=min(i100,c100);
	r=r-i100*100;
	int i50=r/50;
	i50=min(i50,c50);
	r=r-i50*50;
	int i10=r/10;
	i100=min(i10,c10);
	r=r-i10*10;
	int i5=r/5;
	i100=min(i5,c5);
	r=r-i5*5;
	int i1=r/1;
	i100=min(i1,c1);
	r=r-i1*1;
	int num=i500+i100+i50+i10+i5+i1;
	cout<<i500<<" "<<i100<<" "<<i50<<" "<<i10<<" "<<i5<<" "<<i1<<"num="<<num<<endl;

	return 0;
}
