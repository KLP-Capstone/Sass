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
        if(!ofs.is_open()) return;
        stack<StyleRule_Obj> s;
        for(int i = 0 ; i <root->length() ; i++){
            Statement_Obj child = root->get(i);
            if(child->statement_type() == Statement::RULESET){
                s.push(root->get(i));
            }
            ofs << "statement_type: " << child->statement_type() << endl;
            ofs << "content: " << child->to_string() << endl;
            ofs << endl;
        }
        
        while(!s.empty()){
            StyleRule_Obj obj = s.top();
            Block_Obj block = obj->block();
            s.pop();

            // type, length
            ofs << "statement_type: " << obj->statement_type() << "\n";
            ofs << "block length: " << block->length() << "\n";
            ofs << endl;

            for(int i = 0 ; i < block->length() ; i++){
                Statement_Obj child = block->get(i);
                if(child->statement_type() == Statement::RULESET){
                    s.push(child);
                }
                ofs << "statement_type: " << child->statement_type() << endl;
                ofs << "content: " << child->to_string() << endl;
                ofs << endl;
            }

            ofs << "\n";
        }
    

        ofs.close();
    }
}