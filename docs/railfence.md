# Rail-Fence Cipher

The **Rail-Fence Cipher** is a transposition cipher where the plaintext letters remain the same but are reordered to form the ciphertext.

## Rail-Fence Cipher Encoder/Decoder

The Rail-Fence cipher encoder/decoder tool uses the following files:
- [railfence.h](../tools/railfence.h)
  
```
Usage: ./railfence <option(s)>
Options:
        -h,--help               Show this help message
        -r,--rails INT_RAILS    Set the number of rails (3 is default)
        -d,--decode             Decode input stream
```
---

### How it works

The *key* for the cipher is the number of rails. By default, it is 3. Like many of the simple ciphers, all letters are capitalized. If the message to encipher was:

```
ATTACK THE FORT AT NOON ON TUESDAY
```

This would be encoded in the following manner. Only letters are considered.

```
A...C...E...T...O...N...S...
.T.A.K.H.F.R.A.N.O.O.T.E.D.Y
..T...T...O...T...N...U...A.
```

The letters are enciphered up and down in terms of rows. Once all the letters have been added the enciphered message is then ordered in terms of the rows. So for our example message, the result is then:

```
ACETONSTAKHFRANOOTEDYTTOTNUA
```

### Example

```
$ cat ../data/quick_brown_fox.txt
THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
The quick brown fox jumps over the lazy dog
```

```
$ ./railfence < ../data/quick_brown_fox.txt
TUBNJSRLDHIRFUOTAOHQIKRWFXUPOETEAYOTEUCBONOJMSVRHLZDGECOOMVHZGQKWXPEEY
```

This cipher only considers alphabetic characters, so whitespace, punctuation, etc. is lost. 

```
$ ./railfence < ../data/quick_brown_fox.txt | ./railfence -d
THEQUICKBROWNFOXJUMPSOVERTHELAZYDOGTHEQUICKBROWNFOXJUMPSOVERTHELAZYDOG
```
