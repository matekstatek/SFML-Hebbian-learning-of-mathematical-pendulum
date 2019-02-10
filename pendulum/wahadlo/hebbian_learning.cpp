//
//  hebbian_learning.cpp
//  wahadlo
//
//  Created by Matek on 27.11.2018.
//  Copyright © 2018 Matek. All rights reserved.
//


#include "hebbian_learning.hpp"
#include <cmath>

#define alpha 0.5 // wspolczynnik uczenia

Hebb::Hebb(){
    for(double i=0; i<N; i+=1){
        x[(int)i] = (double)(i/100);
        y[(int)i] = f(x[(int)i]);
        out[(int)i] = bipolar(abs(x[(int)i] - y[(int)i]));
    }
    
    random_weights();
    train();
}

double Hebb::f(double t){
    return 2*cos(2*t + pi/2);
}

double Hebb::bipolar(double t){
    if (t > 0) return -1;
    return 1;
}

void Hebb::random_weights(){
    for(int i=0; i<N; i++){
        w[i] = (rand() % 100); // 73
        w[i] = w[i] / 100; //0.73
        
        if (rand() % 100 >= 50)
            w[i] = -w[i];
    }
}

void Hebb::train(){
    for(int j=0; j<number_of_trainings; j++){
        for(int i=0; i<N; i++){
            w[i] = w[i] + alpha * y[i] * out[i];
            w[i] /= 2;
        }
        std::cout << "Network trained " << j << " times." << std::endl;
    }
}

double Hebb::wx(int i){
    return w[i];
}
