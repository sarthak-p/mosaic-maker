---

This report was generated for **spati20** using **191d0491b749ef23c573a66ebd4807a4cc6ea3e1** (latest commit as of **February 21st 2021, 8:16 pm**)

---




## Score: 23/61 (37.70%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c Image.cpp -o .objs/Image.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c StickerSheet.cpp -o .objs/StickerSheet.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests-part1.cpp -o .objs/tests/tests-part1.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests-part2.cpp -o .objs/tests/tests-part2.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/Image.o .objs/StickerSheet.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests-part1.o .objs/tests/tests-part2.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✓ - [1/1] - Image lighten() lightens pixels by 0.1

- **Points**: 1 / 1





### ✓ - [1/1] - Image lighten() does not lighten a pixel above 1.0

- **Points**: 1 / 1





### ✓ - [1/1] - Image darken(0.2) darkens pixels by 0.2

- **Points**: 1 / 1





### ✓ - [1/1] - Image darken(0.2) does not darken a pixel below 0.0

- **Points**: 1 / 1





### ✓ - [1/1] - Image saturate() saturates a pixels by 0.1

- **Points**: 1 / 1





### ✓ - [1/1] - Image rotateColor(double) rotates the color

- **Points**: 1 / 1





### ✓ - [1/1] - Image rotateColor(double) keeps the hue in the range 0..360

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(2.0) results in the correct width/height

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(0.5) results in the correct width/height

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(2) scales pixel data in a reasonable way

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(0.5) scales pixel data in a reasonable way

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(10000\, 200) results in the correct width/height

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(720\, 10000) results in the correct width/height

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(240\, 50) results in the correct width/height

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(180\, 80) results in the correct width/height

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(10000\, 200) scales pixel data in a reasonable way

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(720\, 10000) scales pixel data in a reasonable way

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(240\, 50) scales pixel data in a reasonable way

- **Points**: 1 / 1





### ✓ - [1/1] - Image scale(180\, 80) scales pixel data in a reasonable way

- **Points**: 1 / 1





### ✗ - [0/3] - Image doesn't have any memory erorrs

- **Points**: 0 / 3

```
==112== Memcheck, a memory error detector
==112== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==112== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==112== Command: ./test -r xml "Image\ doesn't\ have\ any\ memory\ erorrs"
==112== 
==112== 
==112== HEAP SUMMARY:
==112==     in use at exit: 19,248 bytes in 6 blocks
==112==   total heap usage: 2,592 allocs, 2,586 frees, 333,528 bytes allocated
==112== 
==112== 3,216 (16 direct, 3,200 indirect) bytes in 1 blocks are definitely lost in loss record 3 of 6
==112==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==112==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==112==    by 0x40910A: Image::scale(double) (Image.cpp:210)
==112==    by 0x42A398: ____C_A_T_C_H____T_E_S_T____42() (tests-part1.cpp:239)
==112==    by 0x46ACF2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==112==    by 0x45B446: Catch::TestCase::invoke() const (catch.hpp:10793)
==112==    by 0x45B37C: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==112==    by 0x4578D6: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==112==    by 0x455EAE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==112==    by 0x45F246: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==112==    by 0x45DEE2: Catch::Session::runInternal() (catch.hpp:10149)
==112==    by 0x45DBAA: Catch::Session::run() (catch.hpp:10106)
==112== 
==112== 3,216 (16 direct, 3,200 indirect) bytes in 1 blocks are definitely lost in loss record 4 of 6
==112==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==112==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==112==    by 0x40910A: Image::scale(double) (Image.cpp:210)
==112==    by 0x409300: Image::scale(unsigned int, unsigned int) (Image.cpp:233)
==112==    by 0x42A3C5: ____C_A_T_C_H____T_E_S_T____42() (tests-part1.cpp:241)
==112==    by 0x46ACF2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==112==    by 0x45B446: Catch::TestCase::invoke() const (catch.hpp:10793)
==112==    by 0x45B37C: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==112==    by 0x4578D6: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==112==    by 0x455EAE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==112==    by 0x45F246: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==112==    by 0x45DEE2: Catch::Session::runInternal() (catch.hpp:10149)
==112== 
==112== 12,816 (16 direct, 12,800 indirect) bytes in 1 blocks are definitely lost in loss record 6 of 6
==112==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==112==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==112==    by 0x40910A: Image::scale(double) (Image.cpp:210)
==112==    by 0x42A3AE: ____C_A_T_C_H____T_E_S_T____42() (tests-part1.cpp:240)
==112==    by 0x46ACF2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==112==    by 0x45B446: Catch::TestCase::invoke() const (catch.hpp:10793)
==112==    by 0x45B37C: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==112==    by 0x4578D6: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==112==    by 0x455EAE: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==112==    by 0x45F246: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==112==    by 0x45DEE2: Catch::Session::runInternal() (catch.hpp:10149)
==112==    by 0x45DBAA: Catch::Session::run() (catch.hpp:10106)
==112== 
==112== LEAK SUMMARY:
==112==    definitely lost: 48 bytes in 3 blocks
==112==    indirectly lost: 19,200 bytes in 3 blocks
==112==      possibly lost: 0 bytes in 0 blocks
==112==    still reachable: 0 bytes in 0 blocks
==112==         suppressed: 0 bytes in 0 blocks
==112== 
==112== For counts of detected and suppressed errors, rerun with: -v
==112== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)

```



### ✗ - [0/5] - A basic StickerSheet works

- **Points**: 0 / 5


```
Original: sheet.render() == expected
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=7fba8083f2e0faa4)
```


### ✗ - [0/1] - StickerSheet::changeMaxStickers() does not discard stickers when resized larger

- **Points**: 0 / 1


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✗ - [0/1] - StickerSheet::changeMaxStickers() does not discard original stickers when resized smaller

- **Points**: 0 / 1


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✗ - [0/1] - StickerSheet::changeMaxStickers() can increase the number of stickers on an image

- **Points**: 0 / 1


```
Original: sheet.render() == expected
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=3f7e11ac17e7bc9a)
```


### ✗ - [0/1] - StickerSheet::changeMaxStickers() discards stickers beyond the end of a smaller StickerSheet

- **Points**: 0 / 1


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✗ - [0/1] - StickerSheet::removeSticker() can remove the last sticker

- **Points**: 0 / 1


```
Original: sheet.render() == expected
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=7fba8083f2e0faa4)
```


### ✗ - [0/1] - StickerSheet::removeSticker() can remove the first sticker

- **Points**: 0 / 1


```
Original: sheet.render() == expected
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=7fba8083f2e0faa4)
```


### ✗ - [0/1] - StickerSheet::removeSticker() can remove all stickers

- **Points**: 0 / 1


```
Original: sheet.render() == alma
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=3fa66744920ffb90)
```


### ✓ - [1/1] - StickerSheet::getSticker() returns the sticker

- **Points**: 1 / 1





### ✓ - [1/1] - StickerSheet::getSticker() returns NULL for a non-existant sticker

- **Points**: 1 / 1





### ✓ - [1/1] - StickerSheet::getSticker() returns NULL for a removed sticker

- **Points**: 1 / 1





### ✗ - [0/1] - StickerSheet::translate() translates a sticker's location

- **Points**: 0 / 1


```
Original: sheet.render() == expected
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=7fba8083f2e0faa4)
```


### ✓ - [1/1] - StickerSheet::translate() returns false for a non-existant sticker

- **Points**: 1 / 1





### ✗ - [0/5] - A complex StickerSheet is correct

- **Points**: 0 / 5


```
Original: sheet.render() == expected
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=3fa48f43ec5ef17d)
```


### ✗ - [0/2] - StickerSheet's copy constructor makes an independent copy

- **Points**: 0 / 2


```
Original: s1.render() == expected2
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=3f7e11ac17e7bc9a)
```


### ✗ - [0/2] - StickerSheet's assignment operator makes an independent copy

- **Points**: 0 / 2


```
Original: s1.render() == expected2
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=900, h=600, hash=3f7e11ac17e7bc9a)
```


### ✗ - [0/3] - StickerSheet doesn't have any memory errors

- **Points**: 0 / 3


```
Fatal Error: SIGSEGV - Segmentation violation signal
```


### ✗ - [0/10] - myImage.png exists and contains stickers

- **Points**: 0 / 10


```
Original: stickers >= 1
Expanded: 0 >= 1
```


---