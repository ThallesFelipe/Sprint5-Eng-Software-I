#include "unitSystem.h"

void unit_system_constructor()
{
    System *system1 = new SystemImplementation();
    assert(system1->getId() == "NULL");
    assert(system1->getValue() == 0);

    System *system2 = new SystemImplementation("test", 1);
    assert(system2->getId() == "test");
    assert(system2->getValue() == 1);

    System *system3 = new SystemImplementation(*system2);

    delete system1;
    delete system2;
    delete system3;
};

void unit_system_destructor() {};

void unit_system_getValue(void)
{
    System *system1 = new SystemImplementation(10);
    assert(system1->getValue() == 10);

    delete system1;
};

void unit_system_setValue(void)
{
    System *system1 = new SystemImplementation();
    system1->setValue(10);
    assert(system1->getValue() == 10);

    delete system1;
};

void unit_system_getId()
{
    System *system1 = new SystemImplementation("test");
    assert(system1->getId() == "test");

    delete system1;
};

void unit_system_setId()
{
    System *system1 = new SystemImplementation();
    system1->setId("test");
    assert(system1->getId() == "test");

    delete system1;
};

void run_unit_test_system()
{
    unit_system_constructor();
    unit_system_destructor();
    unit_system_getValue();
    unit_system_setValue();
    unit_system_getId();
    unit_system_setId();
};