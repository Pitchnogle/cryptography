# Caesar Cipher

The **Caesar Cipher**, also known as a shift cipher, is one of the oldest and simplest forms of encryption. In this cipher, each letter in the original message, called the plaintext, is shifted by a fixed amount. For example, if the shift amount was 3, then an 'A' would be replaced by a 'D', a 'B' would be replaced by an 'E', etc.

In this way, a message that initially was quite readable, ends up in a form that cannot be understood at a simple glance.

*To match the classical implementation, lower case letter are not used and are replaced by capital letters.*

## Caesar Cipher Encoder/Decoder

The Caesar cipher encoder/decoder tool uses the following files:
- [cipher.h](../src/cipher.h)
- [caesar_cipher.h](../src/caesar_cipher.h)
- [caesar_cipher.cpp](../src/caesar_cipher.cpp)
- [caesar.cpp](../tools/caesar.cpp)

```
Usage: ./caesar <option(s)>
Options:
        -h,--help               Show this help message
        -s,--shift INT_SHIFT    Set Caesar cipher shift
        -d,--decode             Decode input stream
```

---

### Example

```
$ cat ../data/quick_brown_fox.txt
THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
The quick brown fox jumps over the lazy dog
```

Here is the same message using a shift of 7 (the default).

```
$ ./caesar < ../data/quick_brown_fox.txt
AOL XBPJR IYVDU MVE QBTWZ VCLY AOL SHGF KVN
AOL XBPJR IYVDU MVE QBTWZ VCLY AOL SHGF KVN
```

### Decode Example

```
$ ./caesar < ../data/quick_brown_fox.txt | ./caesar -d
THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
```

If we used a different shift amount, the message would be garbled still.

```
$ ./caesar < ../data/quick_brown_fox.txt | ./caesar -d -s 6
UIF RVJDL CSPXO GPY KVNQT PWFS UIF MBAZ EPH
UIF RVJDL CSPXO GPY KVNQT PWFS UIF MBAZ EPH
```
