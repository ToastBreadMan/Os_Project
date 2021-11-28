#pragma once

int stren(char * str)
{
    int count = 0;

    while (str[count] != '\0')
        count++;

    return count;
}
