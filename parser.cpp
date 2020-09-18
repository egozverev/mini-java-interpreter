// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hh"


// Unqualified %code blocks.
#line 75 "grammar/parser.y"

    #include "grammar/driver.hh"
    #include "location.hh"
    #include "grammar/expressions/Expression.h"
    #include "grammar/expressions/ThisExpression.h"
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
    #include "grammar/statements/WhileStatement.h"


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
    #include "grammar/functions/FunctionParameters.h"
    #include "grammar/functions/FunctionCall.h"
    #include "grammar/functions/ParamValueList.h"

    #include "grammar/values/ClassVarDecl.h"

    #include "grammar/statements/ReturnStatement.h"



    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }

#line 106 "/home/egor/C_projects/mini-java-compiler/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 197 "/home/egor/C_projects/mini-java-compiler/parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 39: // "bool"
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case 38: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 52: // class_declaration
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::ClassDeclaration>  > (YY_MOVE (that.value));
        break;

      case 51: // class_declarations
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::ClassDeclarationList>  > (YY_MOVE (that.value));
        break;

      case 59: // declaration
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Declaration>  > (YY_MOVE (that.value));
        break;

      case 60: // declarations
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::DeclarationList>  > (YY_MOVE (that.value));
        break;

      case 45: // expr
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Expression>  > (YY_MOVE (that.value));
        break;

      case 58: // method_declaration
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Function>  > (YY_MOVE (that.value));
        break;

      case 62: // method_invocation
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::FunctionCall>  > (YY_MOVE (that.value));
        break;

      case 57: // formals
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::FunctionParameters>  > (YY_MOVE (that.value));
        break;

      case 46: // lvalue
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Lvalue>  > (YY_MOVE (that.value));
        break;

      case 49: // main_class
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::MainClass>  > (YY_MOVE (that.value));
        break;

      case 61: // expressions
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::ParamValueList>  > (YY_MOVE (that.value));
        break;

      case 50: // program
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Program>  > (YY_MOVE (that.value));
        break;

      case 48: // statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Statement>  > (YY_MOVE (that.value));
        break;

      case 47: // statements
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::StatementList>  > (YY_MOVE (that.value));
        break;

      case 55: // simple_type
      case 56: // type
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Type>  > (YY_MOVE (that.value));
        break;

      case 53: // variable_declaration
      case 54: // local_variable_declaration
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::VariableDeclaration>  > (YY_MOVE (that.value));
        break;

      case 37: // "identifier"
      case 63: // type_identifier
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 39: // "bool"
        value.move< bool > (YY_MOVE (that.value));
        break;

      case 38: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case 52: // class_declaration
        value.move< std::shared_ptr<ast::ClassDeclaration>  > (YY_MOVE (that.value));
        break;

      case 51: // class_declarations
        value.move< std::shared_ptr<ast::ClassDeclarationList>  > (YY_MOVE (that.value));
        break;

      case 59: // declaration
        value.move< std::shared_ptr<ast::Declaration>  > (YY_MOVE (that.value));
        break;

      case 60: // declarations
        value.move< std::shared_ptr<ast::DeclarationList>  > (YY_MOVE (that.value));
        break;

      case 45: // expr
        value.move< std::shared_ptr<ast::Expression>  > (YY_MOVE (that.value));
        break;

      case 58: // method_declaration
        value.move< std::shared_ptr<ast::Function>  > (YY_MOVE (that.value));
        break;

      case 62: // method_invocation
        value.move< std::shared_ptr<ast::FunctionCall>  > (YY_MOVE (that.value));
        break;

      case 57: // formals
        value.move< std::shared_ptr<ast::FunctionParameters>  > (YY_MOVE (that.value));
        break;

      case 46: // lvalue
        value.move< std::shared_ptr<ast::Lvalue>  > (YY_MOVE (that.value));
        break;

      case 49: // main_class
        value.move< std::shared_ptr<ast::MainClass>  > (YY_MOVE (that.value));
        break;

      case 61: // expressions
        value.move< std::shared_ptr<ast::ParamValueList>  > (YY_MOVE (that.value));
        break;

      case 50: // program
        value.move< std::shared_ptr<ast::Program>  > (YY_MOVE (that.value));
        break;

      case 48: // statement
        value.move< std::shared_ptr<ast::Statement>  > (YY_MOVE (that.value));
        break;

      case 47: // statements
        value.move< std::shared_ptr<ast::StatementList>  > (YY_MOVE (that.value));
        break;

      case 55: // simple_type
      case 56: // type
        value.move< std::shared_ptr<ast::Type>  > (YY_MOVE (that.value));
        break;

      case 53: // variable_declaration
      case 54: // local_variable_declaration
        value.move< std::shared_ptr<ast::VariableDeclaration>  > (YY_MOVE (that.value));
        break;

      case 37: // "identifier"
      case 63: // type_identifier
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 39: // "bool"
        value.copy< bool > (that.value);
        break;

      case 38: // "number"
        value.copy< int > (that.value);
        break;

      case 52: // class_declaration
        value.copy< std::shared_ptr<ast::ClassDeclaration>  > (that.value);
        break;

      case 51: // class_declarations
        value.copy< std::shared_ptr<ast::ClassDeclarationList>  > (that.value);
        break;

      case 59: // declaration
        value.copy< std::shared_ptr<ast::Declaration>  > (that.value);
        break;

      case 60: // declarations
        value.copy< std::shared_ptr<ast::DeclarationList>  > (that.value);
        break;

      case 45: // expr
        value.copy< std::shared_ptr<ast::Expression>  > (that.value);
        break;

      case 58: // method_declaration
        value.copy< std::shared_ptr<ast::Function>  > (that.value);
        break;

      case 62: // method_invocation
        value.copy< std::shared_ptr<ast::FunctionCall>  > (that.value);
        break;

      case 57: // formals
        value.copy< std::shared_ptr<ast::FunctionParameters>  > (that.value);
        break;

      case 46: // lvalue
        value.copy< std::shared_ptr<ast::Lvalue>  > (that.value);
        break;

      case 49: // main_class
        value.copy< std::shared_ptr<ast::MainClass>  > (that.value);
        break;

      case 61: // expressions
        value.copy< std::shared_ptr<ast::ParamValueList>  > (that.value);
        break;

      case 50: // program
        value.copy< std::shared_ptr<ast::Program>  > (that.value);
        break;

      case 48: // statement
        value.copy< std::shared_ptr<ast::Statement>  > (that.value);
        break;

      case 47: // statements
        value.copy< std::shared_ptr<ast::StatementList>  > (that.value);
        break;

      case 55: // simple_type
      case 56: // type
        value.copy< std::shared_ptr<ast::Type>  > (that.value);
        break;

      case 53: // variable_declaration
      case 54: // local_variable_declaration
        value.copy< std::shared_ptr<ast::VariableDeclaration>  > (that.value);
        break;

      case 37: // "identifier"
      case 63: // type_identifier
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 39: // "bool"
        value.move< bool > (that.value);
        break;

      case 38: // "number"
        value.move< int > (that.value);
        break;

      case 52: // class_declaration
        value.move< std::shared_ptr<ast::ClassDeclaration>  > (that.value);
        break;

      case 51: // class_declarations
        value.move< std::shared_ptr<ast::ClassDeclarationList>  > (that.value);
        break;

      case 59: // declaration
        value.move< std::shared_ptr<ast::Declaration>  > (that.value);
        break;

      case 60: // declarations
        value.move< std::shared_ptr<ast::DeclarationList>  > (that.value);
        break;

      case 45: // expr
        value.move< std::shared_ptr<ast::Expression>  > (that.value);
        break;

      case 58: // method_declaration
        value.move< std::shared_ptr<ast::Function>  > (that.value);
        break;

      case 62: // method_invocation
        value.move< std::shared_ptr<ast::FunctionCall>  > (that.value);
        break;

      case 57: // formals
        value.move< std::shared_ptr<ast::FunctionParameters>  > (that.value);
        break;

      case 46: // lvalue
        value.move< std::shared_ptr<ast::Lvalue>  > (that.value);
        break;

      case 49: // main_class
        value.move< std::shared_ptr<ast::MainClass>  > (that.value);
        break;

      case 61: // expressions
        value.move< std::shared_ptr<ast::ParamValueList>  > (that.value);
        break;

      case 50: // program
        value.move< std::shared_ptr<ast::Program>  > (that.value);
        break;

      case 48: // statement
        value.move< std::shared_ptr<ast::Statement>  > (that.value);
        break;

      case 47: // statements
        value.move< std::shared_ptr<ast::StatementList>  > (that.value);
        break;

      case 55: // simple_type
      case 56: // type
        value.move< std::shared_ptr<ast::Type>  > (that.value);
        break;

      case 53: // variable_declaration
      case 54: // local_variable_declaration
        value.move< std::shared_ptr<ast::VariableDeclaration>  > (that.value);
        break;

      case 37: // "identifier"
      case 63: // type_identifier
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 39: // "bool"
        yylhs.value.emplace< bool > ();
        break;

      case 38: // "number"
        yylhs.value.emplace< int > ();
        break;

      case 52: // class_declaration
        yylhs.value.emplace< std::shared_ptr<ast::ClassDeclaration>  > ();
        break;

      case 51: // class_declarations
        yylhs.value.emplace< std::shared_ptr<ast::ClassDeclarationList>  > ();
        break;

      case 59: // declaration
        yylhs.value.emplace< std::shared_ptr<ast::Declaration>  > ();
        break;

      case 60: // declarations
        yylhs.value.emplace< std::shared_ptr<ast::DeclarationList>  > ();
        break;

      case 45: // expr
        yylhs.value.emplace< std::shared_ptr<ast::Expression>  > ();
        break;

      case 58: // method_declaration
        yylhs.value.emplace< std::shared_ptr<ast::Function>  > ();
        break;

      case 62: // method_invocation
        yylhs.value.emplace< std::shared_ptr<ast::FunctionCall>  > ();
        break;

      case 57: // formals
        yylhs.value.emplace< std::shared_ptr<ast::FunctionParameters>  > ();
        break;

      case 46: // lvalue
        yylhs.value.emplace< std::shared_ptr<ast::Lvalue>  > ();
        break;

      case 49: // main_class
        yylhs.value.emplace< std::shared_ptr<ast::MainClass>  > ();
        break;

      case 61: // expressions
        yylhs.value.emplace< std::shared_ptr<ast::ParamValueList>  > ();
        break;

      case 50: // program
        yylhs.value.emplace< std::shared_ptr<ast::Program>  > ();
        break;

      case 48: // statement
        yylhs.value.emplace< std::shared_ptr<ast::Statement>  > ();
        break;

      case 47: // statements
        yylhs.value.emplace< std::shared_ptr<ast::StatementList>  > ();
        break;

      case 55: // simple_type
      case 56: // type
        yylhs.value.emplace< std::shared_ptr<ast::Type>  > ();
        break;

      case 53: // variable_declaration
      case 54: // local_variable_declaration
        yylhs.value.emplace< std::shared_ptr<ast::VariableDeclaration>  > ();
        break;

      case 37: // "identifier"
      case 63: // type_identifier
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 218 "grammar/parser.y"
{
    yylhs.value.as < std::shared_ptr<ast::Program>  > () = std::make_shared<ast::Program>(yystack_[1].value.as < std::shared_ptr<ast::MainClass>  > (), yystack_[0].value.as < std::shared_ptr<ast::ClassDeclarationList>  > ());
    driver.program = yylhs.value.as < std::shared_ptr<ast::Program>  > ();

}
#line 1024 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 3:
#line 226 "grammar/parser.y"
{
    yylhs.value.as < std::shared_ptr<ast::MainClass>  > () = std::make_shared<ast::MainClass>(yystack_[2].value.as < std::shared_ptr<ast::StatementList>  > ());
}
#line 1032 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 4:
#line 232 "grammar/parser.y"
        {yylhs.value.as < std::shared_ptr<ast::ClassDeclarationList>  > () = std::make_shared<ast::ClassDeclarationList>();}
#line 1038 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 5:
#line 233 "grammar/parser.y"
                                        {yystack_[1].value.as < std::shared_ptr<ast::ClassDeclarationList>  > () -> AddDeclaration(yystack_[0].value.as < std::shared_ptr<ast::ClassDeclaration>  > ()); yylhs.value.as < std::shared_ptr<ast::ClassDeclarationList>  > () = yystack_[1].value.as < std::shared_ptr<ast::ClassDeclarationList>  > ();}
#line 1044 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 6:
#line 236 "grammar/parser.y"
           {yylhs.value.as < std::shared_ptr<ast::StatementList>  > () = std::make_shared<ast::StatementList>(); yylhs.value.as < std::shared_ptr<ast::StatementList>  > () -> AddStatement(yystack_[0].value.as < std::shared_ptr<ast::Statement>  > ());}
#line 1050 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 7:
#line 237 "grammar/parser.y"
                        {yystack_[1].value.as < std::shared_ptr<ast::StatementList>  > () -> AddStatement(yystack_[0].value.as < std::shared_ptr<ast::Statement>  > ()); yylhs.value.as < std::shared_ptr<ast::StatementList>  > () = yystack_[1].value.as < std::shared_ptr<ast::StatementList>  > ();}
#line 1056 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 8:
#line 239 "grammar/parser.y"
                                                                  {
    yylhs.value.as < std::shared_ptr<ast::ClassDeclaration>  > () = std::make_shared<ast::ClassDeclaration>(yystack_[3].value.as < std::string > (), "", yystack_[1].value.as < std::shared_ptr<ast::DeclarationList>  > ());
    }
#line 1064 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 9:
#line 242 "grammar/parser.y"
                                                                       {
    yylhs.value.as < std::shared_ptr<ast::ClassDeclaration>  > () = std::make_shared<ast::ClassDeclaration>(yystack_[5].value.as < std::string > (), yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::shared_ptr<ast::DeclarationList>  > ());
    }
#line 1072 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 10:
#line 248 "grammar/parser.y"
           {yylhs.value.as < std::shared_ptr<ast::DeclarationList>  > () = std::make_shared<ast::DeclarationList>();}
#line 1078 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 11:
#line 249 "grammar/parser.y"
                               {yylhs.value.as < std::shared_ptr<ast::DeclarationList>  > () = yystack_[1].value.as < std::shared_ptr<ast::DeclarationList>  > (); yylhs.value.as < std::shared_ptr<ast::DeclarationList>  > ()->AddDeclaration(yystack_[0].value.as < std::shared_ptr<ast::Declaration>  > ());}
#line 1084 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 12:
#line 252 "grammar/parser.y"
                         {yylhs.value.as < std::shared_ptr<ast::Declaration>  > () = yystack_[0].value.as < std::shared_ptr<ast::VariableDeclaration>  > ();}
#line 1090 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 13:
#line 253 "grammar/parser.y"
                         {yylhs.value.as < std::shared_ptr<ast::Declaration>  > () = yystack_[0].value.as < std::shared_ptr<ast::Function>  > ();}
#line 1096 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 14:
#line 256 "grammar/parser.y"
                                                          {
    yylhs.value.as < std::shared_ptr<ast::Function>  > () = std::make_shared<ast::Function>(yystack_[5].value.as < std::string > (), yystack_[6].value.as < std::shared_ptr<ast::Type>  > (), std::make_shared<ast::FunctionParameters>(), yystack_[1].value.as < std::shared_ptr<ast::StatementList>  > ());
    }
#line 1104 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 15:
#line 259 "grammar/parser.y"
                                                                    {
    yylhs.value.as < std::shared_ptr<ast::Function>  > () = std::make_shared<ast::Function>(yystack_[6].value.as < std::string > (), yystack_[7].value.as < std::shared_ptr<ast::Type>  > (), yystack_[4].value.as < std::shared_ptr<ast::FunctionParameters>  > (), yystack_[1].value.as < std::shared_ptr<ast::StatementList>  > ());
    }
#line 1112 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 16:
#line 264 "grammar/parser.y"
                                             {yylhs.value.as < std::shared_ptr<ast::VariableDeclaration>  > () = std::make_shared<ast::VariableDeclaration>(yystack_[1].value.as < std::string > (), yystack_[2].value.as < std::shared_ptr<ast::Type>  > ());}
#line 1118 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 17:
#line 267 "grammar/parser.y"
                      {yylhs.value.as < std::shared_ptr<ast::FunctionParameters>  > () = std::make_shared<ast::FunctionParameters>(yystack_[0].value.as < std::string > (), yystack_[1].value.as < std::shared_ptr<ast::Type>  > ());}
#line 1124 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 18:
#line 268 "grammar/parser.y"
                                    {yylhs.value.as < std::shared_ptr<ast::FunctionParameters>  > () = yystack_[0].value.as < std::shared_ptr<ast::FunctionParameters>  > (); yylhs.value.as < std::shared_ptr<ast::FunctionParameters>  > ()->AddParam(yystack_[2].value.as < std::string > (), yystack_[3].value.as < std::shared_ptr<ast::Type>  > ());}
#line 1130 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 19:
#line 271 "grammar/parser.y"
                {yylhs.value.as < std::shared_ptr<ast::Type>  > () = yystack_[0].value.as < std::shared_ptr<ast::Type>  > ();}
#line 1136 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 20:
#line 272 "grammar/parser.y"
                 {}
#line 1142 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 21:
#line 275 "grammar/parser.y"
              {yylhs.value.as < std::shared_ptr<ast::Type>  > () = std::make_shared<ast::Boolean>();}
#line 1148 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 22:
#line 276 "grammar/parser.y"
            {yylhs.value.as < std::shared_ptr<ast::Type>  > () = std::make_shared<ast::Integer>();}
#line 1154 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 23:
#line 277 "grammar/parser.y"
             {yylhs.value.as < std::shared_ptr<ast::Type>  > () = std::make_shared<ast::Void>();}
#line 1160 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 24:
#line 278 "grammar/parser.y"
                      {yylhs.value.as < std::shared_ptr<ast::Type>  > () = std::make_shared<ast::UserType>(yystack_[0].value.as < std::string > ());}
#line 1166 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 25:
#line 282 "grammar/parser.y"
                        {}
#line 1172 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 26:
#line 285 "grammar/parser.y"
                                      {}
#line 1178 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 27:
#line 286 "grammar/parser.y"
                                 {yylhs.value.as < std::shared_ptr<ast::Statement>  > () = yystack_[0].value.as < std::shared_ptr<ast::VariableDeclaration>  > ();}
#line 1184 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 28:
#line 287 "grammar/parser.y"
                         {yylhs.value.as < std::shared_ptr<ast::Statement>  > () = yystack_[1].value.as < std::shared_ptr<ast::StatementList>  > ();}
#line 1190 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 29:
#line 288 "grammar/parser.y"
                                   {yylhs.value.as < std::shared_ptr<ast::Statement>  > () = std::make_shared<ast::IfStatement>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Statement>  > ());}
#line 1196 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 30:
#line 289 "grammar/parser.y"
                                                    {
    yylhs.value.as < std::shared_ptr<ast::Statement>  > () = std::make_shared<ast::IfElseStatement>(yystack_[4].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[2].value.as < std::shared_ptr<ast::Statement>  > (), yystack_[0].value.as < std::shared_ptr<ast::Statement>  > ());
    }
#line 1204 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 31:
#line 292 "grammar/parser.y"
                                     {yylhs.value.as < std::shared_ptr<ast::Statement>  > () = std::make_shared<ast::WhileStatement>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Statement>  > ());}
#line 1210 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 32:
#line 293 "grammar/parser.y"
                              {yylhs.value.as < std::shared_ptr<ast::Statement>  > () = std::make_shared<ast::PrintStatement>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1216 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 33:
#line 294 "grammar/parser.y"
                          {yylhs.value.as < std::shared_ptr<ast::Statement>  > () = std::make_shared<ast::Assignment>(yystack_[3].value.as < std::shared_ptr<ast::Lvalue>  > (), driver, yystack_[1].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1222 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 34:
#line 295 "grammar/parser.y"
                        {yylhs.value.as < std::shared_ptr<ast::Statement>  > () = std::make_shared<ast::ReturnStatement>(yystack_[1].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1228 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 35:
#line 296 "grammar/parser.y"
                            {yylhs.value.as < std::shared_ptr<ast::Statement>  > () = yystack_[1].value.as < std::shared_ptr<ast::FunctionCall>  > ();}
#line 1234 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 36:
#line 300 "grammar/parser.y"
                         {yylhs.value.as < std::shared_ptr<ast::VariableDeclaration>  > () = yystack_[0].value.as < std::shared_ptr<ast::VariableDeclaration>  > ();}
#line 1240 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 37:
#line 303 "grammar/parser.y"
                                  {yylhs.value.as < std::shared_ptr<ast::FunctionCall>  > () = std::make_shared<ast::FunctionCall>(yystack_[4].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[2].value.as < std::string > (), std::make_shared<ast::ParamValueList>());}
#line 1246 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 38:
#line 304 "grammar/parser.y"
                                                {yylhs.value.as < std::shared_ptr<ast::FunctionCall>  > () = std::make_shared<ast::FunctionCall>(yystack_[5].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::shared_ptr<ast::ParamValueList>  > ());}
#line 1252 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 39:
#line 308 "grammar/parser.y"
         {yylhs.value.as < std::shared_ptr<ast::ParamValueList>  > () = std::make_shared<ast::ParamValueList>(yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1258 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 40:
#line 309 "grammar/parser.y"
                       {yystack_[1].value.as < std::shared_ptr<ast::ParamValueList>  > ()->AddParam(yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ()); yylhs.value.as < std::shared_ptr<ast::ParamValueList>  > () = yystack_[1].value.as < std::shared_ptr<ast::ParamValueList>  > ();}
#line 1264 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 41:
#line 312 "grammar/parser.y"
                 {yylhs.value.as < std::shared_ptr<ast::Lvalue>  > () = std::make_shared<ast::PlainIdent>(yystack_[0].value.as < std::string > ());}
#line 1270 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 42:
#line 313 "grammar/parser.y"
                                {}
#line 1276 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 43:
#line 316 "grammar/parser.y"
                 {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 1282 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 44:
#line 319 "grammar/parser.y"
                  {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::AddExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1288 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 45:
#line 320 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::SubstractExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1294 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 46:
#line 321 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::MulExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1300 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 47:
#line 322 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::DivExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1306 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 48:
#line 323 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::ModExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1312 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 49:
#line 324 "grammar/parser.y"
                        {}
#line 1318 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 50:
#line 325 "grammar/parser.y"
                        {}
#line 1324 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 51:
#line 326 "grammar/parser.y"
                                     {}
#line 1330 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 52:
#line 327 "grammar/parser.y"
                                    {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::ClassVarDecl>(yystack_[2].value.as < std::string > ());}
#line 1336 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 53:
#line 328 "grammar/parser.y"
               {}
#line 1342 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 54:
#line 329 "grammar/parser.y"
                   {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = yystack_[1].value.as < std::shared_ptr<ast::Expression>  > ();}
#line 1348 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 55:
#line 330 "grammar/parser.y"
                   {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::IdentExpression> (yystack_[0].value.as < std::string > (), driver);}
#line 1354 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 56:
#line 331 "grammar/parser.y"
               {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::PlainNumberExpression> (yystack_[0].value.as < int > ());}
#line 1360 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 57:
#line 332 "grammar/parser.y"
             {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::ThisExpression>();}
#line 1366 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 58:
#line 333 "grammar/parser.y"
             {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::PlainBooleanExpression> (yystack_[0].value.as < bool > ());}
#line 1372 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 59:
#line 334 "grammar/parser.y"
                        {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = yystack_[0].value.as < std::shared_ptr<ast::FunctionCall>  > ();}
#line 1378 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 60:
#line 335 "grammar/parser.y"
                     {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::AndExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1384 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 61:
#line 336 "grammar/parser.y"
                     {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::OrExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1390 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 62:
#line 337 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::LessExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1396 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 63:
#line 338 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::GreaterExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1402 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 64:
#line 339 "grammar/parser.y"
                     {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::EqualExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1408 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;


#line 1412 "/home/egor/C_projects/mini-java-compiler/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -48;

  const signed char parser::yytable_ninf_ = -44;

  const short
  parser::yypact_[] =
  {
     -17,   -28,   -48,    12,    -7,   -13,   -48,   -10,    -8,   -48,
       9,   -19,     2,   -48,     1,    20,   325,    32,    59,   -48,
     -48,   -48,   -48,    44,   -48,   -48,    53,    36,   -48,   -48,
     -48,   -48,   -48,    62,    39,    57,    76,   330,    65,    69,
     -48,   -48,   -48,   196,   178,   225,   196,    44,    77,    79,
     225,   -48,    80,     0,   -48,   -48,    81,   225,   431,    89,
      88,   -48,   -48,   -48,    91,    75,    61,    93,   -48,   356,
     -48,   117,    84,    96,   225,   225,   262,   225,   225,   225,
     431,   -32,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,    78,   -48,   -48,   196,   110,    94,
     -48,   -48,   225,   104,   371,   386,   -48,   401,   294,   416,
     106,   -48,   446,   446,    27,    27,   431,   431,   431,   431,
     431,   431,   310,   279,   -48,   146,    44,   196,   326,   -48,
     196,   127,   196,   -48,   -48,    -4,   -48,   -48,   -48,   -48,
     175,   -48,   100,   -48,   -48,   -48,   431,   211,   -48,   196,
     -48,   431,   -48
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     4,     0,     0,     2,     1,     0,     0,     5,
       0,     0,     0,    10,     0,     0,     0,     0,     0,     8,
      22,    21,    23,     0,    43,    12,    19,     0,    13,    11,
      24,    20,    10,     0,     0,     0,     0,     0,     0,     0,
      25,    16,     9,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,    55,    56,    58,     0,     0,     0,     0,
       0,     6,    36,    27,    59,     0,     0,     0,    55,     0,
      59,     0,     0,    24,     0,     0,     0,     0,     0,     0,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,    35,     0,    17,     0,
      54,    28,     0,     0,     0,     0,    34,     0,     0,     0,
       0,    50,    45,    44,    46,    47,    64,    60,    61,    62,
      63,    48,     0,     0,     3,     0,     0,     0,     0,    52,
       0,     0,     0,    42,    26,     0,    49,    33,    14,    18,
       0,    51,    29,    32,    31,    37,    39,     0,    15,     0,
      38,    40,    30
  };

  const signed char
  parser::yypgoto_[] =
  {
     -48,   -27,   -48,   -26,   -47,   -48,   -48,   -48,   -48,   -12,
     -48,    86,   -22,     8,   -48,   -48,   103,   -48,   -43,    90,
     -48
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    58,    59,    60,    61,     2,     3,     5,     9,    62,
      63,    26,    27,    67,    28,    29,    16,   147,    70,    30,
      31
  };

  const short
  parser::yytable_[] =
  {
      64,    34,    13,    64,    25,   110,   -41,    45,   145,     4,
     111,     1,     6,    95,     7,     8,    10,    64,    69,    78,
      71,    14,    66,    76,    95,    25,    47,    15,    64,    11,
      80,    51,    81,    68,    54,    55,    12,   -43,    17,    57,
      86,    87,    88,    89,    90,    91,    92,   104,   105,    18,
     107,   108,   109,    32,    64,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,    20,    21,    22,
      33,   125,    35,    36,    38,   128,    39,    40,    95,    41,
      44,    24,    64,   142,    64,   144,    43,    64,    74,    64,
      75,    77,    79,    95,    96,    93,    97,    64,    98,    45,
     124,   140,   152,   102,    66,    99,    64,   103,   146,    46,
      94,    20,    21,    22,   126,   127,   129,   135,    47,    48,
     151,    49,    50,    51,    52,    53,    54,    55,    45,    56,
     143,    57,   149,    72,   139,    37,     0,    73,    46,   101,
      20,    21,    22,     0,     0,     0,     0,    47,    48,     0,
      49,    50,    51,    52,    53,    54,    55,    45,    56,     0,
      57,     0,     0,     0,     0,     0,     0,    46,   138,    20,
      21,    22,     0,     0,     0,     0,    47,    48,     0,    49,
      50,    51,    52,    53,    54,    55,    45,    56,     0,    57,
      65,     0,     0,     0,     0,     0,    46,   148,    20,    21,
      22,    20,    21,    22,     0,    47,    48,    45,    49,    50,
      51,    52,    53,    54,    55,    24,    56,    46,    57,    20,
      21,    22,    45,   150,     0,     0,    47,    48,     0,    49,
      50,    51,    52,    53,    54,    55,    45,    56,     0,    57,
       0,    47,     0,     0,     0,     0,    51,     0,    68,    54,
      55,     0,     0,     0,    57,    47,     0,     0,     0,     0,
      51,     0,    68,    54,    55,   106,     0,    81,    57,    82,
      83,    84,    85,     0,     0,    86,    87,    88,    89,    90,
      91,    92,   137,     0,    81,     0,    82,    83,    84,    85,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    81,
       0,    82,    83,    84,    85,     0,     0,    86,    87,    88,
      89,    90,    91,    92,   133,    81,     0,    82,    83,    84,
      85,     0,     0,    86,    87,    88,    89,    90,    91,    92,
     136,    81,     0,    82,    83,    84,    85,     0,     0,    86,
      87,    88,    89,    90,    91,    92,   141,    19,    20,    21,
      22,    23,    42,    20,    21,    22,    23,     0,     0,     0,
       0,    81,    24,    82,    83,    84,    85,    24,   100,    86,
      87,    88,    89,    90,    91,    92,    81,     0,    82,    83,
      84,    85,     0,   130,    86,    87,    88,    89,    90,    91,
      92,    81,     0,    82,    83,    84,    85,     0,   131,    86,
      87,    88,    89,    90,    91,    92,    81,     0,    82,    83,
      84,    85,     0,   132,    86,    87,    88,    89,    90,    91,
      92,    81,     0,    82,    83,    84,    85,     0,   134,    86,
      87,    88,    89,    90,    91,    92,    81,     0,    82,    83,
      84,    85,     0,     0,    86,    87,    88,    89,    90,    91,
      92,    81,     0,     0,     0,    84,    85,     0,     0,    86,
      87,    88,    89,    90,    91,    92
  };

  const short
  parser::yycheck_[] =
  {
      43,    23,    21,    46,    16,    37,     6,    11,    12,    37,
      42,    28,     0,    60,    21,    28,    26,    60,    45,    19,
      46,    40,    44,    50,    71,    37,    30,    25,    71,    37,
      57,    35,     5,    37,    38,    39,    27,    37,    37,    43,
      13,    14,    15,    16,    17,    18,    19,    74,    75,    29,
      77,    78,    79,    21,    97,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    23,    24,    25,
      11,    97,    19,    37,    12,   102,    37,    20,   125,     3,
      11,    37,   125,   130,   127,   132,    21,   130,    11,   132,
      11,    11,    11,   140,     3,     6,    21,   140,    37,    11,
      22,   127,   149,    19,   126,    12,   149,    11,   135,    21,
      22,    23,    24,    25,     4,    21,    12,    11,    30,    31,
     147,    33,    34,    35,    36,    37,    38,    39,    11,    41,
       3,    43,    32,    47,   126,    32,    -1,    47,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    11,    41,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    11,    41,    -1,    43,
      12,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    23,    24,    25,    -1,    30,    31,    11,    33,    34,
      35,    36,    37,    38,    39,    37,    41,    21,    43,    23,
      24,    25,    11,    12,    -1,    -1,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    11,    41,    -1,    43,
      -1,    30,    -1,    -1,    -1,    -1,    35,    -1,    37,    38,
      39,    -1,    -1,    -1,    43,    30,    -1,    -1,    -1,    -1,
      35,    -1,    37,    38,    39,     3,    -1,     5,    43,     7,
       8,     9,    10,    -1,    -1,    13,    14,    15,    16,    17,
      18,    19,     3,    -1,     5,    -1,     7,     8,     9,    10,
      -1,    -1,    13,    14,    15,    16,    17,    18,    19,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,     5,    -1,     7,     8,     9,    10,    -1,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    22,    23,    24,
      25,    26,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,     5,    37,     7,     8,     9,    10,    37,    12,    13,
      14,    15,    16,    17,    18,    19,     5,    -1,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,     5,    -1,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,     5,    -1,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,     5,    -1,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    13,    14,    15,    16,    17,    18,
      19,     5,    -1,    -1,    -1,     9,    10,    -1,    -1,    13,
      14,    15,    16,    17,    18,    19
  };

  const signed char
  parser::yystos_[] =
  {
       0,    28,    49,    50,    37,    51,     0,    21,    28,    52,
      26,    37,    27,    21,    40,    25,    60,    37,    29,    22,
      23,    24,    25,    26,    37,    53,    55,    56,    58,    59,
      63,    64,    21,    11,    56,    19,    37,    60,    12,    37,
      20,     3,    22,    21,    11,    11,    21,    30,    31,    33,
      34,    35,    36,    37,    38,    39,    41,    43,    45,    46,
      47,    48,    53,    54,    62,    12,    56,    57,    37,    45,
      62,    47,    55,    63,    11,    11,    45,    11,    19,    11,
      45,     5,     7,     8,     9,    10,    13,    14,    15,    16,
      17,    18,    19,     6,    22,    48,     3,    21,    37,    12,
      12,    22,    19,    11,    45,    45,     3,    45,    45,    45,
      37,    42,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    22,    47,     4,    21,    45,    12,
      12,    12,    12,    20,    12,    11,    20,     3,    22,    57,
      47,    20,    48,     3,    48,    12,    45,    61,    22,    32,
      12,    45,    48
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    44,    50,    49,    51,    51,    47,    47,    52,    52,
      60,    60,    59,    59,    58,    58,    53,    57,    57,    56,
      56,    55,    55,    55,    55,    64,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    54,    62,    62,    61,
      61,    46,    46,    63,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,    13,     0,     2,     1,     2,     5,     7,
       0,     2,     1,     1,     8,     9,     3,     2,     4,     1,
       1,     1,     1,     1,     1,     3,     4,     1,     3,     5,
       7,     5,     5,     4,     3,     2,     1,     5,     6,     1,
       2,     1,     4,     1,     3,     3,     3,     3,     3,     4,
       3,     5,     4,     2,     3,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\";\"", "\",\"", "\".\"",
  "\"=\"", "\"-\"", "\"+\"", "\"*\"", "\"/\"", "\"(\"", "\")\"", "\"==\"",
  "\"&&\"", "\"||\"", "\"<\"", "\">\"", "\"%\"", "\"[\"", "\"]\"", "\"{\"",
  "\"}\"", "\"int\"", "\"boolean\"", "\"void\"", "\"public\"",
  "\"static\"", "\"class\"", "\"main\"", "\"new\"", "\"if\"", "\"else\"",
  "\"print\"", "\"return\"", "\"this\"", "\"while\"", "\"identifier\"",
  "\"number\"", "\"bool\"", "\"extends\"", "\"assert\"", "\"length\"",
  "\"!\"", "$accept", "expr", "lvalue", "statements", "statement",
  "main_class", "program", "class_declarations", "class_declaration",
  "variable_declaration", "local_variable_declaration", "simple_type",
  "type", "formals", "method_declaration", "declaration", "declarations",
  "expressions", "method_invocation", "type_identifier", "array_type", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   217,   217,   225,   232,   233,   236,   237,   239,   242,
     248,   249,   252,   253,   256,   259,   264,   267,   268,   271,
     272,   275,   276,   277,   278,   282,   285,   286,   287,   288,
     289,   292,   293,   294,   295,   296,   300,   303,   304,   308,
     309,   312,   313,   316,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1959 "/home/egor/C_projects/mini-java-compiler/parser.cpp"

#line 345 "grammar/parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
