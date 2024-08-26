#ifndef UNITMODEL_H
#define UNITMODEL_H

#include <iostream>
#include <cmath>
#include <cstring>
#include <assert.h>

#include "../../src/flowExponential.h"
#include "../../src/flowLogistic.h"
#include "../../src/model.h"
#include "../../src/modelImplementation.h"
#include "../../src/systemImplementation.h"
#include "../../src/system.h"
#include "../../src/flow.h"

/**
 * @brief This function run the unit test of the model
 *
 */
void run_unit_test_model();

/**
 * @brief This function does the unit test of the Constructor
 *
 */
void unit_model_constructor();

/**
 * @brief This function does the unit test of the destructor
 *
 */
void unit_model_destructor();

/**
 * @brief This function does the unit test of the get Id
 *
 */
void unit_model_getId();

/**
 * @brief This function does the unit test of the set Id
 *
 */
void unit_model_setId();

/**
 * @brief This function does the unit test of the add
 *
 */
void unit_model_add();

/**
 * @brief This function does the unit test of the remove
 *
 */
void unit_model_remove();

/**
 * @brief This function does the unit test of the clear
 *
 */
void unit_model_clear();

/**
 * @brief This function does the unit test of the run
 *
 */
void unit_model_run();

#endif // UNITMODEL_H