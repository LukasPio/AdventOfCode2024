#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file = fopen("adventOfCode/inputs/day1.txt", "r");

    char line[14];

    int result = 0;

    char *token;
    int collum = 0;

    char left[1000][6];
    char right[1000][6];

    int leftIndex = 0;
    int rightIndex = 0;

    if (file != NULL)
    {
        while (fgets(line, sizeof(line), file))
        {
            line[strcspn(line, "\n")] = '\0';

            token = strtok(line, " \t");
            while (token != NULL)
            {
                if (collum == 0)
                {
                    strncpy(left[leftIndex], token, sizeof(left[leftIndex]) - 1);
                    left[leftIndex][sizeof(left[leftIndex]) - 1] = '\0';
                    leftIndex++;
                    collum = 1;
                }
                else
                {
                    strncpy(right[rightIndex], token, sizeof(right[rightIndex]) - 1);
                    right[rightIndex][sizeof(right[rightIndex]) - 1] = '\0';
                    rightIndex++;
                    collum = 0;
                }
                token = strtok(NULL, " \t");
            }
        }

        fclose(file);

        printf("First element of first column: %s\n", left[0]);
        printf("Last element of right column: %s\n", right[rightIndex - 1]);
    }
    else
    {
        fprintf(stderr, "Unable to open file!\n");
    }

    int leftNumber = 0;

    int rightNumber = 0;
    int counter = 0;

    for (int i = 0; i < 1000; i++) {
        leftNumber = atoi(left[i]);
        for (int j = 0; j < 1000; j++) {
            if (atoi(right[j]) == leftNumber) counter++;
        }
        result += leftNumber * counter;
        counter = 0;
    }

    printf("Result: %i", result);

    return 0;
}
