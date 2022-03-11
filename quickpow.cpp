#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll quickpow(ll x ,ll y, ll mod)
{
    ll res=1;
    for(x%=mod;y;y>>1,x*x%mod)
    if (y&1) res=res*x%mod;
    return res;
}