#include "Interpreter.h"

#include "visitor_requirements.h"
/*

Interpreter::Interpreter(std::shared_ptr<ScopeLayer> root) :
    current_layer_(std::move(root)) {
  offsets_.push(0);
}

void Interpreter::Visit(std::shared_ptr<ast::PlainNumberExpression> expression) {
  //tos_value_.SetType(std::move(std::make_unique<ast::Integer>()));
  tos_value_.SetValue(expression->value);
  tos_value_.SetType(INT);
}

void Interpreter::Visit(std::shared_ptr<ast::PlainBooleanExpression> expression) {
  //tos_value_.SetType(std::move(std::make_unique<ast::Boolean>()));
  tos_value_.SetValue(expression->value);
  tos_value_.SetType(BOOLEAN);
}

void Interpreter::Visit(std::shared_ptr<ast::AddExpression> expression) {
  //tos_value_.SetType(std::move(std::make_unique<ast::Integer>()));
  int value = Accept(expression->GetFirst()).ToInt() + Accept(expression->GetSecond()).ToInt();
  SetTosValue(value);
  tos_value_.SetType(INT);
}

void Interpreter::Visit(std::shared_ptr<ast::ModExpression> expression) {
  //tos_value_.SetType(std::move(std::make_unique<ast::Integer>()));
  int value = Accept(expression->GetFirst()).ToInt() % Accept(expression->GetSecond()).ToInt();
  SetTosValue(value);
  tos_value_.SetType(INT);
}

void Interpreter::Visit(std::shared_ptr<ast::SubstractExpression> expression) {
  //tos_value_.SetType(std::move(std::make_unique<ast::Integer>()));
  int value = Accept(expression->GetFirst()).ToInt() - Accept(expression->GetSecond()).ToInt();
  SetTosValue(value);
  tos_value_.SetType(INT);
}

void Interpreter::Visit(std::shared_ptr<ast::MulExpression> expression) {
  //tos_value_.SetType(std::move(std::make_unique<ast::Integer>()));
  int value = Accept(expression->GetFirst()).ToInt() * Accept(expression->GetSecond()).ToInt();
  SetTosValue(value);
  tos_value_.SetType(INT);
}

void Interpreter::Visit(std::shared_ptr<ast::DivExpression> expression) {
  //tos_value_.SetType(std::move(std::make_unique<ast::Integer>()));
  int value = Accept(expression->GetFirst()).ToInt() / Accept(expression->GetSecond()).ToInt();
  SetTosValue(value);
  tos_value_.SetType(INT);
}

void Interpreter::Visit(std::shared_ptr<ast::IdentExpression> expression) {
  //tos_value_.SetType(std::move(std::make_unique<ast::Integer>()));
  SetTosValue(*(current_layer_->Get(Symbol(expression->GetIdent()))));
}

void Interpreter::Visit(std::shared_ptr<ast::AndExpression> expression) {
  //tos_value_.SetType(std::move(std::make_unique<ast::Boolean>()));
  bool value = Accept(expression->GetFirst()).ToBool() && Accept(expression->GetSecond()).ToBool();
  SetTosValue(value);
  tos_value_.SetType(BOOLEAN);
  //tos_value_ = Accept(expression->GetFirst()) + Accept(expression->GetSecond());
}

void Interpreter::Visit(std::shared_ptr<ast::OrExpression> expression) {
  //tos_value_.SetType(std::move(std::make_unique<ast::Boolean>()));
  bool value = Accept(expression->GetFirst()).ToBool() || Accept(expression->GetSecond()).ToBool();
  SetTosValue(value);
  tos_value_.SetType(BOOLEAN);
}

void Interpreter::Visit(std::shared_ptr<ast::LessExpression> expression) {
  //tos_value_.SetType(std::move(std::make_unique<ast::Boolean>()));
  bool value = Accept(expression->GetFirst()).ToInt() < Accept(expression->GetSecond()).ToInt();
  SetTosValue(value);
  tos_value_.SetType(BOOLEAN);
}

void Interpreter::Visit(std::shared_ptr<ast::GreaterExpression> expression) {
  //tos_value_.SetType(std::move(std::make_unique<ast::Boolean>()));
  bool value = Accept(expression->GetFirst()).ToInt() > Accept(expression->GetSecond()).ToInt();
  SetTosValue(value);
  tos_value_.SetType(BOOLEAN);
}

void Interpreter::Visit(std::shared_ptr<ast::EqualExpression> expression) {
  //tos_value_.SetType(std::move(std::make_unique<ast::Boolean>()));
  bool value = Accept(expression->GetFirst()).ToInt() == Accept(expression->GetSecond()).ToInt();
  SetTosValue(value);
  tos_value_.SetType(BOOLEAN);
}


void Interpreter::Visit(std::shared_ptr<ast::Assignment> assignment) {
  Object assign_value = Accept(assignment->GetExpression());
  std::string ident = assignment->GetLvalue()->GetId();
  Types required_type = current_layer_->Get(Symbol(ident))->GetType();
  if (assign_value.GetType() != required_type) {
    throw std::runtime_error("Invalid type");
  }
  current_layer_->Put(Symbol(ident), std::make_shared<Object>(assign_value));
}

void Interpreter::Visit(std::shared_ptr<ast::PrintStatement> statement) {
  //statement->GetExpression()->Accept(*this);
  std::cout << Accept(statement->GetExpression()).ToInt() << std::endl;
}

void Interpreter::Visit(std::shared_ptr<ast::IfElseStatement> statement) {
  bool condition = Accept(statement->GetExpression()).ToBool();
  if (condition) {
    Accept(statement->GetTrueStatement());
  } else {
    Accept(statement->GetFalseStatement());
  }
}

void Interpreter::Visit(std::shared_ptr<ast::IfStatement> statement) {
  bool condition = Accept(statement->GetExpression()).ToBool();
  if (condition) {
    Accept(statement->GetStatement());
  }
}


void Interpreter::Visit(std::shared_ptr<ast::StatementList> statement_list) {
  current_layer_ = current_layer_->GetChild(offsets_.top());
  offsets_.push(0);
  for (auto &elem: statement_list->statements_) {
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

void Interpreter::Visit(std::shared_ptr<ast::VariableDeclaration> declaration) {
  // nothing
}


void Interpreter::Execute(std::shared_ptr<ast::Program> program) {
  Visit(std::move(program));
}


void Interpreter::SetTosValue(const int value) {
  tos_value_.SetValue(value);
  //tos_value_.SetType(std::move(std::make_unique<ast::Integer>()));
}

void Interpreter::SetTosValue(const bool value) {
  tos_value_.SetValue(value);
  //tos_value_.SetType(std::move(std::make_unique<ast::Boolean>()));}
}
void Interpreter::SetTosValue(const Object& value) {
  tos_value_ = value;
}*/