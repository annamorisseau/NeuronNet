#include "random.h"

RandomNumbers::RandomNumbers(unsigned long int s)
{     if (s == 0) {
        std::random_device rd;
        seed = rd();
    }
    rng = std::mt19937(seed);}

    void RandomNumbers::uniform_double(std::vector<double>& res, double lower, double upper){ // il serait mieux de reutiliser mehode double uniform
    std::uniform_real_distribution<> unif(lower, upper);
    for (auto I = res.begin(); I != res.end(); I++) *I = unif(rng); //rng ->seed
}
    
    double RandomNumbers::uniform_double(double lower, double upper){
    std::uniform_real_distribution<> unif(lower, upper);
    double result = unif(rng);
    return result;
}
    
    void RandomNumbers::normal(std::vector<double> &res, double mean, double sd){
    std::normal_distribution<> norm(mean, sd);
    for (auto I = res.begin(); I != res.end(); I++) *I = norm(rng);
}
    double RandomNumbers::normal(double mean, double sd){
    std::normal_distribution<> norm(mean, sd);
    double result = norm(rng);
    return result;
}
    
    void RandomNumbers::poisson(std::vector<int> &res, double mean){
		std::poisson_distribution<> pois(mean);
		for (auto I = res.begin(); I != res.end(); I++) *I = pois(rng);
	}
    
    
    int RandomNumbers::poisson(double mean){
		std::poisson_distribution<> pois(mean);
		int result = pois(rng);
		return result;
	}
    
    void RandomNumbers::shuffle(std::vector<size_t> &_v) {std::shuffle(_v.begin(), _v.end(), rng);}

//{}

