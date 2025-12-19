template<typename T>
struct Node{
  T val, res;
  ll pri, sze;
  bool rev;
  Node *l, *r;
  
  Node(const T& v): val(v), res(v),
                    pri(rndm(rng)),
                    sze(1),
                    rev(false),
                    l(nullptr), r(nullptr) {}
};
 
template<typename T>
int size(Node<T>* t){ return t? t->sze: 0; }
 
template<typename T>
T rslt(Node<T>* t){ return t? t->res: 0; } //result identity
 
template<typename T>
void pull(Node<T>* t){
  if(!t) return;
  t->res = t->val + rslt(t->l)+rslt(t->r);
  t->sze = 1 + size(t->l)+size(t->r);
}
 
template<typename T>
void push(Node<T>* t){
  if(!t or !t->rev) return;
  t->rev = false;
 
  swap(t->l, t->r);
  if(t->l) t->l->rev ^= true;
  if(t->r) t->r->rev ^= true;
}
 
template<typename T>
Node<T>* merge(Node<T>* L, Node<T>* R){
  if(!L) return R;
  if(!R) return L;
 
  push(L); push(R);
  if(L->pri > R->pri){
    L->r = merge(L->r, R);
    pull(L); return L;
  }else{
    R->l = merge(L, R->l);
    pull(R); return R;
  }
}
 
template<typename T>
pair<Node<T>*, Node<T>*> split(Node<T>* t, int k){
  if(!t) return {nullptr, nullptr};
  push(t);
 
  if(size(t->l) >= k){
    auto pr = split(t->l, k);
    t->l = pr.second;
    pull(t); return {pr.first, t};
  }else{
    auto pr = split(t->r, k-size(t->l)-1);
    t->r = pr.first;
    pull(t); return {t, pr.second};
  }
}
 
template<typename T>
Node<T>* reverse(Node<T>* t){
  t->rev ^= true;
  return t;
}
 
template<typename T>
Node<T>* build(vector<T> &v){
  Node<T>* tree = nullptr;
  fir(sz(v)){
    Node<T>* cur = new Node(v[i]);
    tree = merge(tree, cur);
  }
  return tree;
}
template<typename T>
void destroy(Node<T>* t){
  if(!t) return;
  destroy(t->l); destroy(t->r);
  delete t;
}
 
template<typename T>
void print(Node<T>* t) {
  if(!t) return;
  push(t);
 
  print(t->l);
  cout<<t->val;
  print(t->r);
}
 
void solve(){
  ll n, k; cin>>n>>k;
  vi v(n); fir(n) cin>>v[i];
 
  auto tree = build(v);
  fir(k){
    ll t, l, r; cin>>t>>l>>r; l--; r--;
    if(t==1){
      auto [A, B] = split(tree, l);
      auto [Bp, C] = split(B, r-l+1);
 
      B = reverse(Bp);
      tree = merge(A, merge(B, C));
    }
    if(t==2){
      auto [A, B] = split(tree, l);
      auto [Bp, C] = split(B, r-l+1);
 
      cout<<rslt(Bp)<<en;
      tree = merge(A, merge(Bp, C));
    }
  }
  destroy(tree);
}
