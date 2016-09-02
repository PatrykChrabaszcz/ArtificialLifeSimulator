#include "foodnode.h"

#include <QSGVertexColorMaterial>

#include "shader.h"

FoodNode::FoodNode(PlantElement* element):
    m_pElement(element)
{
    m_geometry = new QSGGeometry(QSGGeometry::defaultAttributes_TexturedPoint2D(), 0);

    m_geometry->setDrawingMode(GL_TRIANGLE_STRIP);

    m_geometry->setLineWidth(1);
    setGeometry(m_geometry);

    m_material = Shader::createMaterial();
    m_material->state()->color = element->color();
    setMaterial(m_material);

    initCircleTable();
    updateGeometry();
}

FoodNode::~FoodNode()
{
    delete m_geometry;
    delete m_material;
}

void FoodNode::updateGeometry(){

    //Draw animal body
    updateCircleTable(m_pElement->radius(),m_pElement->xPosition(),m_pElement->yPosition());

    markDirty(QSGNode::DirtyGeometry);
}
