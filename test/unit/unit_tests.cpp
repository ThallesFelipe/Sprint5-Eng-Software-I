#include "unit_tests.h"

void run_unit_tests_globals()
{
    cout << "Running unit tests..." << endl;

    cout << "System tests: ";
    run_unit_test_system();
    cout << "\033[42mOK!\033[0m" << endl;

    cout << "Flow tests: ";
    run_unit_test_flow();
    cout << "\033[42mOK!\033[0m" << endl;

    cout << "Model tests: ";
    run_unit_test_model();
    cout << "\033[42mOK!\033[0m" << endl;

    cout << endl
         << "\033[42mFinished unit test!\033[0m" << endl;
};