#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <fstream>

using namespace std;

main()
{
    int t,n;
    int i,j;
    char str[25];
    int vote;
    char names[101][25];
    int votes[101];
    int count,ct;
    bool found;
    char vt;

    cin>>t;
    while (t--)
    {
        memset(votes,0,sizeof(votes));
        cin>>n;
        count=0;
        ct=0;
        for (i=0;i<n;i++)
        {
            cin>>str>>vt;
            if (vt=='+')
                vote=1;
            else
                vote=-1;

            found=false;

            for (j=0;j<ct&&!found;j++)
                if (strcmp(str,names[j])==0)
                {
                    votes[j]=vote;
                    found=true;
                    break;
                }
            if (!found)
            {
                votes[ct]=vote;
                strcpy(names[ct],str);
                ct++;
            }

        }
        for (i=0;i<ct;i++)
            count+=votes[i];
        cout<<count<<endl;
    }
    return 0;
}