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
#line 60 "grammar/parser.y"

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

#line 87 "/home/egor/C_projects/mini-java-compiler/parser.cpp"


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
#line 178 "/home/egor/C_projects/mini-java-compiler/parser.cpp"


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
      case 31: // "bool"
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case 30: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 53: // class_declaration
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::ClassDeclaration>  > (YY_MOVE (that.value));
        break;

      case 52: // class_declarations
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::ClassDeclarationList>  > (YY_MOVE (that.value));
        break;

      case 46: // expr
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Expression>  > (YY_MOVE (that.value));
        break;

      case 47: // lvalue
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Lvalue>  > (YY_MOVE (that.value));
        break;

      case 50: // main_class
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::MainClass>  > (YY_MOVE (that.value));
        break;

      case 51: // program
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Program>  > (YY_MOVE (that.value));
        break;

      case 49: // statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Statement>  > (YY_MOVE (that.value));
        break;

      case 48: // statements
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::StatementList>  > (YY_MOVE (that.value));
        break;

      case 56: // simple_type
      case 57: // type
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Type>  > (YY_MOVE (that.value));
        break;

      case 54: // variable_declaration
      case 55: // local_variable_declaration
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::VariableDeclaration>  > (YY_MOVE (that.value));
        break;

      case 29: // "identifier"
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
      case 31: // "bool"
        value.move< bool > (YY_MOVE (that.value));
        break;

      case 30: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case 53: // class_declaration
        value.move< std::shared_ptr<ast::ClassDeclaration>  > (YY_MOVE (that.value));
        break;

      case 52: // class_declarations
        value.move< std::shared_ptr<ast::ClassDeclarationList>  > (YY_MOVE (that.value));
        break;

      case 46: // expr
        value.move< std::shared_ptr<ast::Expression>  > (YY_MOVE (that.value));
        break;

      case 47: // lvalue
        value.move< std::shared_ptr<ast::Lvalue>  > (YY_MOVE (that.value));
        break;

      case 50: // main_class
        value.move< std::shared_ptr<ast::MainClass>  > (YY_MOVE (that.value));
        break;

      case 51: // program
        value.move< std::shared_ptr<ast::Program>  > (YY_MOVE (that.value));
        break;

      case 49: // statement
        value.move< std::shared_ptr<ast::Statement>  > (YY_MOVE (that.value));
        break;

      case 48: // statements
        value.move< std::shared_ptr<ast::StatementList>  > (YY_MOVE (that.value));
        break;

      case 56: // simple_type
      case 57: // type
        value.move< std::shared_ptr<ast::Type>  > (YY_MOVE (that.value));
        break;

      case 54: // variable_declaration
      case 55: // local_variable_declaration
        value.move< std::shared_ptr<ast::VariableDeclaration>  > (YY_MOVE (that.value));
        break;

      case 29: // "identifier"
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
      case 31: // "bool"
        value.copy< bool > (that.value);
        break;

      case 30: // "number"
        value.copy< int > (that.value);
        break;

      case 53: // class_declaration
        value.copy< std::shared_ptr<ast::ClassDeclaration>  > (that.value);
        break;

      case 52: // class_declarations
        value.copy< std::shared_ptr<ast::ClassDeclarationList>  > (that.value);
        break;

      case 46: // expr
        value.copy< std::shared_ptr<ast::Expression>  > (that.value);
        break;

      case 47: // lvalue
        value.copy< std::shared_ptr<ast::Lvalue>  > (that.value);
        break;

      case 50: // main_class
        value.copy< std::shared_ptr<ast::MainClass>  > (that.value);
        break;

      case 51: // program
        value.copy< std::shared_ptr<ast::Program>  > (that.value);
        break;

      case 49: // statement
        value.copy< std::shared_ptr<ast::Statement>  > (that.value);
        break;

      case 48: // statements
        value.copy< std::shared_ptr<ast::StatementList>  > (that.value);
        break;

      case 56: // simple_type
      case 57: // type
        value.copy< std::shared_ptr<ast::Type>  > (that.value);
        break;

      case 54: // variable_declaration
      case 55: // local_variable_declaration
        value.copy< std::shared_ptr<ast::VariableDeclaration>  > (that.value);
        break;

      case 29: // "identifier"
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
      case 31: // "bool"
        value.move< bool > (that.value);
        break;

      case 30: // "number"
        value.move< int > (that.value);
        break;

      case 53: // class_declaration
        value.move< std::shared_ptr<ast::ClassDeclaration>  > (that.value);
        break;

      case 52: // class_declarations
        value.move< std::shared_ptr<ast::ClassDeclarationList>  > (that.value);
        break;

      case 46: // expr
        value.move< std::shared_ptr<ast::Expression>  > (that.value);
        break;

      case 47: // lvalue
        value.move< std::shared_ptr<ast::Lvalue>  > (that.value);
        break;

      case 50: // main_class
        value.move< std::shared_ptr<ast::MainClass>  > (that.value);
        break;

      case 51: // program
        value.move< std::shared_ptr<ast::Program>  > (that.value);
        break;

      case 49: // statement
        value.move< std::shared_ptr<ast::Statement>  > (that.value);
        break;

      case 48: // statements
        value.move< std::shared_ptr<ast::StatementList>  > (that.value);
        break;

      case 56: // simple_type
      case 57: // type
        value.move< std::shared_ptr<ast::Type>  > (that.value);
        break;

      case 54: // variable_declaration
      case 55: // local_variable_declaration
        value.move< std::shared_ptr<ast::VariableDeclaration>  > (that.value);
        break;

      case 29: // "identifier"
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
      case 31: // "bool"
        yylhs.value.emplace< bool > ();
        break;

      case 30: // "number"
        yylhs.value.emplace< int > ();
        break;

      case 53: // class_declaration
        yylhs.value.emplace< std::shared_ptr<ast::ClassDeclaration>  > ();
        break;

      case 52: // class_declarations
        yylhs.value.emplace< std::shared_ptr<ast::ClassDeclarationList>  > ();
        break;

      case 46: // expr
        yylhs.value.emplace< std::shared_ptr<ast::Expression>  > ();
        break;

      case 47: // lvalue
        yylhs.value.emplace< std::shared_ptr<ast::Lvalue>  > ();
        break;

      case 50: // main_class
        yylhs.value.emplace< std::shared_ptr<ast::MainClass>  > ();
        break;

      case 51: // program
        yylhs.value.emplace< std::shared_ptr<ast::Program>  > ();
        break;

      case 49: // statement
        yylhs.value.emplace< std::shared_ptr<ast::Statement>  > ();
        break;

      case 48: // statements
        yylhs.value.emplace< std::shared_ptr<ast::StatementList>  > ();
        break;

      case 56: // simple_type
      case 57: // type
        yylhs.value.emplace< std::shared_ptr<ast::Type>  > ();
        break;

      case 54: // variable_declaration
      case 55: // local_variable_declaration
        yylhs.value.emplace< std::shared_ptr<ast::VariableDeclaration>  > ();
        break;

      case 29: // "identifier"
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
#line 170 "grammar/parser.y"
{
    yylhs.value.as < std::shared_ptr<ast::Program>  > () = std::make_shared<ast::Program>(yystack_[1].value.as < std::shared_ptr<ast::MainClass>  > (), yystack_[0].value.as < std::shared_ptr<ast::ClassDeclarationList>  > ());
    driver.program = yylhs.value.as < std::shared_ptr<ast::Program>  > ();

}
#line 880 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 3:
#line 178 "grammar/parser.y"
{
    yylhs.value.as < std::shared_ptr<ast::MainClass>  > () = std::make_shared<ast::MainClass>(yystack_[2].value.as < std::shared_ptr<ast::StatementList>  > ());
}
#line 888 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 4:
#line 184 "grammar/parser.y"
        {yylhs.value.as < std::shared_ptr<ast::ClassDeclarationList>  > () = std::make_shared<ast::ClassDeclarationList>();}
#line 894 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 5:
#line 185 "grammar/parser.y"
                                        {yystack_[1].value.as < std::shared_ptr<ast::ClassDeclarationList>  > () -> AddDeclaration(yystack_[0].value.as < std::shared_ptr<ast::ClassDeclaration>  > ()); yylhs.value.as < std::shared_ptr<ast::ClassDeclarationList>  > () = yystack_[1].value.as < std::shared_ptr<ast::ClassDeclarationList>  > ();}
#line 900 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 6:
#line 188 "grammar/parser.y"
           {yylhs.value.as < std::shared_ptr<ast::StatementList>  > () = std::make_shared<ast::StatementList>(); yylhs.value.as < std::shared_ptr<ast::StatementList>  > () -> AddStatement(yystack_[0].value.as < std::shared_ptr<ast::Statement>  > ());}
#line 906 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 7:
#line 189 "grammar/parser.y"
                        {yystack_[1].value.as < std::shared_ptr<ast::StatementList>  > () -> AddStatement(yystack_[0].value.as < std::shared_ptr<ast::Statement>  > ()); yylhs.value.as < std::shared_ptr<ast::StatementList>  > () = yystack_[1].value.as < std::shared_ptr<ast::StatementList>  > ();}
#line 912 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 8:
#line 191 "grammar/parser.y"
                                                                  {yylhs.value.as < std::shared_ptr<ast::ClassDeclaration>  > () = std::make_shared<ast::ClassDeclaration>();}
#line 918 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 9:
#line 192 "grammar/parser.y"
                                                                               {}
#line 924 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 10:
#line 195 "grammar/parser.y"
           {}
#line 930 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 11:
#line 196 "grammar/parser.y"
                               {}
#line 936 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 12:
#line 199 "grammar/parser.y"
                         {}
#line 942 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 13:
#line 200 "grammar/parser.y"
                         {}
#line 948 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 14:
#line 203 "grammar/parser.y"
                                                          {}
#line 954 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 15:
#line 204 "grammar/parser.y"
                                                                    {}
#line 960 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 16:
#line 206 "grammar/parser.y"
                                             {yylhs.value.as < std::shared_ptr<ast::VariableDeclaration>  > () = std::make_shared<ast::VariableDeclaration>(yystack_[1].value.as < std::string > (), yystack_[2].value.as < std::shared_ptr<ast::Type>  > ());}
#line 966 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 17:
#line 209 "grammar/parser.y"
                      {}
#line 972 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 18:
#line 210 "grammar/parser.y"
                                {}
#line 978 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 19:
#line 213 "grammar/parser.y"
                {}
#line 984 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 20:
#line 214 "grammar/parser.y"
                 {}
#line 990 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 21:
#line 217 "grammar/parser.y"
              {yylhs.value.as < std::shared_ptr<ast::Type>  > () = std::make_shared<ast::Boolean>();}
#line 996 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 22:
#line 218 "grammar/parser.y"
            {yylhs.value.as < std::shared_ptr<ast::Type>  > () = std::make_shared<ast::Integer>();}
#line 1002 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 23:
#line 219 "grammar/parser.y"
             {yylhs.value.as < std::shared_ptr<ast::Type>  > () = std::make_shared<ast::Void>();}
#line 1008 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 24:
#line 220 "grammar/parser.y"
                      {yylhs.value.as < std::shared_ptr<ast::Type>  > () = std::make_shared<ast::UserType>();}
#line 1014 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 25:
#line 224 "grammar/parser.y"
                        {}
#line 1020 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 26:
#line 227 "grammar/parser.y"
                                      {}
#line 1026 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 27:
#line 228 "grammar/parser.y"
                                 {yylhs.value.as < std::shared_ptr<ast::Statement>  > () = yystack_[0].value.as < std::shared_ptr<ast::VariableDeclaration>  > ();}
#line 1032 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 28:
#line 229 "grammar/parser.y"
                         {yylhs.value.as < std::shared_ptr<ast::Statement>  > () = yystack_[1].value.as < std::shared_ptr<ast::StatementList>  > ();}
#line 1038 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 29:
#line 230 "grammar/parser.y"
                                   {}
#line 1044 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 30:
#line 231 "grammar/parser.y"
                                                    {}
#line 1050 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 31:
#line 232 "grammar/parser.y"
                                     {}
#line 1056 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 32:
#line 233 "grammar/parser.y"
                              {yylhs.value.as < std::shared_ptr<ast::Statement>  > () = std::make_shared<ast::PrintStatement>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1062 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 33:
#line 234 "grammar/parser.y"
                          {yylhs.value.as < std::shared_ptr<ast::Statement>  > () = std::make_shared<ast::Assignment>(yystack_[3].value.as < std::shared_ptr<ast::Lvalue>  > (), driver, yystack_[1].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1068 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 34:
#line 235 "grammar/parser.y"
                        {}
#line 1074 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 35:
#line 236 "grammar/parser.y"
                            {}
#line 1080 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 36:
#line 240 "grammar/parser.y"
                         {yylhs.value.as < std::shared_ptr<ast::VariableDeclaration>  > () = yystack_[0].value.as < std::shared_ptr<ast::VariableDeclaration>  > ();}
#line 1086 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 39:
#line 247 "grammar/parser.y"
         {}
#line 1092 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 40:
#line 248 "grammar/parser.y"
                       {}
#line 1098 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 41:
#line 251 "grammar/parser.y"
                 {yylhs.value.as < std::shared_ptr<ast::Lvalue>  > () = std::make_shared<ast::PlainIdent>(yystack_[0].value.as < std::string > ());}
#line 1104 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 42:
#line 252 "grammar/parser.y"
                                {}
#line 1110 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 43:
#line 255 "grammar/parser.y"
                 {}
#line 1116 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 44:
#line 258 "grammar/parser.y"
                  {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::AddExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1122 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 45:
#line 259 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::SubstractExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1128 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 46:
#line 260 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::MulExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1134 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 47:
#line 261 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::DivExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1140 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 48:
#line 262 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::ModExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1146 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 49:
#line 263 "grammar/parser.y"
                        {}
#line 1152 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 50:
#line 264 "grammar/parser.y"
                        {}
#line 1158 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 51:
#line 265 "grammar/parser.y"
                                     {}
#line 1164 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 52:
#line 266 "grammar/parser.y"
                                    {}
#line 1170 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 53:
#line 267 "grammar/parser.y"
               {}
#line 1176 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 54:
#line 268 "grammar/parser.y"
                   {}
#line 1182 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 55:
#line 269 "grammar/parser.y"
                   {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::IdentExpression> (yystack_[0].value.as < std::string > (), driver);}
#line 1188 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 56:
#line 270 "grammar/parser.y"
               {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::PlainNumberExpression> (yystack_[0].value.as < int > ());}
#line 1194 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 57:
#line 271 "grammar/parser.y"
             {}
#line 1200 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 58:
#line 272 "grammar/parser.y"
             {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::PlainBooleanExpression> (true);}
#line 1206 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 59:
#line 273 "grammar/parser.y"
              {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::PlainBooleanExpression> (false);}
#line 1212 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 60:
#line 274 "grammar/parser.y"
                        {}
#line 1218 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 61:
#line 275 "grammar/parser.y"
                     {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::AndExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1224 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 62:
#line 276 "grammar/parser.y"
                     {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::OrExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1230 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 63:
#line 277 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::LessExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1236 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 64:
#line 278 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::GreaterExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1242 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 65:
#line 279 "grammar/parser.y"
                     {yylhs.value.as < std::shared_ptr<ast::Expression>  > () = std::make_shared<ast::EqualExpression>(yystack_[2].value.as < std::shared_ptr<ast::Expression>  > (), yystack_[0].value.as < std::shared_ptr<ast::Expression>  > ());}
#line 1248 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;


#line 1252 "/home/egor/C_projects/mini-java-compiler/parser.cpp"

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


  const signed char parser::yypact_ninf_ = -62;

  const signed char parser::yytable_ninf_ = -44;

  const short
  parser::yypact_[] =
  {
      -5,   -17,   -62,    24,     6,     7,   -62,    17,    14,   -62,
      30,    23,    43,    36,   -62,    42,    41,    92,    63,    57,
     -62,   -62,   -62,   -62,   -12,   -62,   -62,    59,    49,   -62,
     -62,   -62,   -62,    67,    61,    53,    65,    81,    71,   -62,
      84,   -62,   -62,   219,   274,     5,   277,   219,   100,     3,
     -62,   101,   108,   111,   277,   -12,   277,   -62,   -62,   -62,
     430,   118,   115,   -62,   -62,   -62,   120,   -62,   106,    97,
     129,   -62,   317,   -62,   141,   277,   277,   277,   277,   277,
     261,   123,   119,   430,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   -21,   277,   121,   -62,   -62,
     219,   -12,   127,   -62,   -62,   330,   345,   359,   374,   388,
     -62,   277,   132,   444,   444,    48,    48,   430,   430,   430,
     430,   430,   430,   402,   138,   -62,   276,   -62,   167,   -62,
     219,   150,   -62,   -62,   219,   219,   416,   -62,   -62,    12,
     -62,   -62,   193,   -62,   130,   -62,   -62,   -62,   277,   -62,
     219,    89,   136,   -62,   -62,   156,   -62
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     4,     0,     0,     2,     1,     0,     0,     5,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
       8,    22,    21,    23,     0,    43,    12,    19,     0,    11,
      13,    20,    24,     0,     0,     0,     0,     0,     0,    10,
       0,    25,    16,     0,     0,     0,     0,     0,     0,    55,
      56,     0,     0,     0,     0,     0,     0,    57,    58,    59,
       0,     0,     0,     6,    36,    27,    60,     9,     0,     0,
       0,    55,     0,    60,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,    35,
       0,    17,     0,    54,    28,     0,     0,     0,     0,     0,
      34,     0,     0,    45,    44,    46,    47,    65,    61,    62,
      63,    64,    48,     0,     0,    50,     0,     3,     0,    18,
       0,     0,    42,    26,     0,     0,     0,    52,    49,     0,
      33,    14,     0,    32,    29,    31,    51,    37,     0,    15,
       0,    39,     0,    30,    40,     0,    38
  };

  const short
  parser::yypgoto_[] =
  {
     -62,   -40,   -62,   -42,   -61,   -62,   -62,   -62,   -62,   -14,
     -62,   112,   -22,   133,   -62,   -62,    72,   -62,   -43,    28,
     113
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    60,    61,    62,    63,     2,     3,     5,     9,    64,
      65,    27,    28,    17,    29,    30,    70,    31,    73,   152,
      32
  };

  const short
  parser::yytable_[] =
  {
      66,    98,    35,    26,    66,    74,    72,   -41,   124,    21,
      22,    23,     4,    98,    80,    68,    83,    25,   125,    66,
      76,     1,   147,    69,     6,     7,    21,    22,    23,   148,
      26,    66,   -43,     8,    25,   105,   106,   107,   108,   109,
      13,    10,    14,    11,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    12,   126,    66,   128,    88,
      89,    90,    91,    92,    93,    94,    15,    98,    16,    18,
      19,   136,    33,   144,   145,    34,    36,    38,    37,    69,
      39,    98,    40,    41,    42,    66,    95,    66,   142,   153,
      43,    66,    66,    45,    84,    85,    86,    87,    46,    66,
      88,    89,    90,    91,    92,    93,    94,    66,   151,    75,
      77,   151,    20,    21,    22,    23,    24,    78,    71,    50,
      79,    25,    96,    99,    46,   100,   101,    95,   112,    55,
      56,    57,    58,    59,    47,    97,    21,    22,    23,   102,
     111,   127,   137,    48,    49,    50,   130,   139,    51,    52,
      46,    53,    54,   143,   155,    55,    56,    57,    58,    59,
      47,   104,    21,    22,    23,   150,   156,    81,    82,    48,
      49,    50,    44,   129,    51,    52,    46,    53,    54,   154,
       0,    55,    56,    57,    58,    59,    47,   141,    21,    22,
      23,     0,     0,     0,     0,    48,    49,    50,     0,     0,
      51,    52,    46,    53,    54,     0,     0,    55,    56,    57,
      58,    59,    47,   149,    21,    22,    23,     0,     0,     0,
       0,    48,    49,    50,     0,     0,    51,    52,    46,    53,
      54,     0,     0,    55,    56,    57,    58,    59,    47,     0,
      21,    22,    23,     0,     0,     0,     0,    48,    49,    50,
       0,     0,    51,    52,     0,    53,    54,     0,     0,    55,
      56,    57,    58,    59,   110,     0,    84,    85,    86,    87,
       0,     0,    88,    89,    90,    91,    92,    93,    94,   140,
       0,    84,    85,    86,    87,     0,    46,    88,    89,    90,
      91,    92,    93,    94,    67,    21,    22,    23,    24,    95,
       0,     0,     0,    25,     0,     0,    71,    50,     0,     0,
       0,     0,     0,     0,    95,     0,     0,    55,    56,    57,
      58,    59,    84,    85,    86,    87,     0,   103,    88,    89,
      90,    91,    92,    93,    94,    84,    85,    86,    87,     0,
     131,    88,    89,    90,    91,    92,    93,    94,     0,     0,
      84,    85,    86,    87,     0,    95,    88,    89,    90,    91,
      92,    93,    94,   132,    84,    85,    86,    87,    95,   133,
      88,    89,    90,    91,    92,    93,    94,     0,     0,    84,
      85,    86,    87,    95,   134,    88,    89,    90,    91,    92,
      93,    94,     0,    84,    85,    86,    87,    95,   135,    88,
      89,    90,    91,    92,    93,    94,     0,    84,    85,    86,
      87,     0,    95,    88,    89,    90,    91,    92,    93,    94,
     138,    84,    85,    86,    87,     0,    95,    88,    89,    90,
      91,    92,    93,    94,   146,    84,    85,    86,    87,     0,
      95,    88,    89,    90,    91,    92,    93,    94,     0,     0,
       0,    86,    87,     0,    95,    88,    89,    90,    91,    92,
      93,    94,     0,     0,     0,     0,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95
  };

  const short
  parser::yycheck_[] =
  {
      43,    62,    24,    17,    47,    47,    46,     4,    29,    21,
      22,    23,    29,    74,    54,    10,    56,    29,    39,    62,
      17,    26,    10,    45,     0,    19,    21,    22,    23,    17,
      44,    74,    29,    26,    29,    75,    76,    77,    78,    79,
      17,    24,    19,    29,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    25,    96,   100,   100,    11,
      12,    13,    14,    15,    16,    17,    23,   128,    32,    27,
      29,   111,     9,   134,   135,    18,    17,    10,    29,   101,
      19,   142,    29,    18,     3,   128,    38,   130,   130,   150,
      19,   134,   135,     9,     5,     6,     7,     8,     9,   142,
      11,    12,    13,    14,    15,    16,    17,   150,   148,     9,
       9,   151,    20,    21,    22,    23,    24,     9,    29,    30,
       9,    29,     4,     3,     9,    19,    29,    38,     9,    40,
      41,    42,    43,    44,    19,    20,    21,    22,    23,    10,
      17,    20,    10,    28,    29,    30,    19,     9,    33,    34,
       9,    36,    37,     3,    18,    40,    41,    42,    43,    44,
      19,    20,    21,    22,    23,    35,    10,    55,    55,    28,
      29,    30,    39,   101,    33,    34,     9,    36,    37,   151,
      -1,    40,    41,    42,    43,    44,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    -1,    -1,
      33,    34,     9,    36,    37,    -1,    -1,    40,    41,    42,
      43,    44,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    -1,    -1,    33,    34,     9,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    19,    -1,
      21,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      -1,    -1,    33,    34,    -1,    36,    37,    -1,    -1,    40,
      41,    42,    43,    44,     3,    -1,     5,     6,     7,     8,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,     3,
      -1,     5,     6,     7,     8,    -1,     9,    11,    12,    13,
      14,    15,    16,    17,    20,    21,    22,    23,    24,    38,
      -1,    -1,    -1,    29,    -1,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    40,    41,    42,
      43,    44,     5,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
       5,     6,     7,     8,    -1,    38,    11,    12,    13,    14,
      15,    16,    17,    18,     5,     6,     7,     8,    38,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,     5,
       6,     7,     8,    38,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,     5,     6,     7,     8,    38,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,     5,     6,     7,
       8,    -1,    38,    11,    12,    13,    14,    15,    16,    17,
      18,     5,     6,     7,     8,    -1,    38,    11,    12,    13,
      14,    15,    16,    17,    18,     5,     6,     7,     8,    -1,
      38,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,     7,     8,    -1,    38,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38
  };

  const signed char
  parser::yystos_[] =
  {
       0,    26,    50,    51,    29,    52,     0,    19,    26,    53,
      24,    29,    25,    17,    19,    23,    32,    58,    27,    29,
      20,    21,    22,    23,    24,    29,    54,    56,    57,    59,
      60,    62,    65,     9,    18,    57,    17,    29,    10,    19,
      29,    18,     3,    19,    58,     9,     9,    19,    28,    29,
      30,    33,    34,    36,    37,    40,    41,    42,    43,    44,
      46,    47,    48,    49,    54,    55,    63,    20,    10,    57,
      61,    29,    46,    63,    48,     9,    17,     9,     9,     9,
      46,    56,    65,    46,     5,     6,     7,     8,    11,    12,
      13,    14,    15,    16,    17,    38,     4,    20,    49,     3,
      19,    29,    10,    10,    20,    46,    46,    46,    46,    46,
       3,    17,     9,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    29,    39,    46,    20,    48,    61,
      19,    10,    18,    10,    10,    10,    46,    10,    18,     9,
       3,    20,    48,     3,    49,    49,    18,    10,    17,    20,
      35,    46,    64,    49,    64,    18,    10
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    45,    51,    50,    52,    52,    48,    48,    53,    53,
      58,    58,    59,    59,    60,    60,    54,    61,    61,    57,
      57,    56,    56,    56,    56,    62,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    55,    63,    63,    64,
      64,    47,    47,    65,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46
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
       1,     3,     3,     3,     3,     3
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
  "\"class\"", "\"main\"", "\"print\"", "\"identifier\"", "\"number\"",
  "\"bool\"", "\"extends\"", "\"assert\"", "\"if\"", "\"else\"",
  "\"while\"", "\"return\"", "\".\"", "\"length\"", "\"new\"", "\"!\"",
  "\"this\"", "\"true\"", "\"false\"", "$accept", "expr", "lvalue",
  "statements", "statement", "main_class", "program", "class_declarations",
  "class_declaration", "variable_declaration",
  "local_variable_declaration", "simple_type", "type", "declarations",
  "declaration", "method_declaration", "formals", "array_type",
  "method_invocation", "expressions", "type_identifier", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   169,   169,   177,   184,   185,   188,   189,   191,   192,
     195,   196,   199,   200,   203,   204,   206,   209,   210,   213,
     214,   217,   218,   219,   220,   224,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   240,   243,   244,   247,
     248,   251,   252,   255,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279
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
#line 1804 "/home/egor/C_projects/mini-java-compiler/parser.cpp"

#line 285 "grammar/parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
