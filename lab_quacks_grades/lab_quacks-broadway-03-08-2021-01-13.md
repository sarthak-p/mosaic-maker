---

This report was generated for **spati20** using **2acfa2aef92168e7f0dbfd1b127d98a7e3f23225** (latest commit as of **March 7th 2021, 11:59 pm**)

---




## Score: 14/14 (100.00%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c exercises.cpp -o .objs/exercises.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/basic.cpp -o .objs/tests/basic.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/exercises.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/basic.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✓ - [1/1] - sumDigits

- **Points**: 1 / 1

```
==57== Memcheck, a memory error detector
==57== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==57== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==57== Command: ./test -r xml "sumDigits"
==57== 
==57== 
==57== HEAP SUMMARY:
==57==     in use at exit: 16 bytes in 1 blocks
==57==   total heap usage: 1,690 allocs, 1,689 frees, 218,360 bytes allocated
==57== 
==57== LEAK SUMMARY:
==57==    definitely lost: 0 bytes in 0 blocks
==57==    indirectly lost: 0 bytes in 0 blocks
==57==      possibly lost: 0 bytes in 0 blocks
==57==    still reachable: 16 bytes in 1 blocks
==57==         suppressed: 0 bytes in 0 blocks
==57== Reachable blocks (those to which a pointer was found) are not shown.
==57== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==57== 
==57== For counts of detected and suppressed errors, rerun with: -v
==57== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - triangle

- **Points**: 1 / 1

```
==59== Memcheck, a memory error detector
==59== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==59== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==59== Command: ./test -r xml "triangle"
==59== 
==59== 
==59== HEAP SUMMARY:
==59==     in use at exit: 16 bytes in 1 blocks
==59==   total heap usage: 1,676 allocs, 1,675 frees, 217,912 bytes allocated
==59== 
==59== LEAK SUMMARY:
==59==    definitely lost: 0 bytes in 0 blocks
==59==    indirectly lost: 0 bytes in 0 blocks
==59==      possibly lost: 0 bytes in 0 blocks
==59==    still reachable: 16 bytes in 1 blocks
==59==         suppressed: 0 bytes in 0 blocks
==59== Reachable blocks (those to which a pointer was found) are not shown.
==59== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==59== 
==59== For counts of detected and suppressed errors, rerun with: -v
==59== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [3/3] - sum

- **Points**: 3 / 3

```
==61== Memcheck, a memory error detector
==61== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==61== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==61== Command: ./test -r xml "sum"
==61== 
==61== 
==61== HEAP SUMMARY:
==61==     in use at exit: 16 bytes in 1 blocks
==61==   total heap usage: 1,773 allocs, 1,772 frees, 304,056 bytes allocated
==61== 
==61== LEAK SUMMARY:
==61==    definitely lost: 0 bytes in 0 blocks
==61==    indirectly lost: 0 bytes in 0 blocks
==61==      possibly lost: 0 bytes in 0 blocks
==61==    still reachable: 16 bytes in 1 blocks
==61==         suppressed: 0 bytes in 0 blocks
==61== Reachable blocks (those to which a pointer was found) are not shown.
==61== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==61== 
==61== For counts of detected and suppressed errors, rerun with: -v
==61== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [3/3] - isBalanced

- **Points**: 3 / 3

```
==63== Memcheck, a memory error detector
==63== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==63== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==63== Command: ./test -r xml "isBalanced"
==63== 
==63== 
==63== HEAP SUMMARY:
==63==     in use at exit: 16 bytes in 1 blocks
==63==   total heap usage: 1,753 allocs, 1,752 frees, 314,808 bytes allocated
==63== 
==63== LEAK SUMMARY:
==63==    definitely lost: 0 bytes in 0 blocks
==63==    indirectly lost: 0 bytes in 0 blocks
==63==      possibly lost: 0 bytes in 0 blocks
==63==    still reachable: 16 bytes in 1 blocks
==63==         suppressed: 0 bytes in 0 blocks
==63== Reachable blocks (those to which a pointer was found) are not shown.
==63== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==63== 
==63== For counts of detected and suppressed errors, rerun with: -v
==63== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [3/3] - scramble 17

- **Points**: 3 / 3

```
==65== Memcheck, a memory error detector
==65== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==65== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==65== Command: ./test -r xml "scramble\ 17"
==65== 
==65== 
==65== HEAP SUMMARY:
==65==     in use at exit: 16 bytes in 1 blocks
==65==   total heap usage: 1,688 allocs, 1,687 frees, 230,832 bytes allocated
==65== 
==65== LEAK SUMMARY:
==65==    definitely lost: 0 bytes in 0 blocks
==65==    indirectly lost: 0 bytes in 0 blocks
==65==      possibly lost: 0 bytes in 0 blocks
==65==    still reachable: 16 bytes in 1 blocks
==65==         suppressed: 0 bytes in 0 blocks
==65== Reachable blocks (those to which a pointer was found) are not shown.
==65== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==65== 
==65== For counts of detected and suppressed errors, rerun with: -v
==65== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [3/3] - scramble 9

- **Points**: 3 / 3

```
==67== Memcheck, a memory error detector
==67== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==67== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==67== Command: ./test -r xml "scramble\ 9"
==67== 
==67== 
==67== HEAP SUMMARY:
==67==     in use at exit: 16 bytes in 1 blocks
==67==   total heap usage: 1,683 allocs, 1,682 frees, 230,160 bytes allocated
==67== 
==67== LEAK SUMMARY:
==67==    definitely lost: 0 bytes in 0 blocks
==67==    indirectly lost: 0 bytes in 0 blocks
==67==      possibly lost: 0 bytes in 0 blocks
==67==    still reachable: 16 bytes in 1 blocks
==67==         suppressed: 0 bytes in 0 blocks
==67== Reachable blocks (those to which a pointer was found) are not shown.
==67== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==67== 
==67== For counts of detected and suppressed errors, rerun with: -v
==67== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



---