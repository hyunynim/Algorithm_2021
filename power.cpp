int pow(int a, int n){
  if(n == 0) return 1;
  if(n == 1) return a;
  
  if(n % 2)
    return pow(a, n - 1) * a;
  
  int res = pow(a, n / 2);
  return res * res;
}
