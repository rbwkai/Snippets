struct Trie{
  ll A, S;
  struct Node{
    vector<Node*> nxt;
    Node(): nxt(2, nullptr){}
  };
  Node* root;
 
  Trie(): A(2), S(64){
    root = new Node();
  }
 
  void insert(ll x){
    Node* cur = root;
    fir(S){
      bool bt = (x>>ii)&1;
      if(!cur->nxt[bt]) cur->nxt[bt] = new Node();
      cur = cur->nxt[bt];
    }
  }
  ll find(ll x){
    Node* cur = root;
    ll mtch = 0;
    fir(S){
      ll bt = (x>>ii)&1;
      if(cur->nxt[!bt]) mtch|=((!bt)<<ii), cur=cur->nxt[!bt];
      else mtch|=(bt<<ii), cur=cur->nxt[bt];
    }
    return mtch;
  }
 
  void clear(Node* node) {
    if (!node) return;
    for(Node* child: node->nxt)
      clear(child);
    delete node;
  }
  ~Trie() {
    clear(root);
  }
};
