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


class VisitorMathML : Visitor{


        public:

                VisitorMathML(){
                        expTree = "";
                        cnt = 1;
                }

                VisitorMathML(const string& expTree) : expTree(expTree){}

                void visit_op(Op* node){

                        expTree += "\n" + count(cnt) +  "</cn>" + node->stringify() + "</cn>";
                }

                void visit_rand(Rand* node){

                         expTree += "\n" + count(cnt) +  "</cn>" + node->stringify() + "</cn>";


                }

                string getexpTree() const{

                        return expTree;

                }

                void setexpTree(const string& expTree){

                        this->expTree = expTree;

                }

                virtual void visit_add_begin(Add* node) {
                  expTree += "\n" +  count(cnt) + "<apply>";
                  ++cnt;
                  expTree +=  "\n" + count(cnt) +  "<plus/>";
                }
                virtual void visit_add_middle(Add* node) {
                        expTree += "";
                }
                virtual void visit_add_end(Add* node) {
                        expTree += "\n" + count(--cnt) + "</apply>";
                }

                virtual void visit_sub_begin(Sub* node) {
                  expTree += "\n" +  count(cnt) + "<apply>";
                  ++cnt;
                  expTree +=  "\n" + count(cnt) +  "<minus/>";

                }
                virtual void visit_sub_middle(Sub* node) {
                        expTree += "";
                }
                virtual void visit_sub_end(Sub* node) {
                        expTree += "\n" + count(--cnt) + "</apply>";

                }

                virtual void visit_mult_begin(Mult* node) {
                  expTree += "\n" +  count(cnt) + "<apply>";
                  ++cnt;
                  expTree +=  "\n" + count(cnt) +  "<times/>";
                }
                virtual void visit_mult_middle(Mult* node) {
                        expTree += "";
                }
                virtual void visit_mult_end(Mult* node) {
                        expTree += "\n" + count(--cnt) + "</apply>";
                }

                void visit_div_begin(Div* node){

                  expTree += "\n" +  count(cnt) + "<apply>";
                  ++cnt;
                  expTree +=  "\n" + count(cnt) +  "<divide/>";

                }
                void visit_div_middle(Div* node){



                }
                void visit_div_end(Div* node){

                        expTree += "\n" + count(--cnt) + "</apply>";

                }
                void visit_pow_begin(Pow* node){

                        expTree += "\n" +  count(cnt) + "<apply>";
                        ++cnt;
                        expTree +=  "\n" + count(cnt) +  "<power/>";

                }
                void visit_pow_middle(Pow* node){

                        expTree += "";

                }
                void visit_pow_end(Pow* node){

                        expTree += "\n" + count(--cnt) + "</apply>";

                 }

                string PrintLaTeX(Base* ptr){


                        Iterator* it = new Iterator(ptr);
                        for(it; !it->is_done();  it->next()){

                                (it->current_node())->accept(this, it->current_index());

                        }

                        delete it;

                        return "<math>" + this->getexpTree() + "\n<math>";


                }

                string count(int x){

                        string str = "";
                        while(x > 0){

                                str += "\t";
                                --x;
                        }
                        return str;

                }
        private:

                string expTree= "";
                int cnt = 1;

};

