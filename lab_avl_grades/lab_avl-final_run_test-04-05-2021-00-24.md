---

This report was generated for **spati20** using **a0a8d0aab73479eed8d190378bb03324569214fc** (latest commit as of **April 4th 2021, 11:59 pm**)

---




## Score: 35/50 (70.00%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c coloredout.cpp -o .objs/coloredout.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests.cpp -o .objs/tests/tests.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/coloredout.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✓ - [10/10] - test_find

- **Points**: 10 / 10

```
==57== Memcheck, a memory error detector
==57== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==57== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==57== Command: ./test -r xml "test_find"
==57== 
==57== 
==57== HEAP SUMMARY:
==57==     in use at exit: 0 bytes in 0 blocks
==57==   total heap usage: 1,667 allocs, 1,667 frees, 216,640 bytes allocated
==57== 
==57== All heap blocks were freed -- no leaks are possible
==57== 
==57== For counts of detected and suppressed errors, rerun with: -v
==57== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - test_insert_small

- **Points**: 5 / 5





### ✓ - [10/10] - test_insert_find

- **Points**: 10 / 10





### ✓ - [10/10] - test_insert_big

- **Points**: 10 / 10

```
==61== Memcheck, a memory error detector
==61== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==61== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==61== Command: ./test -r xml "test_insert_big"
==61== 
==61== 
==61== HEAP SUMMARY:
==61==     in use at exit: 0 bytes in 0 blocks
==61==   total heap usage: 1,693 allocs, 1,693 frees, 218,128 bytes allocated
==61== 
==61== All heap blocks were freed -- no leaks are possible
==61== 
==61== For counts of detected and suppressed errors, rerun with: -v
==61== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✗ - [0/5] - test_remove_small

- **Points**: 0 / 5


```
Original: solnFuncCalls == funcCalls
Expanded: { "rotateLeftRight", "rotateLeft", "rotateRight", "rotateLeft" }
==
{ "rotateLeftRight", "rotateLeft", "rotateRight" }
```


### ✗ - [0/10] - test_remove_big

- **Points**: 0 / 10


```
Original: solnFuncCalls == funcCalls
Expanded: { "rotateRight", "rotateRight", "rotateRight", "rotateRight", "rotateRightLeft", "rotateRight", "rotateLeft", "rotateLeft", "rotateLeftRight", "rotateLeft", "rotateRight", "rotateRight", "rotateLeft" }
==
{ "rotateRight", "rotateRight", "rotateRight", "rotateRight", "rotateRightLeft", "rotateRight", "rotateLeft", "rotateLeft", "rotateLeftRight", "rotateLeft", "rotateRight", "rotateRight" }
```


---