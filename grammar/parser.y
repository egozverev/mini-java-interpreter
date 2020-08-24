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
        class PlainBooleanExpression;
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
        class IfStatement;
        class IfElseStatement;

        class Lvalue;
        class PlainIdent;

        class MainClass;
        class ClassDeclaration;
        class ClassDeclarationList;
        class Declaration;
        class DeclarationList;
        class Program;

        class VariableDeclaration;

        class Type;
        class Integer;
        class Void;
        class Boolean;
        class UserType;

        class Function;
        class FunctionParameters;
        class FunctionCall;
        class ParamValueList;
        class ClassVarDecl;

        class ReturnStatement;

    }
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "grammar/driver.hh"
    #include "location.hh"
    #include "grammar/expressions/Expression.h"
    #include "grammar/expressions/NumberExpression.h"
    #include "grammar/expressions/PlainNumberExpression.h"
    #include "grammar/expressions/PlainBooleanExpression.h"
    #include "grammar/expressions/BoolExpression.h"
    #include "grammar/expressions/AddExpression.h"
    #include "grammar/expressions/MulExpression.h"
    #include "grammar/expressions/DivExpression.h"
    #include "grammar/expressions/SubstractExpression.h"
    #include "grammar/expressions/ModExpression.h"
    #include "grammar/expressions/IdentExpression.h"
    #include "grammar/expressions/AndExpression.h"
    #include "grammar/expressions/OrExpression.h"
    #include "grammar/expressions/LessExpression.h"
    #include "grammar/expressions/GreaterExpression.h"
    #include "grammar/expressions/EqualExpression.h"

    #include "grammar/assignments/Assignment.h"

    #include "grammar/statements/Statement.h"
    #include "grammar/statements/StatementList.h"
    #include "grammar/statements/PrintStatement.h"
    #include "grammar/statements/IfStatement.h"
    #include "grammar/statements/IfElseStatement.h"


    #include "grammar/values/Lvalue.h"
    #include "grammar/values/PlainIdent.h"

    #include "grammar/declarations/MainClass.h"
    #include "grammar/declarations/ClassDeclaration.h"
    #include "grammar/declarations/ClassDeclarationList.h"

    #include "grammar/declarations/Declaration.h"
    #include "grammar/declarations/DeclarationList.h"

    #include "grammar/program_base/Program.h"
    #include "grammar/values/VariableDeclaration.h"
    #include "grammar/values/Types.h"

    #include "grammar/functions/Function.h"
    #include "grammar/fnctions/FunctionParameters.h"
    #include "grammar/functions/FunctionCall.h"
    #include "grammar/functions/ParamValueLust.h"

    #include "grammar/values/ClassVarDecl.h"

    #include "grammar/statements/ReturnStatement.h"



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
    COMMA ","
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
    NEW_KW "new"
    IF_KW "if"
    ELSE_KW "else"
    PRINT "print"
;


%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%token <bool> BOOLEAN "bool"
//%token <void> VOID "voidness"
%nterm <std::shared_ptr<ast::Expression> > expr
%nterm <std::shared_ptr<ast::Lvalue> > lvalue
%nterm <std::shared_ptr<ast::StatementList> > statements
%nterm <std::shared_ptr<ast::Statement> > statement
%nterm <std::shared_ptr<ast::MainClass> > main_class
%nterm <std::shared_ptr<ast::Program> > program
%nterm <std::shared_ptr<ast::ClassDeclarationList> > class_declarations
%nterm <std::shared_ptr<ast::ClassDeclaration> > class_declaration
%nterm <std::shared_ptr<ast::VariableDeclaration> > variable_declaration
%nterm <std::shared_ptr<ast::VariableDeclaration> > local_variable_declaration
%nterm <std::shared_ptr<ast::Type> > simple_type
%nterm <std::shared_ptr<ast::Type> > type
%nterm <std::shared_ptr<ast::FunctionParameters> > formals
%nterm <std::shared_ptr<ast::Function> > method_declaration
%nterm <std::shared_ptr<ast::Declaration> > declaration
%nterm <std::shared_ptr<ast::DeclarationList> > declarations
%nterm <std::shared_ptr<ast::ParamValueList> > expressions
%nterm <std::shared_ptr<ast::FunctionCall> > method_invocation
%nterm <std::string> type_identifier








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

class_declaration : "class"	"identifier" "{" declarations "}" {
    $$ = std::make_shared<ast::ClassDeclaration>(%2, "", $4);
    }
    | "class" "identifier" "extends" "identifier" "{" declarations "}" {
    $$ = std::make_shared<ast::ClassDeclaration>($2, $4, $6);
    }
    ;

declarations:
    %empty {$$ = std::make_shared<DeclarationList>();}
    | declarations declaration {$$ = $1; $$->AddDeclaration($2);};

declaration:
    variable_declaration {$$ = $1;}
    | method_declaration {$$ = $1;};

method_declaration:
    "public" type "identifier" "(" ")" "{" statements "}" {
    $$ = std::make_shared<Function>($3, $2, nullptr , $7);
    }
    | "public" type "identifier" "(" formals ")" "{" statements "}" {
    $$ = std::make_shared<Function>($3, $2, $5, $8);
    };


variable_declaration : type "identifier" ";" {$$ = std::make_shared<ast::VariableDeclaration>($2, $1);};

formals:
    type "identifier" {$$ = std::make_shared<FunctionParameters>($2, $1);}
    | type "identifier" "," formals {$$ = $4; $$->AddParam($2, $1);};

type:
    simple_type {$$ = $1;}
    | array_type {};

simple_type:
    "boolean" {$$ = std::make_shared<ast::Boolean>();}
    | "int" {$$ = std::make_shared<ast::Integer>();}
    | "void" {$$ = std::make_shared<ast::Void>();}
    | type_identifier {$$ = std::make_shared<ast::UserType>($1);}
    ;

array_type:
    simple_type "[" "]" {};


statement :	"assert" "(" expr ")" {}
    | local_variable_declaration {$$ = $1;}
    | "{" statements "}" {$$ = $2;}
    | "if"  "(" expr ")" statement {$$ = std::make_shared<ast::IfStatement>($3, $5);}
    | "if"  "(" expr ")" statement "else" statement {
    $$ = std::make_shared<ast::IfElseStatement>($3, $5, $7);
    }
    | "while" "(" expr ")" statement {}
    | "print" "(" expr")" ";" {$$ = std::make_shared<ast::PrintStatement>($3);}
    | lvalue "=" expr ";" {$$ = std::make_shared<ast::Assignment>($1, driver, $3);}
    | "return" expr ";" {$$ = std::make_shared<ReturnStatement>($2);}
    | method_invocation ";" {$$ = $1;};


local_variable_declaration:
    variable_declaration {$$ = $1;};

method_invocation:
    expr "." "identifier" "(" ")" {$$ = std::make_shared<FunctionCall>($1, $3, nullptr);}
    | expr "." "identifier" "(" expressions ")" {$$ = std::make_shared<FunctionCall>($1, $3, $5);}
    ;

expressions:
    expr {$$ = std::make_shared<ParamValueList>($1);}
    | expressions expr{$$ = $1; $$.AddParam($2);};

lvalue :
    "identifier" {$$ = std::make_shared<ast::PlainIdent>($1);}
    | "identifier" "[" expr "]" {};

type_identifier:
    "identifier" {$$ = $1;};

expr :
    expr "+" expr {$$ = std::make_shared<ast::AddExpression>($1, $3);}
    | expr "-" expr {$$ = std::make_shared<ast::SubstractExpression>($1, $3);}
    | expr "*" expr {$$ = std::make_shared<ast::MulExpression>($1, $3);}
    | expr "/" expr {$$ = std::make_shared<ast::DivExpression>($1, $3);}
    | expr "%" expr {$$ = std::make_shared<ast::ModExpression>($1, $3);}
    | expr "[" expr "]" {}
    | expr "." "length" {}
    | "new" simple_type "[" expr "]" {}
    | "new" type_identifier "(" ")" {$$ = std::make_shared<ClassVarDecl>($2);}
    | "!" expr {}
    | "(" expr ")" {$$ = $2;}
    | "identifier" {$$ = std::make_shared<ast::IdentExpression> ($1, driver);}
    | "number" {$$ = std::make_shared<ast::PlainNumberExpression> ($1);}
    | "this" {}
    | "bool" {$$ = std::make_shared<ast::PlainBooleanExpression> ($1);}
    | method_invocation {}
    | expr "&&" expr {$$ = std::make_shared<ast::AndExpression>($1, $3);}
    | expr "||" expr {$$ = std::make_shared<ast::OrExpression>($1, $3);}
    | expr "<" expr {$$ = std::make_shared<ast::LessExpression>($1, $3);}
    | expr ">" expr {$$ = std::make_shared<ast::GreaterExpression>($1, $3);}
    | expr "==" expr {$$ = std::make_shared<ast::EqualExpression>($1, $3);}
    ;




%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
