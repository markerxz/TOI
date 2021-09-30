#include<stdio.h>
#include<algorithm>
#include<limits.h>
#include<iostream>
using namespace std;
long long int cat[2000005];
long long int maxcat=0,mincat=LLONG_MAX;
int ncat;
long long int l,r,mid;
long long int ans;

bool checkcat (int teamsolomid)
{
	
	long long int eiei=-1;
	for(int i=1;i<=ncat;i++)
	{
		
		if(eiei!=-1&&cat[i]>teamsolomid)
		{
			if(cat[i]==eiei)
			{
				eiei=-1;
				continue;
			}else return false;
			
		}
		
		if(cat[i]>teamsolomid&&eiei==-1)
		{
			eiei=cat[i];
			continue;
		}
		
		
		
	}
	ans = teamsolomid;
	return true;
}

main()
{
	
	scanf("%d",&ncat);
	for(int i=1;i<=ncat;i++)
	{
		scanf("%lld",&cat[i]);
	//	cin>>cat[i];
	//	maxcat=max(cat[i],maxcat);
	//	mincat=min(cat[i],mincat);
	}
	
	
	l=0,r=LONG_MAX;
/*	if(checkcat(0))
	{
		printf("0");
		return 0;
	}
*/	while(l<=r)
	{
		
		mid=(l+r)/2;
	//	printf("l = %d mid = %d r = %d\n",l,mid,r);
		if(checkcat(mid))
		{
			r=mid-1;
		}else l=mid+1;
	}
	printf("%lld",ans);
}
