#ifndef FLOWIMPLEMENTATION_H
#define FLOWIMPLEMENTATION_H

#include <iostream>
#include <string>

#include "system.h"
#include "flow.h"

class FlowImplementation : public Flow
{
protected:
    string id;
    System *source;
    System *destiny;

public:
    /**
     * @brief Construct a new Flow Implementation object
     *
     */
    FlowImplementation();

    /**
     * @brief Construct a new Flow Implementation object
     *
     * @param obj
     */
    FlowImplementation(Flow &obj);

    /**
     * @brief Construct a new Flow Implementation object
     *
     * @param id
     * @param source
     * @param destiny
     */
    FlowImplementation(const string id, System *source, System *destiny);

    /**
     * @brief Destroy the Flow Implementation object
     *
     */
    virtual ~FlowImplementation();

    /**
     * @brief Get the Id object
     *
     * @return string
     */
    string getId() const;

    /**
     * @brief Set the Id object
     *
     * @param id
     */
    void setId(const string id);

    /**
     * @brief Get the Source object
     *
     * @return System*
     */
    System *getSource() const;

    /**
     * @brief Set the Source object
     *
     * @param source
     */
    void setSource(System *source);

    /**
     * @brief Get the Destiny object
     *
     * @return System*
     */
    System *getDestiny() const;

    /**
     * @brief Set the Destiny object
     *
     * @param destiny
     */
    void setDestiny(System *destiny);

    /**
     * @brief Comparison operator for flow objects
     *
     * @param obj
     * @return Flow&
     */
    Flow &operator=(const Flow &obj);

    /**
     * @brief Pure virtual method that will be inherited by subclasses created by the user, this one will contain an equation that will be executed in the flow by the model
     *
     * @return float
     */
    virtual float execute() = 0;
};

#endif // FLOWIMPLEMENTATION_H