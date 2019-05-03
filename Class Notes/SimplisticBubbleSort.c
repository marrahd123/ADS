int SimplisticBubbleSort (int * data, int length){
  int lcv1, lcv2;
  int temp;
  if (data != NULL) {
    for (lcv1 = 0; lcv1 < length; lcv1++){
      for (lcv2 = 0; lcv2 < (length - 1); lcv2++){
        if (data [lcv2] < data [lcv2 + 1]){
          temp = data [lcv2]; // 1
          data [lcv2] = data [lcv2 + 1]; // 1+1+1
          data [lcv2 + 1] = temp; // 1+1 
        }
      }
    }
    return 0;
  } else {
    return 1;
  }
}

// int SimplisticBubbleSort (int * data, int length){
//         int lcv1, lcv2;
        
//         (1 + 1)
//         4If - 1 Unit 
//         4(data != NULL) - 1 Unit
//             (1 + 1*(N+1) + 1*N)
//             5 lcv1 = 0 - 1 unit;
//             5 lcv1 < length - (1*(n+1)) Unit
//             5 lcv1++ - 1*n unit 
//                 (N * (1 + 2*(N+1-1) + 1*(N-1))
//                 6 lcv2 = 0 - 1 unit;
//                 6 lcv2 < length - (1*(n+1)) Unit
//                 6 lcv2++ - 1*n unit
//                 (N*(N-1)*(1+1+1+1+1))
//                 7 If - 1 
//                 7 data[lcv2] < data[lcv2+2] - Inequality - 1 
//                 7 [lcv2+1] - 1 unit
//                 7 data[lvc2] - 1 unit
//                 7 data[lvc2 +1] - 1 unit
//                 (N*(N-1)*(1+1+1+1+1+1))
//                 8 data[lcv2]
//                 9 data[lcv2]
//                 9 lcv2 + 1
//                 9 data[lcv2+1]
//                 10 data[lcv2+1]
//                 10 lcv2+1
//                 (1)
//Best = 8n^2-3N+4
//Worst = 14n^2-9N+4