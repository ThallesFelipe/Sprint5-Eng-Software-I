#ifndef UNITFLOW_H
#define UNITFLOW_H

#include <iostream>
#include <cmath>
#include <cstring>
#include <assert.h>

#include "../../src/flow.h"
#include "../../src/flowExponential.h"
#include "../../src/flowLogistic.h"
#include "../../src/systemImplementation.h"
#include "../../src/system.h"
#include "../../src/model.h"
#include "../../src/modelImplementation.h"

/**
 *@brief This function run the unit test of the flow
 */
void run_unit_test_flow();

/**
 *@brief This function does the unit test of the constructor
 */
void unit_flow_constructor();

/**
 *@brief This function does the unit test of the destructor
 */
void unit_flow_destructor();

/**
 *@brief This function does the unit test of the Get Id
 */
void unit_flow_getId();

/**
 *@brief This function does the unit test of the Set Id
 */
void unit_flow_setId();

/**
 *@brief This function does the unit test of the Get Source
 */
void unit_flow_getSource();

/**
 *@brief This function does the unit test of the Set Source
 */
void unit_flow_setSource();

/**
 *@brief This function does the unit test of the Get Destiny
 */
void unit_flow_getDestiny();

/**
 *@brief This function does the unit test of the Set Destiny
 */
void unit_flow_setDestiny();

/**
 *@brief This function does the unit test of the execute
 */
void unit_flow_execute();

#endif // UNITFLOW_H