#pragma once

#include "base.hpp"
#include <cmath>
#include <string>

using namespace std;

        class Sub: public Base {
                public:
                        Sub(Base* x, Base* y) : Base() {

                                lhs = x;
                                rhs = y;

                        }


                        double evaluate() {
                                return lhs->evaluate()-rhs->evaluate();
                        }

                        string stringify() {
                                return "(" + lhs->stringify() + "-" + rhs->stringify() + ")";
                        }

			~Sub(){
				delete lhs;
				delete rhs;
			}

                private:

                        Base* lhs;
                        Base* rhs;



        };
