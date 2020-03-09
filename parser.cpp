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
#line 20 "parser.y"

    #include "driver.hh"
    #include "location.hh"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }

#line 54 "/home/egor/C_projects/mini-java-compiler/parser.cpp"


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
#line 145 "/home/egor/C_projects/mini-java-compiler/parser.cpp"


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
      case 46: // expr
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 29: // "identifier"
      case 47: // lvalue
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
      case 46: // expr
        value.move< int > (YY_MOVE (that.value));
        break;

      case 29: // "identifier"
      case 47: // lvalue
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
      case 46: // expr
        value.copy< int > (that.value);
        break;

      case 29: // "identifier"
      case 47: // lvalue
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
      case 46: // expr
        value.move< int > (that.value);
        break;

      case 29: // "identifier"
      case 47: // lvalue
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
      case 46: // expr
        yylhs.value.emplace< int > ();
        break;

      case 29: // "identifier"
      case 47: // lvalue
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
#line 83 "parser.y"
                                       {}
#line 643 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 3:
#line 85 "parser.y"
                                                                                                       {}
#line 649 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 4:
#line 88 "parser.y"
        {}
#line 655 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 5:
#line 89 "parser.y"
                                        {}
#line 661 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 6:
#line 92 "parser.y"
           {}
#line 667 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 7:
#line 93 "parser.y"
                        {}
#line 673 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 8:
#line 95 "parser.y"
                                                                  {}
#line 679 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 9:
#line 96 "parser.y"
                                                                               {}
#line 685 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 10:
#line 99 "parser.y"
           {}
#line 691 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 11:
#line 100 "parser.y"
                               {}
#line 697 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 12:
#line 103 "parser.y"
                         {}
#line 703 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 13:
#line 104 "parser.y"
                         {}
#line 709 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 14:
#line 107 "parser.y"
                                                          {}
#line 715 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 15:
#line 108 "parser.y"
                                                                    {}
#line 721 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 16:
#line 110 "parser.y"
                                             { driver.variables[yystack_[1].value.as < std::string > ()] = 0;}
#line 727 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 17:
#line 113 "parser.y"
                      {}
#line 733 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 18:
#line 114 "parser.y"
                                {}
#line 739 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 19:
#line 117 "parser.y"
                {}
#line 745 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 20:
#line 118 "parser.y"
               {}
#line 751 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 21:
#line 121 "parser.y"
          {}
#line 757 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 22:
#line 122 "parser.y"
                {}
#line 763 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 23:
#line 123 "parser.y"
             {}
#line 769 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 24:
#line 124 "parser.y"
                      {}
#line 775 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 25:
#line 127 "parser.y"
                        {}
#line 781 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 26:
#line 130 "parser.y"
                 {}
#line 787 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 27:
#line 131 "parser.y"
                                      {}
#line 793 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 28:
#line 132 "parser.y"
                                 {}
#line 799 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 29:
#line 133 "parser.y"
                         {}
#line 805 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 30:
#line 134 "parser.y"
                                   {}
#line 811 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 31:
#line 135 "parser.y"
                                                    {}
#line 817 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 32:
#line 136 "parser.y"
                                     {}
#line 823 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 33:
#line 137 "parser.y"
                              {std::cout << yystack_[2].value.as < int > ();}
#line 829 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 34:
#line 138 "parser.y"
                          {driver.variables[yystack_[3].value.as < std::string > ()] = yystack_[1].value.as < int > ();}
#line 835 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 35:
#line 139 "parser.y"
                        {}
#line 841 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 36:
#line 140 "parser.y"
                            {}
#line 847 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 37:
#line 144 "parser.y"
                         {}
#line 853 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 40:
#line 151 "parser.y"
         {}
#line 859 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 41:
#line 152 "parser.y"
                       {}
#line 865 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 42:
#line 155 "parser.y"
                 {yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();}
#line 871 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 43:
#line 156 "parser.y"
                                {}
#line 877 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 44:
#line 159 "parser.y"
                              {}
#line 883 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 45:
#line 160 "parser.y"
                        {}
#line 889 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 46:
#line 161 "parser.y"
                        {}
#line 895 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 47:
#line 162 "parser.y"
                                     {}
#line 901 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 48:
#line 163 "parser.y"
                                    {}
#line 907 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 49:
#line 164 "parser.y"
               {}
#line 913 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 50:
#line 165 "parser.y"
                   {}
#line 919 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 51:
#line 166 "parser.y"
                   {}
#line 925 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 52:
#line 167 "parser.y"
               {yylhs.value.as < int > () = yystack_[0].value.as < int > ();}
#line 931 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 53:
#line 168 "parser.y"
             {}
#line 937 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 54:
#line 169 "parser.y"
             {}
#line 943 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 55:
#line 170 "parser.y"
              {}
#line 949 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 56:
#line 171 "parser.y"
                        {}
#line 955 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 57:
#line 174 "parser.y"
                       {}
#line 961 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 58:
#line 175 "parser.y"
            {}
#line 967 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 59:
#line 176 "parser.y"
           {}
#line 973 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 60:
#line 177 "parser.y"
          {}
#line 979 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 61:
#line 178 "parser.y"
            {}
#line 985 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 62:
#line 179 "parser.y"
          {}
#line 991 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 63:
#line 180 "parser.y"
           {}
#line 997 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 64:
#line 181 "parser.y"
          {}
#line 1003 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 65:
#line 182 "parser.y"
          {}
#line 1009 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;

  case 66:
#line 183 "parser.y"
          {}
#line 1015 "/home/egor/C_projects/mini-java-compiler/parser.cpp"
    break;


#line 1019 "/home/egor/C_projects/mini-java-compiler/parser.cpp"

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


  const signed char parser::yypact_ninf_ = -121;

  const signed char parser::yytable_ninf_ = -43;

  const short
  parser::yypact_[] =
  {
     -14,   -22,    18,    -7,    38,  -121,    34,  -121,    -7,    44,
      45,  -121,    49,    43,    31,    63,    58,  -121,  -121,  -121,
      77,  -121,    68,    31,  -121,  -121,    61,  -121,  -121,    65,
      91,    83,  -121,  -121,   110,    77,   111,   106,   117,  -121,
     118,  -121,   130,    31,    56,   133,   134,   129,   136,   140,
     123,  -121,    74,  -121,    74,   137,    77,   132,    74,   148,
      -1,  -121,   149,   150,   151,   132,    77,   132,  -121,  -121,
    -121,   285,   159,   144,  -121,    74,  -121,   162,   146,    74,
    -121,  -121,   172,  -121,   147,   132,   132,   132,   132,   132,
     116,   153,   194,   285,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,   132,   -24,   132,   132,   161,  -121,
    -121,  -121,   174,  -121,  -121,   185,   200,   214,   229,   243,
    -121,   132,   158,   257,   195,  -121,   285,   131,  -121,  -121,
     168,  -121,  -121,    74,    74,   271,  -121,  -121,     0,  -121,
    -121,   197,  -121,  -121,  -121,   132,    74,    29,   191,  -121,
    -121,   223,  -121
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     4,     0,     1,     0,     2,     4,     0,
       0,     5,     0,     0,    10,     0,     0,    21,    22,    23,
       0,    26,     0,    10,    13,    12,     0,    19,    24,     0,
       0,     0,     8,    11,     0,     0,     0,     0,     0,    16,
       0,    20,     0,    10,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     9,     0,     0,    17,     0,     0,     0,
      51,    52,     0,     0,     0,     0,     0,     0,    53,    54,
      55,     0,     0,     0,    37,     6,    28,    56,     0,     0,
      18,    51,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    49,    63,    62,    64,    65,    61,    57,
      58,    59,    60,    66,     0,     0,     0,     0,     0,     7,
      36,    14,     0,    50,    29,     0,     0,     0,     0,     0,
      35,     0,     0,     0,     0,    46,    44,     0,     3,    15,
       0,    43,    27,     0,     0,     0,    48,    45,     0,    34,
      33,    30,    32,    47,    38,     0,     0,    40,     0,    31,
      41,     0,    39
  };

  const short
  parser::yypgoto_[] =
  {
    -121,   -56,  -121,  -121,  -121,   239,    26,  -121,   -19,  -121,
    -121,    33,   205,     5,  -121,   -27,  -121,   228,  -120,  -121,
     -52,   119,  -121
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    71,    72,     2,     3,     7,    73,     8,    22,    23,
      24,    74,    49,    26,    35,    27,    41,    28,    75,    76,
      83,   148,   106
  };

  const short
  parser::yytable_[] =
  {
      77,    82,    77,   -42,    33,   124,    77,     4,    40,    90,
     144,    93,     1,   141,   142,   125,    86,   145,     5,     6,
     -26,   -26,   -26,    77,    47,    31,   149,    77,   -26,   115,
     116,   117,   118,   119,    94,    95,    96,    97,    57,    91,
      98,    99,   100,   101,   102,   103,   104,    25,   123,    50,
     126,   127,    17,    18,    19,    20,    25,     9,    81,    61,
      21,    50,    13,    10,    14,   135,    48,   105,    12,    66,
      67,    68,    69,    70,    15,    16,    25,    17,    18,    19,
      78,    77,    77,    57,    84,    21,    29,    30,    32,   147,
      34,   147,    36,    58,    77,    17,    18,    19,    17,    18,
      19,   109,    59,    60,    61,   112,    21,    62,    63,    37,
      64,    65,    38,    39,    66,    67,    68,    69,    70,   120,
      42,    94,    95,    96,    97,    43,    44,    98,    99,   100,
     101,   102,   103,   104,   139,    45,    94,    95,    96,    97,
      46,    57,    98,    99,   100,   101,   102,   103,   104,    53,
      55,    51,    56,    52,   105,    54,    79,    85,    87,    88,
      89,    81,    61,   107,   108,   110,   111,   114,   136,   105,
     121,   140,    66,    67,    68,    69,    70,    94,    95,    96,
      97,   128,   113,    98,    99,   100,   101,   102,   103,   104,
      94,    95,    96,    97,   129,   130,    98,    99,   100,   101,
     102,   103,   104,   122,   138,    94,    95,    96,    97,   151,
     105,    98,    99,   100,   101,   102,   103,   104,   131,    94,
      95,    96,    97,   105,   132,    98,    99,   100,   101,   102,
     103,   104,   146,   152,    94,    95,    96,    97,   105,   133,
      98,    99,   100,   101,   102,   103,   104,    11,    94,    95,
      96,    97,   105,   134,    98,    99,   100,   101,   102,   103,
     104,    80,    94,    95,    96,    97,   150,   105,    98,    99,
     100,   101,   102,   103,   104,   137,    94,    95,    96,    97,
       0,   105,    98,    99,   100,   101,   102,   103,   104,   143,
      94,    95,    96,    97,    92,   105,    98,    99,   100,   101,
     102,   103,   104,     0,     0,     0,     0,     0,     0,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   105
  };

  const short
  parser::yycheck_[] =
  {
      52,    57,    54,     4,    23,    29,    58,    29,    35,    65,
      10,    67,    26,   133,   134,    39,    17,    17,     0,    26,
      21,    22,    23,    75,    43,    20,   146,    79,    29,    85,
      86,    87,    88,    89,     5,     6,     7,     8,     9,    66,
      11,    12,    13,    14,    15,    16,    17,    14,   104,    44,
     106,   107,    21,    22,    23,    24,    23,    19,    29,    30,
      29,    56,    17,    29,    19,   121,    10,    38,    24,    40,
      41,    42,    43,    44,    25,    32,    43,    21,    22,    23,
      54,   133,   134,     9,    58,    29,    23,    29,    20,   145,
      29,   147,    27,    19,   146,    21,    22,    23,    21,    22,
      23,    75,    28,    29,    30,    79,    29,    33,    34,    18,
      36,    37,    29,     3,    40,    41,    42,    43,    44,     3,
       9,     5,     6,     7,     8,    19,     9,    11,    12,    13,
      14,    15,    16,    17,     3,    17,     5,     6,     7,     8,
      10,     9,    11,    12,    13,    14,    15,    16,    17,    20,
      10,    18,    29,    19,    38,    19,    19,     9,     9,     9,
       9,    29,    30,     4,    20,     3,    20,    20,    10,    38,
      17,     3,    40,    41,    42,    43,    44,     5,     6,     7,
       8,    20,    10,    11,    12,    13,    14,    15,    16,    17,
       5,     6,     7,     8,    20,    10,    11,    12,    13,    14,
      15,    16,    17,     9,     9,     5,     6,     7,     8,    18,
      38,    11,    12,    13,    14,    15,    16,    17,    18,     5,
       6,     7,     8,    38,    10,    11,    12,    13,    14,    15,
      16,    17,    35,    10,     5,     6,     7,     8,    38,    10,
      11,    12,    13,    14,    15,    16,    17,     8,     5,     6,
       7,     8,    38,    10,    11,    12,    13,    14,    15,    16,
      17,    56,     5,     6,     7,     8,   147,    38,    11,    12,
      13,    14,    15,    16,    17,    18,     5,     6,     7,     8,
      -1,    38,    11,    12,    13,    14,    15,    16,    17,    18,
       5,     6,     7,     8,    66,    38,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38
  };

  const signed char
  parser::yystos_[] =
  {
       0,    26,    48,    49,    29,     0,    26,    50,    52,    19,
      29,    50,    24,    17,    19,    25,    32,    21,    22,    23,
      24,    29,    53,    54,    55,    56,    58,    60,    62,    23,
      29,    58,    20,    53,    29,    59,    27,    18,    29,     3,
      60,    61,     9,    19,     9,    17,    10,    53,    10,    57,
      58,    18,    19,    20,    19,    10,    29,     9,    19,    28,
      29,    30,    33,    34,    36,    37,    40,    41,    42,    43,
      44,    46,    47,    51,    56,    63,    64,    65,    51,    19,
      57,    29,    46,    65,    51,     9,    17,     9,     9,     9,
      46,    60,    62,    46,     5,     6,     7,     8,    11,    12,
      13,    14,    15,    16,    17,    38,    67,     4,    20,    51,
       3,    20,    51,    10,    20,    46,    46,    46,    46,    46,
       3,    17,     9,    46,    29,    39,    46,    46,    20,    20,
      10,    18,    10,    10,    10,    46,    10,    18,     9,     3,
       3,    63,    63,    18,    10,    17,    35,    46,    66,    63,
      66,    18,    10
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    45,    48,    49,    50,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    56,    57,    57,    59,
      58,    60,    60,    60,    60,    61,    62,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    64,    65,    65,
      66,    66,    47,    47,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,    13,     0,     2,     1,     2,     5,     9,
       0,     2,     1,     1,     8,     9,     3,     2,     3,     0,
       3,     1,     1,     1,     1,     3,     1,     4,     1,     3,
       5,     7,     5,     5,     4,     3,     2,     1,     5,     8,
       1,     2,     1,     4,     3,     4,     3,     5,     4,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
  "program", "main_class", "class_declarations", "statements",
  "class_declaration", "declarations", "declaration", "method_declaration",
  "variable_declaration", "formals", "type", "$@1", "simple_type",
  "array_type", "type_identifier", "statement",
  "local_variable_declaration", "method_invocation", "expressions",
  "binary_operator", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    83,    83,    85,    88,    89,    92,    93,    95,    96,
      99,   100,   103,   104,   107,   108,   110,   113,   114,   117,
     117,   121,   122,   123,   124,   127,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   144,   147,   148,
     151,   152,   155,   156,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183
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
#line 1540 "/home/egor/C_projects/mini-java-compiler/parser.cpp"

#line 187 "parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
