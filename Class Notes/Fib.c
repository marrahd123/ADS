// James Cain
//O(2^n)
int RecFib (int n) {
  if (n <= 1) {
    return n;
  } else {
    return RecFib (n - 1) + RecFib (n - 2);
  }
}

//O(N)
int ArrayFib (int n) {
// Derived from Algorithm 1.7, page 15, Foundations of Algorithms, 4th Ed., by R. Neapolitan & K. Naimipour
  if (n >= 1) {
    int lcv;
    int * fib = (int *) malloc (n * sizeof(int));
    fib [0] = 0;
    fib [1] = 1;
    fib [2] = 1;
    for (lcv = 3; lcv <= n; lcv ++) 
    {
      fib [lcv] = fib [lcv - 1] + fib [lcv - 2];//this part is iterative, not recursive. IT IS LINEAR. N
      //fib only needs the 2 previous values, that is it
    }
    int temp = fib[n];
    free(fib);
    return fib [n];
  } else {
    return n;
  }
}

//Linear O(something N)
int IterFib (int n) {
  int lcv, total, prev1, prev2;
  for (lcv = 2, total = n, prev2 = 0, prev1 = 1; lcv <= n; lcv++) {
    total = prev1 + prev2;
    prev2 = prev1;
    prev1 = total;
  }
  return total;
}

int OptimalFib (int n) {
  int total, prev1, prev2;
  for (total = n, prev2 = 0, prev1 = 1; n > 1; n--) {
    total = prev1 + prev2;
    prev2 = prev1;
    prev1 = total;
  }
  return total;
}
