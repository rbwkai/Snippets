
// dp [j] = min{ f(i) + g(i)*h(j) : b + mx
// query h(j) : x
// insert g(i), f(i) : m, b
struct LCTree{
  struct Line{ll m, b;};
  struct Node{
    Line line;
    Node *l=nullptr, *r=nullptr;
    Node(Line _line): line(_line){}
  };
  
  ll L, R;
  Node *root = nullptr;
  LCTree(ll _L, ll _R): L(_L), R(_R) {}
  
  ll eval(Line& line, ll x) {return line.m*x + line.b;}
 
  void inBE(Line nwline, Node*& nd, ll lo, ll hi){
    if(!nd){
      nd = new Node(nwline);
      return;
    }
 
    ll md = lo + (hi-lo)/2;
    if(eval(nwline, md) <= eval(nd->line, md)) swap(nwline, nd->line);
    if(lo == hi) return;
 
    if (eval(nwline, lo) < eval(nd->line, lo))
      inBE(nwline, nd->l, lo, md);
    else if (eval(nwline, hi) < eval(nd->line, hi))
      inBE(nwline, nd->r, md+1, hi);
  }
  void insert(ll m, ll b){
    Line nline{m, b};
    inBE(nline, root, L, R);
  }
 
  ll query(ll x, Node* nd=nullptr, ll lo=inf, ll hi=inf) {
    if(lo==inf) nd=root, lo=L, hi=R;
    if(!nd) return inf;
 
    ll res = eval(nd->line, x);
    if (lo == hi) return res;
 
    ll md = lo + (hi-lo)/2;
    if (x<=md and nd->l)
      res = min(res, query(x, nd->l, lo, md));
    else if (x > md and nd->r)
      res = min(res, query(x, nd->r, md+1, hi));
    return res;
  }
 
  void clear(Node* nd) {
    if(!nd) return;
    clear(nd->l); clear(nd->r);
    delete nd;
  }
  ~LCTree() {clear(root);}
};


