#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int number_of_students;
    int number_owed;
    float input;
    int student_payments[1000];
    int total_sum;
    int per_person;
    int cents_left;
    int change_hands;
    int i;
    
    while (scanf("%i\n", &number_of_students) != EOF)
    {
        if (number_of_students == 0)
        {
            break;
        }
        
        number_owed = 0;
        total_sum = 0;
        change_hands = 0;
        memset(student_payments, 0, sizeof student_payments);
 
        for (i = 0; i < number_of_students; i++)
        {
            scanf("%f\n", &input); 
            student_payments[i] = (int) (input * 100);
            total_sum += student_payments[i]; 
        }

        per_person = (int) (total_sum / number_of_students);
        cents_left = total_sum % number_of_students; 
        
        for (i = 0; i < number_of_students; i++)
        {
            if (student_payments[i] < per_person)
            {
                change_hands += (per_person - student_payments[i]);
            } 
            else
            {
                number_owed++;
            }
        }

        if (cents_left > number_owed)
        {
            change_hands += (cents_left - number_owed);
        }
        
        printf("$%0.2f\n", change_hands / 100.0);
    }

    return 0;
}

