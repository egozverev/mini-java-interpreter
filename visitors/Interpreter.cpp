#include "Interpreter.h"

#include "visitor_requirements.h"

#include <iostream>

Interpreter::Interpreter() {
  is_tos_expression_ = false;
  tos_value_ = 0;
}

void Interpreter::Visit(PlainNumberExpression* expression) {
  SetTosValue(expression->value);
}

void Interpreter::Visit(AddExpression* expression) {
  int value = 0;
  expression->GetFirst()->Accept(this);
  value += tos_value_;

  expression->GetSecond()->Accept(this);
  value += tos_value_;
  SetTosValue(value);
}

void Interpreter::Visit(ModExpression* expression) {
  int value = 0;
  expression->GetFirst()->Accept(this);
  value = tos_value_;

  expression->GetSecond()->Accept(this);
  value %= tos_value_;
  SetTosValue(value);
}

void Interpreter::Visit(SubstractExpression* expression) {
  expression->GetFirst()->Accept(this);
  int value = tos_value_;
  expression->GetSecond()->Accept(this);
  value -= tos_value_;

  SetTosValue(value);
}

void Interpreter::Visit(MulExpression* expression) {
  expression->GetFirst()->Accept(this);
  int value = tos_value_;
  expression->GetSecond()->Accept(this);
  value *= tos_value_;

  SetTosValue(value);
}

void Interpreter::Visit(DivExpression* expression) {
  expression->GetFirst()->Accept(this);
  int value = tos_value_;
  expression->GetSecond()->Accept(this);
  value /= tos_value_;

  SetTosValue(value);
}

void Interpreter::Visit(IdentExpression* expression) {
  int value = variables_[expression->GetIdent()];

  SetTosValue(value);
}

void Interpreter::Visit(Assignment* assignment) {
  assignment->GetExpression()->Accept(this);
  variables_[assignment->GetLvalue()->GetId()] = tos_value_;

  UnsetTosValue();
}

void Interpreter::Visit(PrintStatement* statement) {
  statement->GetExpression()->Accept(this);
  std::cout << tos_value_ << std::endl;

  UnsetTosValue();
}

void Interpreter::Visit(StatementList* statement_list) {
  for (auto it = statement_list->statements_.end() - 1;
       it != statement_list->statements_.begin() - 1; --it) {
    (*it)->Accept(this);
  }

  UnsetTosValue();
}

void Interpreter::Visit(MainClass* main_class) {
  main_class->GetStatementList()->Accept(this);

  UnsetTosValue();
}

void Interpreter::Visit(ClassDeclarationList* class_declaration) {
  //yet nothing
  UnsetTosValue();
}


void Interpreter::Visit(Program* program) {
  program->GetMainClass()->Accept(this);

  program->GetDeclList()->Accept(this); // tos value is called
}



void Interpreter::SetTosValue(int value) {
  tos_value_ = value;
  is_tos_expression_ = true;
}

void Interpreter::UnsetTosValue() {
  tos_value_ = 0;
  is_tos_expression_ = false;
}

void Interpreter::Execute(Program *program) {
  UnsetTosValue();
  Visit(program);
}