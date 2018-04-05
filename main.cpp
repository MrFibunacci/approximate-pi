#include <iostream>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <limits>

struct Point {
    double x;
    double y;
};

// Little helper for random double numbers
double fRand(double fMin, double fMax)
{
    double f = (double) rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

double approximatePI(unsigned long long inCircle, unsigned long long total)
{
    return (4 * ((float)inCircle / total));
}

int main()
{
    // setup some values
    const int max_executions = 100;
    const int sims_per_exec  = 20'000'000;

    double radius = 200.0f;

    double myPi;

    unsigned long long points_in_circle = 0;
    unsigned long long points_total     = 0;

    std::cout.precision(15);

    // loop throu all point and check if they are in the "circle" and init dots    
    for(int i = 0; i < max_executions; ++i)
    {
        for (int j = 0; j < sims_per_exec; ++j) {
            Point temp_point;
            temp_point.x = fRand(-radius, radius);
            temp_point.y = fRand(-radius, radius);
            
            ++points_total;

            double distance_centre = temp_point.x * temp_point.x + temp_point.y * temp_point.y;
            if(distance_centre <= radius * radius)
            {
                ++points_in_circle;
            }
        }

        myPi = approximatePI(points_in_circle, points_total);

        // show some hot data
        system("clear");
        std::cout << "\nIteration:        " << i + 1 << std::endl;
        std::cout << "Points in circle: " << points_in_circle << std::endl;
        std::cout << "Points in total:  " << points_total << std::endl;
        std::cout << "PI:               " << std::fixed << myPi << std::endl;
    }

    myPi = approximatePI(points_in_circle, points_total);

    double diff = M_PI - myPi;

    std::cout << std::fixed << diff << std::endl;

    return 0;
}