#include "Market.h"

int main()
{
    vector<float> k{0.5,1,0.5};

    distributionParams f{-1,1,"Normal"};
    distributionParams s{0,1,"Normal"};
    distributionParams g{1,1,"Normal"};

    vector<distributionParams> dP{f,s,g};
    GaussianMixtureDistribution G(k,dP);

}


