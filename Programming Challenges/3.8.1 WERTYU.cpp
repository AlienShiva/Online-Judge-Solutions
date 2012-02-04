#include <iostream>
#include <string>
using namespace std;

main()
{
    string l,ip;
    int i,len,in;
    char ch;

    l="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    while(getline(cin,ip,'\n'))
    {
        len=ip.size();
        for(i=0;i<len;i++)
        {
            ch=ip[i];
            in=l.find(ch,0);
            if(in!=string::npos)
                ip[i]=l[in-1];
        }
        cout<<ip<<endl;
    }
    return 0;
}
