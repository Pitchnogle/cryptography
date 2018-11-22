# Atbash Cipher

The **Atbash Cipher** is a simple substitude cipher where all the letters in the plaintext are reversed. Thus, any 'A's become 'Z's, 'B's become 'Y's, etc.

## Atbash Cipher Encoder/Decoder

The Atbash cipher encoder/decoder tool uses the following files:
- [cipher.h](../src/cipher.h)
- [atbash_cipher.h](../src/atbash_cipher.h)
- [atbash_cipher.cpp](../src/atbash_cipher.cpp)
- [atbash.cpp](../tools/atbash.cpp)

```
Usage: ./atbash <option(s)>
Options:
        -h,--help               Show this help message
        -d,--decode             Decode input stream
```
---

### Example

```
$ cat ../data/caps.txt
ABCDEFGHIJKLMNOPQRSTUVWXYZ
```

```
$ ./atbash < ../data/caps.txt
ZYXWVUTSRQPONMLKJIHGFEDCBA
```

```
$ ./atbash < ../data/quick_brown_fox.txt
GSV JFRXP YILDM ULC QFNKH LEVI GSV OZAB WLT
GSV JFRXP YILDM ULC QFNKH LEVI GSV OZAB WLT
```

```
$ ./atbash < ../data/quick_brown_fox.txt | ./atbash -d
THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
```

Since the Atbash cipher is just a pure letter substitution, there is effectively no difference between encoding and decoding. So, in the last example, the -d argument was unnecessary.

```
$ ./atbash < ../data/quick_brown_fox.txt | ./atbash
THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
```
