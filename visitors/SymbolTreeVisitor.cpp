#include "SymbolTreeVisitor.h"
#include "visitor_requirements.h"

SymbolTreeVisitor::SymbolTreeVisitor() : tree_(std::move(std::make_shared<ScopeLayer>())) {
  current_layer_ = tree_.root_;
}


void SymbolTreeVisitor::Visit(std::shared_ptr<ast::PlainNumberExpression> expression) {

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::PlainBooleanExpression> expression) {

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::AddExpression> expression) {

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::SubstractExpression> expression) {

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::MulExpression> expression) {

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::ModExpression> expression) {

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::DivExpression> expression) {

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::IdentExpression> expression) {

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::AndExpression> expression) {

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::OrExpression> expression) {

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::LessExpression> expression) {

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::GreaterExpression> expression) {

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::EqualExpression> expression) {

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::Assignment> assignment) {
  std::string value_name = assignment->GetLvalue()->GetId();
  auto search_layer = current_layer_;
  while (!search_layer->Has(Symbol(value_name)) && search_layer != GetRoot()) {
    search_layer = search_layer->GetParent();
  }
  if (!search_layer->Has(Symbol(value_name))) {
    throw std::runtime_error("Assignment of undeclared variable");
  }
}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::PrintStatement> statement) {

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::IfElseStatement> statement) {
  std::vector<std::shared_ptr<ast::Statement>> statements {
    statement->GetTrueStatement(), statement->GetFalseStatement()
  };
  for (auto& stmt: statements){
    auto next_layer = std::make_shared<ScopeLayer>();
    current_layer_->AddChild(next_layer);
    current_layer_ = next_layer;
    stmt->Accept(*this);
    current_layer_ = current_layer_->GetParent();
  }


}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::IfStatement> statement) {
  auto next_layer = std::make_shared<ScopeLayer>();
  current_layer_->AddChild(next_layer);
  current_layer_ = next_layer;
  statement->GetStatement()->Accept(*this);
  current_layer_ = current_layer_->GetParent();
}


void SymbolTreeVisitor::Visit(std::shared_ptr<ast::StatementList> statement_list) {
  auto next_layer = std::make_shared<ScopeLayer>();
  current_layer_->AddChild(next_layer);
  current_layer_ = next_layer;
  for (auto &elem: statement_list->statements_) {
    elem->Accept(*this);
  }
  current_layer_ = current_layer_->GetParent();
}


void SymbolTreeVisitor::Visit(std::shared_ptr<ast::Program> program) {
  program->GetMainClass()->Accept(*this);
  program->GetDeclList()->Accept(*this);
}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::MainClass> main_class) {
  main_class->GetStatementList()->Accept(*this);

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::ClassDeclarationList> decl_list) {

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::VariableDeclaration> declaration) {
  current_layer_->DeclareVariable(Symbol(declaration->GetName()));
}

std::shared_ptr<ScopeLayer> SymbolTreeVisitor::GetRoot() {
  return tree_.root_;
}


