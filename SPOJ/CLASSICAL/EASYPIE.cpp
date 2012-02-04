#include<iostream>
#include<cstring>
using namespace std;

struct t
{
	char name[16];
	bool success[9];
	int nos[9];
}teams[100];

main()
{
	int t,n,Time,i,j,nt;

	scanf("%d",&t);
	while(t)
	{
	    scanf("%d",&n);
        nt=0;
		char probID,result,name[16];
        int teamID;
        int noAcc[9],avSub[9],avTime[9];
        double as,at;
        bool found;
		for(i=0;i<100;i++)
			for(j=0;j<9;j++)
			{
				teams[i].success[j]=false;
				teams[i].nos[j]=0;
			}
		for(i=0;i<9;i++)
			noAcc[i]=avSub[i]=avTime[i]=0;

		while(n)
		{
		    scanf("%d %s %c %c",&Time,name,&probID,&result);
			found=false;
			for(i=0;i<nt && !found;i++)
				if(strcmp(teams[i].name,name)==0)
				{
					found=true;
					teamID=i;
					break;
				}
			if(!found)
			{
				strcpy(teams[nt].name,name);
				teamID=nt;
				nt++;
			}
			probID-=65;
			if(result=='R')
			{
				teams[teamID].nos[probID]++;
			}
			else
			{
				if(!teams[teamID].success[probID])
				{
					teams[teamID].success[probID]=true;
					noAcc[probID]++;
					avSub[probID]+=1+teams[teamID].nos[probID];
					avTime[probID]+=Time;
				}
			}
			n--;
		}
		for(i=0;i<9;i++)
		{
			printf("%c %d",i+65,noAcc[i]);
			if(noAcc[i]!=0)
			{
				as=double(double(avSub[i])/double(noAcc[i]));
				at=double(double(avTime[i])/double(noAcc[i]));
				printf(" %.2lf %.2lf",as,at);
			}
			printf("\n");
		}
		t--;
	}
	return 0;
}
