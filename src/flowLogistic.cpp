#include "flowLogistic.h"

FlowLogisticImplementation::FlowLogisticImplementation()
{
    id = "NULL";
    source = NULL;
    destiny = NULL;
};

FlowLogisticImplementation::FlowLogisticImplementation(Flow &obj)
{
    if (&obj == this)
        return;

    id = obj.getId();
    source = obj.getSource();
    destiny = obj.getDestiny();
};

FlowLogisticImplementation::FlowLogisticImplementation(const string id, System *source, System *destiny) : FlowImplementation(id, source, destiny) {};
FlowLogisticImplementation::~FlowLogisticImplementation() {};

float FlowLogisticImplementation::execute()
{
    return ((0.01 * getDestiny()->getValue()) * (1 - getDestiny()->getValue() / 70));
};