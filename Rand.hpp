#pragma once
#include "base.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Rand : public Base {
	public:
		Rand() : Base() {
			srand(time(NULL)); 
			this->value = rand()%100;
		 }
		virtual double evaluate() { return value; }
		virtual std::string stringify() { 
			ostringstream ss;
			ss << setprecision(8) << noshowpoint << value;
			return ss.str();
		}
		int number_of_children() {
                        numChild = 1;
                }


	private:
		double value;
		int numChild;
};
