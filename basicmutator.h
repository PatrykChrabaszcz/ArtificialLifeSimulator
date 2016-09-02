#ifndef BASICMUTATOR_H
#define BASICMUTATOR_H

#include "mutator.h"

///
/// \brief The BasicMutator class is a simple class responsible for creating
/// new population members. It should be improved to see the power of EA.
/// Now it is too simple and naive.
///
class BasicMutator : public Mutator
{
public:
    explicit BasicMutator();

    //TO DO add mutation parameters (?)(also in base class )

    virtual void mutate(const std::vector<LivingElement*>& animals, LivingElement* animal);

    virtual std::vector<float> crossover(const std::vector<float>& geneOne, const std::vector<float>& geneTwo) const;
    virtual void mutate(std::vector<float>& gene ) const;

};

#endif // BASICMUTATOR_H
