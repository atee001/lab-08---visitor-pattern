#include "gtest/gtest.h"
#include "../Add.hpp"
#include "../Sub.hpp"
#include "../Pow.hpp"
#include "../Mult.hpp"
#include "../Div.hpp"
#include "../base.hpp"
#include "../op.hpp"


TEST(numChildTest, TwoChildren){


	Base* expTree = new Mult(new Op(8), new Op(10));
	
	EXPECT_EQ(expTree->number_of_children(), 2);

	delete expTree;

}

TEST(GetChildTest, Left){


	Base* lhs = new Op(10);
	Base* rhs = new Op(11);

	Base* add= new Add(lhs, rhs);

	Base* pow = new Pow(add, new Op(2));

	EXPECT_EQ(pow->get_child(0), add);

	delete pow;

}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
