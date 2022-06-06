#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int number_of_students;
    int number_above_average;
    float student_payments[1000];
    float total_sum;
    float per_person;
    int cents_left;
    float change_hands;
    int i;
    
    while (scanf("%i\n", &number_of_students) != EOF)
    {
        if (number_of_students == 0)
        {
            break;
        }
        
        number_above_average = 0;
        total_sum = 0.0;
        change_hands = 0.0;
        memset(student_payments, 0.0, sizeof student_payments);
 
        for (i = 0; i < number_of_students; i++)
        {
            scanf("%f\n", &student_payments[i]); 
            student_payments[i] *= 100;
            total_sum += student_payments[i]; 
        }

        per_person = (float) (int) (total_sum / number_of_students);
        
        for (i = 0; i < number_of_students; i++)
        {
            if (student_payments[i] < per_person)
            {
                change_hands += (per_person - student_payments[i]);
            }

            else
            {
                number_above_average++;
            }
        }

        cents_left = (int) total_sum % number_of_students;
        if (cents_left > 0 && cents_left > number_above_average)
        {
            change_hands += (float) (cents_left - number_above_average);
        }
        
        printf("$%0.2f\n", change_hands / 100);
    }

    return 0;
}

