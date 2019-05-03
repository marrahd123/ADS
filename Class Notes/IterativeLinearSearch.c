// James Cain
int IterLinSearch (int * data, int length, int target) {
  int lcv;
  for (lcv = 0; lcv < length; lcv ++) {
    if (data [lcv] == target) {
      return lcv;
	printf("%d ", lcv);
    }
  }
  return -1;
}

// IterLinSearch ***** EXAM?
// for lcv = 0 (1 unit)
// lcv < length (n+1) 
// lcv ++ (n units)
// if...(1 unit + array lookup 1 + 1 equality check) = 1+1+1
// return lcv (1 unit)
// }
// }
// return( = or 1)

// TOTAL: 1+(N+1)+(N)
//         N * (1+1+1)
//         1 OR 1
// 1)  O(5N+3) WORST CASE
// 2) BEST CASE: (6)  (1+1) +(1+1+1) +1
// -Data Sensitive 
//     Best case is 1st element, worst case is last element
// After commenting out 1st return and uncommenting the print statement:
// -You can now repeat the print statement (where the 1st return was) which changes worst case, but best case stays the same
// - If you are looking for a 1 in an array of 0's, it won't print
// -Worst case: O(6n+3)
// -Best Case: O(5n+4)

// -Data insensitive
//     printing the letter a: NO POSSIBILITY OF VARIANCE