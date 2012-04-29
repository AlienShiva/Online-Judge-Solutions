#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int nval(char c)
{
    switch(c)
    {
    case 'A':
        return 0;
    case 'C':
        return 1;
    case 'G':
        return 2;
    case 'T':
        return 3;
    }
}

struct node
{
    unsigned short cnt;
    bool isdna;
    node* ptr[4];
};

class trie
{
public:
    node* root;
    trie()
    {
        root=new node;
        init(root);
    }

    void init(node* vertex)
    {
        int i;
        vertex->cnt=-1;
        vertex->isdna=false;
        for(i=0; i<4; i++)
            vertex->ptr[i]=NULL;
    }

    void insert(char seq[])
    {
        int i,n;

        node* curr=root;
        node* child;

        for(i=0; seq[i]; i++)
        {
            n=nval(seq[i]);

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
        }
        curr->cnt++;
        curr->isdna=true;
    }

    void traverse_and_count(node* vertex, unsigned short arr[])
    {
        if(vertex==NULL)   return;

        if(vertex->isdna==true)
            arr[vertex->cnt]++;

        int i;
        for(i=0; i<4; i++)
            if(vertex->ptr[i]!=NULL)
                traverse_and_count(vertex->ptr[i],arr);
    }

    ~trie()
    {
        delete_trie(root);
    }

    void delete_trie(node* vertex)
    {
        if(vertex==NULL)   return;

        int i;
        for(i=0; i<4; i++)
            if(vertex->ptr[i]!=NULL)
                delete_trie(vertex->ptr[i]);

        delete vertex;
    }
};

main()
{
    int i,j,n,m;
    unsigned short ans[20001];
    char c,seq[22];
    trie* t=NULL;

    scanf("%d %d",&n,&m);
    while(n && m)
    {
        t=new trie;

        memset(ans,0,sizeof(ans));

        for(i=0; i<n; i++)
        {
            c=0;
            j=0;
            while(c<33) c=getchar_unlocked();
            while(c>33)
            {
                seq[j++]=c;
                c=getchar_unlocked();
            }
            seq[j]='\0';

            t->insert(seq);
        }

        t->traverse_and_count(t->root,ans);

        for(i=0; i<n; i++)
            printf("%d\n",ans[i]);

        delete t;

        scanf("%d %d",&n,&m);
    }
    return 0;
}
