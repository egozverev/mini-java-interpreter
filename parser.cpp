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
#line 49 "parser.y"

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

#line 84 "/home/egor/C_projects/mini-java-compiler/parser.cpp"


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
#line 175 "/home/egor/C_projects/mini-java-compiler/parser.cpp"


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
      case 53: // class_declaration
        value.YY_MOVE_OR_COPY< ClassDeclaration* > (YY_MOVE (that.value));
        break;

      case 52: // class_declarations
        value.YY_MOVE_OR_COPY< ClassDeclarationList* > (YY_MOVE (that.value));
        break;

      case 47: // lvalue
        value.YY_MOVE_OR_COPY< Lvalue* > (YY_MOVE (that.value));
        break;

      case 50: // main_class
        value.YY_MOVE_OR_COPY< MainClass* > (YY_MOVE (that.value));
        break;

      case 46: // expr
        value.YY_MOVE_OR_COPY< NumberExpression*  > (YY_MOVE (that.value));
        break;

      case 51: // program
        value.YY_MOVE_OR_COPY< Program* > (YY_MOVE (that.value));
        break;

      case 49: // statement
        value.YY_MOVE_OR_COPY< Statement* > (YY_MOVE (that.value));
        break;

      case 48: // statements
        value.YY_MOVE_OR_COPY< StatementList* > (YY_MOVE (that.value));
        break;

      case 31: // "bool"
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case 30: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
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
      case 53: // class_declaration
        value.move< ClassDeclaration* > (YY_MOVE (that.value));
        break;

      case 52: // class_declarations
        value.move< ClassDeclarationList* > (YY_MOVE (that.value));
        break;

      case 47: // lvalue
        value.move< Lvalue* > (YY_MOVE (that.value));
        break;

      case 50: // main_class
        value.move< MainClass* > (YY_MOVE (that.value));
        break;

      case 46: // expr
        value.move< NumberExpression*  > (YY_MOVE (that.value));
        break;

      case 51: // program
        value.move< Program* > (YY_MOVE (that.value));
        break;

      case 49: // statement
        value.move< Statement* > (YY_MOVE (that.value));
        break;

      case 48: // statements
        value.move< StatementList* > (YY_MOVE (that.value));
        break;

      case 31: // "bool"
        value.move< bool > (YY_MOVE (that.value));
        break;

      case 30: // "number"
        value.move< int > (YY_MOVE (that.value));
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
      case 53: // class_declaration
        value.copy< ClassDeclaration* > (that.value);
        break;

      case 52: // class_declarations
        value.copy< ClassDeclarationList* > (that.value);
        break;

      case 47: // lvalue
        value.copy< Lvalue* > (that.value);
        break;

      case 50: // main_class
        value.copy< MainClass* > (that.value);
        break;

      case 46: // expr
        value.copy< NumberExpression*  > (that.value);
        break;

      case 51: // program
        value.copy< Program* > (that.value);
        break;

      case 49: // statement
        value.copy< Statement* > (that.value);
        break;

      case 48: // statements
        value.copy< StatementList* > (that.value);
        break;

      case 31: // "bool"
        value.copy< bool > (that.value);
        break;

      case 30: // "number"
        value.copy< int > (that.value);
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
      case 53: // class_declaration
        value.move< ClassDeclaration* > (that.value);
        break;

      case 52: // class_declarations
        value.move< ClassDeclarationList* > (that.value);
        break;

      case 47: // lvalue
        value.move< Lvalue* > (that.value);
        break;

      case 50: // main_class
        value.move< MainClass* > (that.value);
        break;

      case 46: // expr
        value.move< NumberExpression*  > (that.value);
        break;

      case 51: // program
        value.move< Program* > (that.value);
        break;

      case 49: // statement
        value.move< Statement* > (that.value);
        break;

      case 48: // statements
        value.move< StatementList* > (that.value);
        break;

      case 31: // "bool"
        value.move< bool > (that.value);
        break;

      case 30: // "number"
        value.move< int > (that.value);
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
      case 53: // class_declaration
        yylhs.value.emplace< ClassDeclaration* > ();
        break;

      case 52: // class_declarations
        yylhs.value.emplace< ClassDeclarationList* > ();
        break;

      case 47: // lvalue
        yylhs.value.emplace< Lvalue* > ();
        break;

      case 50: // main_class
        yylhs.value.emplace< MainClass* > ();
        break;

      case 46: // expr
        yylhs.value.emplace< NumberExpression*  > ();
        break;

      case 51: // program
        yylhs.value.emplace< Program* > ();
        break;

      case 49: // statement
        yylhs.value.emplace< Statement* > ();
        break;

      case 48: // statements
        yylhs.value.emplace< StatementList* > ();
        break;

      case 31: // "bool"
        yylhs.value.emplace< bool > ();
        break;

      case 30: // "number"
        yylhs.value.emplace< int > ();
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
#line 151 "parser.y"
{
    yylhs.value.as < Program* > () = new Program(yystack_[1].value.as < MainClass* > (), yystack_[0].value.as < ClassDeclarationList* > ());
    yylhs.value.as < Program* > () -> launch();

}
#line 827 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 3:
#line 159 "parser.y"
{
    yylhs.value.as < MainClass* > () = new MainClass(yystack_[2].value.as < StatementList* > ());
}
#line 835 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 4:
#line 165 "parser.y"
        {yylhs.value.as < ClassDeclarationList* > () = new ClassDeclarationList();}
#line 841 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 5:
#line 166 "parser.y"
                                        {yystack_[0].value.as < ClassDeclarationList* > () -> AddDeclaration(yystack_[1].value.as < ClassDeclaration* > ()); yylhs.value.as < ClassDeclarationList* > () = yystack_[0].value.as < ClassDeclarationList* > ();}
#line 847 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 6:
#line 169 "parser.y"
           {yylhs.value.as < StatementList* > () = new StatementList(); yylhs.value.as < StatementList* > () -> AddStatement(yystack_[0].value.as < Statement* > ());}
#line 853 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 7:
#line 170 "parser.y"
                        {yystack_[0].value.as < StatementList* > () -> AddStatement(yystack_[1].value.as < Statement* > ()); yylhs.value.as < StatementList* > () = yystack_[0].value.as < StatementList* > ();}
#line 859 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 8:
#line 172 "parser.y"
                                                                  {yylhs.value.as < ClassDeclaration* > () = new ClassDeclaration();}
#line 865 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 9:
#line 173 "parser.y"
                                                                               {}
#line 871 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 10:
#line 176 "parser.y"
           {}
#line 877 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 11:
#line 177 "parser.y"
                               {}
#line 883 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 12:
#line 180 "parser.y"
                         {}
#line 889 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 13:
#line 181 "parser.y"
                         {}
#line 895 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 14:
#line 184 "parser.y"
                                                          {}
#line 901 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 15:
#line 185 "parser.y"
                                                                    {}
#line 907 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 16:
#line 187 "parser.y"
                                             {}
#line 913 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 17:
#line 190 "parser.y"
                      {}
#line 919 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 18:
#line 191 "parser.y"
                                {}
#line 925 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 19:
#line 194 "parser.y"
                {}
#line 931 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 20:
#line 195 "parser.y"
               {}
#line 937 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 21:
#line 198 "parser.y"
          {}
#line 943 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 22:
#line 199 "parser.y"
                {}
#line 949 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 23:
#line 200 "parser.y"
             {}
#line 955 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 24:
#line 201 "parser.y"
                      {}
#line 961 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 25:
#line 204 "parser.y"
                        {}
#line 967 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 26:
#line 207 "parser.y"
                 {}
#line 973 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 27:
#line 208 "parser.y"
                                      {}
#line 979 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 28:
#line 209 "parser.y"
                                 {}
#line 985 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 29:
#line 210 "parser.y"
                         {}
#line 991 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 30:
#line 211 "parser.y"
                                   {}
#line 997 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 31:
#line 212 "parser.y"
                                                    {}
#line 1003 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 32:
#line 213 "parser.y"
                                     {}
#line 1009 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 33:
#line 214 "parser.y"
                              {yylhs.value.as < Statement* > () = new PrintStatement(yystack_[2].value.as < NumberExpression*  > ());}
#line 1015 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 34:
#line 215 "parser.y"
                          {yylhs.value.as < Statement* > () = new Assignment(yystack_[3].value.as < Lvalue* > (), driver, yystack_[1].value.as < NumberExpression*  > ());}
#line 1021 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 35:
#line 216 "parser.y"
                        {}
#line 1027 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 36:
#line 217 "parser.y"
                            {}
#line 1033 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 37:
#line 221 "parser.y"
                         {}
#line 1039 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 40:
#line 228 "parser.y"
         {}
#line 1045 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 41:
#line 229 "parser.y"
                       {}
#line 1051 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 42:
#line 232 "parser.y"
                 {yylhs.value.as < Lvalue* > () = new PlainIdent(yystack_[0].value.as < std::string > ());}
#line 1057 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 43:
#line 233 "parser.y"
                                {}
#line 1063 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 44:
#line 236 "parser.y"
                  {yylhs.value.as < NumberExpression*  > () = new AddExpression(yystack_[2].value.as < NumberExpression*  > (), yystack_[0].value.as < NumberExpression*  > ());}
#line 1069 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 45:
#line 237 "parser.y"
                    {yylhs.value.as < NumberExpression*  > () = new SubstractExpression(yystack_[2].value.as < NumberExpression*  > (), yystack_[0].value.as < NumberExpression*  > ());}
#line 1075 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 46:
#line 238 "parser.y"
                    {yylhs.value.as < NumberExpression*  > () = new MulExpression(yystack_[2].value.as < NumberExpression*  > (), yystack_[0].value.as < NumberExpression*  > ());}
#line 1081 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 47:
#line 239 "parser.y"
                    {yylhs.value.as < NumberExpression*  > () = new DivExpression(yystack_[2].value.as < NumberExpression*  > (), yystack_[0].value.as < NumberExpression*  > ());}
#line 1087 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 48:
#line 240 "parser.y"
                    {yylhs.value.as < NumberExpression*  > () = new ModExpression(yystack_[2].value.as < NumberExpression*  > (), yystack_[0].value.as < NumberExpression*  > ());}
#line 1093 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 49:
#line 241 "parser.y"
                        {}
#line 1099 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 50:
#line 242 "parser.y"
                        {}
#line 1105 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 51:
#line 243 "parser.y"
                                     {}
#line 1111 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 52:
#line 244 "parser.y"
                                    {}
#line 1117 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 53:
#line 245 "parser.y"
               {}
#line 1123 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 54:
#line 246 "parser.y"
                   {}
#line 1129 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 55:
#line 247 "parser.y"
                   {yylhs.value.as < NumberExpression*  > () = new IdentExpression(yystack_[0].value.as < std::string > (), driver);}
#line 1135 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 56:
#line 248 "parser.y"
               {yylhs.value.as < NumberExpression*  > () = new PlainNumberExpression(yystack_[0].value.as < int > ());}
#line 1141 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 57:
#line 249 "parser.y"
             {}
#line 1147 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 58:
#line 250 "parser.y"
             {}
#line 1153 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 59:
#line 251 "parser.y"
              {}
#line 1159 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 60:
#line 252 "parser.y"
                        {}
#line 1165 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;


#line 1169 "/home/egor/C_projects/mini-java-compiler/parser.cpp"

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


  const signed char parser::yypact_ninf_ = -57;

  const signed char parser::yytable_ninf_ = -43;

  const short
  parser::yypact_[] =
  {
      -9,    -4,    -6,    26,    46,    39,   -57,    -6,   -57,    49,
     119,   -57,    56,    69,    54,    59,    57,   -57,   -57,   -57,
     153,   -57,    88,    54,   -57,   -57,    83,   -57,   -57,    89,
     101,    91,   -57,   -57,   124,   153,   132,   130,   133,   -57,
     138,   -57,   148,    54,    84,   149,   147,   157,   164,   179,
     162,   -57,    81,   -57,    81,   173,   153,     7,    81,   184,
     177,   -57,   186,   206,   207,     7,   153,     7,   -57,   -57,
     -57,   226,   208,   202,    81,   -57,   -57,   214,   204,    81,
     -57,   -57,   127,   -57,   209,     7,     7,     7,     7,     7,
      50,   213,   230,   226,     7,     7,     7,     7,     7,     7,
     -21,     7,   224,   -57,   -57,   -57,   225,   -57,   -57,   140,
     146,   163,   180,   197,   -57,     7,   236,    -3,    -3,    53,
      53,   226,   203,   231,   -57,   123,   -57,   -57,   244,   -57,
     -57,    81,    81,   220,   -57,   -57,     2,   -57,   -57,   188,
     -57,   -57,   -57,     7,    81,    55,   232,   -57,   -57,   238,
     -57
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     4,     0,     0,     0,     2,     4,     1,     0,
       0,     5,     0,     0,    10,     0,     0,    21,    22,    23,
       0,    26,     0,    10,    13,    12,     0,    19,    24,     0,
       0,     0,     8,    11,     0,     0,     0,     0,     0,    16,
       0,    20,     0,    10,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     9,     0,     0,    17,     0,     0,     0,
      55,    56,     0,     0,     0,     0,     0,     0,    57,    58,
      59,     0,     0,     0,     6,    37,    28,    60,     0,     0,
      18,    55,     0,    60,     0,     0,     0,     0,     0,     0,
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
     -57,   -56,   -57,   -51,    28,   -57,   -57,   242,   -57,    31,
     -57,   -57,     1,   195,   -10,   -57,   -14,   -57,   187,   -57,
     -52,   107
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    71,    72,    73,    74,     2,     3,     6,     7,    22,
      23,    24,    75,    49,    26,    35,    27,    41,    28,    76,
      83,   146
  };

  const short
  parser::yytable_[] =
  {
      77,    82,    77,    78,    96,    97,    77,    84,   123,    90,
      31,    93,   142,    98,    99,    25,    57,     1,   124,   143,
       5,    40,    77,   103,    25,     4,     8,    77,   106,   109,
     110,   111,   112,   113,    50,   100,    81,    61,   117,   118,
     119,   120,   121,   122,    25,   125,    50,    66,    67,    68,
      69,    70,    91,   114,    33,    94,    95,    96,    97,   133,
      94,    95,    96,    97,    57,     9,    98,    99,    10,    98,
      99,    98,    99,    12,    47,    17,    18,    19,    20,    77,
      77,    15,    29,    21,    81,    61,    30,   145,   100,   145,
      57,   100,    77,   100,    48,    66,    67,    68,    69,    70,
      58,    16,    17,    18,    19,    17,    18,    19,    32,    59,
      60,    61,    34,    21,    62,    63,    36,    64,    65,    37,
      38,    66,    67,    68,    69,    70,   137,    39,    94,    95,
      96,    97,    94,    95,    96,    97,    13,   107,    14,    98,
      99,    42,    44,    98,    99,    94,    95,    96,    97,    43,
     128,    94,    95,    96,    97,    45,    98,    99,    46,   139,
     140,   100,    98,    99,   129,   100,    52,    51,    94,    95,
      96,    97,   147,   130,    17,    18,    19,    53,   100,    98,
      99,   -42,    21,    54,   100,    94,    95,    96,    97,    55,
     131,    56,    79,    85,    86,    87,    98,    99,   -26,   -26,
     -26,   100,    94,    95,    96,    97,   -26,   132,    94,    95,
      96,    97,   101,    98,    99,    88,    89,   104,   100,    98,
      99,   135,   102,   144,   105,    94,    95,    96,    97,   108,
     115,    94,    95,    96,    97,   100,    98,    99,   141,   116,
     136,   100,    98,    99,   126,   127,   134,   138,   150,    11,
     149,    80,   148,    92,     0,     0,     0,     0,   100,     0,
       0,     0,     0,     0,   100
  };

  const short
  parser::yycheck_[] =
  {
      52,    57,    54,    54,     7,     8,    58,    58,    29,    65,
      20,    67,    10,    16,    17,    14,     9,    26,    39,    17,
      26,    35,    74,    74,    23,    29,     0,    79,    79,    85,
      86,    87,    88,    89,    44,    38,    29,    30,    94,    95,
      96,    97,    98,    99,    43,   101,    56,    40,    41,    42,
      43,    44,    66,     3,    23,     5,     6,     7,     8,   115,
       5,     6,     7,     8,     9,    19,    16,    17,    29,    16,
      17,    16,    17,    24,    43,    21,    22,    23,    24,   131,
     132,    25,    23,    29,    29,    30,    29,   143,    38,   145,
       9,    38,   144,    38,    10,    40,    41,    42,    43,    44,
      19,    32,    21,    22,    23,    21,    22,    23,    20,    28,
      29,    30,    29,    29,    33,    34,    27,    36,    37,    18,
      29,    40,    41,    42,    43,    44,     3,     3,     5,     6,
       7,     8,     5,     6,     7,     8,    17,    10,    19,    16,
      17,     9,     9,    16,    17,     5,     6,     7,     8,    19,
      10,     5,     6,     7,     8,    17,    16,    17,    10,   131,
     132,    38,    16,    17,    18,    38,    19,    18,     5,     6,
       7,     8,   144,    10,    21,    22,    23,    20,    38,    16,
      17,     4,    29,    19,    38,     5,     6,     7,     8,    10,
      10,    29,    19,     9,    17,     9,    16,    17,    21,    22,
      23,    38,     5,     6,     7,     8,    29,    10,     5,     6,
       7,     8,     4,    16,    17,     9,     9,     3,    38,    16,
      17,    18,    20,    35,    20,     5,     6,     7,     8,    20,
      17,     5,     6,     7,     8,    38,    16,    17,    18,     9,
       9,    38,    16,    17,    20,    20,    10,     3,    10,     7,
      18,    56,   145,    66,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    38
  };

  const signed char
  parser::yystos_[] =
  {
       0,    26,    50,    51,    29,    26,    52,    53,     0,    19,
      29,    52,    24,    17,    19,    25,    32,    21,    22,    23,
      24,    29,    54,    55,    56,    57,    59,    61,    63,    23,
      29,    59,    20,    54,    29,    60,    27,    18,    29,     3,
      61,    62,     9,    19,     9,    17,    10,    54,    10,    58,
      59,    18,    19,    20,    19,    10,    29,     9,    19,    28,
      29,    30,    33,    34,    36,    37,    40,    41,    42,    43,
      44,    46,    47,    48,    49,    57,    64,    65,    48,    19,
      58,    29,    46,    65,    48,     9,    17,     9,     9,     9,
      46,    61,    63,    46,     5,     6,     7,     8,    16,    17,
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
      54,    54,    55,    55,    56,    56,    57,    58,    58,    60,
      59,    61,    61,    61,    61,    62,    63,    49,    49,    49,
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
  "class_declaration", "declarations", "declaration", "method_declaration",
  "variable_declaration", "formals", "type", "$@1", "simple_type",
  "array_type", "type_identifier", "local_variable_declaration",
  "method_invocation", "expressions", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   150,   150,   158,   165,   166,   169,   170,   172,   173,
     176,   177,   180,   181,   184,   185,   187,   190,   191,   194,
     194,   198,   199,   200,   201,   204,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   221,   224,   225,
     228,   229,   232,   233,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252
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
#line 1677 "/home/egor/C_projects/mini-java-compiler/parser.cpp"

#line 272 "parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
