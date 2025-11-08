
ll p_inv(vi &v){
  ll res=0, n=sz(v);
  ordered_set<ll> st; //NOT a multiset. index ordered set might not work if problem requires something else. 
  fir(n) st.insert(v[i]);
  fir(n){
    res+=st.order_of_key(v[i]);
    st.erase(st.find(v[i]));
  }
  return res;
}
