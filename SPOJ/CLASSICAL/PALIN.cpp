#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char k[1000099],orig[1000099];

main()
{
    int t;
    int i,j,l,all_nine,len,mid,mid1,mid2;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%s",orig);
        for (i=0;orig[i]&&orig[i]=='0';i++);
        strcpy(orig,orig+i);

        strcpy(k,orig);
        all_nine=len=0;
        for (i=0;k[i];i++)
        {
            len++;
            if (k[i]=='9')
                all_nine++;
        }
        if (len==0)
        {
            printf("1\n");
            continue;
        }
        if (all_nine!=len)
            all_nine=0;

        if (all_nine)
        {
            memset(k,'0',len+1);
            k[len+1]='\0';
            k[0]=k[len]='1';
            printf("%s\n",k);
            continue;
        }

        //mirror

        mid=len/2;
        if (len&1)
        {
            mid1=mid;
            mid2=mid;
        }
        else
        {
            mid1=mid;
            mid2=mid-1;
        }

        for (i=mid1,j=mid2;i<len;i++,j--)
            k[i]=k[j];

        for (i=mid;i<len;i++)
            if (k[i]!=orig[i])
                break;

        if (k[i]>orig[i])
            printf("%s\n",k);

        else
        {
            i=mid1,j=mid2;
            for (;i>=0;i++,j--)
            {
                if (k[i]=='9')
                    k[i]=k[j]='0';
                else
                {
                    k[i]=k[j]=k[i]+1;
                    printf("%s\n",k);
                    break;
                }
            }
        }
    }
    return 0;
}
