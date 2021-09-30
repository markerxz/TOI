#include<stdio.h>
bool cc[5000002];
main()
{
	int n;
	scanf("%d",&n);
	char x;
	for(int i=1;i<=n;i++)
	{
		scanf(" %c",&x);
		cc[i]=x-'0';
		
	/*	if(cc[i])
		printf("yay\n");
		else printf("noy\n");*/
		
	}
	int i=2;
	for(;i<=n;i++)
	{
		if(cc[i]!=cc[1])
		break;
	}
//	printf("%d",i);
	if(i-1==n){
	
		printf("1");
		return 0;
	}
	i=2;
	for(;i<=n/2;i++)
	{
		if(n%i==0)
		{
			int k=1;
			int j=1+i;
			for(;j<=n;j++,k++)
			{
			//	printf("k = %d ; j = %d\n",k,j);
				if(cc[k]!=cc[j])
				break;
				
				if(k==i)
				k=0;
				
			}
			if(j-1==n)
			{
			printf("%d",i);
			return 0;	
			}
			
		}
	}
	printf("%d",n);
	
}
