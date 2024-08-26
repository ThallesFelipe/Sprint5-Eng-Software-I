#ifndef SYSTEMIMPLEMENTATION_H
#define SYSTEMIMPLEMENTATION_H

#include <ostream>
#include <string>

#include "system.h"

using namespace std;

class SystemImplementation : public System
{
protected:
    string id;
    double value;

public:
    /**
     * @brief Construct a new System Implementation object
     *
     */
    SystemImplementation();

    /**
     * @brief Construct a new System Implementation object
     *
     * @param id
     */
    SystemImplementation(const string id);

    /**
     * @brief Construct a new System Implementation object
     *
     * @param value
     */
    SystemImplementation(double value);

    /**
     * @brief Construct a new System Implementation object
     *
     * @param obj
     */
    SystemImplementation(System &obj);

    /**
     * @brief Construct a new System Implementation object
     *
     * @param id
     * @param Value
     */
    SystemImplementation(const string id, double Value);

    /**
     * @brief Destroy the System Implementation object
     *
     */
    virtual ~SystemImplementation();

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
     * @brief Get the Value object
     *
     * @return double
     */
    double getValue() const;

    /**
     * @brief Set the Value object
     *
     * @param value
     */
    void setValue(double value);

    /**
     * @brief
     *
     * @param obj
     * @return System&
     */
    System &operator=(const System &obj);
};

#endif // SYSTEMIMPLEMENTATION_H