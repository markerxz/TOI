#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

int nnode,nedge;
int startz,endz,npeople;

struct data{
	int node,we;
	bool operator <(const data &a)const{
		return a.we>we;
	}
}d;
vector <data> v[2569];
priority_queue <data> q;

int mem[2569];

void findway (int posinow,int wenow)
{
//	printf("posinow = %d ; wenow = %d\n",posinow,wenow);
	if(mem[posinow]!=wenow)
	return ;
	
	for(int i=0;i<v[posinow].size();i++)
	{
		int mini=min(mem[posinow],v[posinow][i].we);
		if(mini>mem[v[posinow][i].node])
		{
			mem[v[posinow][i].node]=mini;
			d.node=v[posinow][i].node;
			d.we=mini;
		//	printf("push node %d ; we %d\n",d.node,d.we);
			q.push(d);
		}
	}
}

main()
{
	scanf("%d %d",&nnode,&nedge);
	int x,y,w;
	for(int i=1;i<=nedge;i++)
	{
		scanf("%d %d %d",&x,&y,&w);
		d.node=y;
		d.we=w;
		v[x].push_back(d);
		d.node=x;
		d.we=w;
		v[y].push_back(d);	
	}
	scanf("%d %d %d",&startz,&endz,&npeople);
	mem[startz]=100000069;
	findway(startz,100000069);
	while(!q.empty())
	{
		data temp = q.top();
		q.pop();
		findway(temp.node,temp.we);
	}
	int result = npeople/(mem[endz]-1);
	if(npeople%(mem[endz]-1)!=0)
	{
		result++;
	 } 
	printf("%d",result);
}













