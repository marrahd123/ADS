int RecLinSearch (int * data, int length, int current, int target) { 
  if (current < length) {
    if (data [current] == target) {
      return current;
    } else {
      return RecLinSearch (data, length, current + 1, target);
    }
  } else {
    return -1;
  }
}


// 1+1 //if (current < length)
// 1+1+1 //if (data [current] == target)
// / 1 //return current;
// \ 1+1+T(N-1) //return RecLinSearch (data, length, current + 1, target);
// / 1 //return -1;
// \ 
// T(N) = 7+T(N-1)

// T(0) = 3 //base case

// T(N-1) = 7+T(N-1-1)
// T(N) = 7+7+T(N-1-1)

// T(N-2) = 7 + T(N-2-1)
// T(N) = 7+7+7+T(N-3)

// T(N) = 7 * K + T(N-K)

// N-K = 0
// //solve for zero
// K+N-K = 0 + K
// N = K

// T(N) = 7 * N + T(0) = 7*N+3
// 0(7N+3)

// O(7N+3)//worst case
// Best case = 6 //first three lines 
// Theta (when best case = worst case) DOES NOT EXIST OR its 0(3) if there is NO DATA
// //cannot be 3 (current>length) because that is a degenerate case we do not want to analyze