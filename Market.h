#include <iostream>
#include <iomanip>
#include <vector>   
#include <string>
#include "./Eigen/Core"
#include <random>
#include <map>
#include <chrono> 
//#include "jsoncpp/json/json.h"

#define string std::string
#define vector std::vector
#define normal std::normal_distribution
#define tuple std::tuple

class EmissionModifier
{
    
};

class TransitionModifier
{

};

// struct to contain necessary info about a single normal distribution
struct distributionParams
{
    float mean;
    float variance;
};

struct marketEvent 
{
    string name;
    float influence;
};

class EmissionModel
{
    // Consists of the characters for three gaussians
    public:

        EmissionModel(distributionParams lG,
                        distributionParams mG,
                        distributionParams rG);
        EmissionModel(distributionParams lG,
                        distributionParams mG,
                        distributionParams rG,
                        float lW,
                        float mW,
                        float rW);

        distributionParams leftGaussian;
        distributionParams middleGaussian;
        distributionParams rightGaussian;
    
        float leftWeight;
        float middleWeight;
        float rightWeight;
        
        void set_Gaussian(string specificy, distributionParams newParam);
        void set_GaussianValue(string specGauss,string specValue,float val);
        void change_GaussianValue(string specGauss,string specValue,float dVal);
        
        float get_emission();
};

class CEO
{
    public:
        CEO();
        string name;
        string personality;
        float reputation;
};

class GrowthModel
{
    public:
        GrowthModel();
        GrowthModel(EmissionModel recessionState,
                    EmissionModel stagnationState,
                    EmissionModel growingState,
                    int startState);
        
        string getCurrentState();
        float getInternalValue();
        float getInternalValueTendency();

        void setInternalValue();
        void setInternalValueTendency();
        
        // represents a single time step in which the internalValue is calulated 
        // and the state emits a growth value
        void update();
        void update(marketEvent event);

        // log function
        void printLog();

    private:
        float internalValueCurrent;
        float internalValueTendency;


};

class Company
{
    public:
        string industry;
        CEO mCEO;
        int employees;
        int locations;
        int availableStocks;
        GrowthModel growthModel;
};
