
using Tree = vector<vector<pi>>;
struct TreeLCA{
  ll n;
  vi par, val,  dep, jmp, jmp_M;
  TreeLCA(ll n_): n(n_),
                  par(n_+1), val(n_+1, inf),
                  dep(n_+1),
                  jmp(n_+1), jmp_M(n_+1, inf){}

  void dfs(Tree &edg, vi &value, ll at, ll pr){
    dep[at] = dep[pr]+1;
    par[at] = pr;
    val[at] = value[at];

    if(dep[jmp[jmp[pr]]]-dep[jmp[pr]]
    == dep[jmp[pr]]-dep[pr]){
      jmp[at] = jmp[jmp[pr]];
      jmp_M[at] = min(val[pr], min(jmp_M[pr], jmp_M[jmp[pr]]));
    }
    else{
      jmp[at]   = pr;
      jmp_M[at] = val[pr];
    }

    for(auto [to, wt]: edg[at]) if(to!=pr) dfs(edg, value, to, at);
  }
  void build(Tree &edg, vi &value){
    dfs(edg, value, 1, 0);
  }

  ll kth_anc(ll x, ll k){
    ll tl = dep[x]-k;

    if(tl<1) return -1;
    else{
      while(dep[x]!=tl) x = (dep[jmp[x]]>=tl? jmp[x]: par[x]);
      return x;
    }
  }
  ll kth_anc_min(ll x, ll k){
    ll tl = dep[x]-k;
    ll res = val[x];
    if(tl<1) return res;
    while(dep[x]!=tl){
      if(dep[jmp[x]]>=tl) res=min(res, jmp_M[x]), x=jmp[x];
      else res=min(res, val[par[x]]), x=par[x];
    }
    return res;
  }

  ll lca(ll a, ll b){
    if(dep[a]<dep[b]) swap(a, b);
    a = kth_anc(a, dep[a]-dep[b]);
    if(a==b) return a;

    while(jmp[a]!=jmp[b]){
      a=jmp[a];
      b=jmp[b];
    }
    while(a!=b){
      a=par[a];
      b=par[b];
    }
    return a;
  }
};



