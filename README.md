# Week 2 CS50

All files are from week 2 of Harvard CS50X

- **Readability** - A program to implement Coleman-Liau index and determine what grade the book is aimed at 📖
  - program should count the number of letters, words, and sentences in the text. You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z, any sequence of characters separated by spaces should c
  - program should print as output "Grade X" where X is the grade level computed by the [Coleman-Liau formula](https://en.wikipedia.org/wiki/Coleman%E2%80%93Liau_index), rounded to the nearest integer.
  - If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output "Grade 16+"
  - If the index number is less than 1, your program should output "Before Grade 1".

- **Substitution** - A program that implements a substitution cipher that encrypts a string based on a passed in key 🔑
  - Must accept a single command-line argument, the key to use for the substitution.
  - If the program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with printf) and return from main a value of 1.
  - If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character, or not containing each letter exactly once), your program should print an error message of your choice (with printf) and return from main a value of 1
  - The program must output plaintext: (without a newline) and then prompt the user for a string
  - The program must output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character in the ciphertext; non-alphabetical characters should be outputted unchanged.
  - After outputting ciphertext, you should print a newline. 