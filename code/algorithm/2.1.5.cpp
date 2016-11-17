#include<iostream>
#include<queue>
using namespace std;
const int INF=100000000;
int bfs(char** a,int n,int m,int gx,int gy,int sx,int sy)
{
   
	int dx[4]={1,0,-1,0};
   	int dy[4]={0,1,0,-1};
   	int b[n][m],nx,ny;
   	queue< pair<int,int> > que;
   	for(int i=0;i<n;++i)
         	for(int j=0;j<m;++j)
                {
   			b[i][j]=INF;
		}
	typedef pair<int,int> P;
	 pair<int,int> p(sx,sy);
  	 que.push(p);
  	 b[sx][sy]=0;
  	 while(que.size())
   	{
   		pair<int,int> p=que.front();
		que.pop();
        	if(p.first==gx &&p.second==gy)
	        	break;
        	for(int i=0;i<4;i++)
                {
   	        	nx=p.first+dx[i];
   	                ny=p.second+dy[i];
   	 		if(nx>=0 && nx<n && ny>=0 && ny<m && a[nx][ny]!='#' && b[nx][ny]==INF)
   			{
				pair<int,int> p(nx,ny);
				que.push(p);
   				b[nx][ny]=b[p.first][p.second]+1;
   			}

        	}	
   	}	
	return b[gx][gy];
}
int main()
{
	int n,m,num=0;
	cout<<"n= ";
	cin>>n;
	cout<<"m=";
	cin>>m;
	int sx,sy,gx,gy;
	cout<<"input the start"<<endl;
	cin>>sx;
	cin>>sy;
	cout<<"input the end"<<endl;
	cin>>gx;
	cin>>gy;
	char** a=new char*[n];
	for(int i=0;i<n;i++)
		a[i]=new char[m];
	cout<<"input the array: "<<endl;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin>>a[i][j];
        int f=bfs(a,n,m,gx,gy,sx,sy);
	cout<<f<<endl;
	
	return 0;
}
