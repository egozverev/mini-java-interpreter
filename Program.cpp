#include "Program.h"

Program::Program(
    MainClass *main_class, ClassDeclarationList *declaration_list) :
    main_class_(main_class), declaration_list_(declaration_list) {}

void Program::launch() const {
  //... smth about classes?
  main_class_->perform_body();
}