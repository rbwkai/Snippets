
vi lpf(N+1);
void pre(){
  for(int i=2; i<N; ++i){
    if(!lpf[i]) for(int j=i; j<=N; j+=i){
      if(!lpf[j]) lpf[j]=i;
    }
  }
}



