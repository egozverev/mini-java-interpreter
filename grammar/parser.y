%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    #include <memory>
    class Scanner;
    class Driver;
    namespace ast {
        class Expression;
        class IdentExpression;
        class NumberExpression;
        class PlainNumberExpression;
        class AddExpression;
        class SubstractExpression;
        class DivExpression;
        class ModExpression;
        class BoolExpression;
        class AndExpression;
        class OrExpression;
        class EqualExpression;
        class LessExpression;
        class GreaterExpression;

        class Assignment;

        class Statement;
        class StatementList;
        class PrintStatement;

        class Lvalue;
        class PlainIdent;

        class MainClass;
        class ClassDeclaration;
        class ClassDeclarationList;
        class Program;

        class VariableDeclaration;

        class Type;
        class Integer;
        class Void;
        class Boolean;
        class UserType;
    }
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "grammar/driver.hh"
    #include "location.hh"
    #include "expressions/Expression.h"
    #include "expressions/NumberExpression.h"
    #include "expressions/PlainNumberExpression.h"
    #include "expressions/BoolExpression.h"
    #include "expressions/AddExpression.h"
    #include "expressions/MulExpression.h"
    #include "expressions/DivExpression.h"
    #include "expressions/SubstractExpression.h"
    #include "expressions/ModExpression.h"
    #include "expressions/IdentExpression.h"
    #include "expressions/AndExpression.h"
    #include "expressions/OrExpression.h"
    #include "expressions/LessExpression.h"
    #include "expressions/GreaterExpression.h"
    #include "expressions/EqualExpression.h"

    #include "assignments/Assignment.h"

    #include "statements/Statement.h"
    #include "statements/StatementList.h"
    #include "statements/PrintStatement.h"

    #include "values/Lvalue.h"
    #include "values/PlainIdent.h"

    #include "declarations/MainClass.h"
    #include "declarations/ClassDeclaration.h"
    #include "declarations/ClassDeclarationList.h"

    #include "program_base/Program.h"
    #include "values/VariableDeclaration.h"
    #include "values/Types.h"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    SEPARATOR ";"
    ASSIGN "="
    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    LPAREN "("
    RPAREN ")"
    EQUAL "=="
    AND "&&"
    OR "||"
    LESS "<"
    MORE ">"
    MODULE "%"
    LSPAREN "[" // left square paren
    RSPAREN "]"
    LFPAREN "{" // left figure
    RFPAREN "}"
    INT_T "int"
    BOOLEAN_T "boolean"
    VOID_T "void"
    PUBLIC_KW "public"
    STATIC_KW "static"
    CLASS_KW "class"
    MAIN_KW "main"
    PRINT "print"
;


%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%token <bool> BOOLEAN "bool"
//%token <void> VOID "voidness"
%nterm <std::shared_ptr<ast::NumberExpression> > expr
%nterm <std::shared_ptr<ast::Lvalue> > lvalue
%nterm <std::shared_ptr<ast::StatementList> > statements
%nterm <std::shared_ptr<ast::Statement> > statement
%nterm <std::shared_ptr<ast::MainClass> > main_class
%nterm <std::shared_ptr<ast::Program> > program
%nterm <std::shared_ptr<ast::ClassDeclarationList> > class_declarations
%nterm <std::shared_ptr<ast::ClassDeclaration> > class_declaration
%nterm <std::shared_ptr<ast::VariableDeclaration> > variable_declaration
%nterm <std::shared_ptr<ast::Type> > simple_type
%nterm <std::shared_ptr<ast::Type> > type



%%


%left "+" "-";
%left "*" "/";

%start program;

program: main_class  class_declarations
{
    $$ = std::make_shared<ast::Program>($1, $2);
    driver.program = $$;

};


main_class : "class" "identifier" "{" "public" "static" "void" "main" "(" ")" "{" statements "}"   "}"
{
    $$ = std::make_shared<ast::MainClass>($11);
};


class_declarations:
 %empty {$$ = std::make_shared<ast::ClassDeclarationList>();}
 | class_declarations class_declaration {$1 -> AddDeclaration($2); $$ = $1;};

statements:
 statement {$$ = std::make_shared<ast::StatementList>(); $$ -> AddStatement($1);}
 | statements statement {$1 -> AddStatement($2); $$ = $1;};

class_declaration : "class"	"identifier" "{" declarations "}" {$$ = std::make_shared<ast::ClassDeclaration>();}
    | "class" "identifier" "[" "extends" "identifier" "]" "{" declarations "}" {};

declarations:
    %empty {}
    | declarations declaration {};

declaration:
    variable_declaration {}
    | method_declaration {};

method_declaration:
    "public" type "identifier" "(" ")" "{" statements "}" {}
    | "public" type "identifier" "(" formals ")" "{" statements "}" {};

variable_declaration : type "identifier" ";" {$$ = std::make_shared<ast::VariableDeclaration>($2, $1);};

formals:
    type "identifier" {}
    | type "identifier" formals {};

type:
    simple_type {}
    array_type {};

simple_type:
    "boolean" {$$ = std::make_shared<ast::Boolean>();}
    | "int" {$$ = std::make_shared<ast::Integer>();}
    | "void" {$$ = std::make_shared<ast::Void>();}
    //| type_identifier {$$ = std::make_shared<ast::UserType>();}
    ;

array_type:
    simple_type "[" "]" {};


statement :	"assert" "(" expr ")" {}
    | local_variable_declaration {}
    | "{" statements "}" {}
    | "if"  "(" expr ")" statement {}
    | "if"  "(" expr ")" statement "else" statement {}
    | "while" "(" expr ")" statement {}
    | "print" "(" expr")" ";" {$$ = std::make_shared<ast::PrintStatement>($3);}
    | lvalue "=" expr ";" {$$ = std::make_shared<ast::Assignment>($1, driver, $3);}
    | "return" expr ";" {}
    | method_invocation ";" {};


local_variable_declaration:
    variable_declaration {};

method_invocation:
    expr "." "identifier" "(" ")"
    | expr "." "identifier" "(" "[" expressions "]" ")"

expressions:
    expr {}
    | expr expressions {};

lvalue :
    "identifier" {$$ = std::make_shared<ast::PlainIdent>($1);}
    | "identifier" "[" expr "]" {};

type_identifier:
    "identifier" {};

expr :
    expr "+" expr {$$ = std::make_shared<ast::AddExpression>($1, $3);}
    | expr "-" expr {$$ = std::make_shared<ast::SubstractExpression>($1, $3);}
    | expr "*" expr {$$ = std::make_shared<ast::MulExpression>($1, $3);}
    | expr "/" expr {$$ = std::make_shared<ast::DivExpression>($1, $3);}
    | expr "%" expr {$$ = std::make_shared<ast::ModExpression>($1, $3);}
    | expr "[" expr "]" {}
    | expr "." "length" {}
    | "new" simple_type "[" expr "]" {}
    | "new" type_identifier "(" ")" {}
    | "!" expr {}
    | "(" expr ")" {}
    | "identifier" {$$ = std::make_shared<ast::IdentExpression> ($1, driver);}
    | "number" {$$ = std::make_shared<ast::PlainNumberExpression> ($1);}
    | "this" {}
    | "true" {}
    | "false" {}
    | method_invocation {};
    //expr "&&" expr {$$ = std::make_shared<ast::AndExpression>($1, $3)}
    //| expr "||" expr {$$ = std::make_shared<ast::OrExpression>($1, $3)}
    //| expr "<" expr {$$ = std::make_shared<ast::LessExpression>($1, $3)}
    //| expr ">" expr {$$ = std::make_shared<ast::GreaterExpression>($1, $3)}
    //| expr "==" expr {$$ = std::make_shared<ast::EqualExpression>($1, $3)}

//binary_operator : "&&" {}
//    |  "||" {}
//    |  "<" {}
//    | ">" {}
//    |  "==" {}
//    | "+" {}
//    |  "-" {}
//    | "*" {}
//    | "/" {}
//    | "%" {};



%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
