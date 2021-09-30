#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int ncity,nedge,nfueltank,startz,endz;
int shp[2][105][105];
int fuelcost[105];
struct datax{
	int node,we;
}dx;
struct data{
	int node,fuel,cost;
	bool prime;
	bool operator <(const data &a)const{
		return a.cost<cost;
	}
}d;
vector <datax> v[105];
priority_queue <data> q;
void findway (int posinow,bool primenow,int fuelnow,int costnow)
{
//	printf("posinow = %d ; primenow = %d ; fuelnow = %d ; costnow = %d ;shp = %d\n",posinow,primenow,fuelnow,costnow,shp[primenow][posinow][fuelnow]);
	if(shp[primenow][posinow][fuelnow]<costnow)
		{
		//	printf("no shit\n");
			return ;
			
		}
		
		

	
	if(fuelnow<nfueltank&&shp[primenow][posinow][fuelnow]+fuelcost[posinow]<shp[primenow][posinow][fuelnow+1])
	{
		shp[primenow][posinow][fuelnow+1]=shp[primenow][posinow][fuelnow]+fuelcost[posinow];
		d.node=posinow;
		d.fuel=fuelnow+1;
		d.prime=primenow;
		d.cost=shp[primenow][posinow][fuelnow+1];
		q.push(d);
	}
	
	for(int i=0;i<v[posinow].size();i++)
	{
		int fuelleft=fuelnow-v[posinow][i].we;
		if(fuelleft>=0)
		{
			if(shp[primenow][posinow][fuelnow]<shp[primenow][v[posinow][i].node][fuelleft])
			{
				shp[primenow][v[posinow][i].node][fuelleft]=shp[primenow][posinow][fuelnow];
				d.node=v[posinow][i].node;
				d.cost=costnow;
				d.prime=primenow;
				d.fuel=fuelleft;
				q.push(d);
			}
		}
	}
	if(!primenow)
	{
		if(shp[primenow][posinow][fuelnow]<shp[!primenow][posinow][nfueltank])
		{
			shp[!primenow][posinow][nfueltank]=shp[primenow][posinow][fuelnow];
			d.node=posinow;
			d.cost=costnow;
			d.fuel=nfueltank;
			d.prime=!primenow;
			q.push(d);
		}
	}
}


main()
{
	scanf("%d",&ncity);
	for(int i=1;i<=ncity;i++)
	{
		scanf("%d",&fuelcost[i]);
		}	
	scanf("%d %d %d",&startz,&endz,&nfueltank);
	for(int i=0;i<=nfueltank;i++)
	{
		for(int j=0;j<=ncity;j++)
		{
			shp[false][j][i]=INT_MAX;
			shp[true][j][i]=INT_MAX;
		}
	}
	scanf("%d",&nedge);
	int x,y,w;
	for(int i=1;i<=nedge;i++)
	{
		scanf("%d %d %d",&x,&y,&w);
		dx.node=x;
		dx.we=w;
		v[y].push_back(dx);
		dx.node=y;
		v[x].push_back(dx);
	}
	shp[false][startz][0]=0;
	findway(startz,false,0,0);
	while(!q.empty())
	{
		data temp=q.top();
		q.pop();
		findway(temp.node,temp.prime,temp.fuel,temp.cost);
	}
	
	printf("%d",shp[true][endz][nfueltank]);
	
}











