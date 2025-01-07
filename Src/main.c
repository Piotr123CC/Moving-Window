#include "stdio.h"
#include "stdlib.h"
#include "file.h"
#include "string.h"


int main(int argc, char *argv[])
{
    if (argc == 3)
    {   
        if (handleData(argv[1], atoi(argv[2])) != fileOK)
        {
            exit(1);
        }
    }
    else{
        char fileName[20];
        int windowSize;
        printf("Give file name without file extension(.csv): ");
        scanf("%s",fileName);
        strcat(fileName,".csv");
        printf("Give window size (min 2 max 500): ");
        scanf("%d", &windowSize);
        if (windowSize > 500)
        {
            windowSize = 500;
        }else if (windowSize < 2)
        {
            windowSize = 2;
        }
        if (handleData(fileName, windowSize) != fileOK)
        {
            exit(1);
        }
    }
    printf("FilteredData.csv created successfully\n");
    return 0;
}
