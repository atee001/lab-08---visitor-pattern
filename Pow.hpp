#pragma once 
#include "base.hpp"

#include <cmath>
#include <string>

using namespace std;

	class Pow: public Base {
		public:
			Pow(Base* x, Base* y): Base() {

				lhs = x;
				rhs = y;

			}
			
			~Pow(){

				delete lhs;
				delete rhs;

			}

			double evaluate() {
				

				return pow(lhs->evaluate(), rhs->evaluate());
			}

			string stringify() {
				return "(" + lhs->stringify() + "**" + rhs->stringify() + ")";
			}
			Base* get_child(int i){
        
        return (i == 0) ? lhs : (i == 1) ? rhs : nullptr;

			}
    
			int number_of_children() {
				return 2;
			}
		
			 void accept(Visitor* visitor, int index){

        			return (index == 0) ? visitor->visit_pow_begin(this) : (index == 1) ? visitor->visit_pow_middle(this) : visitor->visit_pow_end(this);

    			}	



		private:

			Base* lhs;
			Base* rhs;



	};
