chdir  .\bin

flex.exe -olex.cpp ..\lexrule.l
bison.exe --defines --verbose -o Grammar.cpp ..\yaccrule.y 

move lex.cpp ..\lex.cpp
move grammar.cpp ..\grammar.cpp
move grammar.cpp.h ..\grammar.h
