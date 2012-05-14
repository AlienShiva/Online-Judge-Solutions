#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

struct recipe
{
    int p;
    char name[1001];
} recipes[1001];

bool operator <(const recipe& a, const recipe& b)
{
    return (a.p<b.p);
}

struct node
{
    int p;
    node *ptr[27];
};

int n;

class Trie
{
public:
    node* root;
    int ans;
    Trie()
    {
        root=new node;
        init(root);
    }

    void init(node* vertex)
    {
        int i;
        vertex->p=0;
        for(i=0; i<27; i++)
            vertex->ptr[i]=NULL;
    }

    void insert(recipe r)
    {
        int i,n;

        node* curr=root;
        node* child;

        for(i=0; r.name[i]; i++)
        {
            if(isalpha(r.name[i]))
                n=r.name[i]-97;
            else
                n=26;

            child=curr->ptr[n];

            if(child!=NULL)
            {
                curr=child;
            }
            else
            {
                child=new node;
                init(child);
                curr->ptr[n]=child;
                curr=child;
            }
            curr->p=r.p;
        }
    }

    bool find(char query[])
    {
        int i,n;

        node* curr=root;
        node* child;

        for(i=0; query[i]; i++)
        {
            if(isalpha(query[i]))
                n=query[i]-97;
            else
                n=26;

            child=curr->ptr[n];

            if(child!=NULL)
            {
                curr=child;
            }
            else
            {
                return false;
            }
        }
        ans=curr->p;
        return true;
    }
};

main()
{
    int i,q;
    char query[1001];
    map <int,string> mapping;
    Trie t;

    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf(" %s %d",recipes[i].name,&recipes[i].p);
        mapping[recipes[i].p]=recipes[i].name;
    }

    sort(recipes,recipes+n);

    for(i=0; i<n; i++)
        t.insert(recipes[i]);

    scanf("%d",&q);
    while(q--)
    {
        scanf(" %s",query);
        if(t.find(query))
            printf("%s\n",mapping[t.ans].c_str());
        else
            printf("NO\n");
    }

    return 0;
}
