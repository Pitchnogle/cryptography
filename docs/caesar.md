# Caesar Cipher

The **Caesar Cipher**, also known as a shift cipher, is one of the oldest and simplest forms of encrypting a message. It is a type of substitution cipher where each letter in the original message (which in cryptography is called the plaintext) is replaced with a letter corresponding to a certain number of letters shifted up or down in the alphabet. 

For each letter of the alphabet, you would take its position in the alphabet, say 3 for the letter **C**, and shift it by the key number. If we had a key of 3, that **C** would be shifted down to an **F** and that same process would be applied to every letter in the plaintext.

In this way, a message that initially was quite readable, ends up in a form that cannot be understood at a simple glance.

## Caesar Cipher Encoder/Decoder

The Caesar cipher encoder/decoder tool uses the following files:
- [Cipher.h](../src/Cipher.h)
- [CaesarCipher.h](../src/CaesarCipher.h)
- [CaesarCipher.cpp](../src/CaesarCipher.cpp)
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
```

Here is the same message using a shift of 7 (the default).

```
$ ./caesar < ../data/quick_brown_fox.txt
AOL XBPJR IYVDU MVE QBTWZ VCLY AOL SHGF KVN
```

### Decode Example

```
$ ./caesar < ../data/quick_brown_fox.txt | ./caesar -d
THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
```

If we used a different shift amount, the message would be garbled still.

```
$ ./caesar < ../data/quick_brown_fox.txt | ./caesar -d -s 6
UIF RVJDL CSPXO GPY KVNQT PWFS UIF MBAZ EPH
```
