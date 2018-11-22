### This folder contains various tools for use with cryptography, ciphers, and codes

Many of the programs in the **tools/** folder are written as Unix-style text filters. The typical usage case is in the form:

```
prog < input_file
```

or

```
prog < input_file > output_file
```

### Contents:
- [atbash](atbash.cpp)<br>
  *Encoder/Decoder program using the Atbash cipher*
- [caesar](caesar.cpp)<br>
  *Encoder/Decoder program using the Caesar cipher*
- [detab](detab.cpp)<br>
  *Text filter replace tabs with a number of spaces*
- [morse](morse.cpp)<br>
  *Encoder/Decoder program using Morse Code*
- [newline](newline.cpp)<br>
  *Text filter automatically adds newlines after n columns*
- [railfence](railfence.cpp)<br>
  *Encoder/Decoder program using the Rail-Fence cipher*
- [regroup](regroup.cpp)<br>
  *Text filter regroups text output into fixed width clusters*
- [scramble](scramble.cpp)<br>
  *Text filter scrambles input. Useful to help make cipher keys*
- [vigenere](vigenere.cpp)<br>
  *Encoder/Decoder program using the Vigenère cipher*
