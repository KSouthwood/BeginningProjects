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

#include <stdio.h>
#include <stdlib.h>

void fizzbuzz(int min, int max);

/*
 *  Classic FizzBuzz problem wherein we print a sequence of numbers, replacing multiples of three
 *  with "Fizz", multiples of five with "Buzz" and multiples of three AND five with "FizzBuzz."
 */

/*
 *  Main loop of program
 *
 *  argc - number of arguments provided to program
 *  argv[] - array of arguments
 */

int main(int argc, char *argv[])
{
    switch (argc)
    {
        case 1:
            fizzbuzz(1, 100);
            break;
        case 2:
            fizzbuzz(1, atoi(argv[1]));
            break;
        case 3:
            fizzbuzz(atoi(argv[1]), atoi(argv[2]));
            break;
        default:
            printf("Usage: %s [max]\n", argv[0]);
            printf("Usage: %s [min] [max]\n", argv[0]);
            return 1;
    }

    printf("\n");
    return 0;
}

void fizzbuzz(int min, int max)
{
    // for loop won't work if max is larger than min, swap values
    if (min > max)  // min = 50, max = 15
    {
        printf("min was greater than max. Swapping.\n\n");
        min = min + max;    // min = 65, max = 15
        max = min - max;    // min = 65, max = 50
        min = min - max;    // min = 15, max = 50
    }

    // we want to start counting from 1, not 0, so set min to 1
    // TODO: remove if we want to handle negative ints and 0
    if (min < 1)
    {
        printf("min must be 1 or greater. Setting min to 1.\n\n");
        min = 1;
    }

    for (int i = min, count = 1; i <= max; i++, count++)
    {
        if (i % 15 == 0)
        {
            printf("FizzBuzz");
        }
        else if (i % 3 == 0)
        {
            printf("Fizz");
        }
        else if (i % 5 == 0)
        {
            printf("Buzz");
        }
        else
        {
            printf("%d", i);
        }

        printf("%s", (count % 20) ? ", " : "\n");
    }

    return;
}
