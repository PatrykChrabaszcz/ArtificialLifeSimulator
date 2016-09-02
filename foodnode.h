#ifndef FOODNODE_H
#define FOODNODE_H

#include "basenode.h"
#include "plantelement.h"


///
/// \brief The FoodNode class is a graphical representation of food element
///
class FoodNode : public BaseNode
{

public:
    explicit FoodNode(PlantElement *element);
    ~FoodNode();

    virtual void updateGeometry();

private:

    PlantElement* m_pElement;


    QSGGeometry *m_geometry;
    QSGSimpleMaterial<State> *m_material;
};

#endif // ANIMALNODE_H
