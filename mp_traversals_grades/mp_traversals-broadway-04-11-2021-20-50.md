---

This report was generated for **spati20** using **3625efb1766f6b81503073fac0c944798a00f274** (latest commit as of **April 11th 2021, 8:51 pm**)

---




## Score: 0/0 (0.00%)


### ✗ - [0/0] - Output from `make`

- **Points**: 0 / 0

```
FloodFilledImage.cpp:33:12: fatal error: member reference type 'ImageTraversal' is not a pointer; did you mean to use '.'?
  traversal->push_back() 
  ~~~~~~~~~^~
           .
1 error generated.
make: *** [.objs/FloodFilledImage.o] Error 1

```
```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c Point.cpp -o .objs/Point.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c FloodFilledImage.cpp -o .objs/FloodFilledImage.o

```


---