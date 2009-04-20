#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

#include "embeddedfont.h"
#include "libeot.h"

int main(int argc, char **argv)
{
    eot_t *state;
    FILE *f = fopen("output.font", "w");
    eot_init(&state, read, 0);
    eotdump(state);
    fwrite(state->fontdata, 1, state->head.FontDataSize, f);
    eotfini(state);
    return 0;
}
