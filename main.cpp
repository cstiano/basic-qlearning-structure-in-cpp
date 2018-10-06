//Sample using Qtablelearning
#include "src/Qtablelearning.h"
#include <math.h>
#include <iostream>

class QlearningSample : public Qtablelearning{
    public:
    using Qtablelearning::Qtablelearning;
    
    // Define reward as the distance between two points
    double reward(std::pair<double, double> a, std::pair<double, double> b){
        return sqrt(((a.first-b.first)*(a.first-b.first))+((a.second-b.second)*(a.second-b.second)));
    }
};

//Verify the current state like the action on the environment
int getCurState(){
    return 0;
}

int main(){
    QlearningSample sample = QlearningSample(16,4);

    int j = 0;
    int num_iterations = 0;
    while(num_iterations<10000){
        //Here should be reseted the environment
        sample.setLastState(0);
        while(j<99){
            j++;
            sample.updateQtable(getCurState(),sample.getRandomAction(), sample.reward(std::make_pair(0,0),std::make_pair(3,3)));
        }
        num_iterations++;
    }
    
    return 0;
}