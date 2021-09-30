/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: WCB
*/

#include<stdio.h>

#include<cstring>
using namespace std;
int dp[1005][1005];
char chc[2005];
char a[1005],b[1005];
int sizea,sizeb;
void q ()
{
		scanf("%s",chc+1);
	
		for(int ai=0;ai<=sizea+1;ai++)
		{for(int aj=0;aj<=sizeb+1;aj++)
		{
			dp[ai][aj]=0;
		}}
	
		dp[0][0]=1;
	for(int ai=1;ai<=sizea;ai++)
	{
		//printf("a[%d] = %c ; chc[%d] = %c \n",ai,a[ai],ai,chc[ai]);
		if(chc[ai]==a[ai]&&dp[ai-1][0]==1)
		{dp[ai][0]=1;//printf("HAY\n");
		}
	}
	for(int ai=1;ai<=sizeb;ai++)
	{//printf("b[%d] = %c ; chc[%d] = %c \n",ai,b[ai],ai,chc[ai]);
		if(chc[ai]==b[ai]&&dp[0][ai-1]==1)
		{dp[0][ai]=1;//printf("HAYb\n");
		}
	}

/*	for(int ia=0;ia<=sizea;ia++)
		{
			for(int ja=0;ja<=sizeb;ja++)
			printf("%d ",dp[ia][ja]);
			printf("\n");
		}
		printf("\n");
		
		*/
			for(int ai=1;ai<=sizea;ai++)
			for(int bi=1;bi<=sizeb;bi++)
			{
			//printf("ai = %d a = %c ;; bi = %d b = %c ;;chc[%d] = %c \n",ai,a[ai],bi,b[bi],ai+bi,chc[ai+bi]);
				if(chc[ai+bi]==a[ai]&&dp[ai-1][bi]==1)
				dp[ai][bi]=1;
				
				if(chc[ai+bi]==b[bi]&&dp[ai][bi-1]==1)
				dp[ai][bi]=1;
			}
		
		
	//printf("\n");
	/*	for(int ia=0;ia<=sizea;ia++)
		{
			for(int ja=0;ja<=sizeb;ja++)
			printf("%d ",dp[ia][ja]);
			printf("\n");
		}*/
		
		if(dp[sizea][sizeb]==1)
		printf("Yes\n");else printf("No\n");
	
	
}

main()
{
	scanf("%s",a+1);
	scanf("%s",b+1);
	sizea=strlen(a+1);
	sizeb=strlen(b+1);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
	q();
	}
}
