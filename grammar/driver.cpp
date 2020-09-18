#include <visitors/FunctionCallVisitor.h>
#include "driver.hh"
#include "parser.hh"



Driver::Driver() :
    trace_parsing(false),
    trace_scanning(false),
    scanner(*this), parser(scanner, *this) {

}


int Driver::parse(const std::string& f) {
    file = f;
    location.initialize(&file);
    scan_begin();
    parser.set_debug_level(trace_parsing);
    int res = parser();
    scan_end();
    return res;
}

void Driver::scan_begin() {
    scanner.set_debug(trace_scanning);
  if (file.empty () || file == "-") {
  } else {
    stream.open(file);
    std::cout << file << std::endl;
    scanner.yyrestart(&stream);
  }
}

void Driver::scan_end()
{
    stream.close();
}

void Driver::ExecuteProgram() {
  SymbolTreeVisitor visitor;
  visitor.Visit(program);

  auto class_tree = visitor.GetClassTree();
  FunctionCallVisitor::InitClassTree(class_tree);
  auto obj = std::make_shared<ClassObject>("main");
  FunctionCallVisitor call_visitor(obj, "main");
  call_visitor.Visit(class_tree.GetNode("main")->GetFunction("main"));
}