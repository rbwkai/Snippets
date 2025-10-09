
template <class T>
struct segtree{
  int ss;
  vector<T> tree; 
  T treeidn;

  segtree(int n, T tid):
    ss(n),
    tree(4*n, tid), treeidn(tid) {}

  T merge(const T &a, const T &b){
    return max(a, b);
  }

  void build(int id, int l, int r, const vector<T> &v){
    if(l==r){
      tree[id] = v[l];
      return;
    }
    int m = l+(r-l)/2;
    build(id*2+1, l, m, v);
    build(id*2+2, m+1, r, v);
    tree[id] = merge(tree[id*2+1], tree[id*2+2]);
  }

  T query(int id, int l, int r, int ql, int qr){
    if(ql<=l and r<=qr) return tree[id];
    if(ql>r or qr<l) return treeidn;

    int m = l+(r-l)/2;
    T tl = query(id*2+1, l, m, ql, qr);
    T tr = query(id*2+2, m+1, r, ql, qr);
    return merge(tl, tr);
  }

  void update(int id, int l, int r, int idx, T val){
    if(l==r){
      tree[id] = val;
      return;
    }
    int m = l+(r-l)/2;
    if(idx<=m)
      update(id*2+1, l, m, idx, val);
    else
      update(id*2+2, m+1, r, idx, val);
    
    tree[id] = merge(tree[id*2+1], tree[id*2+2]);
  }

  void update(int idx, T val){
    update(0, 0, ss-1, idx, val);
  }
  void build(const vector<T> &v){
    build(0, 0, ss-1, v);
  }
  T query(int ql, int qr){
    return query(0, 0, ss-1, ql, qr);
  }
};
