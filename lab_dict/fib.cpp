/**
 * @file fib.cpp
 * Contains Fibonacci-number generating functions both utilizing and not
 * utilizing memoization.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "fib.h"

#include <map>

using std::map;

/**
 * Calculates the nth Fibonacci number where the zeroth is defined to be
 * 0.
 * @param n Which number to generate.
 * @return The nth Fibonacci number.
 */
unsigned long fib(unsigned long n)
{
    if (n == 1) {
        return 1; 
    } else if (n == 0) {
        return 0; 
    } 
    return fib(n - 1) + fib(n - 2);
}

/**
 * Calculates the nth Fibonacci number where the zeroth is defined to be
 * 0. This version utilizes memoization.
 * @param n Which number to generate.
 * @return The nth Fibonacci number.
 */
unsigned long memoized_fib(unsigned long n)
{
    static map<size_t, size_t> memoize = { {0, 0}, {1, 1}, };

    map<size_t, size_t>::iterator it = memoize.find(n);
    
    if (it != memoize.end()) {
        return it->second; 
    }
    memoize[n] = memoized_fib(n - 1) + memoized_fib(n - 2);
    return memoized_fib(n - 1) + memoized_fib(n - 2);
}

