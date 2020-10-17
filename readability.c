#include <stdio.h>
#include <cs50.h>
#include <math.h>


int space (char word[]);
int sentence(char word[]);
int words(int x);
float average(float x, float y);
int count(char s[]);
float coleman(float l, float s);


int main (void)
{
    int z, s, w;
    string n = get_string("Enter the sentence \n");

// Total space
    z = space(n);

// sentence

    // printf("spaces are %i \n", z);

    s = sentence(n);

    // printf("number of sentence: %i \n", s);

// count words
    w = words(z);

    // printf("number of words are:%i \n", w);

// find average number of sentence
    float as = average(s, w);

    // printf("average number of Sentence are: %f \n", as);

// count total letters;
    int tl = count(n);
    // printf("total letters are: %i \n ", tl);
    
// average letters

    float al = average(tl, w);
    // printf("Average number of letters are %f \n", al);
    
    float grade = coleman(al, as);
    if (grade >= 1 && grade <= 16)
    {
     printf(" Grade %.0f\n", grade);
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else 
    {
        printf(" Grade 16+\n");
    }
    
}

//Count Space Function

int space(char word[])
{
    int i;
    int x = 0;

    for (i=0; word[i] != '\0'; i++){

        if(word[i] == ' ')
        {
            x++;

        }


    }
    return x;

}

//Count sentence function

int sentence(char word[])
{
    int x,i;
    x = 0;
    for (i=0; word[i] != '\0'; i++)
    {
        if (word[i] == 33 || word[i] == 46 || word[i]== 63)
        {
            x++;
        }
    }
    return x;
}

//Count Word Function

int words(int x)
{
    int z = x + 1;
    return z;
}

// Average Function

float average(float x, float y)
{
    float l = (x / y) * 100;

    return l;
}
int count(char s[])
{
    int l =0;
    int i;

    for (i=0; s[i] != '\0'; i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
             l++;
        }
        else if(s[i] >= 97 && s[i] <= 122)
        {
            l++;
        }
    }

    return l;
}

float coleman(float l, float s)
{
    float index = 0.0588 * l - 0.296 * s - 15.8;
    
    index = round(index);
    
    return index;
}
