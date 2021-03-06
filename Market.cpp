#include "Market.h"

EmissionModel::EmissionModel(distributionParams lG,
                        distributionParams mG,
                        distributionParams rG)
{
    leftGaussian = lG;
    middleGaussian = mG;
    rightGaussian = rG;

    leftWeight = 0.33;
    middleWeight = 0.33;
    rightWeight = 0.33;
}

EmissionModel::EmissionModel(distributionParams lG,
                        distributionParams mG,
                        distributionParams rG,
                        float lW,
                        float mW,
                        float rW)
{
    leftGaussian = lG;
    middleGaussian = mG;
    rightGaussian = rG;

    leftWeight = lW;
    middleWeight = mW;
    rightWeight = rW;
}

void EmissionModel::set_Gaussian(string specGauss, distributionParams newParam)
{
    if (specGauss.compare("l") == 0)
    {
        leftGaussian = newParam;
    }
    else if (specGauss.compare("m") == 0)
    {
        middleGaussian = newParam;
    }
    else if (specGauss.compare("r") == 0)
    {
        rightGaussian = newParam;
    }
    else
    {
        std::cout << "No Match!" << std::endl;
    }
}

void EmissionModel::set_GaussianValue(string specGauss,string specValue,float val)
{
    if (specGauss.compare("l") == 0)
    {
        if (specValue.compare("mean") == 0) {leftGaussian.mean = val;}
        else if (specValue.compare("std") == 0) {leftGaussian.variance = val;}
        else {std::cout << "specValue has no match!" << std::endl;}
    }
    else if (specGauss.compare("m") == 0)
    {
        if (specValue.compare("mean") == 0) {leftGaussian.mean = val;}
        else if (specValue.compare("std") == 0) {leftGaussian.variance = val;}
        else {std::cout << "specValue has no match!" << std::endl;}
    }
    else if (specGauss.compare("r") == 0)
    {
        if (specValue.compare("mean") == 0) {leftGaussian.mean = val;}
        else if (specValue.compare("std") == 0) {leftGaussian.variance = val;}
        else {std::cout << "specValue has no match!" << std::endl;}
    }
    else
    {
        std::cout << "No Match!" << std::endl;
    }
}

void EmissionModel::change_GaussianValue(string specGauss,string specValue,float dVal)
{
    if (specGauss.compare("l") == 0)
    {
        if (specValue.compare("mean") == 0) {leftGaussian.mean = leftGaussian.mean+dVal;}
        else if (specValue.compare("std") == 0) {leftGaussian.variance = leftGaussian.variance+dVal;}
        else {std::cout << "specValue has no match!" << std::endl;}
    }
    else if (specGauss.compare("m") == 0)
    {
        if (specValue.compare("mean") == 0) {leftGaussian.mean = leftGaussian.mean+dVal;}
        else if (specValue.compare("std") == 0) {leftGaussian.variance = leftGaussian.variance+dVal;}
        else {std::cout << "specValue has no match!" << std::endl;}
    }
    else if (specGauss.compare("r") == 0)
    {
        if (specValue.compare("mean") == 0) {leftGaussian.mean = leftGaussian.mean+dVal;}
        else if (specValue.compare("std") == 0) {leftGaussian.variance = leftGaussian.variance+dVal;}
        else {std::cout << "specValue has no match!" << std::endl;}
    }
    else 
    {
        std::cout << "No Match!" << std::endl;
    }
}

float EmissionModel::get_emission()
{
    // figure out what distribution to draw from
    // draw random number between 0.0 and 1.0 (inclucive)
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    // create random seed for draw mechanism
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e (seed); 

    float m;
    float s;

    if (r<leftWeight)
    {
        m = leftGaussian.mean;
        s = leftGaussian.variance;
        // create distribution
        normal<float> dist(m,s);
        // draw from distribution
        return dist(e);
    } 
    else if (r>=leftWeight && r<(leftWeight+middleWeight))
    {
        m = leftGaussian.mean;
        s = leftGaussian.variance;
        // create distribution
        normal<float> dist(m,s);
        // draw from distribution
        return dist(e);
    }
    else
    {
        m = leftGaussian.mean;
        s = leftGaussian.variance;
        // create distribution
        normal<float> dist(m,s);
        // draw from distribution
        return dist(e);
    }
}

GrowthModel::GrowthModel()
{
    // // init hidden model params
    // modelName = "Markov";
    // transitionTendency = 0;
    // std::norm g = {.5f, 1.f, "Normal"};
    // distributionParams s = {0.f, 1.f, "Normal"};
    // distributionParams f = {-.5f, 1.f, "Normal"};
    
    // // store emission distribution parameters for this instance
    // emissionProperty.insert(std::pair<string,GaussianMixtureDistribution>("G",g));
    // emissionProperty.insert(std::pair<string,GaussianMixtureDistribution>("S",s));
    // emissionProperty.insert(std::pair<string,GaussianMixtureDistribution>("F",f));  
    
    // // set transition between states
    // // [-1:-0.34] -> tendency towards "falling" state
    //     // [-0.33:0.33] -> tendency towards "stagnating" state
    //     // [0.34:1] -> tendeny towards "rising" state
    // thFalling2Stagnation = -.34f;
    // thStagnation2Growing = .33f;
    
    // // set starting state
    //state = "S";

}

// GrowthModel::GrowthModel(string initialState,
//                     string hiddenModelName,
//                     float initialTransitionTendency,
//                     GaussianMixtureDistribution f,
//                     GaussianMixtureDistribution s,
//                     GaussianMixtureDistribution g,
//                     float thF2S,
//                     float thS2G)
// {
//     // init hidden model params
//     modelName = hiddenModelName;
//     transitionTendency = initialTransitionTendency;
//     // store emission distribution parameters for this instance
//     emissionProperty.insert(std::pair<string,GaussianMixtureDistribution>("G",g));
//     emissionProperty.insert(std::pair<string,GaussianMixtureDistribution>("S",s));
//     emissionProperty.insert(std::pair<string,GaussianMixtureDistribution>("F",f));  
    
//     // set transition between states
//     thFalling2Stagnation = thF2S;
//     thStagnation2Growing = thS2G;
    
//     // set starting state
//     state = initialState;


    
// }

/*
GETTER/SETTER
*/

float GrowthModel::getInternalValue()
{
    return this->internalValueCurrent;
}

float GrowthModel::getInternalValueTendency()
{
    return this->internalValueTendency;
}

void GrowthModel::printLog()
{
    // // print internal state
    // std::cout << "State: " <<this->getState() << std::endl;
    // // print transition properties
    // std::cout << "T_tendency: " <<this->getTransitionTendency() << " || " ;
    // std::cout << "ThF2S: " <<this->thFalling2Stagnation << " | ";
    // std::cout << "ThS2G: " <<this->thStagnation2Growing << std::endl;
    // // Distribution Properties
    // // "Growth"
    // distributionParams p = this->getEmissionProperty("G");
    // std::cout << "Growth: " << " || ";
    // std::cout << "Mean: " << p.mean << " | ";
    // std::cout << "Var: " << p.variance << std::endl;
    // // "Stagnation"
    // p = this->getEmissionProperty("S");
    // std::cout << "Stagnation: " <<" || ";
    // std::cout << "Mean: " << p.mean << " | ";
    // std::cout << "Var: " << p.variance << std::endl;
    // // "Falling"
    // p = this->getEmissionProperty("F");
    // std::cout << "Falling: " <<" || ";
    // std::cout << "Mean: " << p.mean << " | ";
    // std::cout << "Var: " << p.variance << std::endl;
}