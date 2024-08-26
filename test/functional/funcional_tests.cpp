#include <iostream>
#include <assert.h>
#include <math.h>

#include "functional_tests.h"
#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"
#include "../../src/flowImplementation.h"

class FlowExponentialImplementation : public FlowImplementation
{
public:
	FlowExponentialImplementation(string id, System *source, System *destiny) : FlowImplementation(id, source, destiny) {};

	/**
	 * @brief Concrete execute method
	 *
	 * @return float
	 */
	virtual float execute()
	{
		return 0.01 * (this->getSource()->getValue());
	}
};

/**
 * @brief LogisticFlow: Class that implements the execute function of the Logistic Flow
 *
 */
class FlowLogisticImplementation : public FlowImplementation
{
public:
	FlowLogisticImplementation(string id, System *source, System *destiny) : FlowImplementation(id, source, destiny) {};

	/**
	 * @brief Concrete execute method
	 *
	 * @return float
	 */
	virtual float execute()
	{
		return 0.01 * (this->getDestiny()->getValue()) * (1 - (this->getDestiny()->getValue()) / 70);
	}
};

/**
 * @brief ComplexFlow: Class that implements the execute function of the Complex Flow
 *
 */
class ComplexFlow : public FlowImplementation
{
public:
	ComplexFlow(string id, System *source, System *destiny) : FlowImplementation(id, source, destiny) {};

	/**
	 * @brief Concrete execute method
	 *
	 * @return Double
	 */
	virtual float execute()
	{
		return 0.01 * (this->getSource()->getValue());
	}
};

void exponentialFuncionalTest()
{
	Model *modelExponential = Model::createModel("Model modelExponential");

	System *system1 = modelExponential->createSystem("system1", 100);
	System *system2 = modelExponential->createSystem("system2", 0);

	modelExponential->createFlow<FlowExponentialImplementation>("exponential", system1, system2);

	modelExponential->execute(0, 100, 1);

	assert(fabs((round((system1->getValue() * 10000)) - 10000 * 36.6032)) < 0.0001);
	assert(fabs((round((system2->getValue() * 10000)) - 10000 * 63.3968)) < 0.0001);
};

void logisticalFuncionalTest()
{
	Model *modelLogistic = Model::createModel("Model modelLogistic");

	System *system1 = modelLogistic->createSystem("system1", 100);
	System *system2 = modelLogistic->createSystem("system2", 10);

	modelLogistic->createFlow<FlowLogisticImplementation>("logistic", system1, system2);

	modelLogistic->execute(0, 100, 1);

	modelLogistic->setId("Logistic system");

	assert(fabs((round((system1->getValue() * 10000)) - 10000 * 88.2167)) < 0.0001);
	assert(fabs((round((system2->getValue() * 10000)) - 10000 * 21.7833)) < 0.0001);
};

void complexFunctionalTest()
{
	Model *modelComplex = Model::createModel("Model modelComplex");

	System *Q1 = modelComplex->createSystem("Q1", 100);
	System *Q2 = modelComplex->createSystem("Q2", 0);
	System *Q3 = modelComplex->createSystem("Q3", 100);
	System *Q4 = modelComplex->createSystem("Q4", 0);
	System *Q5 = modelComplex->createSystem("Q5", 0);

	modelComplex->createFlow<FlowExponentialImplementation>("f", Q1, Q2);
	modelComplex->createFlow<FlowExponentialImplementation>("g", Q1, Q3);
	modelComplex->createFlow<FlowExponentialImplementation>("r", Q2, Q3);
	modelComplex->createFlow<FlowExponentialImplementation>("t", Q2, Q5);
	modelComplex->createFlow<FlowExponentialImplementation>("u", Q3, Q4);
	modelComplex->createFlow<FlowExponentialImplementation>("v", Q4, Q1);

	modelComplex->execute(0, 100, 1);

	assert(fabs((round((Q1->getValue() * 10000)) - 10000 * 31.8513)) < 0.0001);
	assert(fabs((round((Q2->getValue() * 10000)) - 10000 * 18.4003)) < 0.0001);
	assert(fabs((round((Q3->getValue() * 10000)) - 10000 * 77.1143)) < 0.0001);
	assert(fabs((round((Q4->getValue() * 10000)) - 10000 * 56.1728)) < 0.0001);
	assert(fabs((round((Q5->getValue() * 10000)) - 10000 * 16.4612)) < 0.0001);
};