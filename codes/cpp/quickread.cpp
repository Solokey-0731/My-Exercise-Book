#include<bits/stdc++.h>
int QuickRead()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<3)+(x<<1)+(c^48);//x=x*10+c-'0'
        c=getchar();
    }
    return x*f;
}

//Boss-Final Version~~
static char buf[100000], *pa = buf, *pd = buf;
#define gc pa == pd && (pd = (pa = buf) + fread(buf, 1, 100000, stdin), pa == pd) ? EOF : *pa++
inline int read()
{
    register int x(0);
    register char c(gc);
    while (c < '0' || c > '9')
        c = gc;
    while (c >= '0' && c <= '9')
        x = (x << 1) + (x << 3) + (c ^ 48), c = gc;
    return x;
}
