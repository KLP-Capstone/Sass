#include "sass.hpp"
#include "sass_context.hpp"
#include "ast.hpp"

#include <iostream>
#include <fstream>
#include <stack>

namespace Sass{
    using namespace std;
    void sass_compiler_optimization(Sass_Compiler *compiler) {
        Block_Obj root = compiler->root;
        ofstream ofs("log.txt",ios::out | ios::app);
        ///////////////////////////////////////////////////////////////////
        //              TODO : stack을 이용하여 recursive하게 자식으로 들어가   //
        //                     블록 관련 내용 추출하기.                       //
        //              issue: Block 내부의 각 statement의 type을          //
        //                     어떻게 polymorphic variable로 처리할 것인가    //
        //////////////////////////////////////////////////////////////////
        // stack<Statement_Obj> s;
        // s.push(root); 
        // if(!ofs.is_open()) return;
        // while(!s.empty()){
        //     Statement_Obj obj = s.top();

        //     s.pop();

        //     if(obj->statement_type() == Statement::RULESET){
        //          //StyleRule* obj = *(s.top().obj());
        //     }
            
        //     type, length
        //     ofs << obj->statement_type() << "\n";
        //     ofs << obj->length() << "\n";

        //     for(auto iter : obj->elements()){
        //         ofs << iter->to_string() << "\n";
        //         s.push(iter);
        //     }

        //     ofs << "\n";
        // }
    

        ofs.close();
    }
}

