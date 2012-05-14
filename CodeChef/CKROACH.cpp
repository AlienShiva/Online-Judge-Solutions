/*
Strategy : everytime when choosing an insecticide,
choose the one with the least cost to damage ratio
w.r.t. the remaining alive Gs.
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;
int c[201];
int p[201][201];
double alive[201];
bool used_dpc[201];
bool used_cpd[201];

bool pending()
{
    for(int i=0; i<n; i++)
        if(alive[i] > 0.10)
            return true;

    return false;
}

void apply(double arr[], int id)
{
    for(int i=0; i<n; i++)
        if(arr[i]>0.10)
            arr[i] *= (100 - p[i][id]) / 100.0;
}

int find_cheaper_end(bool used[],int id)
{
    int i,j;
    double talive[201];
    bool found;

    for(i=0; i<m; i++)
        if(!used[i] && i!=id && c[i]<c[id])
        {
            memcpy(talive,alive,sizeof(alive));
            apply(talive,i);

            found=true;
            for(j=0; j<n; j++)
                if(talive[j] > 0.10)
                    found=false;

            if(found)
                return i;
        }

    return -1;
}

int select_cpd()
{
    int i,j,best_id;
    double ratio,best_ratio;
    double damage,best_damage;
    double talive[201];

    best_ratio=1e9;
    best_id=0;
    best_damage=0;
    for(i=0; i<m; i++)
        if(!used_cpd[i])
        {
            memcpy(talive,alive,sizeof(alive));
            apply(talive,i);

            damage=0;
            for(j=0; j<n; j++)
                damage+=alive[j]-talive[j];

            damage*=100.0;

            ratio=(200+c[i])/damage;

            if(ratio==best_ratio && damage>best_damage)
            {
                best_ratio=ratio;
                best_id=i;
                best_damage=damage;
            }
            else if(ratio<best_ratio)
            {
                best_ratio=ratio;
                best_id=i;
                best_damage=damage;
            }
        }

    return best_id;
}

int select_dpc()
{
    int i,j,best_id;
    double ratio,best_ratio;
    double damage,best_cost;
    double talive[201];

    best_ratio=-1e9;
    best_id=0;
    best_cost=1e9;
    for(i=0; i<m; i++)
        if(!used_dpc[i])
        {
            memcpy(talive,alive,sizeof(alive));
            apply(talive,i);

            damage=0;
            for(j=0; j<n; j++)
                damage+=alive[j]-talive[j];

            damage*=100.0;

            ratio=damage/c[i];

            if(ratio==best_ratio && c[i]<best_cost)
            {
                best_ratio=ratio;
                best_id=i;
                best_cost=c[i];
            }
            else if(ratio>best_ratio)
            {
                best_ratio=ratio;
                best_id=i;
                best_cost=c[i];
            }
        }

    return best_id;
}

void solve()
{
    int i,j,k,id,cid,cost_cpd,cost_dpc;
    int ans[201],ans_count_cpd,ans_count_dpc;

    for(i=0; i<n; i++)
        alive[i]=1;
    for(i=0; i<m; i++)
        used_cpd[i]=false;

    ans_count_cpd=0;
    cost_cpd=0;
    while(pending())
    {
        id=select_cpd();

        cid=find_cheaper_end(used_cpd,id);
        if(cid!=-1)
            id=cid;

        apply(alive,id);
        used_cpd[id]=true;
        ans[ans_count_cpd++]=id;
        cost_cpd+=c[id];
    }

    for(i=0; i<n; i++)
        alive[i]=1;
    for(i=0; i<m; i++)
        used_dpc[i]=false;

    ans_count_dpc=0;
    cost_dpc=0;
    while(pending())
    {
        id=select_dpc();

        cid=find_cheaper_end(used_dpc,id);
        if(cid!=-1)
            id=cid;

        apply(alive,id);
        used_dpc[id]=true;
        ans[ans_count_dpc++]=id;
        cost_dpc+=c[id];
    }

    if(cost_cpd<cost_dpc)
    {
        printf("%d\n",ans_count_cpd);
        for(i=0; i<m; i++)
            if(used_cpd[i]==true)
                printf("%d ",i+1);
        printf("\n");
    }
    else
    {
        printf("%d\n",ans_count_dpc);
        for(i=0; i<m; i++)
            if(used_dpc[i]==true)
                printf("%d ",i+1);
        printf("\n");
    }
}

void get_input()
{
    int i,j;

    scanf("%d %d",&n,&m);
    for(i=0; i<m; i++)
        scanf("%d",&c[i]);

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            scanf("%d",&p[i][j]);
    }
}

main()
{
    int t;

    scanf("%d",&t);
    while(t--)
    {
        get_input();
        solve();
    }

    return 0;
}
