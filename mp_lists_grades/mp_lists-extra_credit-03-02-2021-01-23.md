---

This report was generated for **spati20** using **1f0e9718fb2da44d88b2cd24f77df6a062d44116** (latest commit as of **March 1st 2021, 11:59 pm**)

---




## Score: 47/52 (90.38%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part2.cpp -o .objs/tests/tests_part2.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part1.cpp -o .objs/tests/tests_part1.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests_part1_extra.cpp -o .objs/tests/tests_part1_extra.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests_part2.o .objs/tests/tests_part1.o .objs/tests/tests_part1_extra.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✓ - [1/1] - List::insertFront size

- **Points**: 1 / 1

```
==71== Memcheck, a memory error detector
==71== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==71== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==71== Command: ./test -r xml "List::insertFront\ size"
==71== 
==71== 
==71== HEAP SUMMARY:
==71==     in use at exit: 0 bytes in 0 blocks
==71==   total heap usage: 2,132 allocs, 2,132 frees, 252,400 bytes allocated
==71== 
==71== All heap blocks were freed -- no leaks are possible
==71== 
==71== For counts of detected and suppressed errors, rerun with: -v
==71== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [2/2] - List::insertBack size

- **Points**: 2 / 2

```
==73== Memcheck, a memory error detector
==73== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==73== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==73== Command: ./test -r xml "List::insertBack\ size"
==73== 
==73== 
==73== HEAP SUMMARY:
==73==     in use at exit: 0 bytes in 0 blocks
==73==   total heap usage: 2,132 allocs, 2,132 frees, 252,400 bytes allocated
==73== 
==73== All heap blocks were freed -- no leaks are possible
==73== 
==73== For counts of detected and suppressed errors, rerun with: -v
==73== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [4/4] - List::insert contents

- **Points**: 4 / 4

```
==75== Memcheck, a memory error detector
==75== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==75== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==75== Command: ./test -r xml "List::insert\ contents"
==75== 
==75== 
==75== HEAP SUMMARY:
==75==     in use at exit: 0 bytes in 0 blocks
==75==   total heap usage: 2,128 allocs, 2,128 frees, 252,304 bytes allocated
==75== 
==75== All heap blocks were freed -- no leaks are possible
==75== 
==75== For counts of detected and suppressed errors, rerun with: -v
==75== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::triplerotate basic

- **Points**: 5 / 5

```
==77== Memcheck, a memory error detector
==77== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==77== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==77== Command: ./test -r xml "List::triplerotate\ basic"
==77== 
==77== 
==77== HEAP SUMMARY:
==77==     in use at exit: 0 bytes in 0 blocks
==77==   total heap usage: 2,136 allocs, 2,136 frees, 252,592 bytes allocated
==77== 
==77== All heap blocks were freed -- no leaks are possible
==77== 
==77== For counts of detected and suppressed errors, rerun with: -v
==77== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [10/10] - List::triplerotate simple

- **Points**: 10 / 10

```
==79== Memcheck, a memory error detector
==79== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==79== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==79== Command: ./test -r xml "List::triplerotate\ simple"
==79== 
==79== 
==79== HEAP SUMMARY:
==79==     in use at exit: 0 bytes in 0 blocks
==79==   total heap usage: 2,140 allocs, 2,140 frees, 252,688 bytes allocated
==79== 
==79== All heap blocks were freed -- no leaks are possible
==79== 
==79== For counts of detected and suppressed errors, rerun with: -v
==79== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::split simple

- **Points**: 5 / 5

```
==81== Memcheck, a memory error detector
==81== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==81== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==81== Command: ./test -r xml "List::split\ simple"
==81== 
==81== 
==81== HEAP SUMMARY:
==81==     in use at exit: 0 bytes in 0 blocks
==81==   total heap usage: 1,990 allocs, 1,990 frees, 247,872 bytes allocated
==81== 
==81== All heap blocks were freed -- no leaks are possible
==81== 
==81== For counts of detected and suppressed errors, rerun with: -v
==81== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - List::split images

- **Points**: 5 / 5





### ✓ - [3/3] - List::_destroy empty list

- **Points**: 3 / 3

```
==84== Memcheck, a memory error detector
==84== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==84== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==84== Command: ./test -r xml "List::_destroy\ empty\ list"
==84== 
==84== 
==84== HEAP SUMMARY:
==84==     in use at exit: 0 bytes in 0 blocks
==84==   total heap usage: 2,140 allocs, 2,140 frees, 253,232 bytes allocated
==84== 
==84== All heap blocks were freed -- no leaks are possible
==84== 
==84== For counts of detected and suppressed errors, rerun with: -v
==84== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::begin() returns an iterator to the front of the list

- **Points**: 1 / 1

```
==86== Memcheck, a memory error detector
==86== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==86== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==86== Command: ./test -r xml "List::begin()\ returns\ an\ iterator\ to\ the\ front\ of\ the\ list"
==86== 
==86== 
==86== HEAP SUMMARY:
==86==     in use at exit: 0 bytes in 0 blocks
==86==   total heap usage: 2,144 allocs, 2,144 frees, 257,568 bytes allocated
==86== 
==86== All heap blocks were freed -- no leaks are possible
==86== 
==86== For counts of detected and suppressed errors, rerun with: -v
==86== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ advances the iterator (pre-increment)

- **Points**: 1 / 1

```
==88== Memcheck, a memory error detector
==88== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==88== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==88== Command: ./test -r xml "List::ListIterator::operator++\ advances\ the\ iterator\ (pre-increment)"
==88== 
==88== 
==88== HEAP SUMMARY:
==88==     in use at exit: 0 bytes in 0 blocks
==88==   total heap usage: 2,144 allocs, 2,144 frees, 259,968 bytes allocated
==88== 
==88== All heap blocks were freed -- no leaks are possible
==88== 
==88== For counts of detected and suppressed errors, rerun with: -v
==88== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ advances the iterator (post-increment)

- **Points**: 1 / 1

```
==90== Memcheck, a memory error detector
==90== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==90== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==90== Command: ./test -r xml "List::ListIterator::operator++\ advances\ the\ iterator\ (post-increment)"
==90== 
==90== 
==90== HEAP SUMMARY:
==90==     in use at exit: 0 bytes in 0 blocks
==90==   total heap usage: 2,144 allocs, 2,144 frees, 259,968 bytes allocated
==90== 
==90== All heap blocks were freed -- no leaks are possible
==90== 
==90== For counts of detected and suppressed errors, rerun with: -v
==90== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator++ (post-increment) returns an un-incremented iterator

- **Points**: 1 / 1

```
==92== Memcheck, a memory error detector
==92== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==92== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==92== Command: ./test -r xml "List::ListIterator::operator++\ (post-increment)\ returns\ an\ un-incremented\ iterator"
==92== 
==92== 
==92== HEAP SUMMARY:
==92==     in use at exit: 0 bytes in 0 blocks
==92==   total heap usage: 2,144 allocs, 2,144 frees, 262,368 bytes allocated
==92== 
==92== All heap blocks were freed -- no leaks are possible
==92== 
==92== For counts of detected and suppressed errors, rerun with: -v
==92== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator-- moves the iterator backwards

- **Points**: 1 / 1

```
==94== Memcheck, a memory error detector
==94== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==94== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==94== Command: ./test -r xml "List::ListIterator::operator--\ moves\ the\ iterator\ backwards"
==94== 
==94== 
==94== HEAP SUMMARY:
==94==     in use at exit: 0 bytes in 0 blocks
==94==   total heap usage: 2,144 allocs, 2,144 frees, 257,568 bytes allocated
==94== 
==94== All heap blocks were freed -- no leaks are possible
==94== 
==94== For counts of detected and suppressed errors, rerun with: -v
==94== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::operator-- (post-increment) returns an un-incremented iterator

- **Points**: 1 / 1

```
==96== Memcheck, a memory error detector
==96== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==96== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==96== Command: ./test -r xml "List::ListIterator::operator--\ (post-increment)\ returns\ an\ un-incremented\ iterator"
==96== 
==96== 
==96== HEAP SUMMARY:
==96==     in use at exit: 0 bytes in 0 blocks
==96==   total heap usage: 2,144 allocs, 2,144 frees, 262,368 bytes allocated
==96== 
==96== All heap blocks were freed -- no leaks are possible
==96== 
==96== For counts of detected and suppressed errors, rerun with: -v
==96== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::end is reached

- **Points**: 1 / 1

```
==98== Memcheck, a memory error detector
==98== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==98== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==98== Command: ./test -r xml "List::ListIterator::end\ is\ reached"
==98== 
==98== 
==98== HEAP SUMMARY:
==98==     in use at exit: 0 bytes in 0 blocks
==98==   total heap usage: 2,137 allocs, 2,137 frees, 255,000 bytes allocated
==98== 
==98== All heap blocks were freed -- no leaks are possible
==98== 
==98== For counts of detected and suppressed errors, rerun with: -v
==98== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - List::ListIterator::end is not ::begin in a non-empty list

- **Points**: 1 / 1

```
==100== Memcheck, a memory error detector
==100== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==100== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==100== Command: ./test -r xml "List::ListIterator::end\ is\ not\ ::begin\ in\ a\ non-empty\ list"
==100== 
==100== 
==100== HEAP SUMMARY:
==100==     in use at exit: 0 bytes in 0 blocks
==100==   total heap usage: 2,137 allocs, 2,137 frees, 257,400 bytes allocated
==100== 
==100== All heap blocks were freed -- no leaks are possible
==100== 
==100== For counts of detected and suppressed errors, rerun with: -v
==100== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [4/4] - List::insert contents #2

- **Points**: 4 / 4

```
==102== Memcheck, a memory error detector
==102== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==102== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==102== Command: ./test -r xml "List::insert\ contents\ #2"
==102== 
==102== 
==102== HEAP SUMMARY:
==102==     in use at exit: 0 bytes in 0 blocks
==102==   total heap usage: 2,143 allocs, 2,143 frees, 252,800 bytes allocated
==102== 
==102== All heap blocks were freed -- no leaks are possible
==102== 
==102== For counts of detected and suppressed errors, rerun with: -v
==102== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✗ - [0/5] - List::split edge cases

- **Points**: 0 / 5


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


---