/*
LANG: C++
COMPILER: WCB
*/
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
struct data{
	int node,we;
	bool operator <(const data &a)const
	{return a.we<we;
	}
}d;

struct nde{
	int x,y;
	
}n[15009];

priority_queue <struct data> q;
vector <int> v;
int h[15009];
int hw[15009];

main()
{
	int nz,m;
	scanf("%d %d",&nz,&m);
	int a,b;
	scanf("%d %d",&a,&b);
	n[1].x=a;
	n[1].y=b;
	
	h[1]=1;
	
	int minwez=9999999999;
	int nd;
	for(int i=2;i<=nz;i++)
	{
		scanf("%d %d",&a,&b);
		n[i].x=a;
		n[i].y=b;
		
		int wez=max(n[i].x-n[1].x,n[1].x-n[i].x)+max(n[i].y-n[1].y,n[1].y-n[i].y);
			d.node=i;
		d.we=wez;
		hw[i]=wez;
		q.push(d);
		/*if(wez<minwez)
		{
			nd=i,minwez=wez;
		}*/
	}
	
	//d.node=nd;
//	d.we=minwez;
//	h[1]=
	//hw[1]=minwez;
	//q.push(d);
/*	while(!q.empty())
	{
			
			q.pop();
	}
	*/
	int ww=0;
	int nn=0;
	aa:
		while(!q.empty()&&nn<nz-1)
		{
			
			//printf("HAY");
			int qtn=q.top().node;
			int qtw=q.top().we;//printf("qtnd = %d ; qtwe = %d\n",q.top().node,q.top().we);	
				q.pop();	
				
				if(h[qtn]==1)goto aa;
				else
				{
				//	printf("HAY\n");
					//printf("qtnd = %d ; qtwe = %d\n",qtn,qtw);	
					h[qtn]=1;
					
					ww+=qtw;
					v.push_back(qtw);
					for(int i=1;i<=nz;i++)
					{
						int wez=max(n[i].x-n[qtn].x,n[qtn].x-n[i].x)+max(n[i].y-n[qtn].y,n[qtn].y-n[i].y);
						if(h[i]!=1&&wez<hw[i])
						{
							
								
							{d.node=i;
								d.we=wez;
								q.push(d);
								hw[i]=wez;
								}
								
								//printf("dn = %d  ;  dwe = %d qpush\n",d.node,d.we);
								
						}
					}
						
				}
			
			nn++;
		}
		
		sort(v.begin(),v.end());
		for(int i=v.size()-1;i>=v.size()-m+1;i--)
		{
			ww-=v[i];
		}
		
		
	
	printf("%d",ww);
}
