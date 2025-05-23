#include "src/ccwc.h"

int main(int argc, char *argv[])
{
    CCWC ccwc_obj;

    if (!ccwc_obj.parseArgs(argc, argv))
    {
        return 1;
    }

    ccwc_obj.evaluate();

    return 0;
}