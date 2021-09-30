#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

long long int shp[10001],shpz[10001];
struct data{
	int node;
	long long int we;
	bool operator <(const data &a)const{
		return a.we<we;
	}
}d;
struct datumz{
	int ans;
	long long int val;
}datum;
bool cmpr (const datumz &a,const datumz &b)
{
	return a.val<b.val||(a.val==b.val&&a.ans<b.ans);	
}
vector <data> v[10001]; 
vector <datumz> ans;
priority_queue <data> q;
int nnode,nedge,startz,endz,budget;
void findway(int nodenow)
{
	for(int i=0;i<v[nodenow].size();i++)
	{
		if((shp[v[nodenow][i].node]==0||shp[nodenow]+v[nodenow][i].we<shp[v[nodenow][i].node])&&shp[nodenow]+v[nodenow][i].we<=budget)
		{
			shp[v[nodenow][i].node]=shp[nodenow]+v[nodenow][i].we;
			d.node=v[nodenow][i].node;
			d.we=shp[v[nodenow][i].node];
			q.push(d);
		}
	}
}
void findwayZ(int nodenow)
{
	for(int i=0;i<v[nodenow].size();i++)
	{
		if((shpz[v[nodenow][i].node]==0||shpz[nodenow]+v[nodenow][i].we<shpz[v[nodenow][i].node]))
		{
			shpz[v[nodenow][i].node]=shpz[nodenow]+v[nodenow][i].we;
			d.node=v[nodenow][i].node;
			d.we=shpz[v[nodenow][i].node];
			q.push(d);
			
			if(shp[v[nodenow][i].node]!=0)
			{
				datum.ans=v[nodenow][i].node;
				datum.val=shpz[v[nodenow][i].node];
				ans.push_back(datum);
			}
			
		}
	}
}
main()
{
	scanf("%d %d",&nnode,&nedge);
	scanf("%d %d %d",&startz,&endz,&budget);
	int x,y;
	long long int w;
	for(int i=1;i<=nedge;i++)
	{
		scanf("%d %d %lld",&x,&y,&w);
		d.node=x;
		d.we=w;
		v[y].push_back(d);
		d.node=y;
		v[x].push_back(d);
	}
	findway(startz);
	while(!q.empty())
	{
		int temp=q.top().node;
		q.pop();
		findway(temp);
	}
	if(shp[endz]!=0)
	{
		printf("%d %lld %d",endz,shp[endz],0);
	}else{
		
		findwayZ(endz);
		while(!q.empty())
		{
			int temp=q.top().node;
			q.pop();
			findwayZ(temp);
		}
		sort(ans.begin(),ans.end(),cmpr);
		printf("%d %lld %d",ans[0].ans,shp[ans[0].ans],shpz[ans[0].ans]);
	}
}
