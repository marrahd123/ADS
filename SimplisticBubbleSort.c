int SimplisticBubbleSort (int * data, int length)
{
  int lcv1, lcv2;
  int temp;
  if (data != NULL) //1 unit of run time(comparing data to null) + 1 other unit of run time(if statement)    ---2---
  {
    for (lcv1 = 0; lcv1 < length; lcv1++)//1 unit(lcv1 = 0) + (1*(loopbody n + 1)) + (1*n) ->not done prior to the loop body, but after the loop body ---2N+1---
    {
      for (lcv2 = 0; lcv2 < (length - 1); lcv2++)// (n *)  1(lcv2=0) + (2* (n+1-1)) + (1* (n-1)) -> the n-1 is because that will always be 1 less than the previous ---- 3N^2---
      {
        if (data [lcv2] < data [lcv2 + 1])//(n * (n-1) * ) (1 (if) + 1 (data at lcv2) + 1 (plus one) + 1 (comparison) + 1 (data at lcv2+1) ) ----5N^2-5N----
        {
          temp = data [lcv2];//n*(n-1) * 1(allocation)
          data [lcv2] = data [lcv2 + 1]; //n*(n-1) * (1 (addition) + 1 + 1 (two array lookups))   -----6N^2-6N----- (all of that)
          data [lcv2 + 1] = temp;//n*(n-1) * (1 + 1) (addition + lookup) 
        }//if
      }//for
    }//for
    return 0; // 1 unit of time 
  }//if 
  else 
  {
    return 1;
  }//else
}//main


//WORST CASE: All of that stuff added = O(14n^2 - 9n + 4)
//BEST CASE: never have to swap: horseshoe (8n^2 -3n +4)