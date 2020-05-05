#include "PlainIdent.h"

PlainIdent::PlainIdent(const std::string &ident) : ident_(ident) {}

std::string PlainIdent::GetId() const { return ident_; }

/*void PlainIdent::Accept(Visitor* visitor) {
  visitor->Visit(this);
}*/