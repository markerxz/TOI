#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
char mapz[2001][2001];
int shpz[2001][2001];
int n,m;
struct data{
	int ai,aj;
}d;
bool checkz(int i,int j)
{
	if(i-j==1||i-j==-1)
	return true;
	
	return false;
}
bool checkkob(int i,int j)
{
	if(i>=0&&i<=n-1)
	if(j>=0&&j<=m-1)
	return true;
	
	return false;
}
queue <data> q;
vector <data> vecstort,vecanstor;
void printtable()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		if(shpz[i][j]==INT_MAX)
		printf("-1 ");
		else
		printf("%d ",shpz[i][j]);
		
		printf("\n");
	}
}

void findway (int posii,int posij)
{
	for(int i=-1;i<=1;i++)
	{
		for(int j=-1;j<=1;j++)
		if(checkz(i,j))
		{
			if(checkkob(posii+i,posij+j))
			{
				if(mapz[posii+i][posij+j]!='W'&&shpz[posii][posij]+1<shpz[posii+i][posij+j])
				{
					shpz[posii+i][posij+j]=shpz[posii][posij]+1;
					d.ai=posii+i;
					d.aj=posij+j;
					q.push(d);		
				}
			}
		}
	}
}
main()
{
	scanf("%d %d ",&n,&m);
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	shpz[i][j]=INT_MAX;
	for(int i=0;i<=n-1;i++)
	{
		scanf("%s",mapz[i]);
		for(int j=0;j<=m-1;j++)
		{
			//scanf(" %c",&mapz[i][j]);
			if(mapz[i][j]=='X')
			{
				d.ai=i;
				d.aj=j;
				vecstort.push_back(d);
				shpz[i][j]=0;
			}
			if(mapz[i][j]=='A')
			{
				d.ai=i;
				d.aj=j;
				vecanstor.push_back(d);
			}
		}
	}
	for(int i=0;i<vecstort.size();i++)
	{
		findway(vecstort[i].ai,vecstort[i].aj);
	}
	while(!q.empty())
	{
		findway(q.front().ai,q.front().aj);
		q.pop();
	}
	int count=0,summer=0;
	for(int i=0;i<vecanstor.size();i++)
	{
		if(shpz[vecanstor[i].ai][vecanstor[i].aj]<INT_MAX)
		{
			count++;
			summer+=shpz[vecanstor[i].ai][vecanstor[i].aj];
		}
	}
	//printtable();
	printf("%d %d",count,summer*2);
}



/*
5 5
EEEEE
AEAEW
WEEWW
WEEXE
WWEXA*/
