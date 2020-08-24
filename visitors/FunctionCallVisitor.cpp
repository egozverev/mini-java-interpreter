#include "FunctionCallVisitor.h"
#include "visitor_requirements.h"

FunctionCallVisitor::FunctionCallVisitor(std::shared_ptr<ClassObject> class_obj, const std::string &func_name) :
    class_object_(std::move(class_obj)),
    frame_(class_tree_.GetNode(class_object_->GetTypeName())->GetFunction(func_name)->GetParamSize()) {
  offsets_.push(0);
  current_layer_ = class_tree_.GetNode(class_object_->GetTypeName())->GetScope(func_name);
  tos_value_ = std::make_shared<Object>();
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::PlainNumberExpression> expression) {
  tos_value_->SetValue(expression->value);
  tos_value_->SetType("int");
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::ThisExpression> expression) {
  tos_value_ = class_object_;
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::PlainBooleanExpression> expression) {
  tos_value_->SetValue(expression->value);
  tos_value_->SetType("bool");
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::AddExpression> expression) {
  int value = Accept(expression->GetFirst())->ToInt() + Accept(expression->GetSecond())->ToInt();
  SetTosValue(value);
  tos_value_->SetType("int");
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::ModExpression> expression) {
  int value = Accept(expression->GetFirst())->ToInt() % Accept(expression->GetSecond())->ToInt();
  SetTosValue(value);
  tos_value_->SetType("int");
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::SubstractExpression> expression) {
  int value = Accept(expression->GetFirst())->ToInt() - Accept(expression->GetSecond())->ToInt();
  SetTosValue(value);
  tos_value_->SetType("int");
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::MulExpression> expression) {
  int value = Accept(expression->GetFirst())->ToInt() * Accept(expression->GetSecond())->ToInt();
  SetTosValue(value);
  tos_value_->SetType("int");
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::DivExpression> expression) {
  int value = Accept(expression->GetFirst())->ToInt() / Accept(expression->GetSecond())->ToInt();
  SetTosValue(value);
  tos_value_->SetType("int");
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::IdentExpression> expression) {
  if(index_table_.HasSymbol(Symbol(expression->GetIdent()))){
    size_t index = index_table_.Get(Symbol(expression->GetIdent()));
    SetTosValue(frame_.Get(index));
  } else {
    tos_value_ = class_object_->GetVariable(expression->GetIdent());
  }
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::AndExpression> expression) {
  bool value = Accept(expression->GetFirst())->ToBool() && Accept(expression->GetSecond())->ToBool();
  SetTosValue(value);
  tos_value_->SetType("bool");
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::OrExpression> expression) {
  bool value = Accept(expression->GetFirst())->ToBool() || Accept(expression->GetSecond())->ToBool();
  SetTosValue(value);
  tos_value_->SetType("bool");
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::LessExpression> expression) {
  bool value = Accept(expression->GetFirst())->ToInt() < Accept(expression->GetSecond())->ToInt();
  SetTosValue(value);
  tos_value_->SetType("bool");
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::GreaterExpression> expression) {
  bool value = Accept(expression->GetFirst())->ToInt() > Accept(expression->GetSecond())->ToInt();
  SetTosValue(value);
  tos_value_->SetType("bool");
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::EqualExpression> expression) {
  bool value = Accept(expression->GetFirst())->ToInt() == Accept(expression->GetSecond())->ToInt();
  SetTosValue(value);
  tos_value_->SetType("bool");
}


void FunctionCallVisitor::Visit(std::shared_ptr<ast::Assignment> assignment) {
  std::shared_ptr<Object> assign_value = Accept(assignment->GetExpression());
  std::string ident = assignment->GetLvalue()->GetId();
  std::shared_ptr<ast::Type> required_type = current_layer_->GetType(Symbol(ident));
  bool is_class_var = false;
  if (required_type == nullptr){
    required_type = class_object_->GetVariable(ident)->GetType();
    is_class_var = true;
  }
  if (assign_value->GetType()->GetTypeName() != required_type->GetTypeName()) {
    throw std::runtime_error("Invalid type");
  }
  if (is_class_var) {
    *class_object_->GetVariable(ident) = * assign_value;
  } else {
    size_t index = index_table_.Get(Symbol(ident));
    frame_.Set(index, *assign_value);
  }

}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::PrintStatement> statement) {
  std::cout << Accept(statement->GetExpression())->ToInt() << std::endl;
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::IfElseStatement> statement) {
  bool condition = Accept(statement->GetExpression())->ToBool();
  if (condition) {
    Accept(statement->GetTrueStatement());
  } else {
    Accept(statement->GetFalseStatement());
  }
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::IfStatement> statement) {
  bool condition = Accept(statement->GetExpression())->ToBool();
  if (condition) {
    Accept(statement->GetStatement());
  }
}


void FunctionCallVisitor::Visit(std::shared_ptr<ast::StatementList> statement_list) {
  if (is_new_scope_){
    is_new_scope_ = false;
  } else {
    current_layer_ = current_layer_->GetChild(offsets_.top());
  }
  offsets_.push(0);
  frame_.AllocScope();
  index_table_.BeginScope();
  for (auto &elem: statement_list->statements_) {
    if (!is_returned_) {
      elem->Accept(*this);
    }
  }
  current_layer_ = current_layer_->GetParent();
  offsets_.pop();
  size_t current_pos = offsets_.top();
  offsets_.pop();
  offsets_.push(++current_pos);
  frame_.DeallocScope();
  index_table_.EndScope();
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::MainClass> main_class) {
  // nothing
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::ClassDeclarationList> class_declaration) {
  //nothing
}


void FunctionCallVisitor::Visit(std::shared_ptr<ast::Program> program) {
  //nothing
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::VariableDeclaration> declaration) {
  size_t index = frame_.AllocVariable(declaration->GetType());
  index_table_.CreateVariable(Symbol(declaration->GetName()), index);
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::ClassDeclaration> declaration) {
  // nothing
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::DeclarationList> declaration) {
  // nothing
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::Function> function) {
  is_new_scope_ = true;
  function->GetParams()->Accept(*this);
  function->GetStatements()->Accept(*this);
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::FunctionParameters> params) {
  size_t index = -1;
  for (auto& param: params->GetParamList()){
    index_table_.CreateVariable(Symbol(param), index);
    --index;
  }

}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::ClassVarDecl> declaration) {
  auto value = std::make_shared<ClassObject>(declaration->GetName());
  auto class_node = class_tree_.GetNode(declaration->GetName());
  for (auto &decl: class_node->GetVars()) {
    value->AddVariable(decl.first, Object(decl.second));
  }
  tos_value_ = std::move(value);
}


void FunctionCallVisitor::Visit(std::shared_ptr<ast::FunctionCall> function_call) {
  std::string name = function_call->GetName();
  auto obj = Accept(function_call->GetClassEntity());
  if (!obj->IsClassObj()) {
    throw std::runtime_error("Not Class Object");
  }
  std::shared_ptr<ClassObject> entity = std::dynamic_pointer_cast<ClassObject>(obj);
  std::shared_ptr<ClassNode> class_node = class_tree_.GetNode(entity->GetTypeName());
  if(!class_node->HasFunction(name)){
    throw std::runtime_error("Invalid function name");
  }
  std::vector<Object> params;
  for (auto &param: function_call->GetParamValues()->GetParams()) {
    params.push_back(*Accept(param));
  }
  FunctionCallVisitor next_visitor(entity, name);
  next_visitor.SetParams(params);
  next_visitor.GetFrame().SetParentFrame(std::make_shared<calls::Frame>(frame_));
  next_visitor.Visit(class_node->GetFunction(name));
  tos_value_ = std::make_shared<Object>(next_visitor.GetFrame().GetReturnValue());
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::ParamValueList> value_list) {
 //nothing
}

void FunctionCallVisitor::Visit(std::shared_ptr<ast::ReturnStatement> statement) {
  frame_.SetReturnValue(*Accept(statement->GetExpr()));
  is_returned_ = true;
}


void FunctionCallVisitor::SetTosValue(const int value) {
  tos_value_->SetValue(value);
}

void FunctionCallVisitor::SetTosValue(const bool value) {
  tos_value_->SetValue(value);
}

void FunctionCallVisitor::SetTosValue(const Object &value) {
  *tos_value_ = value;
}

void FunctionCallVisitor::SetParams(const std::vector<Object> &params) {
  frame_.SetParams(params);
}

calls::Frame& FunctionCallVisitor::GetFrame() {
  return frame_;
}

void FunctionCallVisitor::InitClassTree(const ClassTree &class_tree) {
  class_tree_ = class_tree;
}
