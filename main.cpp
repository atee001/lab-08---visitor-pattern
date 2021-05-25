#include "VisitorLaTeX.hpp"


int main(){

	VisitorLatex* latex = new VisitorLatex();

	Base* one = new Op(1);
	Base* two = new Op(2);
	Base* mult = new Mult(one, two);
	Base* div = new Pow(mult, new Op(3));
	
	cout << latex->PrintLaTeX(div) << endl;
	delete latex;
	delete div;
	return 0;

}
