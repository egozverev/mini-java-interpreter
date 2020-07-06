#include "Program.h"

Program::Program(
    std::shared_ptr<MainClass> main_class, std::shared_ptr<ClassDeclarationList> declaration_list) :
    main_class_(std::move(main_class)), declaration_list_(std::move(declaration_list)) {}

/*void Program::launch() const {
  //... smth about classes?
  main_class_->perform_body();
}*/

std::shared_ptr<MainClass> Program::GetMainClass() { return main_class_; }

std::shared_ptr<ClassDeclarationList> Program::GetDeclList() { return declaration_list_; }
