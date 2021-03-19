#include "Market.h"

int main()
{
    // vector<float> k{0.5,1,0.5};

    // distributionParams f{-1,1,"Normal"};
    // distributionParams s{0,1,"Normal"};
    // distributionParams g{1,1,"Normal"};

    // vector<distributionParams> dP{f,s,g};
    // GaussianMixtureDistribution G(k,dP);

    tuple<float,float> leftGaussian = std::make_tuple(0.f,1.f);
    tuple<float,float> middleGaussian = std::make_tuple(0.f,2.f);
    tuple<float,float> rightGaussian = std::make_tuple(10.f,3.f);

    EmissionModel Test = EmissionModel(leftGaussian,middleGaussian,rightGaussian);

    std::cout << std::get<0>(leftGaussian) << std::endl;
    std::cout << std::get<1>(leftGaussian) << std::endl;
    std::cout << std::get<0>(Test.leftGaussian) << std::endl;
    std::cout << std::get<1>(Test.leftGaussian) << std::endl;

}


