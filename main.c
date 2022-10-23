#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include <string.h>

size_t askForSize();
size_t getSizeFromArgument(char *argument);
void occupyMemory(size_t size);

int main(int argc, char **argv)
{

    if (argc > 1)
    {
        occupyMemory(strtoul(argv[1], &(argv[1]) + strlen(argv[1]), 0));
    }
    else
    {
        while (1)
        {
            occupyMemory(askForSize());

            char shouldContinue = 0;
            while (shouldContinue != 'Y' && shouldContinue != 'N')
            {
                printf("Would you like to run again? [Y/N]: ");
                scanf(" %c", &shouldContinue);
            }
            if (shouldContinue == 'N')
                break;
        }
    }
    return 0;
}

void occupyMemory(size_t size)
{
    char *ptr = ((char *)malloc(size));
    char temp = 0;
    printf("Occupied %zu bytes of data, press ENTER to release.\n", size);
    memset(ptr, 0x7f, size); // claim memory
    while (temp != '\n')
        temp = fgetc(stdin);
    free(ptr);
}

size_t askForSize()
{
    unsigned int wholeSize = 0;
    while (wholeSize < 1)
    {
        printf("Enter the whole size of the memory you want to occupy (for example, \"724\" of \"724M\"): ");
        scanf(" %u", &wholeSize);
    }

    char magnitude_c = 0;
    int askMagnitudeAgain = 1;
    while (askMagnitudeAgain)
    {
        printf("Enter the magnitude of the memory [B/K/M/G]: ");
        scanf(" %c", &magnitude_c);
        switch (magnitude_c)
        {
        case 'B':
        case 'K':
        case 'M':
        case 'G':
            askMagnitudeAgain = 0;
            break;

        default:
            askMagnitudeAgain = 1;
        }
    }

    int magnitude;
    switch (magnitude_c)
    {
    case 'B':
        magnitude = 0;
        break;
    case 'K':
        magnitude = 1;
        break;
    case 'M':
        magnitude = 2;
        break;
    case 'G':
        magnitude = 3;
        break;
    default:
        break;
    }

    int useMebiBytes = -1;
    while (useMebiBytes == -1)
    {
        char temp;
        printf("Would you like to use MebiBytes? Mebibytes use powers of 1000 instead of\n"
               "the traditional powers of 1024. [Y/N]: ");
        scanf(" %c", &temp);
        if (temp == 'Y')
            useMebiBytes = 1;
        else if (temp == 'N')
            useMebiBytes = 0;
    }

    fgetc(stdin); // remove last scanf's \n, otherwise occupyMemory will pick it up and release immediately

    return ((size_t)((unsigned long)wholeSize * (powl(useMebiBytes ? 1000 : 1024, magnitude))));
}
