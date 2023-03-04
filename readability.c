#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    string text = get_string(" Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float L = (float)letters / (float)words * 100;
    float S = (float)sentences / (float)words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index > 0 && index < 17)
    {
        printf("Grade %i\n", index);
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

}
int count_letters(string text)
{
    int letters = 0;
    int digit = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]) || islower(text[i]) || isalpha(text[i]))
        {
            letters++;
        }
        else
            //asta nu se afiseaza nici unde, as putea pune altceva sa sari peste?
            digit = digit + 1;
    }
    //printf(" numarul de litere este: %i \n", letters);
    return letters;
}

int count_words(string text)
{
    int words = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ' || text[i] == '?')
        {
            words++;
        }
    }
    words += 1;
    //printf("numarul de cuvinte %i \n ", words);

    return words;
}
int count_sentences(string text)
{
    int senteces = 0;

    for (int i = 0; i < strlen(text) ; i++)
    {
        if (text[i] == '?' || text[i] == '.' || text[i] == '!')
        {
            senteces++;
        }
    }
    // printf("numarul de propozitii %i \n ", senteces);

    return senteces;
}