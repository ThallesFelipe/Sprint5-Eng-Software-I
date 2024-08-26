#include "systemImplementation.h"

SystemImplementation::SystemImplementation()
{
    id = "NULL";
    value = 0;
};

SystemImplementation::SystemImplementation(System &obj)
{
    id = obj.getId();
    value = obj.getValue();
};

SystemImplementation::SystemImplementation(const string id, double value) : id(id), value(value) {};
SystemImplementation::SystemImplementation(const string id) : id(id), value(0) {};
SystemImplementation::SystemImplementation(double value) : id(""), value(value) {};
SystemImplementation::~SystemImplementation() {};

string SystemImplementation::getId() const
{
    return id;
};

void SystemImplementation::setId(const string id)
{
    this->id = id;
};

double SystemImplementation::getValue() const
{
    return value;
};

void SystemImplementation::setValue(double value)
{
    this->value = value;
};

System &SystemImplementation::operator=(const System &obj)
{
    if (&obj == this)
        return *this;

    id = obj.getId();
    value = obj.getValue();

    return *this;
};