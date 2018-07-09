/***********************************************************************************
 *  MIT License                                                                    *
 *                                                                                 *
 *  Copyright (c) 2018 Keri Southwood-Smith                                        *
 *                                                                                 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy   *
 *  of this software and associated documentation files (the "Software"), to deal  *
 *  in the Software without restriction, including without limitation the rights   *
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      *
 *  copies of the Software, and to permit persons to whom the Software is          *
 *  furnished to do so, subject to the following conditions:                       *
 *                                                                                 *
 *  The above copyright notice and this permission notice shall be included in all *
 *  copies or substantial portions of the Software.                                *
 *                                                                                 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     *
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       *
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    *
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         *
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  *
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  *
 *  SOFTWARE.                                                                      *
 ***********************************************************************************/

/*
 *  Get a string from the user via stdin, then count all the vowels in it. Return the total number
 *  of vowels as well as breakdown by each one.
 */


#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

struct vowels
{
    unsigned int a;
    unsigned int e;
    unsigned int i;
    unsigned int o;
    unsigned int u;
    unsigned int sum;
};

void countVowels(char *phrase, struct vowels *vowel);

int main(void)
{
    // define and initialize the struct
    struct vowels counts;
    counts.a = 0;
    counts.e = 0;
    counts.i = 0;
    counts.o = 0;
    counts.u = 0;
    counts.sum = 0;

    // get the phrase from the user
    char *phrase = get_string("Enter a string: ");

    countVowels(phrase, &counts);

    printf("\nThere are %d vowels in that phrase, consisting of %d a\'s, %d e\'s, %d i\'s, %d o\'s and %d u\'s.\n",
            counts.sum, counts.a, counts.e, counts.i, counts.o, counts.u);

    return 0;
}

/*
 *  Count the number of vowels in a supplied phrase
 *
 *  Keep track of the number of each vowel (aeiou) in a supplied phrase, as well as the total number
 *  of vowels overall.
 *
 *  phrase: string entered by the user
 *  vowel: struct holding the vowel counts and total
 */

void countVowels(char *phrase, struct vowels *vowel)
{
    unsigned int ch = 0;

    while (phrase[ch] != '\0')
    {
        switch (phrase[ch])
        {
        case 'a':
        case 'A':
            vowel->a++;
            vowel->sum++;
            break;

        case 'e':
        case 'E':
            vowel->e++;
            vowel->sum++;
            break;

        case 'i':
        case 'I':
            vowel->i++;
            vowel->sum++;
            break;

        case 'o':
        case 'O':
            vowel->o++;
            vowel->sum++;
            break;

        case 'u':
        case 'U':
            vowel->u++;
            vowel->sum++;
            break;

        default:
            break;
        }

        ch++;
    }
}
