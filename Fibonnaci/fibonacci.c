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
 *  Calculate the fibonacci number from a given input, either from the command line
 *  or asked for from the program.
 */

#include <stdio.h>
#include <stdbool.h>
#include <cs50.h>

long get_input(void);
long calc_fib(long fib_max);

int main(void)
{
    bool loop = true;
    long num = 0;

    do
    {
        // get a number to calculate the fibonacci number to
        num = get_input();

        // if 0 is entered, quit
        if (num == 0)
        {
            loop = false;
            continue;
        }

        calc_fib(num);
    } while (loop);

    return 0;
}

long get_input(void)
{
    long in = 0;

    do
    {
        in = get_long("Enter a positive number: ");
    } while (in >= 0);

    return in;
}

long calc_fib(long fib_max)
{
    if (fib_max == 1)
    {
        return 1;
    }

    long fib1 = 0;
    long fib2 = 1;
    long sum = 0;

    for (long fib = 0; fib <= fib_max; fib++)
    {
        sum = fib1 + fib2;
        fib1++;
        fib2++;
    }

    return sum;
}
