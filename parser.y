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
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

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
%nterm <int> expr
%nterm <std::string> lvalue


%%

%left "+" "-";
%left "*" "/";

%start program;
program: main_class  class_declarations{};

main_class : "class" "identifier" "{" "public" "static" "void" "main" "(" ")" "{" statements "}"   "}" {};

class_declarations:
 %empty {}
 | class_declaration class_declarations {};

statements:
 statement {}
 | statement statements {};

class_declaration : "class"	"identifier" "{" declarations "}" {}
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

variable_declaration : type "identifier" ";" { driver.variables[$2] = 0;};

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
    | "print" "(" expr")" ";" {std::cout << $3;}
    | lvalue "=" expr ";" {driver.variables[$1] = $3;}
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
    "identifier" {$$ = $1;}
    | "identifier" "[" expr "]" {};

expr :
    expr binary_operator expr {}
    | expr "[" expr "]" {}
    | expr "." "length" {}
    | "new" simple_type "[" expr "]" {}
    | "new" type_identifier "(" ")" {}
    | "!" expr {}
    | "(" expr ")" {}
    | "identifier" {}
    | "number" {$$ = $1;}
    | "this" {}
    | "true" {}
    | "false" {}
    | method_invocation {};


binary_operator : "&&" {}
    |  "||" {}
    |  "<" {}
    | ">" {}
    |  "==" {}
    | "+" {}
    |  "-" {}
    | "*" {}
    | "/" {}
    | "%" {};



%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
