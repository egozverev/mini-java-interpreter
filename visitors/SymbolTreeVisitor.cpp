#include "SymbolTreeVisitor.h"
#include "visitor_requirements.h"

SymbolTreeVisitor::SymbolTreeVisitor() : tree_(std::move(std::make_shared<ScopeLayer>())) {
  current_layer_ = tree_.root_;
}


void SymbolTreeVisitor::Visit(std::shared_ptr<ast::PlainNumberExpression> expression) {

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

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::Assignment> assignment) {

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::PrintStatement> statement) {

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::StatementList> statement_list) {
  auto next_layer = std::make_shared<ScopeLayer>(current_layer_);
  current_layer_ = next_layer;
  statement_list->Accept(*this);
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


