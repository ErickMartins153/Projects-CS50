#include <stdio.h>
#include <cs50.h>
#include <math.h>

int start;
int end;
int years;

int main(void)
{
    do
    {
        //get initial population
        start = get_int("initial population: ");

    }
    //prevent that the initial population is lower than 9
    while (start < 9);
    //guarantee that the final population is greater than the initial population
    do
    {
        end = get_int("final population: ");
    }
    while (end < start);

    //loop until the values match each other
    while (start < end)
    {
        start = round(start + start / 3 - start / 4);
        years++;
    }
    printf("Years: %i", years);
}