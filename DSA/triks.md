```cpp
int =   ( start + end ) / 2;
```

here for maximum value of _start_ and _end_ it will have value higher then an int ,mean it's exceeding the range of int so we will can do this eg:

```cpp
int =   start + ( end - start ) / 2;
```

what is happing here:

```cpp
int =   start + ( end - start ) / 2;

or

start +  end / 2  - start / 2

or

start / 2 + end / 2

or

( start + end ) / 2;
```
