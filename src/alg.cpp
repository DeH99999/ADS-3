// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t MaxValue = num;
  uint64_t n = num;
  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
    } 
    else {
      n = 3 * n + 1;
    }
    if (n > MaxValue) MaxValue = n;
  }
  return MaxValue;
}

unsigned int collatzLen(uint64_t num) {
  unsigned int len = 1;
  uint64_t n = num;
  while (n != 1) {
    if (n % 2 == 0) {
      n /= 2;
    } 
    else {
      n = 3 * n + 1;
    }
    ++len;
  }
  return len;
}

unsigned int seqCollatz(unsigned int* maxlen, uint64_t lbound, uint64_t rbound) {
  unsigned int MaxLength = 0;
  unsigned int MaxNumber = 0;
  for (uint64_t n = lbound; n <= rbound; ++n) {
    unsigned int len = collatzLen(n);
    if (len > MaxLength) {
      MaxLength = len;
      MaxNumber = n;
    }
  }
  *maxlen = MaxLength;
  return MaxNumber;
}
