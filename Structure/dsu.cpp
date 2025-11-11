struct DSU{ //O(1)
  vi par, rnk;
  ll xr, cc;

  DSU(ll n): 
    par(n+1), rnk(n+1),
    xr(1), cc(n){
    fir(n+1) par[i]=i, rnk[i]=1;
  }

  ll root(ll x) {return (par[x]==x? x: par[x]=root(par[x]));}
  void link(ll x, ll y){
    x=root(x), y=root(y);
    if(x==y) return;

    if(rnk[x]<rnk[y]) swap(x, y);
    par[y]=x; rnk[x]+=rnk[y];
    xr=max(xr, rnk[x]); cc--;
  }
};

struct DSU{ //O(logN) with rollback
  vi par, rnk;
  ll cc;
  stack<pi> stk;
  
  DSU(ll n):
    par(n+1), rnk(n+1),
    cc(n){
    fir(n+1) par[i]=i, rnk[i]=1;
  }

  ll root(ll x) {return (par[x]==x? x: root(par[x]));}
  void link(ll x, ll y){
    x=root(x), y=root(y);
    if(x==y) {stk.push({-1, -1}); return;}

    if(rnk[x]<rnk[y]) swap(x, y);
    par[y]=x; rnk[x]+=rnk[y];
    stk.push({x, y}); cc--;
  }
  void undo(){
    auto [x, y]=stk.top(); stk.pop();
    if(x==-1) return;

    par[y]=y; rnk[x]-=rnk[y];
    cc++;
  }
};
