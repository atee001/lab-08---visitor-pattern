
#pragma once
#include "base.hpp"
#include <assert.h>

class Div : public Base {

  public:

    Div(Base* lhs, Base* rhs) : Base(){

      this->lhs = lhs;
      this->rhs = rhs;
      assert(rhs->evaluate() != 0 && "Cannot Divide by Zero!"); // divide by zero

    }

    double evaluate(){

      return lhs->evaluate()/rhs->evaluate();

    }
   
    ~Div(){

	delete rhs;
	delete lhs;

	}

    string stringify(){

      return "(" + lhs->stringify() + "/" + rhs->stringify() + ")";

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

};
