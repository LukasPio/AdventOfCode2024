#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *a, const void *b) { 
    return (*(int *)a - *(int *)b);
}

int main()
{
    FILE *file = fopen("adventOfCode2024/inputs/day1.txt", "r");

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
    }
    else
    {
        fprintf(stderr, "Unable to open file!\n");
    }

    int leftNumbers[1000] = {0};
    int rightNumbers[1000] = {0};

    for (int i = 0; i < 1000; i++) {
        leftNumbers[i] = atoi(left[i]);
        rightNumbers[i] = atoi(right[i]);
    }

    qsort(leftNumbers, 1000, sizeof(leftNumbers[0]), comp);
    qsort(rightNumbers, 1000, sizeof(rightNumbers[0]), comp);

    for (int i = 0; i < 1000; i++) {
        result += abs(leftNumbers[i] - rightNumbers[i]);
    }

    printf("Result: %i\n", result);
}