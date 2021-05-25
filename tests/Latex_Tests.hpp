#include "../VisitorLaTeX.hpp"
#include "gtest/gtest.h"
#pragma once

TEST(LatexUnitTests, Add){

	Base* one = new Op(1);
	Base* five = new Op(5);
	Base* zero = new Op(0);

	Base* sub = new Sub(five, zero);
	Base* add = new Add(one, sub);

	VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ("${({1}+{({5}-{0})})}$",latex->PrintLaTeX(add));
	delete latex;
	delete add;

}

TEST(LatexUnitTests, Pow){

	Base* five = new Op(5);
	Base* two = new Op(2);

	Base* pow = new Pow(five,two);

	VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ("${({5}^{2})}$", latex->PrintLaTeX(pow));
	delete latex;
	delete pow;

}

TEST(LatexUnitTests, Mult){

	Base* two = new Op(2);
	Base* five = new Op(5);
	
	Base* mult = new Mult(two, five);

	VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ("${({2}\\cdot{5})}$", latex->PrintLaTeX(mult));

	delete latex;
	delete mult;	
}

TEST(LatexUnitTests, Div){

	Base* two = new Op(2);
	Base* three = new Op(3);
	Base* div = new Div(two, three);
	
	VisitorLatex* latex = new VisitorLatex();
	EXPECT_EQ("${\\frac{2}{3}}$", latex->PrintLaTeX(div));

	delete div;
	delete latex;
}

TEST(LatexUnitTests, MultDivPow){

        Base* two = new Op(2);
        Base* five = new Op(5);

        Base* pow = new Pow(five, two);
        Base* mult = new Mult(new Op(2), new Op(5));
	Base* div = new Div(mult,pow);
	

        VisitorLatex* latex = new VisitorLatex();
        EXPECT_EQ("${\\frac{({2}\\cdot{5})}{({5}^{2})}}$",latex->PrintLaTeX(div));
        delete latex;
        delete div;

}

