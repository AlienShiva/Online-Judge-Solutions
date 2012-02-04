#include <stdio.h>
#include <string.h>

#define MAX 1000000

#ifdef ONLINE_JUDGE
#define putchar putchar_unlocked
#endif

#define checkbit(x,i) (x[i>>5] & (1<<(i&31)))
#define setbit(x,i) (x[i>>5]&=~(1<<(i&31)))

unsigned short divs[MAX+100];
unsigned int sec[(MAX+100)/32];

inline void fastWrite(int a)
{
	static char snum[7];
	register int i=0;
	do
	{
		snum[i++]=a%10+48;
		a=a/10;
	}
	while (a);
	i=i-1;
	while (i>=0)
		putchar(snum[i--]);
	putchar('\n');
}

main()
{
	int k,s,cnt,dx;
	register int i,j;

	memset(divs,0,sizeof(divs));
	memset(sec,255,sizeof(sec));

	for(i=1;i<MAX;i++)
		for(j=i;j<=MAX;j+=i)
			divs[j]++;

	for(i=1;i<MAX;i++)
		for(j=i;j<=MAX;j+=i)
			if(checkbit(sec,j))
				if(divs[j] % divs[i] != 0)
					setbit(sec,j);

	cnt=0;
	for (i=1;i<=MAX;i++)
		if (divs[i]>3 && checkbit(sec,i))
			if((cnt++)==107)
			{
				cnt=0;
				fastWrite(i);
			}
	return 0;
}
