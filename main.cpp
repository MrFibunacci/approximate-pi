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

int main()
{
    // store dots in vector
    std::vector<Point> points;
    // setup some values
    //int32_t max_points = std::numeric_limits<int32_t>::max();
    int max_points = std::numeric_limits<int>::max()/2;
    int radius = 200;

    double pi;

    // init dots
    for(int i = 0; i < max_points; i++)
    {
        Point temp_point;
        temp_point.x = fRand(-radius, radius);
        temp_point.y = fRand(-radius, radius);
        points.push_back(temp_point);
    }
    
    // loop throu all point and check if they are in the "circle"
    int circle_count = 0;
    for(int32_t i = 0; i <= points.size(); i++)
    {
        double distance_centre = points[i].x * points[i].x + points[i].y * points[i].y;
        if(distance_centre <= (double) radius * (double) radius)
        {
            circle_count++;
        }
    }

    pi = (4 * ( (double) circle_count / points.size()));

    double diff = (M_PI-pi);

    std::cout.precision(std::numeric_limits<double>::max());
    std::cout << std::fixed << diff << std::endl;

    return 0;
}