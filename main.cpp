#include <iostream>
#include <cstdlib>
#include <math.h>
#include <limits>
#include <string>
#include "BigFloat.h"

// Little helper for random double numbers
double fRand(double fMin, double fMax)
{
    double f = (double) rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

class PointClass {
private:
	double x;
    double y;

public: 
	PointClass() {
		x = fRand(-200, 200);
		y = fRand(-200, 200);
	};

	double getDistance() {
		return x * x + y * y;
	}
};

std::string approximatePI(unsigned long long inCircle, unsigned long long total)
{
	// does calculation (4 * ((double) inCircle / total)):
	BigFloat a = std::to_string(inCircle);
	BigFloat b = std::to_string(total);
	
	BigFloat result = (a / b) * 4;

	std::cout << result.ToString() << std::endl;
	return result.ToString();;
}

int main()
{
    // setup some values
    const int max_executions = 50;
    const int sims_per_exec  = 50000;

    double radius = 200.0f;

    BigFloat recordPI   = 0;
	BigFloat recordDiff = 0;

	BigFloat M_PI = "3.1415926535897932384626433832795028841971";

	std::cout.precision(50);

    unsigned long long points_in_circle = 0;
    unsigned long long points_total     = 0;
	
	// loop throu all point and check if they are in the "circle" and init dots    
    for(int i = 0; i < max_executions; ++i)
    {
        for (int j = 0; j < sims_per_exec; ++j) 
		{
            PointClass temp_point;
            
			++points_total;

			//std::cout << std::to_string(points_total) << std::endl;

            if(temp_point.getDistance() <= radius * radius)
            {
                ++points_in_circle;
            }
        }

		BigFloat pi = approximatePI(points_in_circle, points_total);
		BigFloat diff;

		std::cout << pi << std::endl;
		getchar();

		recordDiff = M_PI - recordPI;
		diff       = M_PI - pi;
		//double myPi = approximatePI(points_in_circle, points_total);
		//recordDiff = abs(M_PI - recordPI);
		//double diff = abs(M_PI - myPi);

		if (diff < recordDiff) {
			recordDiff = diff;
			recordPI   = pi;

			//system("cls");
			std::cout << "real: " << std::fixed << M_PI << "\n" << std::endl;
			std::cout << "PI:   " << std::fixed << pi.ToString() << "\n" << std::endl;
			std::cout << "diff: " << std::fixed << recordDiff.ToString() << "\n" << std::endl;
		}
    }

    recordPI = approximatePI(points_in_circle, points_total);
	std::cout << recordPI.ToString() << std::endl;

    BigFloat diff = M_PI - recordPI;
	
	std::cout << diff.ToString() << std::endl;
	std::cout << "End" << std::endl;
	
	getchar();
    return 0;
}