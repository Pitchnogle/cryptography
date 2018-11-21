# Vigenère Cipher

The Vigenère Cipher was developed by mathematician Blaise de Vigenère in the 16th century. The Vigenère Cipher was adapted as a twist on the standard Caesar cipher to reduce the effectiveness of performing frequency analysis on the ciphertext. The cipher accomplishes this using uses a text string as a key. Instead of shifting the plaintext letter by a fixed amount like the Caesar cipher, the invidual letter is the key determines the amount to shift. Should the key be shorter than the plaintext, it is repeated until the length matches.

There are two mode supported in the Vigenère cipher implementation
- alphabet mode <br>
  *Traditional mode using modulo 26 math similar to Caesar cipher*
- xor_ascii mode <br>
  *Modern variant using XOR*

## Vigenère Cipher Encoder/Decoder

The Vigenère cipher encoder/decoder tool uses the following files:
- [cipher.h](../src/cipher.h)
- [vigenere_cipher.h](../src/vigenere_cipher.h)
- [vigenere_cipher.cpp](../src/vigenere_cipher.cpp)
- [vigenere.cpp](../tools/vigenere.cpp)

```
 Usage: ./vigenere <option(s)>
Options:
        -h,--help               Show this help message
        -d,--decode             Decode input stream
        -k,--key KEY_STRING     The Vigenère key
        -x,--xor                Use XOR mode
```

---

# Example

Here is an example of interactive use. Without the -k option, the message would not be enciphered.

```
$ ./vigenere -k LEMON
ATTACK AT DAWN
LXFOPV EF RNHR
```

The typical use case would be to run the program as a text filter. Like the Caesar cipher, when using the default alphabet mode, all letters are treated as caps.

```
$ ./vigenere -k secretpassword < ../data/quick_brown_fox.txt
LLG HYBRK TJKKE IGB LLQIH ONWN HYH DEBP HHV
TZW MIZFC FTFAG UOP BQAGV GZGI XAT LSRU RFJ
```

This shows an example of encoding then decoding the message.

```
$ ./vigenere -k secretpassword < ../data/quick_brown_fox.txt | ./vigenere -k secretpassword -d
THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
```

The Vigenère also supports a xor mode. In this mode, the enciphered text may result in non-printable ASCII characters.

```
$ ./vigenere -k secretpassword -x < ../data/quick_brown_fox.txtP═╝R═╔5==3=E%==T:4>#$O=267C&-1P-2).O6+4hi&
ES╗╗╗S
T╝   S╔
       h~
```

However, when using the xor mode, the symbol space is much larger so we don't lose letter capitalization.

```
$ ./vigenere -k secretpassword -x < ../data/quick_brown_fox.txt | ./vigenere -ksecretpassword -d -x
THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
The quick brown fox jumps over the lazy dog
```
