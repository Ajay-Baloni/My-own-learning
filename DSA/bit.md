## Complement of Base 10 Integer

Approach

1. We know that we need to complement. For that we need to change `0` to `1` and `1` to `0`.

2. We need to think, what can we use here from our bitwise operators `(i.e &, |, ^, ~)`.

3. Suppose we have,

```Ex. n = 10, binary-> 1010
    1 0 1 0
    x x x x
  -----------
    0 1 0 1
```

4. Think if we `xor` the `n` with `1111 (mask)`, we will get our desired answer. Like,

```
    1 0 1 0
    1 1 1 1   ==> mask
  ----------- ==> XOR
    0 1 0 1
```

5. Now we just need to make `mask`, for that we can take `1` and do `(left shit + add one)` to make it `1111`. Like,

```
mask -> 0 0 0 1
        0 0 1 0 ==> left shift (mask << 1)
        0 0 1 1 ==> add 1 (mask + 1)
```

6. we know that if we do `& `of `n` with `1111` then we will get that `n` itself.

7. so we will do the `5th step` until `((mask & n) != n)`.

8. At last we can able to make `1111 (mask)` and now return `(mask ^ n)`, see `4th step`.

### Complexity

1. Time complexity: O(ceil(log(n)))
2. Space complexity: O(1)

#### Why Time complexity: O(ceil(log(n)))???

1. we are running the while loop for the number of bit of n.
   n = 2^x ==> (x = number of bits).
   Ex. n = 10, binary -> 1 0 1 0 (4 bits)
   10 = 2^x
   log2(10) = x
   ceil (log2(10)) = x,

2. log2(10) == 3.322, but we represent 10 in 4 bits so take ceil value.

Code

```c++
class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 1;

        while((mask & n) != n){
            mask = mask << 1;
            mask += 1;
        }
        return mask ^ n;
    }
};

```
