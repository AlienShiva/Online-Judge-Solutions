#include <stdio.h>
#include <string.h>

#ifdef ONLINE_JUDGE
#define putchar putchar_unlocked
#endif

short grid[9][9];
short cnt[9][9];
short domain[9][9];

void block(int row, int col, int val)
{
    int i,j,k,rowtab,coltab;

    for (j=0;j<9;j++)
        if (domain[row][j] & (1<<val))
        {
            domain[row][j]&= ~(1<<val);
            cnt[row][j]--;
        }

    for (i=0;i<9;i++)
        if (domain[i][col] & (1<<val))
        {
            domain[i][col]&= ~(1<<val);
            cnt[i][col]--;
        }

    rowtab=row/3 * 3;
    coltab=col/3 * 3;

    for (i=rowtab; i<rowtab+3; i++)
        for (j=coltab; j<coltab+3 ;j++)
            if (domain[i][j] & (1<<val))
            {
                domain[i][j]&= ~(1<<val);
                cnt[i][j]--;
            }

    grid[row][col]=val;
    cnt[row][col]=100;
}

void init()
{
    int i,j,k;

    for (i=0;i<9;i++)
        for (j=0;j<9;j++)
            cnt[i][j]=9;

    memset(domain,255,sizeof(domain));

    for (i=0;i<9;i++)
        for (j=0;j<9;j++)
            if (grid[i][j])
                block(i,j,grid[i][j]);

    for (i=0;i<9;i++)
        for (j=0;j<9;j++)
        {
            if (grid[i][j])
            {
                cnt[i][j]=10;
                for (k=0;k<10;k++)
                    domain[i][j]&= ~(1<<k);
            }
        }
}

inline void read_grid()
{
    int i,j,k,val;
    char s[82];

    scanf(" %s",s);

    k=0;
    for (i=0;i<9;i++)
        for (j=0;j<9;j++)
        {
            if (s[k]!='.')
                val=s[k]-48;
            else
                val=0;

            grid[i][j]=val;
            k++;
        }
}

inline void print_grid()
{
    int i,j;
    putchar('Y');
    putchar('\n');
    for (i=0;i<9;i++)
        for (j=0;j<9;j++)
            putchar(grid[i][j]+48);
    putchar('\n');
}

int findEmpty(int *row, int *col)
{
    int i,j,mrv;

    mrv=10;
    for (i=0;i<9;i++)
        for (j=0;j<9;j++)
            if (cnt[i][j]<mrv)
            {
                *row=i;
                *col=j;
                mrv=cnt[i][j];
            }

    if (mrv==10)
        return 0;

    return 1;
}

int solve()
{
    int row, col,num;
    short tdomain[9][9];
    short tcnt[9][9];
    if (!findEmpty(&row, &col))
        return 1;

    int i,j,rowtab,coltab;
    short isok=0;

    for (j=0;j<10;j++)
        if(domain[row][col] & (1<<j))
            isok|=1<<j;

    for (num = 1; num <= 9; num++)
    {
        if (isok & (1<<num))
        {
            memcpy(tdomain,domain,sizeof(domain));
            memcpy(tcnt,cnt,sizeof(cnt));

            block(row,col,num);

            if (solve())
                return 1;

            memcpy(domain,tdomain,sizeof(tdomain));
            memcpy(cnt,tcnt,sizeof(tcnt));
        }
    }
    return 0;
}

main()
{
    int t;

    scanf("%d",&t);
    while (t--)
    {
        read_grid();
        init();
        solve();
        print_grid();
    }
    return 0;
}
