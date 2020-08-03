#include <string>
#include "statements/Statement.h"
#include "Types.h"

namespace ast {
  class VariableDeclaration : public ast::Statement, public std::enable_shared_from_this<VariableDeclaration> {
  public:
    explicit VariableDeclaration(std::string var_name, std::shared_ptr<Type> type);

    void Accept(Visitor &visitor) override;

    std::string GetName();

    std::shared_ptr<ast::Type> GetType();

  private:

    const std::string var_name_;

    std::shared_ptr<ast::Type> var_type_;
  };
}