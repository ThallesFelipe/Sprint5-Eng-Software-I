#include "modelImplementation.h"
#include "systemImplementation.h"

#include <vector>

ModelImplementation::ModelImplementation()
{
    id = "NULL";
    flows.clear();
    systems.clear();
};

vector<Model *> ModelImplementation::models;

ModelImplementation::ModelImplementation(const string id) : id(id) {};

ModelImplementation::ModelImplementation(Model &obj)
{
    if (&obj == this)
        return;

    id = obj.getId();
};

ModelImplementation::~ModelImplementation()
{
    for (auto modelatual = models.begin(); modelatual < models.end(); modelatual++)
        if ((*modelatual) == this)
            models.erase(modelatual);
};

string ModelImplementation::getId() const
{
    return id;
};

void ModelImplementation::setId(const string id)
{
    this->id = id;
};

Model::vectorFlow ModelImplementation::flowBegin()
{
    return flows.begin();
};

Model::vectorFlow ModelImplementation::flowEnd()
{
    return flows.end();
};

int ModelImplementation::flowSize()
{
    return flows.size();
};

Model::vectorSystem ModelImplementation::systemBegin()
{
    return systems.begin();
};

Model::vectorSystem ModelImplementation::systemEnd()
{
    return systems.end();
};

int ModelImplementation::systemSize()
{
    return systems.size();
};

void ModelImplementation::add(System *subSystem)
{
    systems.push_back(subSystem);
};

void Model::add(Model *model)
{
    return ModelImplementation::add(model);
};

void ModelImplementation::add(Model *model)
{
    models.push_back(model);
};

Model *Model::createModel(string id = "unnamed")
{
    return ModelImplementation::createModel(id);
};

Model *ModelImplementation::createModel(string id = "unnamed")
{
    Model *model = new ModelImplementation(id);

    add(model);
    return model;
};

void ModelImplementation::add(Flow *flow)
{
    flows.push_back(flow);
};

bool ModelImplementation::remove(System *obj)
{
    for (auto thisystem = systems.begin(); thisystem != systems.end(); thisystem++)
        if (*thisystem == obj)
        {
            systems.erase(thisystem);
            return true;
        }
    return false;
};

bool ModelImplementation::remove(Flow *obj)
{
    for (auto thisFlows = flows.begin(); thisFlows != flows.end(); thisFlows++)
        if (*thisFlows == obj)
        {
            flows.erase(thisFlows);
            return true;
        }
    return false;
};

ModelImplementation &ModelImplementation::operator=(const ModelImplementation &obj)
{
    if (this != &obj)
    {
        this->flows.clear();
        this->systems.clear();
        this->flows.insert(this->flows.begin(), obj.flows.begin(), obj.flows.end());
        this->systems.insert(this->systems.begin(), obj.systems.begin(), obj.systems.end());
    }
    return *this;
};

void ModelImplementation::clear()
{
    id = "NULL";
    flows.clear();
    systems.clear();
};

void ModelImplementation::execute(int start, int finish, int increment)
{
    vector<Flow *>::iterator vectorFlow;

    System *source;
    System *destiny;

    vector<float> flowValue;

    size_t i = 0;
    size_t j = 0;
    float initial = 0.0;

    for (size_t i = 0; i < flows.size(); i++)
        flowValue.push_back(initial);

    for (int index = start; index < finish; index += increment)
    {
        i = 0;
        vectorFlow = flows.begin();
        while (i != flows.size())
        {
            flowValue[i] = (*vectorFlow)->execute();
            vectorFlow++;
            i++;
        }

        j = 0;
        while (j != flows.size())
        {
            source = flows[j]->getSource();
            source->setValue(source->getValue() - flowValue[j]);

            destiny = flows[j]->getDestiny();
            destiny->setValue(destiny->getValue() + flowValue[j]);
            j++;
        }
    }
};

void ModelImplementation::show()
{
    cout << endl;
    cout << "Sub systems and their values: " << endl;
    for (auto system : systems)
        cout << "." << system->getId() << " " << system->getValue() << endl;

    cout << endl;
};

System *ModelImplementation::createSystem(string id = "unnamed", double initValue = 0.0)
{
    System *s = new SystemImplementation(id, initValue);

    add(s);
    return s;
};