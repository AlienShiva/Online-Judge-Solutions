#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

inline void fastRead(int *a)
{
    register char c=0;
    while (c<33) c=getchar();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar();
    }
}

int n,network[100];

void identify_networks(vector <int> adj[])
{
    memset(network,0,sizeof(network));

    int i,j,k,l,next_no;
    bool visited[n];

    next_no=1;

    for(i=0; i<n; i++)
        if(network[i]==0)
        {
            queue <int> q;
            memset(visited,false,sizeof(visited));

            q.push(i);
            visited[i]=true;
            network[i]=next_no;
            while(!q.empty())
            {
                j=q.front();
                q.pop();

                l=adj[j].size();
                for(k=0; k<l; k++)
                    if(!visited[adj[j][k]])
                    {
                        q.push(adj[j][k]);
                        visited[adj[j][k]]=true;
                        network[adj[j][k]]=next_no;
                    }
            }
            next_no++;
        }
}

main()
{
    int t,m,a,b,q,x,y,i;

    fastRead(&t);
    while(t--)
    {
        fastRead(&n);
        fastRead(&m);

        vector <int> adj[n];

        for(i=0; i<m; i++)
        {
            fastRead(&a);
            fastRead(&b);

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        identify_networks(adj);

        fastRead(&q);

        for(i=0; i<q; i++)
        {
            fastRead(&x);
            fastRead(&y);

            if(network[x]==network[y])
            {
                putchar('Y');
                putchar('O');
            }
            else
            {
                putchar('N');
                putchar('O');
            }
            putchar('\n');
        }
    }

    return 0;
}
