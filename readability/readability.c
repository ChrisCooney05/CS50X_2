#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

void test_text(string input, int n);

int main(void)
{
  string input = get_string("Text: ");

  //gets the length of the string
  int n = strlen(input);

  //kicks off testing the input for a estimated Readability grade
  test_text(input, n);
}

int get_letter_count(string input, int n)
{
  int count = 0;
  //if letter is a letter betwee a - z || A - Z count it
  for (int i = 0; i < n; i++)
  {
    if (input[i] >= 'a' && input[i] <= 'z')
    {
      count++;
    }
    else if (input[i] >= 'A' && input[i] <= 'Z')
    {
      count++;
    }
  }
  return count;
}

int get_word_count(string input, int n)
{
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    // known as casting I can check if the char == 32 or ascii code for a space " "
    if ((int)input[i] == 32)
    {
      count++;
    }
  }
  return count + 1;
}

int get_sentence_count(string input, int n)
{
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    //check if char is a . ! or ?
    if (input[i] == 33 || input[i] == 46 || input[i] == 63)
    {
      count++;
    }
  }
  return count;
}

int get_grade(int words, int letters, int sentences)
{
  //Coleman-Liau index = 0.0588 * L - 0.296 * S - 15.8
  //L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words
  //100 / words * by letters = L
  //100 / words * by sentences = S
  float avrage = 100 / (float)words;
  float l = avrage * letters;
  float s = avrage * sentences;

  return round(0.0588 * l - 0.296 * s - 15.8);
}

void print_grade(int grade)
{
  if (grade < 1)
  {
    printf("Before Grade 1\n");
  }
  else if (grade >= 16)
  {
    printf("Grade 16+\n");
  }
  else
  {
    printf("Grade %i\n", grade);
  }
}

void test_text(string input, int n)
{
  int letter_count = get_letter_count(input, n);
  int word_count = get_word_count(input, n);
  int sentence_count = get_sentence_count(input, n);

  int grade = get_grade(word_count, letter_count, sentence_count);

  print_grade(grade);
}