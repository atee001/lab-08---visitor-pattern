
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
    Base* get_child(int i){
      
      return (i == 0) ? lhs : (i == 1) ? rhs : nullptr;

    }

    int number_of_children() {
             return 2;
     }

    void accept(Visitor* visitor, int index){

	return (index == 0) ? visitor->visit_mult_begin(this) : (index == 1) ? visitor->visit_mult_middle(this) : visitor->visit_mult_end(this);

    }

  private:

    Base* lhs;
    Base* rhs;

};
