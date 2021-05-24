#include "visitor.hpp"
#pragma once


class VisitorLaTeX : Visitor{
	
	
	public:
		
		VisitorLatex(){ expTree = ""; }
		
		VisotorLatex(const string& expTree) : expTree(expTree){}

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
		virtual void visit_add_begin(Add* node) {
			expTree += ")}";
		}

		virtual void visit_sub_begin(Sub* node) {
                        expTree += "{(";
                }
                virtual void visit_sub_middle(Sub* node) {
                        expTree += "-";
                }
                virtual void visit_sub_begin(Sub* node) {
                        expTree += ")}";
                }

		virtual void visit_mult_begin(Mult* node) {
                        expTree += "{(";
                }
                virtual void visit_mult_middle(Mult* node) {
                        expTree += "*";
                }
                virtual void visit_mult_begin(Mult* node) {
                        expTree += ")}";
                }

			
       	// Nodes with two children are visited three times.
        // index = 0 -> begin
        // index = 1 -> middle
        // index = 2 -> end
        	void visit_add_begin(Add* node);
        	void visit_add_middle(Add* node);
        	void visit_add_end(Add* node);
        	void visit_sub_begin(Sub* node);
        	void visit_sub_middle(Sub* node);
        	void visit_sub_end(Sub* node);
        	void visit_mult_begin(Mult* node);
        	void visit_mult_middle(Mult* node);
        	void visit_mult_end(Mult* node);
		void visit_div_begin(Div* node){

      			expTree += "{";

	   	}
  		void visit_div_middle(Div* node){

      			expTree += "\\frac";

    		}
  		void visit_div_end(Div* node){

      			expTree += "}"

    		}
  		void visit_pow_begin(Pow* node){

      			expTree += "{";

    		}
  		void visit_pow_middle(Pow* node){

      			expTree += "^";

    		}
  		void visit_pow_end(Pow* node){

      			expTree += "}"
      
   		 }	
	private:
	
		string expTree;

};
