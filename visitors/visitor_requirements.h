#pragma once

#include "grammar/expressions/Expression.h"
#include "grammar/expressions/ThisExpression.h"
#include "grammar/expressions/NumberExpression.h"
#include "grammar/expressions/BoolExpression.h"
#include "grammar/expressions/AddExpression.h"
#include "grammar/expressions/SubstractExpression.h"
#include "grammar/expressions/MulExpression.h"
#include "grammar/expressions/ModExpression.h"
#include "grammar/expressions/DivExpression.h"
#include "grammar/expressions/IdentExpression.h"
#include "grammar/expressions/AndExpression.h"
#include "grammar/expressions/OrExpression.h"
#include "grammar/expressions/EqualExpression.h"
#include "grammar/expressions/LessExpression.h"
#include "grammar/expressions/GreaterExpression.h"
#include "grammar/expressions/PlainNumberExpression.h"
#include "grammar/expressions/PlainBooleanExpression.h"

#include "grammar/assignments/Assignment.h"

#include "grammar/statements/Statement.h"
#include "grammar/statements/PrintStatement.h"
#include "grammar/statements/IfElseStatement.h"
#include "grammar/statements/IfStatement.h"
#include "grammar/statements/StatementList.h"
#include "grammar/statements/ReturnStatement.h"

#include "grammar/values/Lvalue.h"
#include "grammar/values/PlainIdent.h"
#include "grammar/values/Types.h"
#include "grammar/values/VariableDeclaration.h"
#include "grammar/values/ClassVarDecl.h"

#include "grammar/declarations/MainClass.h"
#include "grammar/declarations/ClassDeclaration.h"
#include "grammar/declarations/DeclarationList.h"

#include "grammar/declarations/ClassDeclarationList.h"
#include "grammar/program_base/Program.h"

#include "grammar/functions/Function.h"
#include "grammar/functions/FunctionParameters.h"

#include "grammar/functions/ParamValueList.h"
#include "grammar/functions/FunctionCall.h"

