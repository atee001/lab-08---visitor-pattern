#include "visitor.hpp"
#include "iterator.hpp"
#include <iostream>
#include "Add.hpp"
#include "Sub.hpp"
#include "Pow.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "base.hpp"
#include "op.hpp"
#include "Rand.hpp"
using namespace std;
#pragma once


class VisitorLatex : Visitor{
	
	
	public:
		
		VisitorLatex(){ expTree = ""; }
		
		VisitorLatex(const string& expTree) : expTree(expTree){}

		void visit_op(Op* node){
			
			expTree += "{" + node->stringify() + "}";
			
		}

        	void visit_rand(Rand* node){
			
			expTree += "{" + node->stringify() + "}";
			
		}
	
		string getexpTree() const{
			
			return expTree;
	
		}

		void setexpTree(const string& expTree){
		
			this->expTree = expTree;

		}

		virtual void visit_add_begin(Add* node) {
			expTree += "{(";
		}
		virtual void visit_add_middle(Add* node) {
			expTree += "+";
		}
		virtual void visit_add_end(Add* node) {
			expTree += ")}";
		}

		virtual void visit_sub_begin(Sub* node) {
                        expTree += "{(";
                }
                virtual void visit_sub_middle(Sub* node) {
                        expTree += "-";
                }
                virtual void visit_sub_end(Sub* node) {
                        expTree += ")}";
                }

		virtual void visit_mult_begin(Mult* node) {
                        expTree += "{(";
                }
                virtual void visit_mult_middle(Mult* node) {
                        expTree += "\\cdot";
                }
                virtual void visit_mult_end(Mult* node) {
                        expTree += ")}";
                }

		void visit_div_begin(Div* node){

      			expTree += "{\\frac";

	   	}
  		void visit_div_middle(Div* node){

      			

    		}
  		void visit_div_end(Div* node){

      			expTree += "}";

    		}
  		void visit_pow_begin(Pow* node){

      			expTree += "{(";

    		}
  		void visit_pow_middle(Pow* node){

      			expTree += "^";

    		}
  		void visit_pow_end(Pow* node){

      			expTree += ")}";
      
   		 }
	
		string PrintLaTeX(Base* ptr){
			

			Iterator* it = new Iterator(ptr);			
			for(it; !it->is_done();  it->next()){
			
				(it->current_node())->accept(this, it->current_index());	
				
			}	

			delete it;			

			return "$" + this->getexpTree() + "$";
			
			
		}	
	private:
	
		string expTree;

};
