#ifndef MODEL_H
#define MODEL_H

#include <cstring>
#include <ostream>
#include <vector>

#include "system.h"
#include "flow.h"

class Model
{
public:
    /**
     * @brief Destroy the Model object
     *
     */
    virtual ~Model() {};

    /**
     * @brief Setting the flow vector type
     *
     */
    typedef typename vector<Flow *>::iterator vectorFlow;

    /**
     * @brief Setting the system vector type
     *
     */
    typedef typename vector<System *>::iterator vectorSystem;

    /**
     * @brief Get the Id object of the Model
     *
     * @return string
     */
    virtual string getId() const = 0;

    /**
     * @brief Set the Id object of the Model
     *
     * @param id
     */
    virtual void setId(const string id) = 0;

    /**
     * @brief This method returns the flow from the beginning
     *
     * @return vectorFlow
     */
    virtual vectorFlow flowBegin() = 0;

    /**
     * @brief This method returns the flow from the end
     *
     * @return vectorFlow
     */
    virtual vectorFlow flowEnd() = 0;

    /**
     * @brief This method returns the size of the flow
     *
     * @return int
     */
    virtual int flowSize() = 0;

    /**
     * @brief This method returns the system from the beginning
     *
     * @return vectorSystem
     */
    virtual vectorSystem systemBegin() = 0;

    /**
     * @brief This method returns the system from the end
     *
     * @return vectorSystem
     */
    virtual vectorSystem systemEnd() = 0;

    /**
     * @brief This method returns the size of the system
     *
     * @return int
     */
    virtual int systemSize() = 0;

    /**
     * @brief This method adds a system to the model
     *
     * @param system
     */
    virtual void add(System *system) = 0;

    /**
     * @brief This method adds a flow to the model
     *
     * @param flow
     */
    virtual void add(Flow *flow) = 0;

    /**
     * @brief This method removes a system from the model
     *
     * @return true
     * @return false
     */
    virtual bool remove(System *) = 0;

    /**
     * @brief This method removes a flow from the model
     *
     * @return true
     * @return false
     */
    virtual bool remove(Flow *) = 0;

    /**
     * @brief This method clears the model
     *
     */
    virtual void clear() = 0;

    /**
     * @brief This method shows the model
     *
     */
    virtual void show() = 0;

    /**
     * @brief This method executes the model
     *
     * @param initialTime
     * @param time
     * @param increment
     */
    virtual void execute(int initialTime, int time, int increment) = 0;

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
     * @param name
     * @param initialValue
     * @return System*
     */
    virtual System *createSystem(string name, double initialValue) = 0;

    /**
     * @brief Create a Flow object
     *
     * @tparam FLOW_TYPE
     * @param id
     * @param source
     * @param destiny
     * @return Flow*
     */
    template <typename FLOW_TYPE>
    Flow *createFlow(const string &id, System *source, System *destiny)
    {
        Flow *f = new FLOW_TYPE(id, source, destiny);

        f->setId(id);
        f->setSource(source);
        f->setDestiny(destiny);

        add(f);

        return f;
    }

    static void add(Model *model);
};

#endif // MODEL_H