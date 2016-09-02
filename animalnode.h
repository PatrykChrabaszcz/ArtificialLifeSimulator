#ifndef ANIMALNODE_H
#define ANIMALNODE_H

#include "basenode.h"
#include "livingelement.h"
#include <QSGVertexColorMaterial>
#include "shader.h"


///
/// \brief The AnimalNode class for graphical representation of animal
///
/// This class uses Qt GeometryNode class to provide graphical
/// representation of animal with its sensors and motors.
/// Sensors lightup on activation, motors are colored with intensity
/// depending on actual power
///
class AnimalNode : public BaseNode
{

    ///
    /// \brief The SensorsNode class for graphical representation of
    /// animal eyes.
    ///
    /// Each eye is a straight ray coming from animal center.
    /// Sensor activates when ray intersects with other element
    ///
    class SensorsNode: public QSGGeometryNode{
        friend class AnimalNode;
        explicit SensorsNode();
        ~SensorsNode();
        void updateGeometry(LivingElement* element);

        QSGGeometry *m_geometry;
        QSGVertexColorMaterial *m_material;
    };

    ///
    /// \brief The MotorsNode class for graphical representation of animal motors.
    ///
    /// Each motor is colored with intensity depending on actual motor power
    ///
    class MotorsNode: public QSGGeometryNode{
        friend class AnimalNode;
        explicit MotorsNode();
        ~MotorsNode();
        void updateGeometry(LivingElement* element);

        QSGGeometry *m_geometry;
        QSGVertexColorMaterial *m_material;
    };

public:
    explicit AnimalNode(LivingElement *element);

    virtual void updateGeometry();
private:
    LivingElement* m_lElement;

    SensorsNode* sn;
    MotorsNode* mn;

    QSGGeometry *m_geometry;
    QSGSimpleMaterial<State> *m_material;
};

#endif // ANIMALNODE_H
