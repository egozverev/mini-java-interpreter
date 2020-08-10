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
#line 62 "grammar/parser.y"

    #include "grammar/driver.hh"
    #include "location.hh"
    #include "expressions/Expression.h"
    #include "expressions/NumberExpression.h"
    #include "expressions/PlainNumberExpression.h"
    #include "expressions/PlainBooleanExpression.h"
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
    #include "statements/IfStatement.h"
    #include "statements/IfElseStatement.h"


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

#line 90 "/home/egor/C_projects/mini-java-compiler/parser.cpp"


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
#line 181 "/home/egor/C_projects/mini-java-compiler/parser.cpp"


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
      case 33: // "bool"
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case 32: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 51: // class_declaration
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::ClassDeclaration>  > (YY_MOVE (that.value));
        break;

      case 50: // class_declarations
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::ClassDeclarationList>  > (YY_MOVE (that.value));
        break;

      case 44: // expr
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Expression>  > (YY_MOVE (that.value));
        break;

      case 45: // lvalue
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Lvalue>  > (YY_MOVE (that.value));
        break;

      case 48: // main_class
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::MainClass>  > (YY_MOVE (that.value));
        break;

      case 49: // program
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Program>  > (YY_MOVE (that.value));
        break;

      case 47: // statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Statement>  > (YY_MOVE (that.value));
        break;

      case 46: // statements
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::StatementList>  > (YY_MOVE (that.value));
        break;

      case 54: // simple_type
      case 55: // type
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Type>  > (YY_MOVE (that.value));
        break;

      case 52: // variable_declaration
      case 53: // local_variable_declaration
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::VariableDeclaration>  > (YY_MOVE (that.value));
        break;

      case 31: // "identifier"
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
      case 33: // "bool"
        value.move< bool > (YY_MOVE (that.value));
        break;

      case 32: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case 51: // class_declaration
        value.move< std::shared_ptr<ast::ClassDeclaration>  > (YY_MOVE (that.value));
        break;

      case 50: // class_declarations
        value.move< std::shared_ptr<ast::ClassDeclarationList>  > (YY_MOVE (that.value));
        break;

      case 44: // expr
        value.move< std::shared_ptr<ast::Expression>  > (YY_MOVE (that.value));
        break;

      case 45: // lvalue
        value.move< std::shared_ptr<ast::Lvalue>  > (YY_MOVE (that.value));
        break;

      case 48: // main_class
        value.move< std::shared_ptr<ast::MainClass>  > (YY_MOVE (that.value));
        break;

      case 49: // program
        value.move< std::shared_ptr<ast::Program>  > (YY_MOVE (that.value));
        break;

      case 47: // statement
        value.move< std::shared_ptr<ast::Statement>  > (YY_MOVE (that.value));
        break;

      case 46: // statements
        value.move< std::shared_ptr<ast::StatementList>  > (YY_MOVE (that.value));
        break;

      case 54: // simple_type
      case 55: // type
        value.move< std::shared_ptr<ast::Type>  > (YY_MOVE (that.value));
        break;

      case 52: // variable_declaration
      case 53: // local_variable_declaration
        value.move< std::shared_ptr<ast::VariableDeclaration>  > (YY_MOVE (that.value));
        break;

      case 31: // "identifier"
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
      case 33: // "bool"
        value.copy< bool > (that.value);
        break;

      case 32: // "number"
        value.copy< int > (that.value);
        break;

      case 51: // class_declaration
        value.copy< std::shared_ptr<ast::ClassDeclaration>  > (that.value);
        break;

      case 50: // class_declarations
        value.copy< std::shared_ptr<ast::ClassDeclarationList>  > (that.value);
        break;

      case 44: // expr
        value.copy< std::shared_ptr<ast::Expression>  > (that.value);
        break;

      case 45: // lvalue
        value.copy< std::shared_ptr<ast::Lvalue>  > (that.value);
        break;

      case 48: // main_class
        value.copy< std::shared_ptr<ast::MainClass>  > (that.value);
        break;

      case 49: // program
        value.copy< std::shared_ptr<ast::Program>  > (that.value);
        break;

      case 47: // statement
        value.copy< std::shared_ptr<ast::Statement>  > (that.value);
        break;

      case 46: // statements
        value.copy< std::shared_ptr<ast::StatementList>  > (that.value);
        break;

      case 54: // simple_type
      case 55: // type
        value.copy< std::shared_ptr<ast::Type>  > (that.value);
        break;

      case 52: // variable_declaration
      case 53: // local_variable_declaration
        value.copy< std::shared_ptr<ast::VariableDeclaration>  > (that.value);
        break;

      case 31: // "identifier"
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
      case 33: // "bool"
        value.move< bool > (that.value);
        break;

      case 32: // "number"
        value.move< int > (that.value);
        break;

      case 51: // class_declaration
        value.move< std::shared_ptr<ast::ClassDeclaration>  > (that.value);
        break;

      case 50: // class_declarations
        value.move< std::shared_ptr<ast::ClassDeclarationList>  > (that.value);
        break;

      case 44: // expr
        value.move< std::shared_ptr<ast::Expression>  > (that.value);
        break;

      case 45: // lvalue
        value.move< std::shared_ptr<ast::Lvalue>  > (that.value);
        break;

      case 48: // main_class
        value.move< std::shared_ptr<ast::MainClass>  > (that.value);
        break;

      case 49: // program
        value.move< std::shared_ptr<ast::Program>  > (that.value);
        break;

      case 47: // statement
        value.move< std::shared_ptr<ast::Statement>  > (that.value);
        break;

      case 46: // statements
        value.move< std::shared_ptr<ast::StatementList>  > (that.value);
        break;

      case 54: // simple_type
      case 55: // type
        value.move< std::shared_ptr<ast::Type>  > (that.value);
        break;

      case 52: // variable_declaration
      case 53: // local_variable_declaration
        value.move< std::shared_ptr<ast::VariableDeclaration>  > (that.value);
        break;

      case 31: // "identifier"
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
      case 33: // "bool"
        yylhs.value.emplace< bool > ();
        break;

      case 32: // "number"
        yylhs.value.emplace< int > ();
        break;

      case 51: // class_declaration
        yylhs.value.emplace< std::shared_ptr<ast::ClassDeclaration>  > ();
        break;

      case 50: // class_declarations
        yylhs.value.emplace< std::shared_ptr<ast::ClassDeclarationList>  > ();
        break;

      case 44: // expr
        yylhs.value.emplace< std::shared_ptr<ast::Expression>  > ();
        break;

      case 45: // lvalue
        yylhs.value.emplace< std::shared_ptr<ast::Lvalue>  > ();
        break;

      case 48: // main_class
        yylhs.value.emplace< std::shared_ptr<ast::MainClass>  > ();
        break;

      case 49: // program
        yylhs.value.emplace< std::shared_ptr<ast::Program>  > ();
        break;

      case 47: // statement
        yylhs.value.emplace< std::shared_ptr<ast::Statement>  > ();
        break;

      case 46: // statements
        yylhs.value.emplace< std::shared_ptr<ast::StatementList>  > ();
        break;

      case 54: // simple_type
      case 55: // type
        yylhs.value.emplace< std::shared_ptr<ast::Type>  > ();
        break;

      case 52: // variable_declaration
      case 53: // local_variable_declaration
        yylhs.value.emplace< std::shared_ptr<ast::VariableDeclaration>  > ();
        break;

      case 31: // "identifier"
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
#line 177 "grammar/parser.y"
{
    yylhs.value.as < std::shared_ptr<ast::Program>  > () = std::make_shared<ast::Program>(yystack_[1].value.as < std::shared_ptr<ast::MainClass>  > (), yystack_[0].value.as < std::shared_ptr<ast::ClassDeclarationList>  > ());
    driver.program = yylhs.value.as < std::shared_ptr<ast::Program>  > ();

}
#line 883 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 3:
#line 185 "grammar/parser.y"
{
    yylhs.value.as < std::shared_ptr<ast::MainClass>  > () = std::make_shared<ast::MainClass>(yystack_[2].value.as < std::shared_ptr<ast::StatementList>  > ());
}
#line 891 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 4:
#line 191 "grammar/parser.y"
        {yylhs.value.as < std::shared_ptr<ast::ClassDeclarationList>  > () = std::make_shared<ast::ClassDeclarationList>();}
#line 897 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 5:
#line 192 "grammar/parser.y"
                                        {yystack_[1].value.as < std::shared_ptr<ast::ClassDeclarationList>  > () -> AddDeclaration(yystack_[0].value.as < std::shared_ptr<ast::ClassDeclaration>  > ()); yylhs.value.as < std::shared_ptr<ast::ClassDeclarationList>  > () = yystack_[1].value.as < std::shared_ptr<ast::ClassDeclarationList>  > ();}
#line 903 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 6:
#line 195 "grammar/parser.y"
           {yylhs.value.as < std::shared_ptr<ast::StatementList>  > () = std::make_shared<ast::StatementList>(); yylhs.value.as < std::shared_ptr<ast::StatementList>  > () -> AddStatement(yystack_[0].value.as < std::shared_ptr<ast::Statement>  > ());}
#line 909 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 7:
#line 196 "grammar/parser.y"
                        {yystack_[1].value.as < std::shared_ptr<ast::StatementList>  > () -> AddStatement(yystack_[0].value.as < std::shared_ptr<ast::Statement>  > ()); yylhs.value.as < std::shared_ptr<ast::StatementList>  > () = yystack_[1].value.as < std::shared_ptr<ast::StatementList>  > ();}
#line 915 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 8:
#line 198 "grammar/parser.y"
                                                                  {yylhs.value.as < std::shared_ptr<ast::ClassDeclaration>  > () = std::make_shared<ast::ClassDeclaration>();}
#line 921 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 9:
#line 199 "grammar/parser.y"
                                                                               {}
#line 927 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 10:
#line 202 "grammar/parser.y"
           {}
#line 933 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 11:
#line 203 "grammar/parser.y"
                               {}
#line 939 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 12:
#line 206 "grammar/parser.y"
                         {}
#line 945 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 13:
#line 207 "grammar/parser.y"
                         {}
#line 951 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 14:
#line 210 "grammar/parser.y"
                                                          {}
#line 957 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 15:
#line 211 "grammar/parser.y"
                                                                    {}
#line 963 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 16:
#line 213 "grammar/parser.y"
                                             {yylhs.value.as < std::shared_ptr<ast::VariableDeclaration>  > () = std::make_shared<ast::VariableDeclaration>(yystack_[1].value.as < std::string > (), yystack_[2].value.as < std::shared_ptr<ast::Type>  > ());}
#line 969 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 17:
#line 216 "grammar/parser.y"
                      {}
#line 975 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 18:
#line 217 "grammar/parser.y"
                                {}
#line 981 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 19:
#line 220 "grammar/parser.y"
                {yylhs.value.as < std::shared_ptr<ast::Type>  > () = yystack_[0].value.as < std::shared_ptr<ast::Type>  > ();}
#line 987 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 20:
#line 221 "grammar/parser.y"
                 {}
#line 993 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 21:
#line 224 "grammar/parser.y"
              {yylhs.value.as < std::shared_ptr<ast::Type>  > () = std::make_shared<ast::Boolean>();}
#line 999 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 22:
#line 225 "grammar/parser.y"
            {yylhs.value.as < std::shared_ptr<ast::Type>  > () = std::make_shared<ast::Integer>();}
#line 1005 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 23:
#line 226 "grammar/parser.y"
             {yylhs.value.as < std::shared_ptr<ast::Type>  > () = std::make_shared<ast::Void>();}
#line 1011 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 24:
#line 227 "grammar/parser.y"
                      {yylhs.value.as < std::shared_ptr<ast::Type>  > () = std::make_shared<ast::UserType>();}
#line 1017 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 25:
#line 231 "grammar/parser.y"
                        {}
#line 1023 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 26:
#line 234 "grammar/parser.y"
                                      {}
#line 1029 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 27:
#line 235 "grammar/parser.y"
                                 {yylhs.value.as < std::shared_ptr<ast::Statement>  > () = yystack_[0].value.as < std::shared_ptr<ast::VariableDeclaration>  > ();}
#line 1035 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 28:
#line 236 "grammar/parser.y"
                         {yylhs.value.as < std::shared_ptr<ast::Statement>  > () = yystack_[1].value.as < std::shared_ptr<ast::StatementList>  > ();}
#line 1041 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 29:
#line 237 "grammar/parser.y"
                                   {yylhs.value.as < std::shared_ptr<ast::Statement>  > () = std::make_shared<ast::IfStatement>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Statement>  > ());}
#line 1047 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 30:
#line 238 "grammar/parser.y"
                                                    {
    yylhs.value.as < std::shared_ptr<ast::Statement>  > () = std::make_shared<ast::IfElseStatement>(yystack_[4].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[2].value.as < std::shared_ptr<ast::Statement>  > (), yystack_[0].value.as < std::shared_ptr<ast::Statement>  > ());
    }
#line 1055 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 31:
#line 241 "grammar/parser.y"
                                     {}
#line 1061 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 32:
#line 242 "grammar/parser.y"
                              {yylhs.value.as < std::shared_ptr<ast::Statement>  > () = std::make_shared<ast::PrintStatement>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1067 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 33:
#line 243 "grammar/parser.y"
                          {yylhs.value.as < std::shared_ptr<ast::Statement>  > () = std::make_shared<ast::Assignment>(yystack_[3].value.as < std::shared_ptr<ast::Lvalue>  > (), driver, yystack_[1].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1073 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 34:
#line 244 "grammar/parser.y"
                        {}
#line 1079 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 35:
#line 245 "grammar/parser.y"
                            {}
#line 1085 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 36:
#line 249 "grammar/parser.y"
                         {yylhs.value.as < std::shared_ptr<ast::VariableDeclaration>  > () = yystack_[0].value.as < std::shared_ptr<ast::VariableDeclaration>  > ();}
#line 1091 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 39:
#line 256 "grammar/parser.y"
         {}
#line 1097 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 40:
#line 257 "grammar/parser.y"
                       {}
#line 1103 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 41:
#line 260 "grammar/parser.y"
                 {yylhs.value.as < std::shared_ptr<ast::Lvalue>  > () = std::make_shared<ast::PlainIdent>(yystack_[0].value.as < std::string > ());}
#line 1109 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 42:
#line 261 "grammar/parser.y"
                                {}
#line 1115 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 43:
#line 264 "grammar/parser.y"
                 {}
#line 1121 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 44:
#line 267 "grammar/parser.y"
                  {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::AddExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1127 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 45:
#line 268 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::SubstractExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1133 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 46:
#line 269 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::MulExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1139 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 47:
#line 270 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::DivExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1145 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 48:
#line 271 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::ModExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1151 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 49:
#line 272 "grammar/parser.y"
                        {}
#line 1157 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 50:
#line 273 "grammar/parser.y"
                        {}
#line 1163 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 51:
#line 274 "grammar/parser.y"
                                     {}
#line 1169 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 52:
#line 275 "grammar/parser.y"
                                    {}
#line 1175 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 53:
#line 276 "grammar/parser.y"
               {}
#line 1181 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 54:
#line 277 "grammar/parser.y"
                   {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = yystack_[1].value.as < std::shared_ptr<ast::Expression>  > ();}
#line 1187 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 55:
#line 278 "grammar/parser.y"
                   {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::IdentExpression> (yystack_[0].value.as < std::string > (), driver);}
#line 1193 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 56:
#line 279 "grammar/parser.y"
               {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::PlainNumberExpression> (yystack_[0].value.as < int > ());}
#line 1199 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 57:
#line 280 "grammar/parser.y"
             {}
#line 1205 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 58:
#line 281 "grammar/parser.y"
             {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::PlainBooleanExpression> (yystack_[0].value.as < bool > ());}
#line 1211 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 59:
#line 284 "grammar/parser.y"
                        {}
#line 1217 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 60:
#line 285 "grammar/parser.y"
                     {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::AndExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1223 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 61:
#line 286 "grammar/parser.y"
                     {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::OrExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1229 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 62:
#line 287 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::LessExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1235 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 63:
#line 288 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::GreaterExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1241 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 64:
#line 289 "grammar/parser.y"
                     {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::EqualExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1247 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;


#line 1251 "/home/egor/C_projects/mini-java-compiler/parser.cpp"

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


  const signed char parser::yypact_ninf_ = -60;

  const signed char parser::yytable_ninf_ = -44;

  const short
  parser::yypact_[] =
  {
     -13,    -7,   -60,    26,     9,    31,   -60,    34,    41,   -60,
      48,   -12,    53,    44,   -60,    52,    49,    43,    72,    65,
     -60,   -60,   -60,   -60,    38,   -60,   -60,    68,    57,   -60,
     -60,   -60,   -60,    79,    89,    78,   104,   115,   105,   -60,
     114,   -60,   -60,   252,   416,    -2,     0,   252,   116,   118,
       8,   -60,   -60,   123,   138,     0,    38,     0,   -60,   404,
     133,   152,   -60,   -60,   -60,   149,   -60,   134,   131,   153,
     -60,   290,   -60,   177,     0,     0,     0,     0,     0,   128,
     147,   156,   404,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -28,     0,   148,   -60,   -60,   252,
      38,   150,   -60,   -60,   303,   319,   332,   348,   361,   -60,
       0,   157,   418,   418,   100,   100,   404,   404,   404,   404,
     404,   404,   376,   161,   -60,   143,   -60,   202,   -60,   252,
     252,   173,   -60,   -60,   252,   390,   -60,   -60,     6,   -60,
     -60,   227,   162,   -60,   -60,   -60,   -60,     0,   -60,   252,
      88,   159,   -60,   -60,   168,   -60
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     4,     0,     0,     2,     1,     0,     0,     5,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
       8,    22,    21,    23,     0,    43,    12,    19,     0,    11,
      13,    20,    24,     0,     0,     0,     0,     0,     0,    10,
       0,    25,    16,     0,     0,     0,     0,     0,     0,     0,
      55,    56,    58,     0,     0,     0,     0,     0,    57,     0,
       0,     0,     6,    36,    27,    59,     9,     0,     0,     0,
      55,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,    24,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,    35,     0,
      17,     0,    54,    28,     0,     0,     0,     0,     0,    34,
       0,     0,    45,    44,    46,    47,    64,    60,    61,    62,
      63,    48,     0,     0,    50,     0,     3,     0,    18,     0,
       0,     0,    42,    26,     0,     0,    52,    49,     0,    33,
      14,     0,    29,    32,    31,    51,    37,     0,    15,     0,
      39,     0,    30,    40,     0,    38
  };

  const short
  parser::yypgoto_[] =
  {
     -60,   -40,   -60,   -37,   -59,   -60,   -60,   -60,   -60,    10,
     -60,   139,   -23,   140,   -60,   -60,    90,   -60,   -43,    51,
     146
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    59,    60,    61,    62,     2,     3,     5,     9,    63,
      64,    27,    28,    17,    29,    30,    69,    31,    72,   151,
      32
  };

  const short
  parser::yytable_[] =
  {
      65,    35,    97,   123,    65,    13,    71,    14,    67,    46,
      73,   124,   -41,     1,    97,    79,   146,    82,    65,    21,
      22,    23,    68,   147,     4,    76,     6,    26,     7,    25,
      65,    70,    51,    52,   104,   105,   106,   107,   108,   -43,
      56,    57,    58,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    26,   125,    65,     8,    10,    21,
      22,    23,   127,    20,    21,    22,    23,    24,    97,    25,
     135,   142,    11,    12,    25,   144,    15,    68,    16,    18,
      19,    33,    97,    34,    65,    36,    65,    65,    37,    38,
     152,    65,   141,    83,    84,    85,    86,    46,    65,    87,
      88,    89,    90,    91,    92,    93,    65,   150,    39,    40,
     150,    87,    88,    89,    90,    91,    92,    93,    42,    70,
      51,    52,    41,    45,    43,    74,    94,    75,    56,    57,
      58,   109,    77,    83,    84,    85,    86,    95,    94,    87,
      88,    89,    90,    91,    92,    93,   139,    78,    83,    84,
      85,    86,    98,    99,    87,    88,    89,    90,    91,    92,
      93,    46,   100,   101,   110,   111,    94,   136,   126,   129,
     138,    47,    96,    21,    22,    23,   143,   154,   155,    44,
      48,    94,    49,    50,    51,    52,    46,    53,    54,    55,
     128,   149,    56,    57,    58,    80,    47,   103,    21,    22,
      23,   153,    81,     0,     0,    48,     0,    49,    50,    51,
      52,    46,    53,    54,    55,     0,     0,    56,    57,    58,
       0,    47,   140,    21,    22,    23,     0,     0,     0,     0,
      48,     0,    49,    50,    51,    52,    46,    53,    54,    55,
       0,     0,    56,    57,    58,     0,    47,   148,    21,    22,
      23,     0,     0,     0,     0,    48,     0,    49,    50,    51,
      52,    46,    53,    54,    55,     0,     0,    56,    57,    58,
       0,    47,     0,    21,    22,    23,     0,     0,     0,     0,
      48,     0,    49,    50,    51,    52,     0,    53,    54,    55,
       0,     0,    56,    57,    58,    83,    84,    85,    86,     0,
     102,    87,    88,    89,    90,    91,    92,    93,    83,    84,
      85,    86,     0,   130,    87,    88,    89,    90,    91,    92,
      93,     0,     0,     0,    83,    84,    85,    86,    94,   131,
      87,    88,    89,    90,    91,    92,    93,    83,    84,    85,
      86,    94,     0,    87,    88,    89,    90,    91,    92,    93,
     132,     0,     0,    83,    84,    85,    86,    94,   133,    87,
      88,    89,    90,    91,    92,    93,    83,    84,    85,    86,
      94,   134,    87,    88,    89,    90,    91,    92,    93,     0,
       0,    83,    84,    85,    86,     0,    94,    87,    88,    89,
      90,    91,    92,    93,   137,    83,    84,    85,    86,    94,
       0,    87,    88,    89,    90,    91,    92,    93,   145,    83,
      84,    85,    86,     0,    94,    87,    88,    89,    90,    91,
      92,    93,     0,     0,     0,    85,    86,     0,    94,    87,
      88,    89,    90,    91,    92,    93,    66,    21,    22,    23,
      24,     0,    94,     0,     0,     0,     0,    25,     0,     0,
       0,     0,     0,     0,     0,     0,    94
  };

  const short
  parser::yycheck_[] =
  {
      43,    24,    61,    31,    47,    17,    46,    19,    10,     9,
      47,    39,     4,    26,    73,    55,    10,    57,    61,    21,
      22,    23,    45,    17,    31,    17,     0,    17,    19,    31,
      73,    31,    32,    33,    74,    75,    76,    77,    78,    31,
      40,    41,    42,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    44,    95,    99,    26,    24,    21,
      22,    23,    99,    20,    21,    22,    23,    24,   127,    31,
     110,   130,    31,    25,    31,   134,    23,   100,    34,    27,
      31,     9,   141,    18,   127,    17,   129,   130,    31,    10,
     149,   134,   129,     5,     6,     7,     8,     9,   141,    11,
      12,    13,    14,    15,    16,    17,   149,   147,    19,    31,
     150,    11,    12,    13,    14,    15,    16,    17,     3,    31,
      32,    33,    18,     9,    19,     9,    38,     9,    40,    41,
      42,     3,     9,     5,     6,     7,     8,     4,    38,    11,
      12,    13,    14,    15,    16,    17,     3,     9,     5,     6,
       7,     8,     3,    19,    11,    12,    13,    14,    15,    16,
      17,     9,    31,    10,    17,     9,    38,    10,    20,    19,
       9,    19,    20,    21,    22,    23,     3,    18,    10,    39,
      28,    38,    30,    31,    32,    33,     9,    35,    36,    37,
     100,    29,    40,    41,    42,    56,    19,    20,    21,    22,
      23,   150,    56,    -1,    -1,    28,    -1,    30,    31,    32,
      33,     9,    35,    36,    37,    -1,    -1,    40,    41,    42,
      -1,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      28,    -1,    30,    31,    32,    33,     9,    35,    36,    37,
      -1,    -1,    40,    41,    42,    -1,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    28,    -1,    30,    31,    32,
      33,     9,    35,    36,    37,    -1,    -1,    40,    41,    42,
      -1,    19,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,
      28,    -1,    30,    31,    32,    33,    -1,    35,    36,    37,
      -1,    -1,    40,    41,    42,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,     5,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,     5,     6,     7,     8,    38,    10,
      11,    12,    13,    14,    15,    16,    17,     5,     6,     7,
       8,    38,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,     5,     6,     7,     8,    38,    10,    11,
      12,    13,    14,    15,    16,    17,     5,     6,     7,     8,
      38,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,     5,     6,     7,     8,    -1,    38,    11,    12,    13,
      14,    15,    16,    17,    18,     5,     6,     7,     8,    38,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,     5,
       6,     7,     8,    -1,    38,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    -1,     7,     8,    -1,    38,    11,
      12,    13,    14,    15,    16,    17,    20,    21,    22,    23,
      24,    -1,    38,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38
  };

  const signed char
  parser::yystos_[] =
  {
       0,    26,    48,    49,    31,    50,     0,    19,    26,    51,
      24,    31,    25,    17,    19,    23,    34,    56,    27,    31,
      20,    21,    22,    23,    24,    31,    52,    54,    55,    57,
      58,    60,    63,     9,    18,    55,    17,    31,    10,    19,
      31,    18,     3,    19,    56,     9,     9,    19,    28,    30,
      31,    32,    33,    35,    36,    37,    40,    41,    42,    44,
      45,    46,    47,    52,    53,    61,    20,    10,    55,    59,
      31,    44,    61,    46,     9,     9,    17,     9,     9,    44,
      54,    63,    44,     5,     6,     7,     8,    11,    12,    13,
      14,    15,    16,    17,    38,     4,    20,    47,     3,    19,
      31,    10,    10,    20,    44,    44,    44,    44,    44,     3,
      17,     9,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    31,    39,    44,    20,    46,    59,    19,
      10,    10,    18,    10,    10,    44,    10,    18,     9,     3,
      20,    46,    47,     3,    47,    18,    10,    17,    20,    29,
      44,    62,    47,    62,    18,    10
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    43,    49,    48,    50,    50,    46,    46,    51,    51,
      56,    56,    57,    57,    58,    58,    52,    59,    59,    55,
      55,    54,    54,    54,    54,    60,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    53,    61,    61,    62,
      62,    45,    45,    63,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,    13,     0,     2,     1,     2,     5,     9,
       0,     2,     1,     1,     8,     9,     3,     2,     3,     1,
       1,     1,     1,     1,     1,     3,     4,     1,     3,     5,
       7,     5,     5,     4,     3,     2,     1,     5,     8,     1,
       2,     1,     4,     1,     3,     3,     3,     3,     3,     4,
       3,     5,     4,     2,     3,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\";\"", "\"=\"", "\"-\"",
  "\"+\"", "\"*\"", "\"/\"", "\"(\"", "\")\"", "\"==\"", "\"&&\"",
  "\"||\"", "\"<\"", "\">\"", "\"%\"", "\"[\"", "\"]\"", "\"{\"", "\"}\"",
  "\"int\"", "\"boolean\"", "\"void\"", "\"public\"", "\"static\"",
  "\"class\"", "\"main\"", "\"if\"", "\"else\"", "\"print\"",
  "\"identifier\"", "\"number\"", "\"bool\"", "\"extends\"", "\"assert\"",
  "\"while\"", "\"return\"", "\".\"", "\"length\"", "\"new\"", "\"!\"",
  "\"this\"", "$accept", "expr", "lvalue", "statements", "statement",
  "main_class", "program", "class_declarations", "class_declaration",
  "variable_declaration", "local_variable_declaration", "simple_type",
  "type", "declarations", "declaration", "method_declaration", "formals",
  "array_type", "method_invocation", "expressions", "type_identifier", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   176,   176,   184,   191,   192,   195,   196,   198,   199,
     202,   203,   206,   207,   210,   211,   213,   216,   217,   220,
     221,   224,   225,   226,   227,   231,   234,   235,   236,   237,
     238,   241,   242,   243,   244,   245,   249,   252,   253,   256,
     257,   260,   261,   264,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   284,
     285,   286,   287,   288,   289
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
#line 1796 "/home/egor/C_projects/mini-java-compiler/parser.cpp"

#line 295 "grammar/parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
