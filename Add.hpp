#pragma once

#include "base.hpp"
#include <cmath>
#include <string>

using namespace std;

        class Add: public Base {
                public:
                        Add(Base* x, Base* y) : Base(){

                                lhs = x;
                                rhs = y;

                        }
			~Add(){

				delete lhs;
				delete rhs;
			}

                        double evaluate() {
                                return lhs->evaluate()+rhs->evaluate();
                        }

                        string stringify() {
                                return "(" + lhs->stringify() + "+" + rhs->stringify() + ")";
                        }


			int number_of_children() {
                                return 2;
                        }

                        Base* get_child(int i){

                        	return (i == 0) ? lhs : (i == 1) ? rhs : nullptr;

                        }		

			void accept(Visitor* visitor, int index) {
				if(index == 0) return visitor->visit_add_begin(this);
				else if(index == 1) return visitor->visit_add_middle(this);
				else return visitor->visit_add_end(this);
			}
                private:

                        Base* lhs;
                        Base* rhs;
	


        };
