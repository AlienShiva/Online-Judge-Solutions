#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct node
{
    bool isnumber;
    node* ptr[10];
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
        vertex->isnumber=false;
        for(i=0; i<10; i++)
            vertex->ptr[i]=NULL;
    }

    bool insert_and_check(char num[])
    {
        int i,l,n;

        node* curr=root;
        node* child;
        bool isnew;

        l=strlen(num);
        for(i=0; i<l; i++)
        {
            n=num[i]-48;

            child=curr->ptr[n];

            if(child!=NULL)
            {
                isnew=false;
                curr=child;
                if(curr->isnumber==true)
                    return false;
            }
            else
            {
                isnew=true;
                child=new node;
                init(child);
                curr->ptr[n]=child;
                curr=child;
            }
        }

        if(isnew==false)
            return false;

        curr->isnumber=true;

        return true;
    }

    ~trie()
    {
        delete_trie(root);
    }

    void delete_trie(node* vertex)
    {
        if(vertex==NULL)   return;

        int i;
        for(i=0; i<10; i++)
            if(vertex->ptr[i]!=NULL)
                delete_trie(vertex->ptr[i]);

        delete vertex;
    }
};

main()
{
    int i,j,T,n;
    char num[12];
    register char c;
    bool consistent;
    trie* t=NULL;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);

        t=new trie;
        consistent=true;
        for(i=0; i<n; i++)
        {
            c=0; j=0;
            while(c<33) c=getchar_unlocked();
            while(c>33)
            {
                num[j++]=c;
                c=getchar_unlocked();
            }
            num[j]='\0';

            if(consistent)
                consistent=t->insert_and_check(num);
        }

        if(consistent)
            printf("YES\n");
        else
            printf("NO\n");

        delete t;
    }
    return 0;
}
