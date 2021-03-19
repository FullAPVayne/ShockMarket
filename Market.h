#include <iostream>
#include <iomanip>
#include <vector>   
#include <string>
#include "./Eigen/Core"
#include <random>
#include <map>
#include <chrono> 

#define string std::string
#define vector std::vector
#define normal std::normal_distribution
#define tuple std::tuple


// struct to contain necessary info about a single normal distribution
struct distributionParams
{
    float mean;
    float variance;
    string distName;
};

// struct to contain necessary info about Mixture of gaussians
struct GaussianMixtureDistribution
{
    string name;
    vector<float> K;
    vector<distributionParams> params;
    vector<normal<float>> distributions;

    GaussianMixtureDistribution(vector<float> K, vector<distributionParams> params);
     
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

        EmissionModel(tuple<float,float> lG,
                        tuple<float,float> mG,
                        tuple<float,float> rG);
        EmissionModel(tuple<float,float> lG,
                        tuple<float,float> mG,
                        tuple<float,float> rG,
                        float lW,
                        float mW,
                        float rW);

        tuple<float,float> leftGaussian;
        tuple<float,float> middleGaussian;
        tuple<float,float> rightGaussian;
    
        float leftWeight;
        float middleWeight;
        float rightWeight;
        
        void set_Gaussian(string specificy, tuple<float,float> newParam);
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
        // constructors, TODO add constructor that loads from JSON file
        GrowthModel();
        GrowthModel(string initialState,
                    string hiddenModelName,
                    float initialTransitionTendency,
                    GaussianMixtureDistribution f,
                    GaussianMixtureDistribution s,
                    GaussianMixtureDistribution g,
                    float thF2S,
                    float thS2G);
        // getter
        string getState();
        float getTransitionTendency();
        float getGrowthRate();
        GaussianMixtureDistribution getEmissionProperty(string state);
        
        
        // update function to use to feed events into the growth model and advance it
        void update();
        void update(marketEvent event);

        // log function
        void printLog();

    private:
        // identifier for the state the model is in "G", "S" or "F"
        string state;
        // name of the underlyinng model
        string modelName;
        // Map mapping the State to the relevant distribution info
        std::map<string,GaussianMixtureDistribution> emissionProperty; 
        // value between zero and [-1,1] inidcating the tendency to change states
        // [-1:-0.34] -> tendency towards "falling" state
        // [-0.33:0.33] -> tendency towards "stagnating" state
        // [0.34:1] -> tendeny towards "rising" state
        float thFalling2Stagnation;
        float thStagnation2Growing;
        
        
        float transitionTendency;
    
};

class Company
{
    public:
        string industry;
        CEO mCEO;
        int employes;
        int locations;
        int availableStocks;
        GrowthModel growthModel;
};
