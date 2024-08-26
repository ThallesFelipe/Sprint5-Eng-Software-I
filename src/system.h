#ifndef SYSTEM_H
#define SYSTEM_H

#include <ostream>
#include <string>

using namespace std;

class System
{
public:
    /**
     * @brief Destroy the System object
     *
     */
    virtual ~System() {};

    /**
     * @brief Get the Id object of the system
     *
     * @return string
     */
    virtual string getId() const = 0;

    /**
     * @brief Set the Id object of the system
     *
     * @param id
     */
    virtual void setId(const string id) = 0;

    /**
     * @brief Get the Value object of the system
     *
     * @return double
     */
    virtual double getValue() const = 0;

    /**
     * @brief Set the Value object of the system
     *
     * @param value
     */
    virtual void setValue(double value = 0.0) = 0;

    /**
     * @brief Comparison operator for system objects
     *
     * @param obj
     * @return System&
     */
    virtual System &operator=(const System &obj) = 0;
};

#endif // SYSTEM_H