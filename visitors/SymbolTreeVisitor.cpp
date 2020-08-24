#include "SymbolTreeVisitor.h"
#include "visitor_requirements.h"


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
  while (search_layer && !search_layer->Has(Symbol(value_name))) {
    search_layer = search_layer->GetParent();
  }
  if (!search_layer || !search_layer->Has(Symbol(value_name))) {
    throw std::runtime_error("Assignment of undeclared variable");
  }
}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::PrintStatement> statement) {

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::IfElseStatement> statement) {
  std::vector<std::shared_ptr<ast::Statement>> statements{
      statement->GetTrueStatement(), statement->GetFalseStatement()
  };
  for (auto &stmt: statements) {
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
  if (is_new_scope_) {
    is_new_scope_ = false;
    next_layer = current_node_->GetScope(current_func_name_);
  } else {
    current_layer_->AddChild(next_layer);
  }
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
  current_node_ = std::make_shared<ClassNode>("main");
  class_tree_.AddMapping("main", current_node_);
  current_func_name_ = "main";
  current_node_->AddFunction(current_func_name_, std::make_shared<ast::Function>(
      "main", ast::Type::BuildType("void"), nullptr, main_class->GetStatementList()
      ));
  is_new_scope_ = true;
  main_class->GetStatementList()->Accept(*this);

}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::ClassDeclaration> declaration) {
  current_node_ = std::make_shared<ClassNode>(declaration->GetName());
  class_tree_.AddMapping(declaration->GetName(), current_node_);
  if (!declaration->GetParentName().empty()) {
    auto parent = class_tree_.GetNode(declaration->GetParentName());
    current_node_->AddParent(parent);
    parent->AddChild(current_node_);
  }
  declaration->GetDeclList()->Accept(*this);
}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::ClassDeclarationList> decl_list) {
  for (auto &decl: decl_list->GetDeclarations()) {
    decl->Accept(*this);
  }
}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::DeclarationList> decl_list) {
  auto functions =  decl_list->GetFunctions();
  auto var_decls = decl_list->GetVarDecls();
  for (auto& func: functions){
    func->Accept(*this);
  }
  for (auto& decl: var_decls) {
    current_node_->AddVariable(decl->GetName(), decl->GetType());
  }
}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::ClassVarDecl> var_decl) {
  // nothing
}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::Function> function) {
  current_func_name_ = function->GetName();
  current_node_->AddFunction(current_func_name_, function);
  is_new_scope_ = true;
  function->GetParams()->Accept(*this);
  function->GetStatements()->Accept(*this);
}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::FunctionParameters> params) {
  auto func_layer = std::make_shared<ScopeLayer>();
  current_node_->AddScope(current_func_name_, func_layer);
  auto names = params->GetParamList();
  auto types = params->GetTypes();
  for (size_t i = 0; i < names.size(); ++i){
    func_layer->DeclareVariable(Symbol(names[i]), types[i]);
  }

}


void SymbolTreeVisitor::Visit(std::shared_ptr<ast::VariableDeclaration> declaration) {
  current_layer_->DeclareVariable(Symbol(declaration->GetName()), declaration->GetType()->GetTypeName());
}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::FunctionCall> expression){
  //nothing
}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::ParamValueList> expression){
  //nothing
}

void SymbolTreeVisitor::Visit(std::shared_ptr<ast::ReturnStatement> expression){
  //nothing
}

ClassTree& SymbolTreeVisitor::GetClassTree() {
  return class_tree_;
}





