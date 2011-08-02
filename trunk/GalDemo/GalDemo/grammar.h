typedef union
{
	char	*strVal;
	int		intVal;
	CGrammarNode	*nodeVal;
} YYSTYPE;
#define	IF	258
#define	ELSE	259
#define	OPEN_PARAM	260
#define	CLOSE_PARAM	261
#define	OPEN_STMT	262
#define	CLOSE_STMT	263
#define	END_STMT	264
#define	LT	265
#define	GT	266
#define	EQ	267
#define	PLUS	268
#define	MINUS	269
#define	ASSIGN	270
#define	ERROR_TOKEN	271
#define	ID	272
#define	STR	273
#define	INT	274


extern YYSTYPE yylval;
