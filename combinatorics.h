/*                               _____ 
  *    ___ ___ ___  ___ ___  ___/ / _ \
  *   (_-</ -_) _ \(_-</ _ \/ _  /\_, /
  *  /___/\__/_//_/___/\___/\_,_//___/ 
  *   https://github.com/sensod9/combinatorics.h
*/

#ifndef _COMBINATORICS_H_INCLUDED
#define _COMBINATORICS_H_INCLUDED
// #include "combinatorics.c"

// Calcutes and returns the factorial of 'n'
unsigned long long factorial(unsigned int n);


/* Permutations. Fills 2d char[][r + 1] with all permutations of given 'alphabet'.
 * 'r' determines the length of the words.
 * Returns size of filled array.
 * e.g.:  int r = 3;
 *        char result[1000][r+1];
 *        long size = permuts('abc', r, result);
 *        for (int i = 0; i < size; i++) printf("%s ", result[i]);
 *        // Output:              "abc acb bac bca cab cba"
*/        // if 'r' = 2:          "ab ac ba bc ca cb"
unsigned long long permuts(const char* alphabet, const unsigned long long r, char (*result_array)[r + 1]);


/* Permutations with repetition. Fills 2d char[][repeat + 1] with all words
 * that consist of characters from given 'alphabet'. 
 * 'repeat' determines the length of the words.
 * Returns size of filled array.
 * e.g.:  int repeat = 2;
 *        char result[1000][repeat+1];
 *        long size = permutsRep('abc', repeat, result);
 *        for (int i = 0; i < size; i++) printf("%s ", result[i]);
*/        // Output:              "aa ab ac ba bb bc ca cb cc"
unsigned long long permutsRep(const char* alphabet, const unsigned long long repeat, char (*result_array)[repeat + 1]);


/* Cartesian product. Fills 2d char[][(repeat * 2) + 1] with
 * ordered pairs (pairs of pairs, etc.) that consist of
 * characters from given 'alphabet1' and 'alphabet2'.
 * 'repeat' determines the amount of pairs within 1 main pair.
 * Returns size of filled array.
 * e.g.:  int repeat = 1;
 *        char result[1000][(repeat * 2)+1];
 *        long size = product("12", "abc", repeat, result);
 *        for (int i = 0; i < size; i++) printf("%s ", result[i]);
 *        // Output:             "1a 1b 1c 2a 2b 2c "
 *        // if 'repeat' = 2:    "1a1a 1a1b 1a1c 1a2a 1a2b 1a2c 1b1a 1b1b 1b1c 1b2a 1b2b 1b2c 
 *        //                      1c1a 1c1b 1c1c 1c2a 1c2b 1c2c 2a1a 2a1b 2a1c 2a2a 2a2b 2a2c 
*/        //                      2b1a 2b1b 2b1c 2b2a 2b2b 2b2c 2c1a 2c1b 2c1c 2c2a 2c2b 2c2c "
unsigned long long product(const char* alphabet1, const char* alphabet2, const unsigned long long repeat, char (*result_array)[(repeat * 2) + 1])

#endif // !_COMBINATORICS_H_INCLUDED
