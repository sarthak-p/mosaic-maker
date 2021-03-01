---

This report was generated for **spati20** using **802c55b30f0b430957cb14be7722ace73c767614** (latest commit as of **February 28th 2021, 11:59 pm**)

---




## Score: 90/90 (100.00%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor circle.cpp -o .objs/circle.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor flower.cpp -o .objs/flower.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor line.cpp -o .objs/line.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor rectangle.cpp -o .objs/rectangle.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor shape.cpp -o .objs/shape.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor triangle.cpp -o .objs/triangle.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor truck.cpp -o .objs/truck.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor vector2.cpp -o .objs/vector2.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor tests/tests.cpp -o .objs/tests/tests.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/circle.o .objs/flower.o .objs/line.o .objs/rectangle.o .objs/shape.o .objs/triangle.o .objs/truck.o .objs/vector2.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✓ - [10/10] - test_virtual_perim

- **Points**: 10 / 10





### ✓ - [10/10] - test_virtual_area

- **Points**: 10 / 10





### ✓ - [20/20] - test_destructor

- **Points**: 20 / 20

```
==74== Memcheck, a memory error detector
==74== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==74== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==74== Command: ./test -r xml "test_destructor"
==74== 
==74== 
==74== HEAP SUMMARY:
==74==     in use at exit: 0 bytes in 0 blocks
==74==   total heap usage: 1,667 allocs, 1,667 frees, 216,576 bytes allocated
==74== 
==74== All heap blocks were freed -- no leaks are possible
==74== 
==74== For counts of detected and suppressed errors, rerun with: -v
==74== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [20/20] - test_constructor

- **Points**: 20 / 20





### ✓ - [10/10] - test_pure_virtual

- **Points**: 10 / 10

```
==77== Memcheck, a memory error detector
==77== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==77== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==77== Command: ./test -r xml "test_pure_virtual"
==77== 
==77== 
==77== HEAP SUMMARY:
==77==     in use at exit: 0 bytes in 0 blocks
==77==   total heap usage: 1,728 allocs, 1,728 frees, 1,757,183 bytes allocated
==77== 
==77== All heap blocks were freed -- no leaks are possible
==77== 
==77== For counts of detected and suppressed errors, rerun with: -v
==77== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [20/20] - test_slicing

- **Points**: 20 / 20

```
==79== Memcheck, a memory error detector
==79== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==79== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==79== Command: ./test -r xml "test_slicing"
==79== 
==79== 
==79== HEAP SUMMARY:
==79==     in use at exit: 0 bytes in 0 blocks
==79==   total heap usage: 1,794 allocs, 1,794 frees, 1,759,580 bytes allocated
==79== 
==79== All heap blocks were freed -- no leaks are possible
==79== 
==79== For counts of detected and suppressed errors, rerun with: -v
==79== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



---