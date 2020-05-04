#include "declarations/MainClass.h"
#include "declarations/ClassDeclarationList.h"

class Program {
public:
  Program(MainClass *main_class, ClassDeclarationList *declaration_list);

  void launch() const;

private:
  MainClass *main_class_;
  ClassDeclarationList *declaration_list_;
};