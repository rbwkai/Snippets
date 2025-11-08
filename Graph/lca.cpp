
  //populate first row of bin with parents
  fjr(20) fir(n) if(j) bin[i+1][j]=bin[ bin[i+1][j-1] ][j-1];

  auto lca = [&](ll a, ll b){
    if(dp[a]>dp[b]) swap(a, b);

    ll jr=dp[b]-dp[a];
    fir(20) if((jr>>i)&1) b=bin[b][i];

    if(a==b){
      return a;
    }
    fir(20){
      ll ch=19-i;
      if(bin[a][ch]!=bin[b][ch]) a=bin[a][ch], b=bin[b][ch];
    }
    return bin[a][0];
  };
