#include "basicmutator.h"

#include "livingelement.h"

#include "assert.h"
BasicMutator::BasicMutator()
{
}

void BasicMutator::mutate(const std::vector<LivingElement*>& animals, LivingElement* animal)
{
    std::vector<LivingElement*> tempVec;
    for(auto a: animals)
        if(a->type() == animal->type() && a != animal)
            tempVec.push_back(a);
    int indexA = rand()%tempVec.size();
    int indexB = rand()%tempVec.size();

    std::vector<float> newGene = crossover(animals[indexA]->behaviourGene(), animals[indexB]->behaviourGene());
    animal->updateBehaviour(newGene);

}

void BasicMutator::mutate(std::vector<float>& gene) const
{

}

std::vector<float> BasicMutator::crossover(const std::vector<float>& geneOne, const std::vector<float>& geneTwo) const{

    assert(geneOne.size() == geneTwo.size());

    std::vector<float> output;

    //Simple method
    for(int i = 0; i<geneOne.size(); ++i)
        if (rand()%2)
            output.push_back(geneOne[i]);
        else
            output.push_back(geneTwo[i]);
    return output;
}
