int RecBinSearch (int * data, int first, int last, int target) 
{
  if (first > last) //1+1
  {
    return -1;//1 OR
  }
  int mid = (first + last) >> 1; //first + last = 1 + 1 (>>)
  if (data [mid] == target) //1+1+1
  {
    return mid;//1 OR
  }
  if (data [mid] > target) //1+1+1
  {
    return RecBinSearch (data, first, mid - 1, target);//1 + T(n/2)   OR 
  } 
  else //0
  {
    return RecBinSearch (data, mid + 1, last, target);//1 + T(n/2)  OR
  } 
}

//T(N) recursive case =
// 2+
// 2+
// 3+
// 3+ (Skipping recursive cases except last)
// 1+T(n/2)
//T(n/2) = 11+T(n/2/2) //substituting n/2 for n
//= T(N) = 11 + 11 + T(n/2/2)
// = 11*k + T(n/2^k)
// T(1) = 11+T(1/2) //the integer 1/2 = 0
//T(1) = 11+T(0) = 11+3 = 14
//T(1) = T(n/2^k) *2^k
//2^k = n
//log base 2 of both sides
//k = log base2 N
//=(11*log base 2 N) + 14
//O(11 * log base 2 (N) + 14) 




//T(0)  if(first>last) is base case, nothing left, T(0)
//T(0) = 3
