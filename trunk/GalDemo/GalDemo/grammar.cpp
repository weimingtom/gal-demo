#include "stdafx.h"
/*  A Bison parser, made from ..\yaccrule.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

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

#line 1 "..\yaccrule.y"

#include "parser.h"
#include "lex.h"

#define YYDEBUG 1	      
#define YYERROR_VERBOSE

CSyntaxTable syntaxTable;
std::list<CGrammarNode*> grammarList;

void yyerror(char *msg);

#line 14 "..\yaccrule.y"
typedef union
{
	char	*strVal;
	int		intVal;
	CGrammarNode	*nodeVal;
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		64
#define	YYFLAG		-32768
#define	YYNTBASE	21

#define YYTRANSLATE(x) ((unsigned)(x) <= 274 ? yytranslate[x] : 40)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,    20,     2,     2,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     4,     7,     9,    12,    15,    19,    22,    24,
    29,    33,    37,    39,    46,    49,    50,    52,    54,    56,
    58,    60,    64,    68,    72,    76,    80,    84,    88,    92,
    96,   100,   104,   106,   108,   110,   114,   116,   118
};

static const short yyrhs[] = {    21,
    22,     0,     0,    25,     9,     0,    27,     0,    30,     9,
     0,     1,     9,     0,     7,    24,     8,     0,    24,    22,
     0,    22,     0,    39,     5,    26,     6,     0,    39,     5,
     6,     0,    26,    20,    36,     0,    36,     0,     3,     5,
    29,     6,    23,    28,     0,     4,    23,     0,     0,    31,
     0,    35,     0,    34,     0,    32,     0,    33,     0,    39,
    15,    36,     0,    39,    15,    35,     0,    39,    15,    34,
     0,    39,    15,    31,     0,    39,    15,    32,     0,    39,
    15,    33,     0,    36,    12,    36,     0,    36,    11,    36,
     0,    36,    10,    36,     0,    36,    14,    36,     0,    36,
    13,    36,     0,    39,     0,    38,     0,    37,     0,     5,
    36,     6,     0,    19,     0,    18,     0,    17,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    37,    38,    42,    43,    44,    45,    49,    53,    54,    58,
    59,    63,    64,    68,    82,    83,    87,    88,    89,    90,
    91,    95,    96,    97,    98,    99,   100,   104,   108,   112,
   116,   120,   124,   125,   126,   127,   131,   142,   153
};

static const char * const yytname[] = {   "$","error","$undefined.","IF","ELSE",
"OPEN_PARAM","CLOSE_PARAM","OPEN_STMT","CLOSE_STMT","END_STMT","LT","GT","EQ",
"PLUS","MINUS","ASSIGN","ERROR_TOKEN","ID","STR","INT","','","program","statement",
"statement_block","statement_list","call_func","param_list","if_statement","else_statement",
"expression","assign_expression","eq_expression","gt_expression","lt_expression",
"minus_expression","plus_expression","simple_expression","const_int","const_string",
"identifier",""
};
#endif

static const short yyr1[] = {     0,
    21,    21,    22,    22,    22,    22,    23,    24,    24,    25,
    25,    26,    26,    27,    28,    28,    29,    29,    29,    29,
    29,    30,    30,    30,    30,    30,    30,    31,    32,    33,
    34,    35,    36,    36,    36,    36,    37,    38,    39
};

static const short yyr2[] = {     0,
     2,     0,     2,     1,     2,     2,     3,     2,     1,     4,
     3,     3,     1,     6,     2,     0,     1,     1,     1,     1,
     1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     1,     1,     1,     3,     1,     1,     1
};

static const short yydefact[] = {     2,
     0,     0,     0,    39,     1,     0,     4,     0,     0,     6,
     0,     3,     5,     0,     0,     0,    38,    37,     0,    17,
    20,    21,    19,    18,     0,    35,    34,    33,    11,     0,
    13,    25,    26,    27,    24,    23,    22,     0,     0,     0,
     0,     0,     0,     0,    10,     0,    36,     0,    16,    30,
    29,    28,    32,    31,    12,     9,     0,     0,    14,     7,
     8,    15,     0,     0
};

static const short yydefgoto[] = {     1,
     5,    49,    57,     6,    30,     7,    59,    19,     8,    20,
    21,    22,    23,    24,    25,    26,    27,    28
};

static const short yypact[] = {-32768,
     4,     3,     9,-32768,-32768,     6,-32768,     7,    29,-32768,
    21,-32768,-32768,    18,    21,    21,-32768,-32768,    11,-32768,
-32768,-32768,-32768,-32768,    38,-32768,-32768,-32768,-32768,    12,
-32768,-32768,-32768,-32768,-32768,-32768,    38,    14,    34,    21,
    21,    21,    21,    21,-32768,    21,-32768,     8,    39,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,     5,    34,-32768,-32768,
-32768,-32768,    42,-32768
};

static const short yypgoto[] = {-32768,
   -38,   -12,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    30,
    40,    43,    44,    45,   -13,-32768,-32768,    -1
};


#define	YYLAST		60


static const short yytable[] = {     9,
    31,    37,    38,    63,     2,     2,     3,     3,     2,    56,
     3,    10,    60,    11,    12,    13,    39,    45,    61,    47,
     4,     4,    16,    29,     4,    16,    50,    51,    52,    53,
    54,    46,    55,    14,     4,    17,    18,     4,    17,    18,
    48,    64,    58,    15,    32,    62,     9,    40,    41,    42,
    43,    44,     0,     0,    33,     9,     0,    34,    35,    36
};

static const short yycheck[] = {     1,
    14,    15,    16,     0,     1,     1,     3,     3,     1,    48,
     3,     9,     8,     5,     9,     9,     6,     6,    57,     6,
    17,    17,     5,     6,    17,     5,    40,    41,    42,    43,
    44,    20,    46,     5,    17,    18,    19,    17,    18,    19,
     7,     0,     4,    15,    15,    58,    48,    10,    11,    12,
    13,    14,    -1,    -1,    15,    57,    -1,    15,    15,    15
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/local/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 37 "..\yaccrule.y"
{grammarList.push_back(yyvsp[0].nodeVal);;
    break;}
case 3:
#line 42 "..\yaccrule.y"
{yyval.nodeVal = yyvsp[-1].nodeVal;;
    break;}
case 4:
#line 43 "..\yaccrule.y"
{yyval.nodeVal = yyvsp[0].nodeVal;;
    break;}
case 5:
#line 44 "..\yaccrule.y"
{yyval.nodeVal = yyvsp[-1].nodeVal;;
    break;}
case 6:
#line 45 "..\yaccrule.y"
{throw "Parse Grammar Error";;
    break;}
case 7:
#line 49 "..\yaccrule.y"
{yyval.nodeVal = yyvsp[-1].nodeVal;;
    break;}
case 8:
#line 53 "..\yaccrule.y"
{yyval.nodeVal = new CGrammarNode(STATEMENT_LIST, yyvsp[-1].nodeVal, yyvsp[0].nodeVal);;
    break;}
case 9:
#line 54 "..\yaccrule.y"
{yyval.nodeVal = new CGrammarNode(STATEMENT_LIST, yyvsp[0].nodeVal);;
    break;}
case 10:
#line 58 "..\yaccrule.y"
{yyval.nodeVal = new CGrammarNode(CALL_FUNC, yyvsp[-3].nodeVal, yyvsp[-1].nodeVal);;
    break;}
case 11:
#line 59 "..\yaccrule.y"
{yyval.nodeVal = new CGrammarNode(CALL_FUNC, yyvsp[-2].nodeVal);;
    break;}
case 12:
#line 63 "..\yaccrule.y"
{yyval.nodeVal = new CGrammarNode(PARAM_LIST, yyvsp[-2].nodeVal, yyvsp[0].nodeVal);;
    break;}
case 13:
#line 64 "..\yaccrule.y"
{yyval.nodeVal = new CGrammarNode(PARAM_LIST, yyvsp[0].nodeVal);;
    break;}
case 14:
#line 69 "..\yaccrule.y"
{
			if (yyvsp[0].nodeVal == NULL)
			{
				yyval.nodeVal = new CGrammarNode(IF_NODE, yyvsp[-3].nodeVal, yyvsp[-1].nodeVal);
			}
			else
			{
				yyval.nodeVal = new CGrammarNode(IF_NODE, yyvsp[-3].nodeVal, yyvsp[-1].nodeVal, yyvsp[0].nodeVal);
			}
		;
    break;}
case 15:
#line 82 "..\yaccrule.y"
{yyval.nodeVal = new CGrammarNode(ELSE_NODE, yyvsp[0].nodeVal);;
    break;}
case 16:
#line 83 "..\yaccrule.y"
{yyval.nodeVal = NULL;;
    break;}
case 17:
#line 87 "..\yaccrule.y"
{yyval.nodeVal = yyvsp[0].nodeVal;;
    break;}
case 18:
#line 88 "..\yaccrule.y"
{yyval.nodeVal = yyvsp[0].nodeVal;;
    break;}
case 19:
#line 89 "..\yaccrule.y"
{yyval.nodeVal = yyvsp[0].nodeVal;;
    break;}
case 20:
#line 90 "..\yaccrule.y"
{yyval.nodeVal = yyvsp[0].nodeVal;;
    break;}
case 21:
#line 91 "..\yaccrule.y"
{yyval.nodeVal = yyvsp[0].nodeVal;;
    break;}
case 22:
#line 95 "..\yaccrule.y"
{yyval.nodeVal = new CGrammarNode(ASSIGN_NODE, yyvsp[-2].nodeVal, yyvsp[0].nodeVal);;
    break;}
case 23:
#line 96 "..\yaccrule.y"
{yyval.nodeVal = new CGrammarNode(ASSIGN_NODE, yyvsp[-2].nodeVal, yyvsp[0].nodeVal);;
    break;}
case 24:
#line 97 "..\yaccrule.y"
{yyval.nodeVal = new CGrammarNode(ASSIGN_NODE, yyvsp[-2].nodeVal, yyvsp[0].nodeVal);;
    break;}
case 25:
#line 98 "..\yaccrule.y"
{yyval.nodeVal = new CGrammarNode(ASSIGN_NODE, yyvsp[-2].nodeVal, yyvsp[0].nodeVal);;
    break;}
case 26:
#line 99 "..\yaccrule.y"
{yyval.nodeVal = new CGrammarNode(ASSIGN_NODE, yyvsp[-2].nodeVal, yyvsp[0].nodeVal);;
    break;}
case 27:
#line 100 "..\yaccrule.y"
{yyval.nodeVal = new CGrammarNode(ASSIGN_NODE, yyvsp[-2].nodeVal, yyvsp[0].nodeVal);;
    break;}
case 28:
#line 104 "..\yaccrule.y"
{yyval.nodeVal = new CGrammarNode(EQ_NODE, yyvsp[-2].nodeVal, yyvsp[0].nodeVal);;
    break;}
case 29:
#line 108 "..\yaccrule.y"
{yyval.nodeVal = new CGrammarNode(GT_NODE, yyvsp[-2].nodeVal, yyvsp[0].nodeVal);;
    break;}
case 30:
#line 112 "..\yaccrule.y"
{yyval.nodeVal = new CGrammarNode(LT_NODE, yyvsp[-2].nodeVal, yyvsp[0].nodeVal);;
    break;}
case 31:
#line 116 "..\yaccrule.y"
{yyval.nodeVal = new CGrammarNode(MINUS_NODE, yyvsp[-2].nodeVal, yyvsp[0].nodeVal);;
    break;}
case 32:
#line 120 "..\yaccrule.y"
{yyval.nodeVal = new CGrammarNode(PLUS_NODE, yyvsp[-2].nodeVal, yyvsp[0].nodeVal);;
    break;}
case 33:
#line 124 "..\yaccrule.y"
{yyval.nodeVal = yyvsp[0].nodeVal;;
    break;}
case 34:
#line 125 "..\yaccrule.y"
{yyval.nodeVal = yyvsp[0].nodeVal;;
    break;}
case 35:
#line 126 "..\yaccrule.y"
{yyval.nodeVal = yyvsp[0].nodeVal;;
    break;}
case 36:
#line 127 "..\yaccrule.y"
{yyval.nodeVal = yyvsp[-1].nodeVal;;
    break;}
case 37:
#line 132 "..\yaccrule.y"
{
		SYNTAX_VALUE value;
		value.type = SYNTAX_INT;
		value.Vun.intVal = yyvsp[0].intVal;
		int index = syntaxTable.AddSyntax(syntaxTable.ConstructName(), value);
		yyval.nodeVal = new CGrammarNode(CONST_INT_NODE, index);
	;
    break;}
case 38:
#line 143 "..\yaccrule.y"
{
		SYNTAX_VALUE value;
		value.type = SYNTAX_STR;
		value.Vun.strVal = yyvsp[0].strVal;
		int index = syntaxTable.AddSyntax(syntaxTable.ConstructName(), value);
		yyval.nodeVal = new CGrammarNode(CONST_STR_NODE, index);
	;
    break;}
case 39:
#line 154 "..\yaccrule.y"
{
		int exist = syntaxTable.FindSyntax(yyvsp[0].strVal);
		if(exist != -1)
		{
			yyval.nodeVal = new CGrammarNode(IDENTITY_NODE, exist);
		}
		else
		{
			SYNTAX_VALUE value;
			value.type = SYNTAX_INT;
			int index = syntaxTable.AddSyntax(yyvsp[0].strVal, value);
			yyval.nodeVal = new CGrammarNode(IDENTITY_NODE, index);
		}
	;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/local/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 170 "..\yaccrule.y"


void yyerror(char *msg) {
   printf("Error: %s lineno:%d.\n", msg, lineno);
}