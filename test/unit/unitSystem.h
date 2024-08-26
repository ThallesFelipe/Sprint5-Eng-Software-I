#ifndef UNITSYSTEM_H
#define UNITSYSTEM_H

#include <iostream>
#include <cmath>
#include <cstring>
#include <assert.h>

#include "../../src/systemImplementation.h"
#include "../../src/system.h"

/**
 *@brief This function run the unit test of the system
 */
void run_unit_test_system();

/**
 *@brief This function does the unit test of the Constructor
 */
void unit_system_constructor();

/**
 *@brief This function does the unit test of the destructor
 */
void unit_system_destructor();

/**
 *@brief This function does the unit test of the get Value
 */
void unit_system_getValue();

/**
 *@brief This function does the unit test of the set Value
 */
void unit_system_setValue();

/**
 *@brief This function does the unit test of the get Id
 */
void unit_system_getId();

/**
 *@brief This function does the unit test of the set Id
 */
void unit_system_setId();

#endif // UNITSYSTEM_H