#ifndef MODELIMP_H
#define MODELIMP_H

#include <cstring>
#include <ostream>
#include <vector>

#include "system.h"
#include "model.h"

class ModelImplementation : public Model
{
protected:
    string id;
    vector<Flow *> flows;
    vector<System *> systems;
    static vector<Model *> models;

private:
    /**
     * @brief Construct a new Model Implementation object
     *
     * @param obj
     */
    ModelImplementation(Model &obj);

    /**
     * @brief This method is overloading the '=' operator, "cloning" from one model to another
     *
     * @param obj
     * @return ModelImplementation&
     */
    ModelImplementation &operator=(const ModelImplementation &obj);

public:
    /**
     * @brief Construct a new Model Implementation object
     *
     */
    ModelImplementation();

    /**
     * @brief Construct a new Model Implementation object
     *
     * @param id
     */
    ModelImplementation(const string id);

    /**
     * @brief Destroy the Model Implementation object
     *
     */
    virtual ~ModelImplementation();

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
     * @brief This method returns the flow from the beginning
     *
     * @return vectorFlow
     */
    vectorFlow flowBegin();

    /**
     * @brief This method returns the flow from the end
     *
     * @return vectorFlow
     */
    vectorFlow flowEnd();

    /**
     * @brief This method returns the size of the flow
     *
     * @return int
     */
    int flowSize();

    /**
     * @brief This method returns the system from the beginning
     *
     * @return vectorSystem
     */
    vectorSystem systemBegin();

    /**
     * @brief This method returns the system from the end
     *
     * @return vectorSystem
     */
    vectorSystem systemEnd();

    /**
     * @brief This method returns the size of the system
     *
     * @return int
     */
    int systemSize();

    /**
     * @brief This method adds a system to the model
     *
     */
    void add(System *);

    /**
     * @brief This method adds a flow to the model
     *
     */
    void add(Flow *);

    /**
     * @brief This method removes a system from the model
     *
     * @return true
     * @return false
     */
    bool remove(System *);

    /**
     * @brief This method removes a flow from the model
     *
     * @return true
     * @return false
     */
    bool remove(Flow *);

    /**
     * @brief This method clears the model
     *
     */
    void clear();

    /**
     * @brief This method shows the model
     *
     */
    void show();

    /**
     * @brief Return the interator of the first stock
     *
     * @param model
     */
    static void add(Model *model);

    /**
     * @brief This method executes the model, must be passed the initial time, the time and the increment
     *
     * @param initTime
     * @param time
     * @param increment
     */
    virtual void execute(int initTime, int time, int increment);

    /**
     * @brief Create a Model object
     *
     * @param id
     * @return Model*
     */
    static Model *createModel(string id);

    /**
     * @brief Create a System object
     *
     * @param id
     * @param initValue
     * @return System*
     */
    System *createSystem(string id, double initValue);
};

#endif // MODELIMP_H