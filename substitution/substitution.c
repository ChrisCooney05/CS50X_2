#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string make_uppercase(string input);
void create_cipher_text(string key, string text);

int main(int argc, string argv[])
{
  if (argc != 2)
  {
    //check to make sure only one command line arg has been given
    printf("You must supply one command line argument\n");
    //if not returning one indicates error to the computer
    return 1;
  }
  string input = make_uppercase(argv[1]);

  if (strlen(input) != 26)
  {
    //checks that Key is the correct length
    printf("Key must contain 26 characters.\n");
    return 1;
  }

  for (int i = 0; i < 26; i++)
  {
    //checks Key to ensure we have only letters
    int j = toupper(input[i]);
    if (j < 65 || j > 90)
    {
      printf("Key Must only contain letters\n");
      return 1;
    }
  }

  for (int i = 0; i < 26; i++)
  {
    //checks key to ensure all letters are unique
    int count = 0;
    for (int j = 0; j < 26; j++)
    {
      if ((int)input[i] == (int)input[j])
      {
        count++;
        //if we get a count of 2 that means one letter is not unique
        if (count >= 2)
        {
          printf("All characters must be unique\n");
          return 1;
        }
      }
    }
  }

  string plain_text = get_string("plaintext: ");

  create_cipher_text(input, plain_text);
}

string make_uppercase(string input)
{
  //converts key to uppercase
  for (int i = 0; i < 26; i++)
  {
    input[i] = toupper(input[i]);
  }
  return input;
}

void create_cipher_text(string key, string text)
{
  //checks value of letter and prints upper or lower case letter acordingly
  printf("ciphertext: ");
  for (int i = 0, n = strlen(text); i < n; i++)
  {
    if (text[i] >= 65 && text[i] <= 90)
    {
      //if letter was A index value is 0 so we grab the first letter of the Key string
      int index = text[i] - 65;
      printf("%c", toupper(key[index]));
    }
    else if (text[i] >= 97 && text[i] <= 122)
    {
      //same as above but for lower case letters
      int index = text[i] - 97;
      printf("%c", tolower(key[index]));
    }
    else
    {
      //prints out any non char or punctuation as is
      printf("%c", text[i]);
    }
  }
  printf("\n");
}
