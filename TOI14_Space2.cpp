#include<stdio.h>
#include<queue>
using namespace std;
struct data{
	//check 2 = checksquare/comet;
	//check 1 = checkstar/comet;
	//check 0 = just checking;
	int posii,posij;
	int round;
	bool flooding,all1_not0;
	int posij2;
	int checking;
}d;
queue <data> q;
bool mp[2][2005];
int sizei,sizej;
int zzz=1;
int square=0,comet=0,star=0;
void flood (int posii,int posij,int round,bool all1_not0)
{
	if(!mp[posii][posij])
	return ;
	
	mp[posii][posij]=false;
	
	if(mp[posii][posij+1])
	flood(posii,posij+1,round,all1_not0);
	
	if(posij-1>=0)
	if(mp[posii][posij-1])
	flood(posii,posij-1,round,all1_not0);
	
	if(posii+1<=zzz)
	{
		if(mp[posii+1][posij])
		flood(posii+1,posij,round,all1_not0);
		
	}else{
		if(all1_not0)
		{
			d.posii=1;
			d.posij=posij;
			d.flooding=true;
			d.all1_not0=true;
			d.checking=0;
			d.round=round+1;
			q.push(d);
		}
	}
	
	if(posii-1>=1)
	if(mp[posii-1][posij])
	flood(posii-1,posij,round,all1_not0);
	
}
void checksquare_comet (int posii,int posij,int round)
{
	if(posii<=zzz)
	{
		if(mp[posii][posij])
		square++;
		else comet++;
		flood(posii,posij+1,round,true);
	}else {
		d.posii=1;
		d.posij=posij;
		d.round=round+1;
		d.flooding=false;
		d.all1_not0=false;
		d.checking=2;
		q.push(d);
		flood(posii-1,posij,round,false);
	}
}
void checkstar_comet (int posii,int posij,int posij2z,int round)
{
	if(posii<=zzz)
	{
		if(mp[posii][posij]&&mp[posii][posij2z])
		checkstar_comet(posii+1,posij+1,posij2z-1,round);	
		else if(mp[posii][posij]||mp[posii][posij2z])
				{
					comet++;
					flood(posii,posij,round,true);
					flood(posii,posij2z,round,true);
				}else {
						if(mp[posii][posij-2]&&mp[posii][posij2z+2])
						{
							star++;
							flood(posii,posij-2,round,true);
						}else{
							comet++;
							flood(posii-1,posij-2,round,true);
						}
					}		
	}else {
		d.posii=1;
		d.posij=posij;
		d.posij2=posij2z;
		d.flooding=false;
		d.all1_not0=false;
		d.checking=1;
		d.round=round+1;
		q.push(d);
		flood(posii-1,posij-1,round,false);		
	}
}
main()
{
	scanf("%d %d",&sizej,&sizei);
	int round=1;
	int reali;
	for(int i=1;i<=sizei;i++)
	{
		reali=i%zzz;
		if(reali==0)
			reali=zzz;
		char O10[2005];
		scanf("%s",O10);
		for(int j=1;j<=sizej;j++)
		{
			mp[reali][j]=O10[j-1]-'0';	
		}
		if(reali==zzz||i==sizei)
		{
			if(i==sizei)
			zzz=reali;
			while(!q.empty()&&q.front().round==round)
			{
				data temp=q.front();
				q.pop();
				if(temp.flooding)
				{
					flood(temp.posii,temp.posij,temp.round,temp.all1_not0);
				}
				if(temp.checking==2)
				{
					checksquare_comet(temp.posii,temp.posij,temp.round);
				}
				if(temp.checking==1)
				{
					checkstar_comet(temp.posii,temp.posij,temp.posij2,temp.round);
				}
			}
			for(int laii=1;laii<=zzz;laii++)
			{
				for(int laij=1;laij<=sizej;laij++)
				{
					if(mp[laii][laij])
					{
						if(mp[laii][laij+1])
						checksquare_comet(laii+1,laij,round);
						else checkstar_comet(laii+1,laij+1,laij-1,round);
					}
				}
			}
			round++;	
		}
	}	
	printf("%d %d %d",square,star,comet);
}

/*
20 12
00000000000000000000
00000000001111111110
00000000000111111100
00000000000011111000
00000000000001110000
00000000000000100000
00000000000000000000
00011111000000000000
00011111000000000000
00011111000000000000
00011111000000000000
00011111000000000000
*/

