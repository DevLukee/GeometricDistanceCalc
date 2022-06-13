#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;


double eagle_view_distance(double g[4]){
    double height;
    double lenght;
    double d;


    if (g[0] > g[2]) {

        height = g[0] - g[2];
        lenght = g[3] - g[1];


        double distance = sqrt((pow(height,2) + pow(lenght,2)));

        double PI = 2*acos(0.0);
   

        

        cout << distance << endl;

        double R = 6371e3; // metres
        double o1 = g[0] * PI/180; // φ, λ in radians
        double o2 = g[2] * PI/180;
        double trio = (g[2]-g[0]) * PI/180;
        double tritri = (g[2]-g[0]) * PI/180;

        double a = sin(trio/2) * sin(trio/2) + cos(o1) * cos(o2) * sin(tritri/2) * sin(tritri/2);
        double c = 2 * atan2(sqrt(a), sqrt(1-a));

        d = R * c; 

        cout << "Distance: " << d << " meters"<< endl;



    


    return d;
    
}


int main() {
    
    double loc1_lang = 0;
    double loc1_lat = 0;

    double loc2_lang = 0;
    double loc2_lat = 0;


    double geo_loc[4] = {loc1_lat, loc1_lang, loc2_lat, loc2_lang};

    eagle_view_distance(geo_loc);

    

    return 0;
}
