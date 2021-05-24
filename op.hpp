#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Op : public Base {
	public:
		Op(double value) : Base() { this->value = value; }
		virtual double evaluate() { return value; }
		virtual std::string stringify() { 
			ostringstream ss;
			ss << setprecision(8) << noshowpoint << value;
			return ss.str();
	}

		Base* get_child(int i){			
			return nullptr;

		}		
	private:
		double value;

};

#endif //__OP_HPP__
