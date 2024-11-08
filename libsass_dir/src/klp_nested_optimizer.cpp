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
        stack<Statement_Obj> s;
        s.push(root); 
        if(!ofs.is_open()) return;
        while(!s.empty()){
            Statement_Obj obj = s.top();
            //s.pop();

            // if(obj->statement_type() == Statement::RULESET){
            //     //StyleRule* obj = *(s.top().obj());
            // }
            
            // //type, length
            // ofs << obj->statement_type() << "\n";
            // ofs << obj->length() << "\n";

            // for(auto iter : obj->elements()){
            //     ofs << iter->to_string() << "\n";
            //     s.push(iter);
            // }

            ofs << "\n";
        }
    

        ofs.close();
    }
}

