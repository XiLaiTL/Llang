grammar llang_simple;

application: (','? listContent)*;

listExpression
    : left+=identifier ('\'' left+=identifier)* ':' right=valueExpression                                              # defineExpression
    | left+=valueExpression ('\'' left+=valueExpression)*  '>'+                                                        # popExpression
    | left+=valueExpression ('\'' left+=valueExpression)* '<' right+=valueExpression ('\'' right+=valueExpression)*    # pushExpression
    | left+=valueExpression ('\'' left+=valueExpression)*  '->' right+=valueExpression ('\'' right+=valueExpression)*  # selectExpression
    | left+=valueExpression ('\'' left+=valueExpression)*                                                              # runExpression
    | ('~'|'del') right+=valueExpression ('\'' right+=valueExpression)*                                                # deleteExpression
    | left+=valueExpression ('\'' left+=valueExpression)*  '=' right=valueExpression                                   # assignmentExpression
    | left+=valueExpression ('\'' left+=valueExpression)*  '++'                                                        # selfPlusExpression
    | '(' listExpression ')'                                                                                           # parenExpression
    ;

valueExpression
    : identifier                                 # singleName
    | '[' (listContent (','? listContent)*)? ']' # anonymousList
    | valueExpression '[' NumericLiteral ']'     # getChild
    | '&' valueExpression                        # connectToNew
    ;

listContent
    : listExpression ';'   #listContentList
    | valueExpression      #listContentValue
    ;

NumericLiteral
    : '-'? DecimalIntegerLiteral
    ;
fragment DecimalIntegerLiteral
    : '0'
    | [1-9] [0-9]*
    ;
identifier
    : Identifier
    | NumericLiteral
    | Colon
    | SelectArrow
    | Push
    | Pop
    | GlobalList
    | SelfPlus
    | Assign
    | DeleteWord
    | Delete
    | '#' Identifier
    ;
Identifier: IdentifierPart+;
fragment IdentifierPart: [a-z_A-Z];

OpenBracket:                    '[';
CloseBracket:                   ']';
OpenParen:                      '(';
CloseParen:                     ')';
Colon:                          ':';
SemiColon:                      ';';
SelectArrow:                   '->';
Push:                           '<';
Pop:                            '>';
GlobalList:                     '@';
Comma:                          ',';
SelfPlus:                      '++';
Assign:                         '=';
DeleteWord:                   'del';
Delete:                         '~';
Connect:                        '&';
Seperator:                     '\'';
FilePrefix:                     '#';

WS: [ \t\n\r] + -> skip;
