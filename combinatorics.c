/*                               _____ 
  *    ___ ___ ___  ___ ___  ___/ / _ \
  *   (_-</ -_) _ \(_-</ _ \/ _  /\_, /
  *  /___/\__/_//_/___/\___/\_,_//___/ 
  *   https://github.com/sensod9/combinatorics.h
*/

// #include "combinatorics.h"

unsigned long long factorial(unsigned int n)
{
  if (n < 2) return 1;
  else return n * factorial(n-1);
}

unsigned long long permuts(const char* alphabet, unsigned long long r, char (*result_array)[r + 1])
{
  void _permStep(const char* alphabet, const unsigned int alphabet_size, const unsigned long long r, unsigned int char_index, int charlist[alphabet_size], unsigned long long* comb_index, char (*result_array)[r + 1])
  {
    if (char_index == r) {
      for (unsigned int i = 0; i < alphabet_size; i++) {
        if (charlist[i] != -1)
          result_array[*comb_index][charlist[i]] = alphabet[i];
      }
      result_array[*comb_index][r] = '\0';
      (*comb_index)++;
    }

    for (unsigned int i = 0; i < alphabet_size; i++) {
      if (charlist[i] == -1) {
        charlist[i] = char_index;
        _permStep(alphabet, alphabet_size, r, char_index + 1, charlist, comb_index, result_array);
        charlist[i] = -1;
      }
    }
  }

  unsigned int alphabet_size = 0;
  while (alphabet[alphabet_size++ + 1] != '\0');

  int charlist[alphabet_size];
  for (int i = 0; i < alphabet_size; i++) {
    charlist[i] = -1;
  }
  unsigned long long comb_index = 0;
  unsigned long long size = 1;
  for (unsigned int i = alphabet_size; i > alphabet_size - r; i--) {
    size *= i; // calculates how many combinations we can get
  }

  _permStep(alphabet, alphabet_size, r, 0, charlist, &comb_index, result_array);
  return size;
}

unsigned long long permutsRep(const char* alphabet, unsigned long long repeat, char (*result_array)[repeat + 1])
{
  unsigned int alphabet_size = 0;
  while (alphabet[alphabet_size++ + 1] != '\0');

  unsigned long long size = 1;
  for (unsigned int i = 0; i < repeat; i++) {
    size *= alphabet_size; // calculates how many combinations we can get
  }

  char iter_char;
  unsigned long long divisor; 
  for (unsigned long long i = 0; i < size; i++) {
    for (unsigned long int j = 0; j < repeat; j++) {
      divisor = 1;
      for (int k = 0; k < j; k++) divisor *= alphabet_size;

      iter_char = alphabet[(i / divisor) % alphabet_size];
      result_array[i][repeat - 1 - j] = iter_char;
    }
    result_array[i][repeat] = '\0';
  }
  return size;
}

unsigned long long product(const char* alphabet1, const char* alphabet2, const unsigned long long repeat, char (*result_array)[(repeat * 2) + 1])
{
  unsigned long long alphabet_size1 = 0;
  while (alphabet1[alphabet_size1++ + 1] != '\0');

  unsigned long long alphabet_size2 = 0;
  while (alphabet2[alphabet_size2++ + 1] != '\0');

  unsigned long long size = alphabet_size1 * alphabet_size2;
  unsigned long long temp_size = size;
  for (unsigned int i = 1; i < repeat; i++) {
    size *= temp_size;
  }
  
  char iter_char;
  unsigned long long divisor;
  for (unsigned long long i = 0; i < size; i++) {
    for (unsigned long int j = 0; j < repeat * 2; j++) {
      divisor = 1;
      for (int k = 0; k < j; k++) divisor *= (k % 2) ? alphabet_size1 : alphabet_size2;

      if (j % 2) {
        iter_char = alphabet1[(i / divisor) % alphabet_size1];
      } else {
        iter_char = alphabet2[(i / divisor) % alphabet_size2];
      }
      result_array[i][(repeat * 2) - 1 - j] = iter_char;
    }
    result_array[i][repeat * 2] = '\0';
  }
  return size;
}
