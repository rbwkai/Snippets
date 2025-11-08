vi inv(N+1), fac(N+1), ifc(N+1);
vi lpf(N+1), mob(N+1);

void pre(){
  inv[0]=0; fac[0]=ifc[0]=1;
  fir(N) if(i){
    inv[i] = (i==1? 1: (inv[i-mod%i]*(mod/i+1))%mod);
    fac[i] = (fac[i-1]*i)%mod;
    ifc[i] = (ifc[i-1]*inv[i])%mod;
  }
  
  for(int i=2; i<N; ++i){
    if(!lpf[i]) for(int j=i; j<=N; j+=i){
      if(!lpf[j]) lpf[j]=i;
    }
  }
 
  mob[1]=1;
  for(int i=2; i<N; i++){
    if(lpf[i/lpf[i]]==lpf[i]) mob[i]=0;
    else mob[i]=-1*mob[i/lpf[i]];
  }
}
