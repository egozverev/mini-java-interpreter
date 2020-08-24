// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file /home/egor/C_projects/mini-java-compiler/parser.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_HOME_EGOR_C_PROJECTS_MINI_JAVA_COMPILER_PARSER_HH_INCLUDED
# define YY_YY_HOME_EGOR_C_PROJECTS_MINI_JAVA_COMPILER_PARSER_HH_INCLUDED
// "%code requires" blocks.
#line 9 "grammar/parser.y"

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

#line 107 "/home/egor/C_projects/mini-java-compiler/parser.hh"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 241 "/home/egor/C_projects/mini-java-compiler/parser.hh"




  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // "bool"
      char dummy1[sizeof (bool)];

      // "number"
      char dummy2[sizeof (int)];

      // class_declaration
      char dummy3[sizeof (std::shared_ptr<ast::ClassDeclaration> )];

      // class_declarations
      char dummy4[sizeof (std::shared_ptr<ast::ClassDeclarationList> )];

      // declaration
      char dummy5[sizeof (std::shared_ptr<ast::Declaration> )];

      // declarations
      char dummy6[sizeof (std::shared_ptr<ast::DeclarationList> )];

      // expr
      char dummy7[sizeof (std::shared_ptr<ast::Expression> )];

      // method_declaration
      char dummy8[sizeof (std::shared_ptr<ast::Function> )];

      // method_invocation
      char dummy9[sizeof (std::shared_ptr<ast::FunctionCall> )];

      // formals
      char dummy10[sizeof (std::shared_ptr<ast::FunctionParameters> )];

      // lvalue
      char dummy11[sizeof (std::shared_ptr<ast::Lvalue> )];

      // main_class
      char dummy12[sizeof (std::shared_ptr<ast::MainClass> )];

      // expressions
      char dummy13[sizeof (std::shared_ptr<ast::ParamValueList> )];

      // program
      char dummy14[sizeof (std::shared_ptr<ast::Program> )];

      // statement
      char dummy15[sizeof (std::shared_ptr<ast::Statement> )];

      // statements
      char dummy16[sizeof (std::shared_ptr<ast::StatementList> )];

      // simple_type
      // type
      char dummy17[sizeof (std::shared_ptr<ast::Type> )];

      // variable_declaration
      // local_variable_declaration
      char dummy18[sizeof (std::shared_ptr<ast::VariableDeclaration> )];

      // "identifier"
      // type_identifier
      char dummy19[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        TOK_END = 0,
        TOK_SEPARATOR = 258,
        TOK_COMMA = 259,
        TOK_ASSIGN = 260,
        TOK_MINUS = 261,
        TOK_PLUS = 262,
        TOK_STAR = 263,
        TOK_SLASH = 264,
        TOK_LPAREN = 265,
        TOK_RPAREN = 266,
        TOK_EQUAL = 267,
        TOK_AND = 268,
        TOK_OR = 269,
        TOK_LESS = 270,
        TOK_MORE = 271,
        TOK_MODULE = 272,
        TOK_LSPAREN = 273,
        TOK_RSPAREN = 274,
        TOK_LFPAREN = 275,
        TOK_RFPAREN = 276,
        TOK_INT_T = 277,
        TOK_BOOLEAN_T = 278,
        TOK_VOID_T = 279,
        TOK_PUBLIC_KW = 280,
        TOK_STATIC_KW = 281,
        TOK_CLASS_KW = 282,
        TOK_MAIN_KW = 283,
        TOK_NEW_KW = 284,
        TOK_IF_KW = 285,
        TOK_ELSE_KW = 286,
        TOK_PRINT = 287,
        TOK_IDENTIFIER = 288,
        TOK_NUMBER = 289,
        TOK_BOOLEAN = 290
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef signed char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, bool&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const bool& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ast::ClassDeclaration> && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::ClassDeclaration> & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ast::ClassDeclarationList> && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::ClassDeclarationList> & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ast::Declaration> && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::Declaration> & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ast::DeclarationList> && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::DeclarationList> & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ast::Expression> && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::Expression> & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ast::Function> && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::Function> & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ast::FunctionCall> && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::FunctionCall> & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ast::FunctionParameters> && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::FunctionParameters> & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ast::Lvalue> && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::Lvalue> & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ast::MainClass> && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::MainClass> & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ast::ParamValueList> && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::ParamValueList> & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ast::Program> && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::Program> & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ast::Statement> && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::Statement> & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ast::StatementList> && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::StatementList> & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ast::Type> && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::Type> & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ast::VariableDeclaration> && v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ast::VariableDeclaration> & v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
       default:
          break;
        }

        // Type destructor.
switch (yytype)
    {
      case 35: // "bool"
        value.template destroy< bool > ();
        break;

      case 34: // "number"
        value.template destroy< int > ();
        break;

      case 52: // class_declaration
        value.template destroy< std::shared_ptr<ast::ClassDeclaration>  > ();
        break;

      case 51: // class_declarations
        value.template destroy< std::shared_ptr<ast::ClassDeclarationList>  > ();
        break;

      case 59: // declaration
        value.template destroy< std::shared_ptr<ast::Declaration>  > ();
        break;

      case 60: // declarations
        value.template destroy< std::shared_ptr<ast::DeclarationList>  > ();
        break;

      case 45: // expr
        value.template destroy< std::shared_ptr<ast::Expression>  > ();
        break;

      case 58: // method_declaration
        value.template destroy< std::shared_ptr<ast::Function>  > ();
        break;

      case 62: // method_invocation
        value.template destroy< std::shared_ptr<ast::FunctionCall>  > ();
        break;

      case 57: // formals
        value.template destroy< std::shared_ptr<ast::FunctionParameters>  > ();
        break;

      case 46: // lvalue
        value.template destroy< std::shared_ptr<ast::Lvalue>  > ();
        break;

      case 49: // main_class
        value.template destroy< std::shared_ptr<ast::MainClass>  > ();
        break;

      case 61: // expressions
        value.template destroy< std::shared_ptr<ast::ParamValueList>  > ();
        break;

      case 50: // program
        value.template destroy< std::shared_ptr<ast::Program>  > ();
        break;

      case 48: // statement
        value.template destroy< std::shared_ptr<ast::Statement>  > ();
        break;

      case 47: // statements
        value.template destroy< std::shared_ptr<ast::StatementList>  > ();
        break;

      case 55: // simple_type
      case 56: // type
        value.template destroy< std::shared_ptr<ast::Type>  > ();
        break;

      case 53: // variable_declaration
      case 54: // local_variable_declaration
        value.template destroy< std::shared_ptr<ast::VariableDeclaration>  > ();
        break;

      case 33: // "identifier"
      case 63: // type_identifier
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YY_ASSERT (tok == token::TOK_END || tok == token::TOK_SEPARATOR || tok == token::TOK_COMMA || tok == token::TOK_ASSIGN || tok == token::TOK_MINUS || tok == token::TOK_PLUS || tok == token::TOK_STAR || tok == token::TOK_SLASH || tok == token::TOK_LPAREN || tok == token::TOK_RPAREN || tok == token::TOK_EQUAL || tok == token::TOK_AND || tok == token::TOK_OR || tok == token::TOK_LESS || tok == token::TOK_MORE || tok == token::TOK_MODULE || tok == token::TOK_LSPAREN || tok == token::TOK_RSPAREN || tok == token::TOK_LFPAREN || tok == token::TOK_RFPAREN || tok == token::TOK_INT_T || tok == token::TOK_BOOLEAN_T || tok == token::TOK_VOID_T || tok == token::TOK_PUBLIC_KW || tok == token::TOK_STATIC_KW || tok == token::TOK_CLASS_KW || tok == token::TOK_MAIN_KW || tok == token::TOK_NEW_KW || tok == token::TOK_IF_KW || tok == token::TOK_ELSE_KW || tok == token::TOK_PRINT || tok == 291 || tok == 292 || tok == 293 || tok == 294 || tok == 295 || tok == 296 || tok == 297 || tok == 298);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YY_ASSERT (tok == token::TOK_END || tok == token::TOK_SEPARATOR || tok == token::TOK_COMMA || tok == token::TOK_ASSIGN || tok == token::TOK_MINUS || tok == token::TOK_PLUS || tok == token::TOK_STAR || tok == token::TOK_SLASH || tok == token::TOK_LPAREN || tok == token::TOK_RPAREN || tok == token::TOK_EQUAL || tok == token::TOK_AND || tok == token::TOK_OR || tok == token::TOK_LESS || tok == token::TOK_MORE || tok == token::TOK_MODULE || tok == token::TOK_LSPAREN || tok == token::TOK_RSPAREN || tok == token::TOK_LFPAREN || tok == token::TOK_RFPAREN || tok == token::TOK_INT_T || tok == token::TOK_BOOLEAN_T || tok == token::TOK_VOID_T || tok == token::TOK_PUBLIC_KW || tok == token::TOK_STATIC_KW || tok == token::TOK_CLASS_KW || tok == token::TOK_MAIN_KW || tok == token::TOK_NEW_KW || tok == token::TOK_IF_KW || tok == token::TOK_ELSE_KW || tok == token::TOK_PRINT || tok == 291 || tok == 292 || tok == 293 || tok == 294 || tok == 295 || tok == 296 || tok == 297 || tok == 298);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, bool v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOK_BOOLEAN);
      }
#else
      symbol_type (int tok, const bool& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOK_BOOLEAN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOK_NUMBER);
      }
#else
      symbol_type (int tok, const int& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOK_NUMBER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOK_IDENTIFIER);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOK_IDENTIFIER);
      }
#endif
    };

    /// Build a parser object.
    parser (Scanner &scanner_yyarg, Driver &driver_yyarg);
    virtual ~parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::TOK_END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::TOK_END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEPARATOR (location_type l)
      {
        return symbol_type (token::TOK_SEPARATOR, std::move (l));
      }
#else
      static
      symbol_type
      make_SEPARATOR (const location_type& l)
      {
        return symbol_type (token::TOK_SEPARATOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::TOK_COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::TOK_COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (location_type l)
      {
        return symbol_type (token::TOK_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN (const location_type& l)
      {
        return symbol_type (token::TOK_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (location_type l)
      {
        return symbol_type (token::TOK_MINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const location_type& l)
      {
        return symbol_type (token::TOK_MINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (location_type l)
      {
        return symbol_type (token::TOK_PLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const location_type& l)
      {
        return symbol_type (token::TOK_PLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STAR (location_type l)
      {
        return symbol_type (token::TOK_STAR, std::move (l));
      }
#else
      static
      symbol_type
      make_STAR (const location_type& l)
      {
        return symbol_type (token::TOK_STAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SLASH (location_type l)
      {
        return symbol_type (token::TOK_SLASH, std::move (l));
      }
#else
      static
      symbol_type
      make_SLASH (const location_type& l)
      {
        return symbol_type (token::TOK_SLASH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN (location_type l)
      {
        return symbol_type (token::TOK_LPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN (const location_type& l)
      {
        return symbol_type (token::TOK_LPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN (location_type l)
      {
        return symbol_type (token::TOK_RPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_RPAREN (const location_type& l)
      {
        return symbol_type (token::TOK_RPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL (location_type l)
      {
        return symbol_type (token::TOK_EQUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_EQUAL (const location_type& l)
      {
        return symbol_type (token::TOK_EQUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (location_type l)
      {
        return symbol_type (token::TOK_AND, std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const location_type& l)
      {
        return symbol_type (token::TOK_AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (location_type l)
      {
        return symbol_type (token::TOK_OR, std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const location_type& l)
      {
        return symbol_type (token::TOK_OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS (location_type l)
      {
        return symbol_type (token::TOK_LESS, std::move (l));
      }
#else
      static
      symbol_type
      make_LESS (const location_type& l)
      {
        return symbol_type (token::TOK_LESS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MORE (location_type l)
      {
        return symbol_type (token::TOK_MORE, std::move (l));
      }
#else
      static
      symbol_type
      make_MORE (const location_type& l)
      {
        return symbol_type (token::TOK_MORE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MODULE (location_type l)
      {
        return symbol_type (token::TOK_MODULE, std::move (l));
      }
#else
      static
      symbol_type
      make_MODULE (const location_type& l)
      {
        return symbol_type (token::TOK_MODULE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSPAREN (location_type l)
      {
        return symbol_type (token::TOK_LSPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_LSPAREN (const location_type& l)
      {
        return symbol_type (token::TOK_LSPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RSPAREN (location_type l)
      {
        return symbol_type (token::TOK_RSPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_RSPAREN (const location_type& l)
      {
        return symbol_type (token::TOK_RSPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LFPAREN (location_type l)
      {
        return symbol_type (token::TOK_LFPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_LFPAREN (const location_type& l)
      {
        return symbol_type (token::TOK_LFPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RFPAREN (location_type l)
      {
        return symbol_type (token::TOK_RFPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_RFPAREN (const location_type& l)
      {
        return symbol_type (token::TOK_RFPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT_T (location_type l)
      {
        return symbol_type (token::TOK_INT_T, std::move (l));
      }
#else
      static
      symbol_type
      make_INT_T (const location_type& l)
      {
        return symbol_type (token::TOK_INT_T, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOLEAN_T (location_type l)
      {
        return symbol_type (token::TOK_BOOLEAN_T, std::move (l));
      }
#else
      static
      symbol_type
      make_BOOLEAN_T (const location_type& l)
      {
        return symbol_type (token::TOK_BOOLEAN_T, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID_T (location_type l)
      {
        return symbol_type (token::TOK_VOID_T, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID_T (const location_type& l)
      {
        return symbol_type (token::TOK_VOID_T, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PUBLIC_KW (location_type l)
      {
        return symbol_type (token::TOK_PUBLIC_KW, std::move (l));
      }
#else
      static
      symbol_type
      make_PUBLIC_KW (const location_type& l)
      {
        return symbol_type (token::TOK_PUBLIC_KW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STATIC_KW (location_type l)
      {
        return symbol_type (token::TOK_STATIC_KW, std::move (l));
      }
#else
      static
      symbol_type
      make_STATIC_KW (const location_type& l)
      {
        return symbol_type (token::TOK_STATIC_KW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLASS_KW (location_type l)
      {
        return symbol_type (token::TOK_CLASS_KW, std::move (l));
      }
#else
      static
      symbol_type
      make_CLASS_KW (const location_type& l)
      {
        return symbol_type (token::TOK_CLASS_KW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAIN_KW (location_type l)
      {
        return symbol_type (token::TOK_MAIN_KW, std::move (l));
      }
#else
      static
      symbol_type
      make_MAIN_KW (const location_type& l)
      {
        return symbol_type (token::TOK_MAIN_KW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEW_KW (location_type l)
      {
        return symbol_type (token::TOK_NEW_KW, std::move (l));
      }
#else
      static
      symbol_type
      make_NEW_KW (const location_type& l)
      {
        return symbol_type (token::TOK_NEW_KW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF_KW (location_type l)
      {
        return symbol_type (token::TOK_IF_KW, std::move (l));
      }
#else
      static
      symbol_type
      make_IF_KW (const location_type& l)
      {
        return symbol_type (token::TOK_IF_KW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE_KW (location_type l)
      {
        return symbol_type (token::TOK_ELSE_KW, std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE_KW (const location_type& l)
      {
        return symbol_type (token::TOK_ELSE_KW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRINT (location_type l)
      {
        return symbol_type (token::TOK_PRINT, std::move (l));
      }
#else
      static
      symbol_type
      make_PRINT (const location_type& l)
      {
        return symbol_type (token::TOK_PRINT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (std::string v, location_type l)
      {
        return symbol_type (token::TOK_IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBER (int v, location_type l)
      {
        return symbol_type (token::TOK_NUMBER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMBER (const int& v, const location_type& l)
      {
        return symbol_type (token::TOK_NUMBER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOLEAN (bool v, location_type l)
      {
        return symbol_type (token::TOK_BOOLEAN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOLEAN (const bool& v, const location_type& l)
      {
        return symbol_type (token::TOK_BOOLEAN, v, l);
      }
#endif


  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    /// In theory \a t should be a token_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static token_number_type yytranslate_ (int t);

    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      std::ptrdiff_t
      ssize () const YY_NOEXCEPT
      {
        return std::ptrdiff_t (size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Some specific tokens.
    static const token_number_type yy_error_token_ = 1;
    static const token_number_type yy_undef_token_ = 2;

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 457,     ///< Last index in yytable_.
      yynnts_ = 21,  ///< Number of nonterminal symbols.
      yyfinal_ = 6, ///< Termination state number.
      yyntokens_ = 44  ///< Number of tokens.
    };


    // User arguments.
    Scanner &scanner;
    Driver &driver;
  };

  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
    };
    const int user_token_number_max_ = 298;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 35: // "bool"
        value.move< bool > (std::move (that.value));
        break;

      case 34: // "number"
        value.move< int > (std::move (that.value));
        break;

      case 52: // class_declaration
        value.move< std::shared_ptr<ast::ClassDeclaration>  > (std::move (that.value));
        break;

      case 51: // class_declarations
        value.move< std::shared_ptr<ast::ClassDeclarationList>  > (std::move (that.value));
        break;

      case 59: // declaration
        value.move< std::shared_ptr<ast::Declaration>  > (std::move (that.value));
        break;

      case 60: // declarations
        value.move< std::shared_ptr<ast::DeclarationList>  > (std::move (that.value));
        break;

      case 45: // expr
        value.move< std::shared_ptr<ast::Expression>  > (std::move (that.value));
        break;

      case 58: // method_declaration
        value.move< std::shared_ptr<ast::Function>  > (std::move (that.value));
        break;

      case 62: // method_invocation
        value.move< std::shared_ptr<ast::FunctionCall>  > (std::move (that.value));
        break;

      case 57: // formals
        value.move< std::shared_ptr<ast::FunctionParameters>  > (std::move (that.value));
        break;

      case 46: // lvalue
        value.move< std::shared_ptr<ast::Lvalue>  > (std::move (that.value));
        break;

      case 49: // main_class
        value.move< std::shared_ptr<ast::MainClass>  > (std::move (that.value));
        break;

      case 61: // expressions
        value.move< std::shared_ptr<ast::ParamValueList>  > (std::move (that.value));
        break;

      case 50: // program
        value.move< std::shared_ptr<ast::Program>  > (std::move (that.value));
        break;

      case 48: // statement
        value.move< std::shared_ptr<ast::Statement>  > (std::move (that.value));
        break;

      case 47: // statements
        value.move< std::shared_ptr<ast::StatementList>  > (std::move (that.value));
        break;

      case 55: // simple_type
      case 56: // type
        value.move< std::shared_ptr<ast::Type>  > (std::move (that.value));
        break;

      case 53: // variable_declaration
      case 54: // local_variable_declaration
        value.move< std::shared_ptr<ast::VariableDeclaration>  > (std::move (that.value));
        break;

      case 33: // "identifier"
      case 63: // type_identifier
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 35: // "bool"
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case 34: // "number"
        value.copy< int > (YY_MOVE (that.value));
        break;

      case 52: // class_declaration
        value.copy< std::shared_ptr<ast::ClassDeclaration>  > (YY_MOVE (that.value));
        break;

      case 51: // class_declarations
        value.copy< std::shared_ptr<ast::ClassDeclarationList>  > (YY_MOVE (that.value));
        break;

      case 59: // declaration
        value.copy< std::shared_ptr<ast::Declaration>  > (YY_MOVE (that.value));
        break;

      case 60: // declarations
        value.copy< std::shared_ptr<ast::DeclarationList>  > (YY_MOVE (that.value));
        break;

      case 45: // expr
        value.copy< std::shared_ptr<ast::Expression>  > (YY_MOVE (that.value));
        break;

      case 58: // method_declaration
        value.copy< std::shared_ptr<ast::Function>  > (YY_MOVE (that.value));
        break;

      case 62: // method_invocation
        value.copy< std::shared_ptr<ast::FunctionCall>  > (YY_MOVE (that.value));
        break;

      case 57: // formals
        value.copy< std::shared_ptr<ast::FunctionParameters>  > (YY_MOVE (that.value));
        break;

      case 46: // lvalue
        value.copy< std::shared_ptr<ast::Lvalue>  > (YY_MOVE (that.value));
        break;

      case 49: // main_class
        value.copy< std::shared_ptr<ast::MainClass>  > (YY_MOVE (that.value));
        break;

      case 61: // expressions
        value.copy< std::shared_ptr<ast::ParamValueList>  > (YY_MOVE (that.value));
        break;

      case 50: // program
        value.copy< std::shared_ptr<ast::Program>  > (YY_MOVE (that.value));
        break;

      case 48: // statement
        value.copy< std::shared_ptr<ast::Statement>  > (YY_MOVE (that.value));
        break;

      case 47: // statements
        value.copy< std::shared_ptr<ast::StatementList>  > (YY_MOVE (that.value));
        break;

      case 55: // simple_type
      case 56: // type
        value.copy< std::shared_ptr<ast::Type>  > (YY_MOVE (that.value));
        break;

      case 53: // variable_declaration
      case 54: // local_variable_declaration
        value.copy< std::shared_ptr<ast::VariableDeclaration>  > (YY_MOVE (that.value));
        break;

      case 33: // "identifier"
      case 63: // type_identifier
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 35: // "bool"
        value.move< bool > (YY_MOVE (s.value));
        break;

      case 34: // "number"
        value.move< int > (YY_MOVE (s.value));
        break;

      case 52: // class_declaration
        value.move< std::shared_ptr<ast::ClassDeclaration>  > (YY_MOVE (s.value));
        break;

      case 51: // class_declarations
        value.move< std::shared_ptr<ast::ClassDeclarationList>  > (YY_MOVE (s.value));
        break;

      case 59: // declaration
        value.move< std::shared_ptr<ast::Declaration>  > (YY_MOVE (s.value));
        break;

      case 60: // declarations
        value.move< std::shared_ptr<ast::DeclarationList>  > (YY_MOVE (s.value));
        break;

      case 45: // expr
        value.move< std::shared_ptr<ast::Expression>  > (YY_MOVE (s.value));
        break;

      case 58: // method_declaration
        value.move< std::shared_ptr<ast::Function>  > (YY_MOVE (s.value));
        break;

      case 62: // method_invocation
        value.move< std::shared_ptr<ast::FunctionCall>  > (YY_MOVE (s.value));
        break;

      case 57: // formals
        value.move< std::shared_ptr<ast::FunctionParameters>  > (YY_MOVE (s.value));
        break;

      case 46: // lvalue
        value.move< std::shared_ptr<ast::Lvalue>  > (YY_MOVE (s.value));
        break;

      case 49: // main_class
        value.move< std::shared_ptr<ast::MainClass>  > (YY_MOVE (s.value));
        break;

      case 61: // expressions
        value.move< std::shared_ptr<ast::ParamValueList>  > (YY_MOVE (s.value));
        break;

      case 50: // program
        value.move< std::shared_ptr<ast::Program>  > (YY_MOVE (s.value));
        break;

      case 48: // statement
        value.move< std::shared_ptr<ast::Statement>  > (YY_MOVE (s.value));
        break;

      case 47: // statements
        value.move< std::shared_ptr<ast::StatementList>  > (YY_MOVE (s.value));
        break;

      case 55: // simple_type
      case 56: // type
        value.move< std::shared_ptr<ast::Type>  > (YY_MOVE (s.value));
        break;

      case 53: // variable_declaration
      case 54: // local_variable_declaration
        value.move< std::shared_ptr<ast::VariableDeclaration>  > (YY_MOVE (s.value));
        break;

      case 33: // "identifier"
      case 63: // type_identifier
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }

} // yy
#line 2366 "/home/egor/C_projects/mini-java-compiler/parser.hh"





#endif // !YY_YY_HOME_EGOR_C_PROJECTS_MINI_JAVA_COMPILER_PARSER_HH_INCLUDED
