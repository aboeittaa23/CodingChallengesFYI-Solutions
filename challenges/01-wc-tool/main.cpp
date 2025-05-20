#include "src/ccwc.h"

int main(int argc, char *argv[])
{
    CCWC ccwc_obj;
    ccwc_obj.parseArgs(argc, argv);
    ccwc_obj.evaluate();

    return 0;
}