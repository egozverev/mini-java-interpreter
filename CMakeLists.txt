cmake_minimum_required(VERSION 3.10)
project(mini_java_compiler)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)
set(
        HEADERS
        ${mini_java_compiler_SOURCE_DIR}/driver.hh
        ${mini_java_compiler_SOURCE_DIR}/parser.hh
)
BISON_TARGET(
        MyParser
        grammar/parser.y
        ${mini_java_compiler_SOURCE_DIR}/parser.cpp
        DEFINES_FILE ${mini_java_compiler_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
        MyScanner
        grammar/scanner.l
        ${mini_java_compiler_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${mini_java_compiler_SOURCE_DIR}/bin)
add_executable(
        mini_java_compiler
        main.cpp
        grammar/driver.cpp
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS}
        grammar/expressions/MulExpression.cpp
        grammar/expressions/AddExpression.cpp
        grammar/expressions/SubstractExpression.cpp
        grammar/expressions/DivExpression.cpp
        grammar/expressions/IdentExpression.cpp
        grammar/assignments/Assignment.cpp
        grammar/statements/Statement.h
        grammar/statements/StatementList.cpp
        grammar/statements/StatementList.h
        grammar/expressions/PlainNumberExpression.cpp
        grammar/expressions/PlainNumberExpression.h
        grammar/expressions/ModExpression.cpp
        grammar/expressions/ModExpression.h
        grammar/expressions/BoolExpression.h
        grammar/expressions/AndExpression.cpp
        grammar/expressions/AndExpression.h
        grammar/expressions/OrExpression.cpp
        grammar/expressions/OrExpression.h
        grammar/expressions/LessExpression.cpp
        grammar/expressions/LessExpression.h
        grammar/expressions/GreaterExpression.cpp
        grammar/expressions/GreaterExpression.h
        grammar/expressions/EqualExpression.cpp
        grammar/expressions/EqualExpression.h
        grammar/values/Lvalue.h
        grammar/values/PlainIdent.cpp
        grammar/values/PlainIdent.h
        grammar/statements/PrintStatement.cpp
        grammar/statements/PrintStatement.h
        grammar/declarations/MainClass.cpp
        grammar/declarations/MainClass.h
        grammar/declarations/ClassDeclaration.cpp
        grammar/declarations/ClassDeclaration.h
        grammar/declarations/ClassDeclarationList.cpp
        grammar/declarations/ClassDeclarationList.h
        grammar/program_base/Program.cpp
        grammar/program_base/Program.h
        visitors/Visitor.h
        visitors/forward_decl.h
        visitors/PrintVisitor.cpp
        visitors/PrintVisitor.h
        grammar/program_base/BaseElement.h
        visitors/visitor_requirements.h
        visitors/Interpreter.cpp
        visitors/Interpreter.h
        symbol_table/Symbol.cpp
        symbol_table/ScopeLayer.cpp
        symbol_table/ScopeLayerTree.cpp
        objects/Object.cpp
        visitors/SymbolTreeVisitor.cpp
        visitors/SymbolTreeVisitor.h
        grammar/values/VariableDeclaration.cpp
        grammar/values/VariableDeclaration.h
        grammar/values/Types.h
        grammar/values/Types.cpp
        visitors/TemplateVisitor.h
        grammar/expressions/PlainBooleanExpression.cpp
        grammar/expressions/PlainBooleanExpression.h
        grammar/statements/IfElseStatement.cpp
        grammar/statements/IfElseStatement.h
        grammar/statements/IfStatement.cpp
        grammar/statements/IfStatement.h
        grammar/functions/FunctionParameters.cpp
        grammar/functions/FunctionParameters.h
        grammar/functions/Function.cpp
        grammar/functions/Function.h
        grammar/declarations/Declaration.cpp
        grammar/declarations/Declaration.h
        grammar/declarations/DeclarationList.cpp
        grammar/declarations/DeclarationList.h
        call_mechanics/Frame.cpp
        call_mechanics/Frame.h
        call_mechanics/FunctionMapping.cpp
        call_mechanics/FunctionMapping.h
        call_mechanics/IndexTable.cpp
        call_mechanics/IndexTable.h objects/ClassObject.cpp objects/ClassObject.h grammar/values/ClassVarDecl.cpp grammar/values/ClassVarDecl.h class_tree/ClassNode.cpp class_tree/ClassNode.h class_tree/ClassTree.cpp class_tree/ClassTree.h grammar/functions/ParamValuesList.cpp grammar/functions/ParamValuesList.h grammar/functions/FunctionCall.cpp grammar/functions/FunctionCall.h grammar/statements/ReturnStatement.cpp grammar/statements/ReturnStatement.h visitors/FunctionCallVisitor.cpp visitors/FunctionCallVisitor.h)
target_include_directories(mini_java_compiler PRIVATE ${mini_java_compiler_SOURCE_DIR})
