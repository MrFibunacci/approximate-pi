#include <iostream>
#include <cstdlib>
#include <math.h>
#include <limits>
#include <string>
#include "BigFloat.h"

const int PRECISION = 50;

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

BigFloat approximatePI(unsigned long long inCircle, unsigned long long total)
{
	// does calculation (4 * ((double) inCircle / total)):
	BigFloat a = std::to_string(inCircle);
	BigFloat b = std::to_string(total);
	
	BigFloat result = BigFloat::PrecDiv(a, b, PRECISION) * 4;


	//std::cout << result.ToString() << std::endl;
	return result;
}

int main()
{
    // setup some values
    const int max_executions = 75;
    const int sims_per_exec  = 500000;

    double radius = 200.0f;

    BigFloat recordPI   = 0;
	recordPI.SetPrecision(PRECISION);
	BigFloat recordDiff = 0;
	recordDiff.SetPrecision(PRECISION);

	BigFloat PI = "3.1415926535897932384626433832795028841971";

	std::cout.precision(PRECISION);

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

		recordDiff = (PI - recordPI);
		diff       = (PI - pi);
		recordDiff.abs();
		diff.abs();

		//std::cout << recordDiff.ToString() << std::endl;

		//double myPi = approximatePI(points_in_circle, points_total);
		//recordDiff = abs(M_PI - recordPI);
		//double diff = abs(M_PI - myPi);

		if (diff < recordDiff) {
			recordDiff = diff;
			recordPI   = pi;

			system("clear");
			std::cout << "real: " << std::fixed << M_PI << "\n" << std::endl;
			std::cout << "PI:   " << std::fixed << pi.ToString() << "\n" << std::endl;
			std::cout << "diff: " << std::fixed << recordDiff.ToString() << "\n" << std::endl;
		}
    }

    recordPI = approximatePI(points_in_circle, points_total);
	std::cout << recordPI.ToString() << std::endl;

    BigFloat diff = PI - recordPI;
	
	std::cout << diff.ToString() << std::endl;
	std::cout << "End" << std::endl;
	
	getchar();
    return 0;
}