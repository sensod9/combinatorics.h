#include <stdio.h>

int main()
{
  int r1 = 3;
  char result1[1000][r1+1];
  long size1 = permuts("abc", r1, result1);
  for (int i = 0; i < size1; i++) printf("%s ", result1[i]);
  // Output:             "abc acb bac bca cab cba "
  // if 'r1' = 2:        "ab ac ba bc ca cb "
  
  putchar('\n');
  int repeat2 = 2;
  char result2[1000][repeat2+1];
  long size2 = permutsRep("abc", repeat2, result2);
  for (int i = 0; i < size2; i++) printf("%s ", result2[i]);
  // Output:             "aa ab ac ba bb bc ca cb cc "
 
  putchar('\n');
  int repeat3 = 1;
  char result3[1000][(repeat3 * 2)+1];
  long size3 = product("12", "abc", repeat3, result3);
  for (int i = 0; i < size3; i++) printf("%s ", result3[i]);
  // Output:             "1a 1b 1c 2a 2b 2c "
  // if 'repeat3' = 2:   "1a1a 1a1b 1a1c 1a2a 1a2b 1a2c 1b1a 1b1b 1b1c 1b2a 1b2b 1b2c 
  //                      1c1a 1c1b 1c1c 1c2a 1c2b 1c2c 2a1a 2a1b 2a1c 2a2a 2a2b 2a2c 
  //                      2b1a 2b1b 2b1c 2b2a 2b2b 2b2c 2c1a 2c1b 2c1c 2c2a 2c2b 2c2c "

  printf("\n%d", factorial(6));
  // Output:             "720"
  
  return 0;
}
