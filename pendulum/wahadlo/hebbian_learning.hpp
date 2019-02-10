//
//  hebbian_learning.hpp
//  wahadlo
//
//  Created by Matek on 27.11.2018.
//  Copyright © 2018 Matek. All rights reserved.
//

#ifndef hebbian_learning_hpp
#define hebbian_learning_hpp
#define pi 3.14159265
#define N 160 // neurony
#define number_of_trainings 1000 // ile razy trenowana jest siec


#include <stdio.h>
#include <cmath>
#include <iostream>

class Hebb{
public:
    Hebb();
    ~Hebb();
    
    double y[N];
    double w[N];
    
    double f(double t);
    double wx(int i);
    
private:
    double x[N];
    double out[N];
    
    double bipolar(double x);
    void random_weights();
    void train();
};

#endif /* hebbian_learning_hpp */
