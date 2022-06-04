#include <stdio.h>

int main()
{
    int start;
    int end; 
    int temp;
    int flipped;
    int counter; 
    int max; 
    int count; 
    int current;  

    while (scanf("%i %i", &start, &end) != EOF)
    {
        max = 0;

        if (end < start)
        {
            temp = start;
            start = end;
            end = temp;
            flipped = 1;
        }
        else
        {
            flipped = 0;
        }
        
        for(counter = start; counter <= end; counter++)
        {
            count = 1;
            current = counter;
            while (current != 1)
            {
                if (current % 2 == 1)
                {
                    current = 3 * current + 1;
                }
                else
                {
                    current /= 2;
                }

                count++;
            }
            
            if (count > max)
            {
                max = count;
            }
        }

        if (flipped == 1)
        {
            temp = start;
            start = end;
            end = temp;
        }

        printf("%i %i %i\n", start, end, max);
    }

    return 0;
}

