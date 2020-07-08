#include "declarations/MainClass.h"
#include "declarations/ClassDeclarationList.h"

namespace ast {
  class Program {
  public:
    Program(std::shared_ptr<MainClass> main_class, std::shared_ptr<ClassDeclarationList> declaration_list);

    //void launch() const;

    std::shared_ptr<MainClass> GetMainClass();

    std::shared_ptr<ClassDeclarationList> GetDeclList();

  private:
    std::shared_ptr<MainClass> main_class_;
    std::shared_ptr<ClassDeclarationList> declaration_list_;
  };
}