#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"
#include "../../src/flowImplementation.h"

#include <assert.h>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <cstring>

#ifndef FUNCTIONAL_TESTS
#define FUNCTIONAL_TESTS

/**
 * @brief This function performs the exponential functional test
 * 
 */
void exponentialFuncionalTest();

/**
 * @brief This function performs the logistical functional test
 * 
 */
void logisticalFuncionalTest();

/**
 * @brief This function runs the complex functional test, which is a combination of the exponential and logistical functional tests and has multiple systems and flows
 * 
 */
void complexFunctionalTest();

#endif // FUNCTIONAL_TESTS