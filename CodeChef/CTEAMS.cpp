#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct node
{
    int a;
    int r;
};

int n;
node ip[100010];
node l[100010];

bool operator <(const node& a, const node& b)
{
    return (a.a<b.a);
}

int bfind(int val)
{
    int low,high,m;

    low=0;
    high=n;
    while (1)
    {
        m=(low+high)/2;

        if (val==l[m].a)
            break;

        else if (val<l[m].a)
            high=m;

        else
            low=m;
    }
    return m;
}

main()
{
    int i,pos,k,j;
    int ans[100010];
    int y,o,tot,ycnt,ocnt,posrat;

    scanf("%d",&n);

    tot=0;
    for (i=0;i<n;i++)
    {
        scanf("%d %d",&ip[i].a,&ip[i].r);

        l[i].a=ip[i].a;
        tot+=l[i].r=ip[i].r;
    }

    sort(l,l+n);

    pos=n/2 + n%2;
    y=o=0;

    for (i=0;i<pos;i++)
        y+=l[i].r;

    o=tot-y;

    ycnt=pos;
    ocnt=n-pos;

    for (k=n-1;k>=0;k--)
    {
        ans[k]=abs(o-y);

        i=bfind(ip[k].a);

        if (i<pos) //Young list
        {
            y=y-l[i].r;
            l[i].r=0;

            ycnt--;

            if (ycnt<ocnt)
            {
                posrat=l[pos].r;
                for (++pos;l[pos].r==0 && pos<n;pos++);
                ycnt++;
                ocnt--;
                if (pos>=0 && pos<n)
                {
                    y+=posrat;
                    o-=posrat;
                }
            }
        }
        else //Old list
        {
            o=o-l[i].r;
            l[i].r=0;

            ocnt--;

            if(i==pos)
            {
                for (++pos;l[pos].r==0 && pos<n;pos++);
            }

            if (ocnt<ycnt-1)
            {
                for (--pos;l[pos].r==0 && pos>=0;pos--);
                ocnt++;
                ycnt--;
                if (pos>=0 && pos<n)
                {
                    o+=l[pos].r;
                    y-=l[pos].r;
                }
            }
        }
    }

    for (i=0;i<n;i++)
        printf("%d\n",ans[i]);

    return 0;
}