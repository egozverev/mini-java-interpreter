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
        parser.y
        ${mini_java_compiler_SOURCE_DIR}/parser.cpp
        DEFINES_FILE ${mini_java_compiler_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
        MyScanner
        scanner.l
        ${mini_java_compiler_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${mini_java_compiler_SOURCE_DIR}/bin)
add_executable(
        mini_java_compiler
        main.cpp
        driver.cpp
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS}
        expressions/MulExpression.cpp
        expressions/AddExpression.cpp
        expressions/SubstractExpression.cpp
        expressions/DivExpression.cpp
        expressions/IdentExpression.cpp
        assignments/Assignment.cpp
        assignments/AssignmentList.cpp
        statements/Statement.h
        statements/StatementList.cpp
        statements/StatementList.h
        expressions/PlainNumberExpression.cpp
        expressions/PlainNumberExpression.h
        expressions/ModExpression.cpp
        expressions/ModExpression.h
        expressions/BoolExpression.h
        expressions/AndExpression.cpp
        expressions/AndExpression.h
        expressions/OrExpression.cpp
        expressions/OrExpression.h
        expressions/LessExpression.cpp
        expressions/LessExpression.h
        expressions/GreaterExpression.cpp
        expressions/GreaterExpression.h
        expressions/EqualExpression.cpp
        expressions/EqualExpression.h
        values/Lvalue.h
        values/PlainIdent.cpp
        values/PlainIdent.h
        statements/PrintStatement.cpp
        statements/PrintStatement.h declarations/MainClass.cpp declarations/MainClass.h declarations/ClassDeclaration.cpp declarations/ClassDeclaration.h declarations/ClassDeclarationList.cpp declarations/ClassDeclarationList.h Program.cpp Program.h)
target_include_directories(mini_java_compiler PRIVATE ${mini_java_compiler_SOURCE_DIR})
