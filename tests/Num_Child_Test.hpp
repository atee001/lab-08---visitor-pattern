#pragma once

#include "gtest/gtest.h"
#include "Add.hpp"
#include "Sub.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "Pow.hpp"

TEST(NumChildTest, Add) {
	Base* left = new Op(0);
	Base* right = new Op(1);
	Add* a = new Add(left,right);

	EXPECT_EQ(a->number_of_children(), 2);
}

TEST(NumChildTest, Sub) {
        Base* left = new Op(0);
        Base* right = new Op(1);
        Sub* s = new Sub(left,right);

        EXPECT_EQ(s->number_of_children(), 2);
}

TEST(NumChildTest, Mult) {
        Base* left = new Op(0);
        Base* right = new Op(1);
        Mult* m = new Mult(left,right);

        EXPECT_EQ(m->number_of_children(), 2);
}

TEST(NumChildTest, Div) {
        Base* left = new Op(0);
        Base* right = new Op(1);
        Div* d = new Div(left,right);

        EXPECT_EQ(d->number_of_children(), 2);
}

TEST(NumChildTest, Pow) {
        Base* left = new Op(0);
        Base* right = new Op(1);
        Pow* p = new Pow(left,right);

        EXPECT_EQ(p->number_of_children(), 2);
}

