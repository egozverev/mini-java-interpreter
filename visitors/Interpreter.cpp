#include "Interpreter.h"

#include "visitor_requirements.h"


Interpreter::Interpreter(std::shared_ptr<ScopeLayer> root): current_layer_(std::move(root)) {
  offsets_.push(0);
  tos_value_ = 0;
}

void Interpreter::Visit(std::shared_ptr<ast::PlainNumberExpression> expression) {
  tos_value_ = expression->value;
}

void Interpreter::Visit(std::shared_ptr<ast::PlainBooleanExpression> expression) {
  //tos_value_ = expression->value;
}

void Interpreter::Visit(std::shared_ptr<ast::AddExpression> expression) {
  tos_value_ = Accept(expression->GetFirst()) + Accept(expression->GetSecond());
}

void Interpreter::Visit(std::shared_ptr<ast::ModExpression> expression) {
  tos_value_ = Accept(expression->GetFirst()) % Accept(expression->GetSecond());

}

void Interpreter::Visit(std::shared_ptr<ast::SubstractExpression> expression) {
  tos_value_ = Accept(expression->GetFirst()) - Accept(expression->GetSecond());

}

void Interpreter::Visit(std::shared_ptr<ast::MulExpression> expression) {
  tos_value_ = Accept(expression->GetFirst()) * Accept(expression->GetSecond());

}

void Interpreter::Visit(std::shared_ptr<ast::DivExpression> expression) {
  tos_value_ = Accept(expression->GetFirst()) / Accept(expression->GetSecond());

}

void Interpreter::Visit(std::shared_ptr<ast::IdentExpression> expression) {
  tos_value_ = current_layer_->Get(Symbol(expression->GetIdent()))->ToInt();
}

void Interpreter::Visit(std::shared_ptr<ast::AndExpression> expression) {
  tos_value_ = Accept(expression->GetFirst()) + Accept(expression->GetSecond());
}

void Interpreter::Visit(std::shared_ptr<ast::OrExpression> expression) {

}

void Interpreter::Visit(std::shared_ptr<ast::LessExpression> expression) {

}

void Interpreter::Visit(std::shared_ptr<ast::GreaterExpression> expression) {

}

void Interpreter::Visit(std::shared_ptr<ast::EqualExpression> expression) {

}


void Interpreter::Visit(std::shared_ptr<ast::Assignment> assignment) {
  int value = Accept(assignment->GetExpression());
  std::string ident = assignment->GetLvalue()->GetId();
  current_layer_->Put(Symbol(ident), std::make_shared<Integer>(value));
}

void Interpreter::Visit(std::shared_ptr<ast::PrintStatement> statement) {
  //statement->GetExpression()->Accept(*this);
  std::cout << Accept(statement->GetExpression()) << std::endl;
}

void Interpreter::Visit(std::shared_ptr<ast::StatementList> statement_list) {
  current_layer_ = current_layer_->GetChild(offsets_.top());
  offsets_.push(0);
  for (auto& elem: statement_list->statements_){
    elem->Accept(*this);
  }
  current_layer_ = current_layer_->GetParent();
  offsets_.pop();
  size_t current_pos = offsets_.top();
  offsets_.pop();
  offsets_.push(++current_pos);
}

void Interpreter::Visit(std::shared_ptr<ast::MainClass> main_class) {
  main_class->GetStatementList()->Accept(*this);
}

void Interpreter::Visit(std::shared_ptr<ast::ClassDeclarationList> class_declaration) {
  //yet nothing
}


void Interpreter::Visit(std::shared_ptr<ast::Program> program) {
  program->GetMainClass()->Accept(*this);

  program->GetDeclList()->Accept(*this); // tos value is called
}

void Interpreter::Visit(std::shared_ptr<ast::VariableDeclaration> declaration){
  // nothing
}


void Interpreter::Execute(std::shared_ptr<ast::Program> program) {
  Visit(std::move(program));
}