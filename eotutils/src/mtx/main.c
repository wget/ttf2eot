#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

#include "mtx.h"

int main(int argc, char **argv)
{
    FILE *input = fopen(argv[1], "r");
    struct stat stat;
    uint8_t *data, *rest;
    mtx_t *mtx;
    size_t rsize;

    fstat(fileno(input), &stat);
    data = malloc(stat.st_size);
    fread(data, stat.st_size, 1, input);
    mtx_init(&mtx, data, stat.st_size);
    mtx_dump(mtx);

    FILE *f = fopen("rest.out", "w");

    mtx_getRest(mtx, &rest, &rsize);
    fwrite(rest, 1, rsize, f);
    mtx_getData(mtx, &rest, &rsize);
    fwrite(rest, 1, rsize, f);
    mtx_getCode(mtx, &rest, &rsize);
    fwrite(rest, 1, rsize, f);

    fclose(f);

    mtx_fini(mtx);
    fclose(input);
    free(data);
    return 0;
}
