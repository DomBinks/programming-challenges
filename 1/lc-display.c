#include <stdio.h>
#include <string.h>

int num_in;
char num[9];
int size;
char output[23][96];

void horizontal_bar(int row, int start_col)
{
    int i;
    
    for (i = 0; i < size; i++)
    {
        output[row][start_col+i] = '-'; 
    }
}

void vertical_line(int start_row, int col)
{
    int i;

    for (i = 0; i < size; i++)
    {
        output[start_row+i][col] = '|';
    }
}

int main()
{
    int col;
    int i;
    int j;

    while (scanf("%i %i\n", &size, &num_in) != EOF)
    {
        if (size == 0 && num_in == 0)
        {
            break;
        }

        sprintf(num, "%i", num_in);
        memset(output, ' ', sizeof output);

        for (i = 0, col = 0; i < strlen(num); i++, col += size + 3)
        {
            switch (num[i])
            {
                case '0':
                    horizontal_bar(0, col+1);
                    horizontal_bar((2*size)+2, col+1);
                    vertical_line(1, col);
                    vertical_line(1, col+size+1);
                    vertical_line(size+2, col);
                    vertical_line(size+2, col+size+1);
                    break;

                case '1':
                    vertical_line(1,col+size+1);
                    vertical_line(size+2,col+size+1);
                    break;

                case '2':
                    horizontal_bar(0,col+1);
                    horizontal_bar(size+1,col+1);
                    horizontal_bar((2*size)+2, col+1);
                    vertical_line(1,col+size+1);
                    vertical_line(size+2, col);
                    break;

                case '3':
                    horizontal_bar(0,col+1);
                    horizontal_bar(size+1,col+1);
                    horizontal_bar((2*size)+2, col+1);
                    vertical_line(1,col+size+1);
                    vertical_line(size+2,col+size+1);
                    break;

                case '4':
                    horizontal_bar(size+1, col+1);
                    vertical_line(1,col);
                    vertical_line(1,col+size+1);
                    vertical_line(size+2,col+size+1);
                    break;

                case '5':
                    horizontal_bar(0,col+1);
                    horizontal_bar(size+1,col+1);
                    horizontal_bar((2*size)+2, col+1);
                    vertical_line(1,col);
                    vertical_line(size+2,col+size+1);
                    break;

                case '6':
                    horizontal_bar(0,col+1);
                    horizontal_bar(size+1,col+1);
                    horizontal_bar((2*size)+2, col+1);
                    vertical_line(1,col);
                    vertical_line(size+2, col);
                    vertical_line(size+2,col+size+1);
                    break;

                case '7':
                    horizontal_bar(0,col+1);
                    vertical_line(1,col+size+1);
                    vertical_line(size+2,col+size+1);
                    break;
 
                case '8':
                    horizontal_bar(0,col+1);
                    horizontal_bar(size+1,col+1);
                    horizontal_bar((2*size)+2, col+1);
                    vertical_line(1,col);
                    vertical_line(1,col+size+1);
                    vertical_line(size+2, col);
                    vertical_line(size+2,col+size+1);
                    break;

                case '9':
                    horizontal_bar(0,col+1);
                    horizontal_bar(size+1,col+1);
                    horizontal_bar((2*size)+2, col+1);
                    vertical_line(1,col);
                    vertical_line(1,col+size+1);
                    vertical_line(size+2,col+size+1);
                    break;
                
                default:
                    printf("Error\n"); 
                    return 1;
            }
        }

        for (i = 0; i < (2*size) + 3; i++)
        {
            for (j = 0; j < 96; j++)
            {
                printf("%c", output[i][j]);
            }

            printf("\n");
        } 

        printf("\n");
    }

    return 0;
}

