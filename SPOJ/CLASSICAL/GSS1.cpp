#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

#define LEFT(x) (x<<1)
#define RIGHT(x) ((x<<1)+1)

struct node
{
    int sum;
    int max_sum;
    int prefix;
    int suffix;
};

short int a[50001];
node t[131073];

void build_tree(int id, int s, int e)
{
    if(s==e)
    {
        t[id].sum = t[id].prefix = t[id].suffix = t[id].max_sum = a[s];
        return;
    }

    int l = LEFT(id);
    int r = RIGHT(id);

    build_tree(l,s,(s+e)>>1);
    build_tree(r,((s+e)>>1)+1,e);

    t[id].sum = t[l].sum + t[r].sum;
    t[id].max_sum = max( max(t[l].suffix + t[r].prefix, t[l].max_sum), t[r].max_sum);
    t[id].prefix = max( t[l].prefix, t[l].sum + t[r].prefix);
    t[id].suffix = max( t[r].suffix, t[r].sum + t[l].suffix);
}

node query(int id, int l, int r, int s, int e)
{
    if(l>=s && r<=e)
        return t[id];

    int mid = (l+r)>>1;

    if(e<=mid)
        return query(LEFT(id), l, mid, s, e);
    else if(s>mid)
        return query(RIGHT(id), mid+1, r, s, e);

    node p1 = query(LEFT(id), l, mid, s, e);
    node p2 = query(RIGHT(id), mid+1, r, s, e);
    node p3;

    p3.sum = p1.sum + p2.sum;
    p3.prefix = max(p1.prefix , p1.sum+p2.prefix);
    p3.suffix = max (p2.suffix, p2.sum+p1.suffix);
    p3.max_sum = max(max(p1.suffix+p2.prefix,p1.max_sum),p2.max_sum);

    return p3;
}

main()
{
    int i,n,m,s,e;

    scanf("%d",&n);
    for(i=1; i<=n; i++)
        scanf("%d",&a[i]);

    build_tree(1,1,n);

    scanf("%d",&m);
    while(m--)
    {
        scanf("%d %d",&s,&e);
        printf("%d\n",query(1,1,n,s,e).max_sum);
    }
    return 0;
}
