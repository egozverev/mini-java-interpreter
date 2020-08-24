#include "Program.h"

ast::Program::Program(
    std::shared_ptr<ast::MainClass> main_class, std::shared_ptr<ast::ClassDeclarationList> declaration_list) :
    main_class_(std::move(main_class)), declaration_list_(std::move(declaration_list)) {}

/*void Program::launch() const {
  //... smth about classes?
  main_class_->perform_body();
}*/

std::shared_ptr<ast::MainClass> ast::Program::GetMainClass() { return main_class_; }

std::shared_ptr<ast::ClassDeclarationList> ast::Program::GetDeclList() { return declaration_list_; }
