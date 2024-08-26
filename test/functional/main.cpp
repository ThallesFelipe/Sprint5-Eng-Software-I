#include "functional_tests.h"

int main()
{
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFunctionalTest();

    cout << endl << "\033[42mAll functional tests passed!\033[0m" << endl;

    return 0;
};