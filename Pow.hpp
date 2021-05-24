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

			int number_of_children() {
				numChild = 2;
			}

		private:

			Base* lhs;
			Base* rhs;
			int numChild;


	};
