// James Cain
int ImprovedBubbleSort (int * data, int length){
  int lcv1, lcv2;
  int temp;
  int start;
  int notdone;
  int somethingelse;
  if (data != NULL) {
    start = length - 1;
    notdone = 1;
    for (lcv1 = 1; notdone && (lcv1 < length); lcv1++){
      notdone = 0;
      for (lcv2 = start; lcv2 >= lcv1; lcv2--){
        somethingelse = lcv2 - 1;
        if (data [lcv2] < data [somethingelse]){
          notdone = 1;
          temp = data [lcv2];
          data [lcv2] = data [somethingelse];
          data [somethingelse] = temp;
        }
      }
    }
    return 0;
  } else {
    return 1;
  }
}

//Worst case for his ImprovedBubbleSort - O(6n^2 + 1n +2)
//Best Case = (6n+10)
