
# Writeup for C primer


## pointer.c

line 18: d prints out the first char of c - "6"
line 19: pc prints out the address of the pointer to c[0], actually prints nothing unless you change %c -> %p
line 25: pcp is valid because argv is itself an array of char pointers, so this is a pointer to argv[0] which is itself a pointer
line 28: I think that pcc2 is a constant pointer to a char, so kind of the previous var but inverted order
  - actually based on description of cp, I think I was wrong. This is probably also a pointer to char constant like pcc.
line 31: invalid because pcc is a pointer to a constant char and we've modified the char
line 32: valid because we deference pcp so the final type is char *
line 33: valid because argv[0] is a char *
line 37/38: both are invalid because we are changing the pointer cp which is supposed to be constant
line 39: I guess it is valid because we are changing the char it is pointing to but not the pointer itself?
line 43/44: these are both invalid because we can't change where a const pointer points to as we saw with cp
line 45: invalid because the thing cpc is pointing to is a char const, and we can't change its value

3. Output of the sizes program

```
size of int : 4 bytes
size of short : 2 bytes
size of long : 8 bytes
size of char : 1 bytes
size of float : 4 bytes
size of double : 8 bytes
size of unsigned int : 4 bytes
size of long long : 8 bytes
size of uint8_t : 1 bytes
size of uint16_t : 2 bytes
size of uint32_t : 4 bytes
size of uint64_t : 8 bytes
size of uint_fast8_t : 1 bytes
size of uint_fast16_t : 8 bytes
size of uintmax_t : 8 bytes
size of intmax_t : 8 bytes
size of __int128 : 16 bytes
size of student : 12 bytes
size of x : 20 bytes
size of int* is : 8 bytes
size of short* is : 8 bytes
size of long* is : 8 bytes
size of char* is : 8 bytes
size of float* is : 8 bytes
size of double* is : 8 bytes
size of unsigned int* is : 8 bytes
size of long long* is : 8 bytes
size of uint8_t* is : 8 bytes
size of uint16_t* is : 8 bytes
size of uint32_t* is : 8 bytes
size of uint64_t* is : 8 bytes
size of uint_fast8_t* is : 8 bytes
size of uint_fast16_t* is : 8 bytes
size of uintmax_t* is : 8 bytes
size of intmax_t* is : 8 bytes
size of __int128* is : 8 bytes
size of student* is : 8 bytes
size of &x* is : 8 bytes
``` 

4. Modified code from swap.c :
```
void swap_with_pointers(int *i, int *j) {
  int temp = *i;
  *i = *j;
  *j = temp;
}
```

5. Modifying to make matrix-multiply optimization level 3 (-O3)

```
rm -f testbed.o matrix_multiply.o matrix_multiply .buildmode \
        testbed.gcda matrix_multiply.gcda \
        testbed.gcno matrix_multiply.gcno \
        testbed.c.gcov matrix_multiply.c.gcov fasttime.h.gcov
clang -O3 -DNDEBUG -Wall -std=c99 -D_POSIX_C_SOURCE=200809L -c testbed.c -o testbed.o
clang -O3 -DNDEBUG -Wall -std=c99 -D_POSIX_C_SOURCE=200809L -c matrix_multiply.c -o matrix_multiply.o
clang -o matrix_multiply testbed.o matrix_multiply.o -lrt
```


6. AddressSanitizer output


```
=================================================================
==837==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 16 byte(s) in 1 object(s) allocated from:
    #0 0x4b8838  (/6.172/hw1/matrix-multiply/matrix_multiply+0x4b8838)
    #1 0x4eaa36  (/6.172/hw1/matrix-multiply/matrix_multiply+0x4eaa36)
    #2 0x7f913970683f  (/lib/x86_64-linux-gnu/libc.so.6+0x2083f)

Indirect leak of 64 byte(s) in 4 object(s) allocated from:
    #0 0x4b8838  (/6.172/hw1/matrix-multiply/matrix_multiply+0x4b8838)
    #1 0x4eaac7  (/6.172/hw1/matrix-multiply/matrix_multiply+0x4eaac7)

Indirect leak of 32 byte(s) in 1 object(s) allocated from:
    #0 0x4b8838  (/6.172/hw1/matrix-multiply/matrix_multiply+0x4b8838)
    #1 0x4eaa7b  (/6.172/hw1/matrix-multiply/matrix_multiply+0x4eaa7b)
    #2 0x7f913970683f  (/lib/x86_64-linux-gnu/libc.so.6+0x2083f)

SUMMARY: AddressSanitizer: 112 byte(s) leaked in 6 allocation(s).
```

7. After fixing matrix multiply initialization, we run `./matrix_multiply -p` and see:


```
root@d535abb5ec30:/6.172/hw1/matrix-multiply# ./matrix_multiply -p
Setup
Matrix A:
------------
    3      7      8      1
    7      9      8      3
    1      2      6      7
    9      8      1      9
------------
Matrix B:
------------
    1      3      0      1
    5      5      7      8
    0      1      9      8
    9      3      1      7
------------
Running matrix_multiply_run()...
---- RESULTS ----
Result:
------------
   47     55    122    130
   79     83    138    164
   74     40     75    114
  130     95     74    144
------------
---- END RESULTS ----
Elapsed execution time: 0.000011 sec
```

8. Output of valgrind after we fixed the memory leak

After running `valgrind --leak-check=full ./matrix_multiply -p`, we get no error in the program:

```
---- END RESULTS ----
Elapsed execution time: 0.008312 sec
==1169==
==1169== HEAP SUMMARY:
==1169==     in use at exit: 0 bytes in 0 blocks
==1169==   total heap usage: 39 allocs, 39 frees, 1,680 bytes allocated
==1169==
==1169== All heap blocks were freed -- no leaks are possible
==1169==
==1169== For counts of detected and suppressed errors, rerun with: -v
==1169== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```



