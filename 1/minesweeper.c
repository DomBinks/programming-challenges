#include <stdio.h>
#include <string.h>

int main()
{
    int field_no = 1;
    int rows;
    int cols;
    char row[101];
    int i;
    int j;
    int grid[100][100];

    while (scanf("%i %i\n", &rows, &cols) != EOF)
    {
        memset(grid, 0, sizeof grid);

        if (rows == 0 || cols == 0)
        {
            break;
        }
        
        for (i = 0; i < rows; i++)
        {
            scanf("%s\n", &row);

            for (j = 0; j < cols; j++)
            {
                if (row[j] == '*')
                {
                    if (i - 1 >= 0)
                    {
                        if (j - 1 >= 0)
                        {
                            grid[i-1][j-1] += 1;
                        }
                        grid[i-1][j] += 1;
                        if (j + 1 < cols)
                        {
                            grid[i-1][j+1] += 1;
                        }
                    }
                    
                    if (j - 1 >= 0)
                    {
                        grid[i][j-1] += 1;
                    }
                    grid[i][j] += 9;
                    if (j + 1 < cols)
                    {
                        grid[i][j+1] += 1;
                    }

                    if (i + 1 < rows)
                    {
                        if (j - 1 >= 0)
                        {
                            grid[i+1][j-1] += 1;
                        }
                        grid[i+1][j] += 1;
                        if (j + 1 < cols)
                        {
                            grid[i+1][j+1] += 1;
                        }
                    }
                }
            }
        }

        if (field_no != 1)
        {
            printf("\n");
        }

        printf("Field #%i:\n", field_no++);
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                if (grid[i][j] < 9)
                {
                    printf("%i", grid[i][j]);
                }
                else
                {
                    printf("*");
                }
            }

            printf("\n");
        }
    }

    return 0;
}

