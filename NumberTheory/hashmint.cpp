struct hashmint{
  ll a,b,c;
  static const ll modA = 1000000007;
  static const ll modB = 1000000009;
  static const ll modC = 1000000021;
  hashmint(ll _v=0){
    a = (_v%modA + modA)%modA;
    b = (_v%modB + modB)%modB;
    c = (_v%modC + modC)%modC;
  }
  hashmint(ll _a, ll _b, ll _c){
    a = (_a%modA + modA)%modA;
    b = (_b%modB + modB)%modB;
    c = (_c%modC + modC)%modC;
  }

  friend hashmint operator+(const hashmint& x, const hashmint& y){ return hashmint(x.a + y.a, x.b + y.b, x.c + y.c); }
  friend hashmint operator-(const hashmint& x, const hashmint& y){ return hashmint(x.a - y.a, x.b - y.b, x.c - y.c); }
  friend hashmint operator*(const hashmint& x, const hashmint& y){
    return hashmint(x.a * y.a, x.b * y.b, x.c * y.c);
  }
  friend hashmint operator/(const hashmint& x, const hashmint& y){ return x*minv(y); }
  friend hashmint mpow(const hashmint& b, ll p){
    hashmint a=b, r=1;
    for( ; p; p>>=1, a=a*a) if(p&1) r=r*a;
    return r;
  }
  static ll modpow(ll b, ll e, ll m){
    ll res=1;
    while(e){
      if(e&1) res = (res*b)%m;
      b = (b*b)%m;
      e >>= 1;
    }
  return res;
  }
  friend hashmint minv(const hashmint& x){ return hashmint(modpow(x.a, modA-2, modA), modpow(x.b, modB-2, modB), modpow(x.c, modC-2, modC)); }
  friend bool operator==(const hashmint& x, const hashmint& y){ return x.a==y.a && x.b==y.b && x.c==y.c; }
};
