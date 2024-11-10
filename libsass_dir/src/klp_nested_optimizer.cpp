#include "sass.hpp"
#include "sass_context.hpp"
#include "ast.hpp"

#include <iostream>
#include <fstream>
#include <queue>

namespace Sass{
    using namespace std;
    void sass_compiler_optimization(Sass_Compiler *compiler) {
        Block_Obj root = compiler->root;
        ofstream ofs("log.txt",ios::out | ios::app);
        if(!ofs.is_open()) return;
        // StyleRule_Obj를 담는 queue 생성
        queue<StyleRule_Obj> q;
        for(int i = 0 ; i < root->length() ; i++){
            // 자식 가져오기
            Statement_Obj child = root->get(i);
            // ruleset이면 재귀적으로 탐색하기 위해 queue에 push
            if(child->statement_type() == Statement::RULESET){
                q.push(root->get(i));
            }
            // root 자식 node의 내용 출력
            ofs << "\"statement_type\" :" << child->statement_type() << endl;
            ofs << "\"content\":" << endl << child->to_string() << endl;
            ofs << endl;
        }
        
        while(!q.empty()){
            StyleRule_Obj obj = q.front();
            Block_Obj block = obj->block();
            q.pop();

            // 각 block마다 type, length 출력
            ofs << "\"statement_type\": " << obj->statement_type() << "\n";
            ofs << "\"block length\": " << block->length() << "\n";
            ofs << endl;

            for(int i = 0 ; i < block->length() ; i++){
                Statement_Obj child = block->get(i);
                if(child->statement_type() == Statement::RULESET){
                    q.push(child);
                }
                // 자식 node 출력
                ofs << "\"statement_type\": " << child->statement_type() << endl;
                ofs << "\"content\":" << endl << child->to_string() << endl;
                ofs << endl;
            }

            ofs << "\n";
        }
    

        ofs.close();
    }
}
