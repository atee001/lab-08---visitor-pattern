
#pragma once
#include "base.hpp"

class Mult : public Base {

  public:

    Mult(Base* lhs, Base* rhs) : Base(){

      this->lhs = lhs;
      this->rhs = rhs;

    }
	
    ~Mult(){
	delete lhs;
	delete rhs;
    }

    double evaluate(){

      return lhs->evaluate()*rhs->evaluate();

    }

    string stringify(){

      return "(" + lhs->stringify() + "*" + rhs->stringify() + ")";

    }

  private:

    Base* lhs;
    Base* rhs;

};
