# Basic combinatorics lib for C

## Contains functions:
<ul>
  <li>
    <h3>factorial(unsigned int <code>n</code>)</h3>
    Returns the factorial of given <code>n</code>
  </li>
  <li>
    <h3>permuts(char* <code>alphabet</code>, unsigned long long <code>r</code>, char <code>(*result_array)[r+1]</code>)</h3>
    <strong>Permutations</strong>. Fills 2d <code>char[][n+1]</code> with all permutations of given <code>alphabet.</code>
    Int <code>r</code> determines the length of the words.
    <ul>
      Returns the size of filled array. Example of usage:
    </ul>
    
```
int r = 3;
char result[1000][r+1];
long size = permuts('abc', r, result);
for (int i = 0; i < size; i++) printf("%s ", result[i]);
//       Output: "abc acb bac bca cab cba "
//       Output if 'r' = 2: "ab ac ba bc ca cb "
```

  </li>
  <li>
    <h3>permutsRep(char* <code>alphabet</code>, unsigned long long <code>repeat</code>, char <code>(*result_array)[r+1]</code>)</h3>
    <strong>Permutations with repetition</strong>. Fills 2d <code>char[][n+1]</code> with all words that consist of characters from given <code>alphabet.</code>
    Int <code>repeat</code> determines the length of the words.
    <ul>
      Returns the size of filled array. Example of usage:
    </ul>

```
int repeat = 2;
char result[1000][repeat+1];
long size = permutsRep('abc', repeat, result);
for (int i = 0; i < size; i++) printf("%s ", result[i]);
//       Output: "aa ab ac ba bb bc ca cb cc "
```

  </li>
  <li>
    <h3>product(char* <code>alphabet1</code>, char* <code>alphabet2</code>, unsigned long long <code>repeat</code>, char <code>(*result_array)[(repeat * 2) + 1]</code>)</h3>
    <strong>Cartesian product</strong>. Fills <code>2d char[][(repeat * 2) + 1]</code> withordered pairs (pairs of pairs, etc.) that consist ofcharacters from given <code>alphabet1</code> and <code>alphabet2</code>.
    Int <code>repeat</code> determines the amount of pairs within 1 main pair.
    <ul>
      Returns the size of filled array. Example of usage:
    </ul>

```
int repeat = 1;
char result[1000][(repeat * 2)+1];
long size = product("12", "abc", repeat, result);
for (int i = 0; i < size; i++) printf("%s ", result[i]);
// Output:             "1a 1b 1c 2a 2b 2c "
// if 'repeat' = 2:    "1a1a 1a1b 1a1c 1a2a 1a2b 1a2c 1b1a 1b1b 1b1c 1b2a 1b2b 1b2c 
//                      1c1a 1c1b 1c1c 1c2a 1c2b 1c2c 2a1a 2a1b 2a1c 2a2a 2a2b 2a2c 
//                      2b1a 2b1b 2b1c 2b2a 2b2b 2b2c 2c1a 2c1b 2c1c 2c2a 2c2b 2c2c "
```
  </li>
</ul>

## How to use:
<ul>
  <li>
    <h3>gcc: <code>gcc example.c -L. -l:combinatorics.a</code></h3>
    <code>#include "combinatorics.h"</code> in file is optional (causes only warnings from gcc).
  </li>
</ul>
