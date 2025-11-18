struct MEX{ //tested
  map<ll, ll> fq;
  set<ll> ms = {0};
  ll k = 0;

  void insert(ll u){
    ms.erase(u);
    fq[u]++, k++;

    if(!fq[k]) ms.insert(k);
  }
  void erase(ll u){
    fq[u]=max(fq[u]-1, 0LL);
    if(!fq[u]) ms.insert(u);
  }
  ll mex(){
    return *ms.begin();
  }
};
