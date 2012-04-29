#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct node
{
    int t,d;
};

bool operator < (node a, node b)
{
    return (a.t>b.t);
}

main()
{
    int t,n,i,m,c;
    node temp,t1,t2;

    scanf("%d",&t);
    while(t--)
    {
        priority_queue <node> q;

        scanf("%d",&n);

        for(i=0; i<n; i++)
        {
            scanf("%d %d",&t1.t,&t2.t);
            t1.d=1;
            t2.d=-1;
            q.push(t1);
            q.push(t2);
        }

        n=n<<1;
        m=0;
        c=0;
        for(i=0; i<n; i++)
        {
            temp=q.top();
            q.pop();

            c+=temp.d;
            m=max(m,c);
        }

        printf("%d\n",m);
    }
    return 0;
}
