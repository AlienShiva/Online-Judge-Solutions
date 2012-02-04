#include<iostream>
using namespace std;

main()
{
    string s;
    printf("Ready\n");
    getline(cin,s);
    while(!(s[0]==' ' && s[1]==' '))
    {
        if(s[0]=='b'&&s[1]=='d')
            printf("Mirrored pair\n");
        else if(s[0]=='d'&&s[1]=='b')
            printf("Mirrored pair\n");
        else if(s[0]=='p'&&s[1]=='q')
            printf("Mirrored pair\n");
        else if(s[0]=='q'&&s[1]=='p')
            printf("Mirrored pair\n");
        else
            printf("Ordinary pair\n");
        getline(cin,s);
    }
    return 0;
}
