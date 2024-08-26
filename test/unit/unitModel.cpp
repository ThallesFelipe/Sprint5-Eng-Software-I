#include "unitModel.h"
#include "../../src/modelImplementation.h"
#include "../../src/FlowImplementation.h"
#include "../../src/SystemImplementation.h"

class TestFlow : public FlowImplementation
{
public:
    TestFlow(string id, System *source, System *destiny) : FlowImplementation(id, source, destiny) {};
    
    /**
     * @brief Pure virtual method that will be inherited by subclasses created by the user, this one will contain an equation that will be executed in the flow by the model
     * 
     * @return float 
     */
    virtual float execute()
    {
        return (getSource()->getValue()) + 1;
    }
};

void unit_model_constructor()
{
    ModelImplementation m;
};

void unit_model_destructor() {};

void unit_model_add()
{
    Model *modeltest = Model::createModel("model");
    System *system1 = modeltest->createSystem("system1", 100);
    System *system2 = modeltest->createSystem("system2", 100);

    modeltest->createFlow<TestFlow>("Flow", system1, system2);

    Model::vectorSystem sit = modeltest->systemBegin();
    assert((*sit) == system1);
    sit++;
    assert((*sit) == system2);

    Model::vectorSystem fit = modeltest->systemBegin();
    assert((*fit) == system1);
    fit++;
    assert((*fit) == system2);
};

void unit_model_run()
{
    Model *model = Model::createModel("model");

    System *pop1 = model->createSystem("pop1", 100);
    System *pop2 = model->createSystem("pop2", 0);

    model->createFlow<TestFlow>("exponential", pop1, pop2);

    model->execute(0, 100, 1);

    assert(pop1->getValue() == -1);
    assert(pop2->getValue() == 101);
};

void unit_model_getId()
{
    Model *model1 = new ModelImplementation();
    assert(model1->getId() == "NULL");

    delete model1;
};

void unit_model_setId()
{
    Model *model1 = new ModelImplementation();
    model1->setId("test");
    assert(model1->getId() == "test");

    delete model1;
};

void unit_model_remove()
{
    Model *model1 = new ModelImplementation();
    System *system1 = new SystemImplementation("system1");

    model1->add(system1);

    assert(model1->systemSize() == 1);

    for (auto it = model1->systemBegin(); it != model1->systemEnd(); it++)
        if ((*it)->getId() == system1->getId())
            assert((*it)->getId() == system1->getId());

    model1->remove(system1);

    assert(model1->systemSize() == 0);

    model1->clear();

    delete model1;
    delete system1;
};

void unit_model_clear()
{
    Model *model1 = new ModelImplementation();
    System *system1 = new SystemImplementation("system1");
    System *system2 = new SystemImplementation("system2");
    Flow *flowExp1 = new FlowExponentialImplementation("flowExp", system1, system2);

    model1->add(system1);
    model1->add(system2);
    assert(model1->systemSize() == 2);

    model1->add(flowExp1);
    assert(model1->flowSize() == 1);

    model1->clear();

    assert(model1->systemSize() == 0);
    assert(model1->flowSize() == 0);

    delete model1;
    delete system1;
    delete system2;
    delete flowExp1;
};

void run_unit_test_model()
{
    unit_model_constructor();
    unit_model_destructor();
    unit_model_getId();
    unit_model_setId();
    unit_model_add();
    unit_model_remove();
    unit_model_clear();
    unit_model_run();
};