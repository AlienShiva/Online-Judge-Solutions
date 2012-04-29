#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

#define LEFT(x) (x<<1)
#define RIGHT(x) ((x<<1)+1)

struct interval
{
    int left, right, mid, sum;
    bool changed;
};

class SegmentTree
{
    interval node[262145];

public:
    void init(int id, int s, int e)
    {
        node[id].changed = false;
        node[id].sum = 0;
        node[id].left = s;
        node[id].right = e;
        node[id].mid = (s+e)>>1;

        if(s==e)
            return;

        init(LEFT(id), s, node[id].mid);
        init(RIGHT(id), node[id].mid+1, e);
    }

    void propagate_down(int id)
    {
        if(node[id].changed==false)
            return;

        node[id].changed = false;
        node[id].sum = node[id].right - node[id].left + 1 - node[id].sum;

        if(node[id].left==node[id].right)
            return;

        node[LEFT(id)].changed = !node[LEFT(id)].changed;
        node[RIGHT(id)].changed = !node[RIGHT(id)].changed;
    }

    void update(int id, int s, int e)
    {
        propagate_down(id);

        if(s>node[id].right || e<node[id].left)
            return;

        if(node[id].left>=s && node[id].right<=e)
        {
            node[id].changed = true;
            propagate_down(id);
        }
        else
        {
            update(LEFT(id),s,e);
            update(RIGHT(id),s,e);
            node[id].sum = node[LEFT(id)].sum + node[RIGHT(id)].sum;
        }
    }

    int query(int id, int s, int e)
    {
        propagate_down(id);

        if(s>node[id].right || e<node[id].left)
            return 0;

        if(node[id].left>=s && node[id].right<=e)
            return node[id].sum;

        return (query(LEFT(id),s,e) + query(RIGHT(id),s,e));
    }
};

SegmentTree t;

main()
{
    int n,m,s,e,o;

    scanf("%d %d",&n,&m);
    t.init(1,1,n);

    while(m--)
    {
        scanf("%d %d %d",&o,&s,&e);
        if(o)   printf("%d\n",t.query(1,s,e));
        else    t.update(1,s,e);
    }
    return 0;
}
