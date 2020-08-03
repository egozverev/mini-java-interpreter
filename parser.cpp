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
#line 59 "grammar/parser.y"

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
    #include "values*Types.h"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }

#line 86 "/home/egor/C_projects/mini-java-compiler/parser.cpp"


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
#line 177 "/home/egor/C_projects/mini-java-compiler/parser.cpp"


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

      case 47: // lvalue
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Lvalue>  > (YY_MOVE (that.value));
        break;

      case 50: // main_class
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::MainClass>  > (YY_MOVE (that.value));
        break;

      case 46: // expr
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::NumberExpression>  > (YY_MOVE (that.value));
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

      case 55: // simple_type
      case 56: // type
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Type>  > (YY_MOVE (that.value));
        break;

      case 54: // variable_declaration
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

      case 47: // lvalue
        value.move< std::shared_ptr<ast::Lvalue>  > (YY_MOVE (that.value));
        break;

      case 50: // main_class
        value.move< std::shared_ptr<ast::MainClass>  > (YY_MOVE (that.value));
        break;

      case 46: // expr
        value.move< std::shared_ptr<ast::NumberExpression>  > (YY_MOVE (that.value));
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

      case 55: // simple_type
      case 56: // type
        value.move< std::shared_ptr<ast::Type>  > (YY_MOVE (that.value));
        break;

      case 54: // variable_declaration
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

      case 47: // lvalue
        value.copy< std::shared_ptr<ast::Lvalue>  > (that.value);
        break;

      case 50: // main_class
        value.copy< std::shared_ptr<ast::MainClass>  > (that.value);
        break;

      case 46: // expr
        value.copy< std::shared_ptr<ast::NumberExpression>  > (that.value);
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

      case 55: // simple_type
      case 56: // type
        value.copy< std::shared_ptr<ast::Type>  > (that.value);
        break;

      case 54: // variable_declaration
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

      case 47: // lvalue
        value.move< std::shared_ptr<ast::Lvalue>  > (that.value);
        break;

      case 50: // main_class
        value.move< std::shared_ptr<ast::MainClass>  > (that.value);
        break;

      case 46: // expr
        value.move< std::shared_ptr<ast::NumberExpression>  > (that.value);
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

      case 55: // simple_type
      case 56: // type
        value.move< std::shared_ptr<ast::Type>  > (that.value);
        break;

      case 54: // variable_declaration
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

      case 47: // lvalue
        yylhs.value.emplace< std::shared_ptr<ast::Lvalue>  > ();
        break;

      case 50: // main_class
        yylhs.value.emplace< std::shared_ptr<ast::MainClass>  > ();
        break;

      case 46: // expr
        yylhs.value.emplace< std::shared_ptr<ast::NumberExpression>  > ();
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

      case 55: // simple_type
      case 56: // type
        yylhs.value.emplace< std::shared_ptr<ast::Type>  > ();
        break;

      case 54: // variable_declaration
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
#line 167 "grammar/parser.y"
{
    yylhs.value.as < std::shared_ptr<ast::Program>  > () = std::make_shared<ast::Program>(yystack_[1].value.as < std::shared_ptr<ast::MainClass>  > (), yystack_[0].value.as < std::shared_ptr<ast::ClassDeclarationList>  > ());
    driver.program = yylhs.value.as < std::shared_ptr<ast::Program>  > ();

}
#line 874 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 3:
#line 175 "grammar/parser.y"
{
    yylhs.value.as < std::shared_ptr<ast::MainClass>  > () = std::make_shared<ast::MainClass>(yystack_[2].value.as < std::shared_ptr<ast::StatementList>  > ());
}
#line 882 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 4:
#line 181 "grammar/parser.y"
        {yylhs.value.as < std::shared_ptr<ast::ClassDeclarationList>  > () = std::make_shared<ast::ClassDeclarationList>();}
#line 888 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 5:
#line 182 "grammar/parser.y"
                                        {yystack_[0].value.as < std::shared_ptr<ast::ClassDeclarationList>  > () -> AddDeclaration(yystack_[1].value.as < std::shared_ptr<ast::ClassDeclaration>  > ()); yylhs.value.as < std::shared_ptr<ast::ClassDeclarationList>  > () = yystack_[0].value.as < std::shared_ptr<ast::ClassDeclarationList>  > ();}
#line 894 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 6:
#line 185 "grammar/parser.y"
           {yylhs.value.as < std::shared_ptr<ast::StatementList>  > () = std::make_shared<ast::StatementList>(); yylhs.value.as < std::shared_ptr<ast::StatementList>  > () -> AddStatement(yystack_[0].value.as < std::shared_ptr<ast::Statement>  > ());}
#line 900 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 7:
#line 186 "grammar/parser.y"
                        {yystack_[0].value.as < std::shared_ptr<ast::StatementList>  > () -> AddStatement(yystack_[1].value.as < std::shared_ptr<ast::Statement>  > ()); yylhs.value.as < std::shared_ptr<ast::StatementList>  > () = yystack_[0].value.as < std::shared_ptr<ast::StatementList>  > ();}
#line 906 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 8:
#line 188 "grammar/parser.y"
                                                                  {yylhs.value.as < std::shared_ptr<ast::ClassDeclaration>  > () = std::make_shared<ast::ClassDeclaration>();}
#line 912 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 9:
#line 189 "grammar/parser.y"
                                                                               {}
#line 918 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 10:
#line 192 "grammar/parser.y"
           {}
#line 924 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 11:
#line 193 "grammar/parser.y"
                               {}
#line 930 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 12:
#line 196 "grammar/parser.y"
                         {}
#line 936 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 13:
#line 197 "grammar/parser.y"
                         {}
#line 942 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 14:
#line 200 "grammar/parser.y"
                                                          {}
#line 948 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 15:
#line 201 "grammar/parser.y"
                                                                    {}
#line 954 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 16:
#line 203 "grammar/parser.y"
                                             {yylhs.value.as < std::shared_ptr<ast::VariableDeclaration>  > () = std::make_shared<ast::VariableDeclaration>(yystack_[1].value.as < std::string > (), yystack_[2].value.as < std::shared_ptr<ast::Type>  > ());}
#line 960 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 17:
#line 206 "grammar/parser.y"
                      {}
#line 966 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 18:
#line 207 "grammar/parser.y"
                                {}
#line 972 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 19:
#line 210 "grammar/parser.y"
                {}
#line 978 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 20:
#line 211 "grammar/parser.y"
               {}
#line 984 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 21:
#line 214 "grammar/parser.y"
          {yylhs.value.as < std::shared_ptr<ast::Type>  > () = std::make_shared<ast::Integer>();}
#line 990 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 22:
#line 215 "grammar/parser.y"
                {yylhs.value.as < std::shared_ptr<ast::Type>  > () = std::make_shared<ast::Boolean>();}
#line 996 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 23:
#line 216 "grammar/parser.y"
             {yylhs.value.as < std::shared_ptr<ast::Type>  > () = std::make_shared<ast::Void>();}
#line 1002 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 24:
#line 217 "grammar/parser.y"
                      {yylhs.value.as < std::shared_ptr<ast::Type>  > () = std::make_shared<ast::UserType>();}
#line 1008 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 25:
#line 220 "grammar/parser.y"
                        {}
#line 1014 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 26:
#line 223 "grammar/parser.y"
                 {}
#line 1020 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 27:
#line 224 "grammar/parser.y"
                                      {}
#line 1026 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 28:
#line 225 "grammar/parser.y"
                                 {}
#line 1032 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 29:
#line 226 "grammar/parser.y"
                         {}
#line 1038 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 30:
#line 227 "grammar/parser.y"
                                   {}
#line 1044 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 31:
#line 228 "grammar/parser.y"
                                                    {}
#line 1050 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 32:
#line 229 "grammar/parser.y"
                                     {}
#line 1056 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 33:
#line 230 "grammar/parser.y"
                              {yylhs.value.as < std::shared_ptr<ast::Statement>  > () = std::make_shared<ast::PrintStatement>(yystack_[2].value.as < std::shared_ptr<ast::NumberExpression>  > ());}
#line 1062 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 34:
#line 231 "grammar/parser.y"
                          {yylhs.value.as < std::shared_ptr<ast::Statement>  > () = std::make_shared<ast::Assignment>(yystack_[3].value.as < std::shared_ptr<ast::Lvalue>  > (), driver, yystack_[1].value.as < std::shared_ptr<ast::NumberExpression>  > ());}
#line 1068 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 35:
#line 232 "grammar/parser.y"
                        {}
#line 1074 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 36:
#line 233 "grammar/parser.y"
                            {}
#line 1080 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 37:
#line 237 "grammar/parser.y"
                         {}
#line 1086 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 40:
#line 244 "grammar/parser.y"
         {}
#line 1092 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 41:
#line 245 "grammar/parser.y"
                       {}
#line 1098 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 42:
#line 248 "grammar/parser.y"
                 {yylhs.value.as < std::shared_ptr<ast::Lvalue>  > () = std::make_shared<ast::PlainIdent>(yystack_[0].value.as < std::string > ());}
#line 1104 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 43:
#line 249 "grammar/parser.y"
                                {}
#line 1110 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 44:
#line 252 "grammar/parser.y"
                  {yylhs.value.as < std::shared_ptr<ast::NumberExpression>  > () = std::make_shared<ast::AddExpression>(yystack_[2].value.as < std::shared_ptr<ast::NumberExpression>  > (), yystack_[0].value.as < std::shared_ptr<ast::NumberExpression>  > ());}
#line 1116 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 45:
#line 253 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::NumberExpression>  > () = std::make_shared<ast::SubstractExpression>(yystack_[2].value.as < std::shared_ptr<ast::NumberExpression>  > (), yystack_[0].value.as < std::shared_ptr<ast::NumberExpression>  > ());}
#line 1122 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 46:
#line 254 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::NumberExpression>  > () = std::make_shared<ast::MulExpression>(yystack_[2].value.as < std::shared_ptr<ast::NumberExpression>  > (), yystack_[0].value.as < std::shared_ptr<ast::NumberExpression>  > ());}
#line 1128 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 47:
#line 255 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::NumberExpression>  > () = std::make_shared<ast::DivExpression>(yystack_[2].value.as < std::shared_ptr<ast::NumberExpression>  > (), yystack_[0].value.as < std::shared_ptr<ast::NumberExpression>  > ());}
#line 1134 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 48:
#line 256 "grammar/parser.y"
                    {yylhs.value.as < std::shared_ptr<ast::NumberExpression>  > () = std::make_shared<ast::ModExpression>(yystack_[2].value.as < std::shared_ptr<ast::NumberExpression>  > (), yystack_[0].value.as < std::shared_ptr<ast::NumberExpression>  > ());}
#line 1140 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 49:
#line 257 "grammar/parser.y"
                        {}
#line 1146 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 50:
#line 258 "grammar/parser.y"
                        {}
#line 1152 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 51:
#line 259 "grammar/parser.y"
                                     {}
#line 1158 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 52:
#line 260 "grammar/parser.y"
                                    {}
#line 1164 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 53:
#line 261 "grammar/parser.y"
               {}
#line 1170 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 54:
#line 262 "grammar/parser.y"
                   {}
#line 1176 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 55:
#line 263 "grammar/parser.y"
                   {yylhs.value.as < std::shared_ptr<ast::NumberExpression>  > () = std::make_shared<ast::IdentExpression> (yystack_[0].value.as < std::string > (), driver);}
#line 1182 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 56:
#line 264 "grammar/parser.y"
               {yylhs.value.as < std::shared_ptr<ast::NumberExpression>  > () = std::make_shared<ast::PlainNumberExpression> (yystack_[0].value.as < int > ());}
#line 1188 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 57:
#line 265 "grammar/parser.y"
             {}
#line 1194 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 58:
#line 266 "grammar/parser.y"
             {}
#line 1200 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 59:
#line 267 "grammar/parser.y"
              {}
#line 1206 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 60:
#line 268 "grammar/parser.y"
                        {}
#line 1212 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;


#line 1216 "/home/egor/C_projects/mini-java-compiler/parser.cpp"

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


  const signed char parser::yypact_ninf_ = -120;

  const signed char parser::yytable_ninf_ = -43;

  const short
  parser::yypact_[] =
  {
     -18,   -19,   -10,    23,     8,    15,  -120,   -10,  -120,    41,
      35,  -120,    43,    44,    84,    54,    49,  -120,  -120,  -120,
     137,  -120,  -120,  -120,    65,    63,    84,  -120,  -120,    46,
      83,    90,   137,    79,  -120,  -120,   103,   108,   129,   124,
    -120,  -120,   139,    84,    -3,   149,   136,   152,   155,   147,
     165,  -120,    81,  -120,    81,   137,   158,     6,    81,   173,
     177,  -120,   174,   182,   183,     6,   137,     6,  -120,  -120,
    -120,   226,   185,   175,    81,  -120,  -120,   190,   192,  -120,
      81,  -120,   127,  -120,   195,     6,     6,     6,     6,     6,
      50,   199,   208,   226,     6,     6,     6,     6,     6,     6,
     -15,     6,   202,  -120,  -120,  -120,   204,  -120,  -120,   140,
     146,   163,   180,   197,  -120,     6,   213,   232,   232,    53,
      53,   226,   203,   221,  -120,   123,  -120,  -120,   241,  -120,
    -120,    81,    81,   220,  -120,  -120,    64,  -120,  -120,   194,
    -120,  -120,  -120,     6,    81,    55,   227,  -120,  -120,   236,
    -120
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     4,     0,     0,     0,     2,     4,     1,     0,
       0,     5,     0,     0,    10,     0,     0,    21,    22,    23,
       0,    26,    12,    19,     0,     0,    10,    13,    24,     0,
       0,     0,     0,     0,     8,    11,     0,     0,     0,     0,
      20,    16,     0,    10,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     9,     0,    17,     0,     0,     0,     0,
      55,    56,     0,     0,     0,     0,     0,     0,    57,    58,
      59,     0,     0,     0,     6,    37,    28,    60,     0,    18,
       0,    55,     0,    60,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,    36,    14,     0,    54,    29,     0,
       0,     0,     0,     0,    35,     0,     0,    45,    44,    46,
      47,    48,     0,     0,    50,     0,     3,    15,     0,    43,
      27,     0,     0,     0,    52,    49,     0,    34,    33,    30,
      32,    51,    38,     0,     0,    40,     0,    31,    41,     0,
      39
  };

  const short
  parser::yypgoto_[] =
  {
    -120,   -56,  -120,    62,  -119,  -120,  -120,   240,  -120,    -9,
     -29,    31,   -22,  -120,  -120,   196,  -120,  -120,   184,  -120,
     -52,   107
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    71,    72,    73,    74,     2,     3,     6,     7,    75,
      23,    24,    25,    26,    27,    50,    32,    40,    28,    76,
      83,   146
  };

  const short
  parser::yytable_[] =
  {
      77,    82,    77,    39,    35,    22,    77,    48,     1,    90,
       4,    93,   139,   140,   123,    57,     5,    22,    17,    18,
      19,    47,    77,     8,   124,   147,    21,     9,    77,   109,
     110,   111,   112,   113,    22,    81,    61,    91,   117,   118,
     119,   120,   121,   122,    10,   125,    66,    67,    68,    69,
      70,    31,    13,   114,    14,    94,    95,    96,    97,   133,
      94,    95,    96,    97,    57,    12,    98,    99,    15,    98,
      99,    98,    99,    36,   142,    49,    16,    29,    30,    77,
      77,   143,    41,    34,    81,    61,    49,   145,   100,   145,
      57,   100,    77,   100,    33,    66,    67,    68,    69,    70,
      58,    37,    17,    18,    19,    17,    18,    19,    20,    59,
      60,    61,    42,    21,    62,    63,    78,    64,    65,    38,
      84,    66,    67,    68,    69,    70,   137,    43,    94,    95,
      96,    97,    94,    95,    96,    97,   103,   107,    44,    98,
      99,    45,   106,    98,    99,    94,    95,    96,    97,    46,
     128,    94,    95,    96,    97,    52,    98,    99,    17,    18,
      19,   100,    98,    99,   129,   100,    21,    51,    94,    95,
      96,    97,    53,   130,    54,    56,    55,    80,   100,    98,
      99,   -42,    85,    87,   100,    94,    95,    96,    97,   101,
     131,    88,    89,   104,    86,   102,    98,    99,   -26,   -26,
     -26,   100,    94,    95,    96,    97,   -26,   132,    94,    95,
      96,    97,   105,    98,    99,   108,   115,   116,   100,    98,
      99,   135,   126,   134,   127,    94,    95,    96,    97,   144,
     136,    94,    95,    96,    97,   100,    98,    99,   141,    96,
      97,   100,    98,    99,   138,   149,   150,    11,    98,    99,
      92,    79,   148,     0,     0,     0,     0,     0,   100,     0,
       0,     0,     0,     0,   100,     0,     0,     0,     0,     0,
     100
  };

  const short
  parser::yycheck_[] =
  {
      52,    57,    54,    32,    26,    14,    58,    10,    26,    65,
      29,    67,   131,   132,    29,     9,    26,    26,    21,    22,
      23,    43,    74,     0,    39,   144,    29,    19,    80,    85,
      86,    87,    88,    89,    43,    29,    30,    66,    94,    95,
      96,    97,    98,    99,    29,   101,    40,    41,    42,    43,
      44,    20,    17,     3,    19,     5,     6,     7,     8,   115,
       5,     6,     7,     8,     9,    24,    16,    17,    25,    16,
      17,    16,    17,    27,    10,    44,    32,    23,    29,   131,
     132,    17,     3,    20,    29,    30,    55,   143,    38,   145,
       9,    38,   144,    38,    29,    40,    41,    42,    43,    44,
      19,    18,    21,    22,    23,    21,    22,    23,    24,    28,
      29,    30,     9,    29,    33,    34,    54,    36,    37,    29,
      58,    40,    41,    42,    43,    44,     3,    19,     5,     6,
       7,     8,     5,     6,     7,     8,    74,    10,     9,    16,
      17,    17,    80,    16,    17,     5,     6,     7,     8,    10,
      10,     5,     6,     7,     8,    19,    16,    17,    21,    22,
      23,    38,    16,    17,    18,    38,    29,    18,     5,     6,
       7,     8,    20,    10,    19,    10,    29,    19,    38,    16,
      17,     4,     9,     9,    38,     5,     6,     7,     8,     4,
      10,     9,     9,     3,    17,    20,    16,    17,    21,    22,
      23,    38,     5,     6,     7,     8,    29,    10,     5,     6,
       7,     8,    20,    16,    17,    20,    17,     9,    38,    16,
      17,    18,    20,    10,    20,     5,     6,     7,     8,    35,
       9,     5,     6,     7,     8,    38,    16,    17,    18,     7,
       8,    38,    16,    17,     3,    18,    10,     7,    16,    17,
      66,    55,   145,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      38
  };

  const signed char
  parser::yystos_[] =
  {
       0,    26,    50,    51,    29,    26,    52,    53,     0,    19,
      29,    52,    24,    17,    19,    25,    32,    21,    22,    23,
      24,    29,    54,    55,    56,    57,    58,    59,    63,    23,
      29,    56,    61,    29,    20,    57,    27,    18,    29,    55,
      62,     3,     9,    19,     9,    17,    10,    57,    10,    56,
      60,    18,    19,    20,    19,    29,    10,     9,    19,    28,
      29,    30,    33,    34,    36,    37,    40,    41,    42,    43,
      44,    46,    47,    48,    49,    54,    64,    65,    48,    60,
      19,    29,    46,    65,    48,     9,    17,     9,     9,     9,
      46,    55,    63,    46,     5,     6,     7,     8,    16,    17,
      38,     4,    20,    48,     3,    20,    48,    10,    20,    46,
      46,    46,    46,    46,     3,    17,     9,    46,    46,    46,
      46,    46,    46,    29,    39,    46,    20,    20,    10,    18,
      10,    10,    10,    46,    10,    18,     9,     3,     3,    49,
      49,    18,    10,    17,    35,    46,    66,    49,    66,    18,
      10
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    45,    51,    50,    52,    52,    48,    48,    53,    53,
      57,    57,    58,    58,    59,    59,    54,    60,    60,    61,
      56,    55,    55,    55,    55,    62,    63,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    64,    65,    65,
      66,    66,    47,    47,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,    13,     0,     2,     1,     2,     5,     9,
       0,     2,     1,     1,     8,     9,     3,     2,     3,     0,
       3,     1,     1,     1,     1,     3,     1,     4,     1,     3,
       5,     7,     5,     5,     4,     3,     2,     1,     5,     8,
       1,     2,     1,     4,     3,     3,     3,     3,     3,     4,
       3,     5,     4,     2,     3,     1,     1,     1,     1,     1,
       1
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
  "class_declaration", "variable_declaration", "simple_type", "type",
  "declarations", "declaration", "method_declaration", "formals", "$@1",
  "array_type", "type_identifier", "local_variable_declaration",
  "method_invocation", "expressions", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   166,   166,   174,   181,   182,   185,   186,   188,   189,
     192,   193,   196,   197,   200,   201,   203,   206,   207,   210,
     210,   214,   215,   216,   217,   220,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   237,   240,   241,
     244,   245,   248,   249,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268
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
#line 1726 "/home/egor/C_projects/mini-java-compiler/parser.cpp"

#line 288 "grammar/parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
