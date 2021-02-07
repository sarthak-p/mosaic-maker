---

This report was generated for **spati20** using **7676bcbb74d4c86f34afb90967bc15aa1f3de362** (latest commit as of **February 6th 2021, 10:30 pm**)

---




## Score: 7/13 (53.85%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic cs225/PNG.cpp
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic cs225/HSLAPixel.cpp
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic cs225/lodepng/lodepng.cpp
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic main.cpp intro.cpp
clang++ PNG.o HSLAPixel.o lodepng.o intro.o main.o -std=c++1y -stdlib=libc++ -lc++abi -lm -o intro
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic tests/tests.cpp
clang++ tests.o PNG.o HSLAPixel.o lodepng.o intro.o -std=c++1y -stdlib=libc++ -lc++abi -lm -o test

```


### ✓ - [1/1] - HSLAPixel's default constructor creates a white pixel

- **Points**: 1 / 1





### ✓ - [1/1] - HSLAPixel's default constructor creates an opaque pixel

- **Points**: 1 / 1





### ✓ - [1/1] - HSLAPixel's HSL constructor creates a pixel with provided HSL values

- **Points**: 1 / 1





### ✓ - [1/1] - HSLAPixel's HSL constructor creates an opaque pixel

- **Points**: 1 / 1





### ✓ - [1/1] - HSLAPixel's HSLA constructor creates a pixel with provided HSLA values

- **Points**: 1 / 1





### ✗ - [0/1] - Rotate in_01.png

- **Points**: 0 / 1


```
Original: expected == actual
Expanded: PNG(w=512, h=384, hash=3fbc90d85dfc7fa3)
==
PNG(w=512, h=384, hash=0)
```


### ✗ - [0/1] - Rotate in_02.png

- **Points**: 0 / 1


```
Original: expected == actual
Expanded: PNG(w=409, h=307, hash=ba804f36e56e6d)
==
PNG(w=409, h=307, hash=0)
```


### ✗ - [0/1] - Rotate in_03.png

- **Points**: 0 / 1


```
Original: expected == actual
Expanded: PNG(w=359, h=270, hash=40f5787755b2c08a)
==
PNG(w=359, h=270, hash=0)
```


### ✗ - [0/3] - Creative artwork contains at least three unique colors

- **Points**: 0 / 3


```
FAIL: Creative artwork does not contian three unique colors.
```


### ✓ - [2/2] - Generate creative artwork

- **Points**: 2 / 2





---