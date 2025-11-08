
ll hashll(ll x) {
    x += 0x9e3779b97f4a7c15LL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9LL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebLL;
    x = x ^ (x >> 31);
    return x;
}
