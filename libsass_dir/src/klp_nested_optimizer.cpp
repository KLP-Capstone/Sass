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
        if(ofs.is_open()){
            while(!s.empty()){
                Statement_Obj obj=s.top();
                s.pop();
                
            }
        }
    }
}

