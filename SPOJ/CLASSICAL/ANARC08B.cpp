#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int isdigit(int num)
{
    switch(num)
    {
        case 63 : return 0;
        case 10 : return 1;
        case 93 : return 2;
        case 79 : return 3;
        case 106 : return 4;
        case 103 : return 5;
        case 119 : return 6;
        case 11 : return 7;
        case 127 : return 8;
        case 107 : return 9;
    }
}

main()
{
    int i,len1,len2,temp,n1,n2;
    char ch,num[200],num1[100],num2[100],dec[4];
    dec[3]='\0';
    scanf(" %[^\n]s",num);
    for(i=0;num[i]!='+';i++)
        num1[i]=num[i];
    num1[i]='\0';
    len1=i;
    string s;

    for(len2=0,i++;num[i]!='=';i++,len2++)
        num2[len2]=num[i];
    num2[len2]='\0';

    while(strcmp("BYE",num1)!=0)
    {
        n1=0;
        for(i=0;i<len1;i+=3)
        {
            dec[0]=num1[i]; dec[1]=num1[i+1]; dec[2]=num1[i+2];
            n1=n1*10 + isdigit(atoi(dec));
        }
        n2=0;
        for(i=0;i<len2;i+=3)
        {
            dec[0]=num2[i]; dec[1]=num2[i+1]; dec[2]=num2[i+2];
            n2=n2*10 + isdigit(atoi(dec));
        }
        n1+=n2;
        s.clear();
        while(n1)
        {
            temp=n1%10;
            switch(temp)
            {
                case 0: s="063"+s;
                    break;
                case 1: s="010"+s;
                    break;
                case 2: s="093"+s;
                    break;
                case 3: s="079"+s;
                    break;
                case 4: s="106"+s;
                    break;
                case 5: s="103"+s;
                    break;
                case 6: s="119"+s;
                    break;
                case 7: s="011"+s;
                    break;
                case 8: s="127"+s;
                    break;
                case 9: s="107"+s;
                    break;
            }
            n1=n1/10;
        }
        printf("%s+%s=",num1,num2);
        cout<<s<<endl;

        scanf(" %[^\n]s",num);
        for(i=0;num[i]!='+';i++)
            num1[i]=num[i];
        num1[i]='\0';
        len1=i;

        for(len2=0,i++;num[i]!='=';i++,len2++)
            num2[len2]=num[i];
        num2[len2]='\0';
    }
    return 0;
}
