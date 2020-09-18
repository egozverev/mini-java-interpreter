#include "PlainIdent.h"

ast::PlainIdent::PlainIdent(const std::string &ident) : ident_(ident) {}

std::string ast::PlainIdent::GetId() const { return ident_; }
