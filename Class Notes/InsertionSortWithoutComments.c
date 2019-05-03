// James Cain
int InsertionSort (int * data, int length){
  int lcv1, lcv2;
  int current;
  for (lcv1 = 1; lcv1 < length; lcv1 ++){
    current = data [lcv1];
    for (lcv2 = lcv1 - 1; (lcv2 >= 0) && (data [lcv2] > current); 
         data [lcv2 + 1] = data [lcv2 --]);
    data [lcv2 + 1] = current;
  }
  return 1;
}
