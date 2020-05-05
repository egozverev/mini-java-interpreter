#pragma once

#include <map>
#include <string>
#include <fstream>
#include "scanner.h"
#include "parser.hh"
#include "visitors/PrintVisitor.h"
#include "visitors/Interpreter.h"
class Driver {
public:
  Driver();

  int result;

  int parse(const std::string &f);

  std::string file;
  bool trace_parsing;

  void scan_begin();

  void scan_end();

  void PrintTree(const std::string &filename);

  void ExecuteProgram();

  bool trace_scanning;
  yy::location location; // match a piece of initial code (beg, end)

  friend class Scanner;

  Scanner scanner;
  yy::parser parser;

  Program* program;

private:
  std::ifstream stream;

};
