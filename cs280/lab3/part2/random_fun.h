// random_fun.h

#ifndef CS280_RANDOM_FUN
#define CS280_RANDOM_FUN

// Returns a random number between l and u with uniform probability.
long long equilikely(long long l, long long u);

// Returns a 0 50% of the time, and a 1 50% of the time.
int coin_flip();

// Returns an array containing all numbers from first to second in a 
// random order.
long long* generate_permutation(long long first, long long second);

#endif
