
#include "animalnode.h"

#include <QSGVertexColorMaterial>

#include "shader.h"

AnimalNode::SensorsNode::SensorsNode()
{
    m_geometry = new QSGGeometry(QSGGeometry::defaultAttributes_ColoredPoint2D(), 0);
    m_material = new QSGVertexColorMaterial;

    m_geometry->setDrawingMode(GL_LINES);

    m_geometry->setLineWidth(1);
    setGeometry(m_geometry);
    setMaterial(m_material);
}

AnimalNode::SensorsNode::~SensorsNode()
{
    delete m_geometry;
    delete m_material;
}

void AnimalNode::SensorsNode::updateGeometry(LivingElement* element)
{
    m_geometry->allocate(element->m_sensors.size()*2);
    QSGGeometry::ColoredPoint2D *v = m_geometry->vertexDataAsColoredPoint2D();

    int counter = 0;

    //Transparency
    int alphaValue = 25;

    for(const LivingElement::Sensor& sensor: element->getSensors()){
        v[counter++].set(element->xPosition()+element->radius()*sin(sensor._position+element->rotation()),
                         element->yPosition()+ element->radius()*cos(sensor._position+element->rotation()),
                         sensor._color.red(),sensor._color.green(),sensor._color.blue(),alphaValue);

        v[counter++].set(element->xPosition()+sensor._range*sin(sensor._position+element->rotation()),
                         element->yPosition()+sensor._range*cos(sensor._position+element->rotation()),
                         sensor._color.red(),sensor._color.green(),sensor._color.blue(),alphaValue);
    }
}


AnimalNode::MotorsNode::MotorsNode()
{
    m_geometry = new QSGGeometry(QSGGeometry::defaultAttributes_ColoredPoint2D(), 0);

    m_geometry->setDrawingMode(GL_TRIANGLES);

    m_geometry->setLineWidth(1);
    setGeometry(m_geometry);

    m_material = new QSGVertexColorMaterial;
    setMaterial(m_material);
}

AnimalNode::MotorsNode::~MotorsNode()
{
    delete m_geometry;
    delete m_material;
}

void AnimalNode::MotorsNode::updateGeometry(LivingElement* element)
{
    m_geometry->allocate(element->m_motors.size()*6);
    QSGGeometry::ColoredPoint2D *v = m_geometry->vertexDataAsColoredPoint2D();

    // Motor width in angles
    float mW = 0.4;


    //Transparency
    int alphaValue = 70;

    int counter = 0;
    //Draw motor ( experimental values)
    for(const LivingElement::Motor& motor: element->getMotors()){

        //Motor color depends on actual motor power
        QColor color = QColor(Qt::black);
        color.setAlpha(alphaValue);
        if(motor._power>=0){
            color.setBlue(motor._power*255);
            color.setRed(0);
        }
        else{
            color.setBlue(0);
            color.setRed(-motor._power*255);
        }

        v[counter++].set(element->xPosition()+element->radius()*sin(motor._position+element->rotation()+mW),
                         element->yPosition()+element->radius()*cos(motor._position+element->rotation()+mW),
                         color.red(),color.green(),color.blue(),color.alpha());

        v[counter++].set(element->xPosition()+element->radius()*sin(motor._position+element->rotation()-mW),
                         element->yPosition()+element->radius()*cos(motor._position+element->rotation()-mW),
                         color.red(),color.green(),color.blue(),color.alpha());

        v[counter++].set(element->xPosition()+2*element->radius()*sin(motor._position+element->rotation()+mW),
                         element->yPosition()+2*element->radius()*cos(motor._position+element->rotation()+mW),
                         color.red(),color.green(),color.blue(),color.alpha());

        v[counter++].set(element->xPosition()+element->radius()*sin(motor._position+element->rotation()-mW),
                         element->yPosition()+element->radius()*cos(motor._position+element->rotation()-mW),
                         color.red(),color.green(),color.blue(),color.alpha());

        v[counter++].set(element->xPosition()+2*element->radius()*sin(motor._position+element->rotation()+mW),
                         element->yPosition()+2*element->radius()*cos(motor._position+element->rotation()+mW),
                         color.red(),color.green(),color.blue(),color.alpha());

        v[counter++].set(element->xPosition()+2*element->radius()*sin(motor._position+element->rotation()-mW),
                         element->yPosition()+2*element->radius()*cos(motor._position+element->rotation()-mW),
                         color.red(),color.green(),color.blue(),color.alpha());
    }
}



//************************************************************************************************
AnimalNode::AnimalNode(LivingElement* element):
    m_lElement(element)
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

void AnimalNode::updateGeometry()
{
    //Check color
    if(m_lElement->selected())
        m_material->state()->color = QColor(Qt::blue);
    else{
        m_material->state()->color = m_lElement->color();
    }
    //Draw animal body
    updateCircleTable(m_lElement->radius(),m_lElement->xPosition(),m_lElement->yPosition());

    while(childCount()){
        delete childAtIndex(0);
    }
    removeAllChildNodes();

    sn = new SensorsNode;
    sn->updateGeometry(m_lElement);
    appendChildNode(sn);

    mn = new MotorsNode;
    mn->updateGeometry(m_lElement);
    appendChildNode(mn);

    markDirty(QSGNode::DirtyGeometry);
}
