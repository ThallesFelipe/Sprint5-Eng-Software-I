#ifndef FLOWLOGISTICIMPLEMENTATION_H
#define FLOWLOGISTICIMPLEMENTATION_H

#include "flowImplementation.h"

class FlowLogisticImplementation : public FlowImplementation
{
public:
    /**
     * @brief Construct a new Flow Logistic Implementation object
     *
     */
    FlowLogisticImplementation();

    /**
     * @brief Construct a new Flow Logistic Implementation object
     *
     * @param obj
     */
    FlowLogisticImplementation(Flow &obj);

    /**
     * @brief Construct a new Flow Logistic Implementation object
     *
     * @param id
     * @param source
     * @param destiny
     */
    FlowLogisticImplementation(const string id, System *source, System *destiny);

    /**
     * @brief Destroy the Flow Logistic Implementation object
     *
     */
    virtual ~FlowLogisticImplementation();

    /**
     * @brief
     *
     * @return float
     */
    virtual float execute();
};

#endif // FLOWLOGISTICIMPLEMENTATION_H