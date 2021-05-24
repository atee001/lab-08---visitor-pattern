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

			int number_of_children() {
           return 2;
      }


				
			Base* get_child(int i){

     				return (i == 0) ? lhs : (i == 1) ? rhs : nullptr;

    			}


                private:

                        Base* lhs;
                        Base* rhs;
			int numChild;
			

        };
