%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    class Scanner;
    class Driver;
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
    class AssignmentList;

    class Statement;
    class StatementList;
    class PrintStatement;

    class Lvalue;
    class PlainIdent;

    class MainClass;
    class ClassDeclaration;
    class ClassDeclarationList;
    class Program;
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
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
    #include "assignments/AssignmentList.h"

    #include "statements/Statement.h"
    #include "statements/StatementList.h"
    #include "statements/PrintStatement.h"

    #include "values/Lvalue.h"
    #include "values/PlainIdent.h"

    #include "declarations/MainClass.h"
    #include "declarations/ClassDeclaration.h"
    #include "declarations/ClassDeclarationList.h"

    #include "Program.h"
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
%nterm <NumberExpression* > expr
%nterm <Lvalue*> lvalue
%nterm <StatementList*> statements
%nterm <Statement*> statement
%nterm <MainClass*> main_class
%nterm <Program*> program
%nterm <ClassDeclarationList*> class_declarations
%nterm <ClassDeclaration*> class_declaration


%%


%left "+" "-";
%left "*" "/";

%start program;

program: main_class  class_declarations
{
    $$ = new Program($1, $2);
    $$ -> launch();

};


main_class : "class" "identifier" "{" "public" "static" "void" "main" "(" ")" "{" statements "}"   "}"
{
    $$ = new MainClass($11);
};


class_declarations:
 %empty {$$ = new ClassDeclarationList();}
 | class_declaration class_declarations {$2 -> AddDeclaration($1); $$ = $2;};

statements:
 statement {$$ = new StatementList(); $$ -> AddStatement($1);}
 | statement statements {$2 -> AddStatement($1); $$ = $2;};

class_declaration : "class"	"identifier" "{" declarations "}" {$$ = new ClassDeclaration();}
    | "class" "identifier" "[" "extends" "identifier" "]" "{" declarations "}" {};

declarations:
    %empty {}
    | declaration declarations {};

declaration:
    variable_declaration {}
    | method_declaration {};

method_declaration:
    "public" type "identifier" "(" ")" "{" statements "}" {}
    | "public" type "identifier" "(" formals ")" "{" statements "}" {};

variable_declaration : type "identifier" ";" {};

formals:
    type "identifier" {}
    | type "identifier" formals {};

type:
    simple_type {}
    array_type {};

simple_type:
    "int" {}
    | "boolean" {}
    | "void" {}
    | type_identifier {};

array_type:
    simple_type "[" "]" {};

type_identifier:
    "identifier" {};
statement :	"assert" "(" expr ")" {}
    | local_variable_declaration {}
    | "{" statements "}" {}
    | "if"  "(" expr ")" statement {}
    | "if"  "(" expr ")" statement "else" statement {}
    | "while" "(" expr ")" statement {}
    | "print" "(" expr")" ";" {$$ = new PrintStatement($3);}
    | lvalue "=" expr ";" {$$ = new Assignment($1, driver, $3);}
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
    "identifier" {$$ = new PlainIdent($1);}
    | "identifier" "[" expr "]" {};

expr :
    expr "+" expr {$$ = new AddExpression($1, $3);}
    | expr "-" expr {$$ = new SubstractExpression($1, $3);}
    | expr "*" expr {$$ = new MulExpression($1, $3);}
    | expr "/" expr {$$ = new DivExpression($1, $3);}
    | expr "%" expr {$$ = new ModExpression($1, $3);}
    | expr "[" expr "]" {}
    | expr "." "length" {}
    | "new" simple_type "[" expr "]" {}
    | "new" type_identifier "(" ")" {}
    | "!" expr {}
    | "(" expr ")" {}
    | "identifier" {$$ = new IdentExpression($1, driver);}
    | "number" {$$ = new PlainNumberExpression($1);}
    | "this" {}
    | "true" {}
    | "false" {}
    | method_invocation {};
    //expr "&&" expr {$$ = new AndExpression($1, $3)}
    //| expr "||" expr {$$ = new OrExpression($1, $3)}
    //| expr "<" expr {$$ = new LessExpression($1, $3)}
    //| expr ">" expr {$$ = new GreaterExpression($1, $3)}
    //| expr "==" expr {$$ = new EqualExpression($1, $3)}

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
