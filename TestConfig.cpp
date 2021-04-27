#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
using namespace doctest;

int main(int argc, char **argv)
{
    Context context;
    context.run();
    return 1;
}
