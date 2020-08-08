%{
    #include <cerrno>
    #include <climits>
    #include <cstdlib>
    #include <cstring> // strerror
    #include <string>
    #include <iostream>
    #include "grammar/driver.hh"
    #include "parser.hh"
%}

%option noyywrap nounput noinput batch debug

%option c++
%option yyclass="Scanner"

%{
  // A number symbol corresponding to the value in S.
  yy::parser::symbol_type make_NUMBER(
    const std::string &s,
    const yy::parser::location_type& loc
  );
%}

id    [a-zA-Z][a-zA-Z_0-9]*
int   [0-9]+
blank [ \t\r]

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);// columns += len
%}
%%
%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = driver.location;
  // Code run each time yylex is called.
  loc.step();
%}

{blank}+   loc.step ();
\n+        loc.lines (yyleng); loc.step ();

"-"        return yy::parser::make_MINUS  (loc);
"+"        return yy::parser::make_PLUS   (loc);
"*"        return yy::parser::make_STAR   (loc);
"/"        return yy::parser::make_SLASH  (loc);
"("        return yy::parser::make_LPAREN (loc);
")"        return yy::parser::make_RPAREN (loc);
"="        return yy::parser::make_ASSIGN (loc);
"=="       return yy::parser::make_EQUAL (loc);
"&&"       return yy::parser::make_AND (loc);
"||"       return yy::parser::make_OR (loc);
"<"        return yy::parser::make_LESS (loc);
">"        return yy::parser::make_MORE (loc);
"%"        return yy::parser::make_MODULE (loc);
"["        return yy::parser::make_LSPAREN (loc);
"]"        return yy::parser::make_RSPAREN (loc);
"{"        return yy::parser::make_LFPAREN (loc);
"}"        return yy::parser::make_RFPAREN (loc);
";"        return yy::parser::make_SEPARATOR (loc);
"public"   return yy::parser::make_PUBLIC_KW (loc);
"static"   return yy::parser::make_STATIC_KW (loc);
"class"    return yy::parser::make_CLASS_KW (loc);
"main"     return yy::parser::make_MAIN_KW (loc);
"if"       return yy::parser::make_IF_KW (loc);
"else"     return yy::parser::make_ELSE_KW (loc);
"System.out.println"    return yy::parser::make_PRINT (loc);
"int"      return yy::parser::make_INT_T (loc);
"boolean"  return yy::parser::make_BOOLEAN_T (loc);
"void"     return yy::parser::make_VOID_T (loc) ;
{int}      return make_NUMBER(yytext, loc);
"true"     return yy::parser::make_BOOLEAN(1, loc);
"false"    return yy::parser::make_BOOLEAN(0, loc);
{id}       return yy::parser::make_IDENTIFIER(yytext, loc);


<<EOF>>    return yy::parser::make_END (loc);
.          {
                throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext));
           }
%%

yy::parser::symbol_type make_NUMBER(
  const std::string &s,
  const yy::parser::location_type& loc
) {
  errno = 0;
  long n = strtol(s.c_str(), NULL, 10);
  if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
    throw yy::parser::syntax_error(loc, "integer is out of range: " + s);
  return yy::parser::make_NUMBER((int) n, loc);
}