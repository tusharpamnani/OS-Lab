// implements the best fit, worst fit and first fit

#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n)
{
    printf("\nFirst-Fit\n");
    int i, j;
    int allocation[n];
    printf("The available blocks are\n");
    for (i = 0; i < n; i++)
    {allocation[i] = -1;}
    for (i = 0; i <= n; i++)
    {
        printf("%i\t", blockSize[i]);
    }
    printf("\n");
    printf("\nProcess No.\tProcess Size\tAllocated Block No.\tAvailable Block \tAllocated Block Size\tRemaining Block Size\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                printf(" %i\t\t\t", i + 1);
                printf("%i\t\t", processSize[i]);
                blockSize[j] -= processSize[i];
                printf("%i\t\t", allocation[i] + 1);
                printf("%i\t\t\t", processSize[i] + blockSize[j]);
                printf("%i\t\t\t", processSize[i]);

                printf("%i\n", blockSize[j]);
                break;}
        }
        if (allocation[i] == -1)
        {
            printf(" %i\t\t\t", i + 1);
            printf("%i\t", processSize[i]);
            printf("NA\t\t");
            printf("NA\t\t\t");
            printf("NA\t\t\t");
            printf("NA\n");
        }}}

void worstFit(int blockSize[], int m, int processSize[], int n)
{   printf("\nWorst-Fit\n");
    int i, j;
    int allocation[n], OgBlockSize[m];
    printf("The available blocks are\n");
    for (i = 0; i <= n; i++)
    {
        printf("%i\t", blockSize[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }

    for (i = 0; i < m; i++)
    {
        OgBlockSize[i] = blockSize[i];
    }
    printf("\nProcess No.\tProcess Size\tAllocated Block No.\tAvailable Block \tAllocated Block Size\tRemaining Block Size\n");
    for (i = 0; i < n; i++)
    {
        int worstFitIndex = -1;
        for (j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (worstFitIndex == -1 || blockSize[j] > blockSize[worstFitIndex])
                {
                    worstFitIndex = j;
                }
            }
        }

        if (worstFitIndex != -1)
        {
            allocation[i] = worstFitIndex;
            printf(" %i\t\t\t", i + 1);
            printf("%i\t\t", processSize[i]);
            printf("%i\t\t\t", allocation[i] + 1);
            blockSize[worstFitIndex] -= processSize[i];
            printf("%i\t\t\t", processSize[i] + blockSize[worstFitIndex]);
            printf("%i\t\t\t", processSize[i]);
            printf("%i\n", blockSize[worstFitIndex]);
        }
        else
        {
            printf(" %i\t\t\t", i + 1);
            printf("%i\t\t", processSize[i]);
            printf("NA\t\t\t");
            printf("NA\t\t\t");
            printf("NA\t\t\t");
            printf("NA\n");
        }}}

void bestFit(int blockSize[], int m, int processSize[], int n)
{   printf("\nBest-Fit\n");
    int i, j;
    int allocation[n], OgBlockSize[m];
    for (i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    printf("THe available blocks are\n");
    for (i = 0; i <= n; i++)
    {
        printf("%i\t", blockSize[i]);
    }
    printf("\n");

    for (i = 0; i < m; i++)
    {
        OgBlockSize[i] = blockSize[i];
    }
    printf("\nProcess No.\tProcess Size\tAllocated Block No.\tAvailable Block \tAllocated Block Size\tRemaining Block Size\n");
    for (i = 0; i < n; i++)
    {
        int bestFitIndex = -1;
        for (j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestFitIndex == -1 || blockSize[j] < blockSize[bestFitIndex])
                {
                    bestFitIndex = j;
                }
            }
        }

        if (bestFitIndex != -1)
        {
            allocation[i] = bestFitIndex;
            printf(" %i\t\t\t", i + 1);
            printf("%i\t\t", processSize[i]);
            printf("%i\t\t\t", allocation[i] + 1);
            blockSize[bestFitIndex] -= processSize[i];
            printf("%i\t\t\t", processSize[i] + blockSize[bestFitIndex]);
            printf("%i\t\t\t", processSize[i]);
            printf("%i\n", blockSize[bestFitIndex]);
        }
        else
        {
            printf(" %i\t\t\t", i + 1);
            printf("%i\t\t", processSize[i]);
            printf("NA\t\t");
            printf("NA\t\t\t");
            printf("NA\t\t\t");
            printf("NA\n");
        }}}
        
int main()
{
    int m;
    int n;
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    m = sizeof(blockSize) / sizeof(blockSize[0]);
    n = sizeof(processSize) / sizeof(processSize[0]);

    firstFit(blockSize, m, processSize, n);
    worstFit(blockSize, m, processSize, n);
    bestFit(blockSize, m, processSize, n);
    return 0;
}
