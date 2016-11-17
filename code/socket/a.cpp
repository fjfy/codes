#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct 
{
	double **mat;
	int m,n;
}matrix;
void initial(matrix &T,int m,int n)
{
	int i;
	T.mat=(double **)malloc(m*sizeof(double*));
	for (i=0;i<m;i++)
	{
		T.mat[i]=(double*)malloc(n*sizeof(double));
	}
	T.m=m;
	T.n=n;
}
void initzero(matrix &T,int m,int n)
{
	initial(T,m,n);
	for(int i=i;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			T.mat[i][j]=0;
		}
	}
}
void destroy(matrix &T)
{
	for(int i=0;i<T.m,i++)
		free(T.mat[i]);
	free(T.mat);

}
int main()
{
	
	return 0;
}