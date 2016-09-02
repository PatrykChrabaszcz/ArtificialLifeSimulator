#ifndef ANNBRAIN_H
#define ANNBRAIN_H

#include <floatfann.h>
#include <fann_cpp.h>

#include "brain.h"

///
/// \brief The ANNBrain class implements brain using artificial neural networks
///
/// Neural networks are provided by FANN library, Neural network have static structure.
/// Weights of connection between network nodes can be changed using updateGene function
///
class ANNBrain : public Brain
{
public:
    explicit ANNBrain();
    virtual ~ANNBrain();

    ///
    /// \brief think converts inputs from sensors into outputs to motors
    /// \param input vector of floats with sensor data
    /// \param output vector of floats with motors data
    ///
    virtual void think(std::vector<float>& input, std::vector<float>& output);

    ///
    /// \brief gene used to extract brain information for further processing
    /// \return array of floats representing connections weights
    ///
    virtual const std::vector<float>& gene() const;

    ///
    /// \brief updateGene updates connections in neural network using gene array
    ///
    ///
    virtual void updateGene(const std::vector<float>& gene);

private:
    FANN::neural_net m_neuralNet;

    //Life time managed by ANNBrain
    FANN::connection* m_connections;

    std::vector<float> m_gene;
};

#endif // ANNBRAIN_H
