/*
 *  The scanner definition for COOL.
 */

/*
 *  Stuff enclosed in %{ %} in the first section is copied verbatim to the
 *  output, so headers and global definitions are placed here to be visible
 * to the code in the file.  Don't remove anything that was here initially
 */
%option noyywrap 
%{
#include <cool-parse.h>
#include <stringtab.h>
#include <utilities.h>

/* The compiler assumes these identifiers. */
#define yylval cool_yylval
#define yylex  cool_yylex

/* Max size of string constants */
#define MAX_STR_CONST 1025
#define YY_NO_UNPUT   /* keep g++ happy */

extern FILE *fin; /* we read from this file */

/* define YY_INPUT so we read from the FILE fin:
 * This change makes it possible to use this scanner in
 * the Cool compiler.
 */
#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( (result = fread( (char*)buf, sizeof(char), max_size, fin)) < 0) \
		YY_FATAL_ERROR( "read() in flex scanner failed");

char string_buf[MAX_STR_CONST]; /* to assemble string constants */
char *string_buf_ptr;

extern int curr_lineno;
extern int verbose_flag;

extern YYSTYPE cool_yylval;

/*
 *  Add Your own definitions here
 */

%}

/*
 * Define names for regular expressions here.
 */

DARROW          =>
LE              <=
%x COMMENT
%x DASHCOMMENT
%x STRING

CLASS           [cC][lL][aA][sS][sS]
ELSE            [eE][lL][sS][eE]
FALSE           f[aA][lL][sS][eE]
FI              [fF][iI]  
IF              [iI][fF]  
IN              [iI][nN]  
INHERITS        [iI][nN][hH][eE][rR][iI][tT][sS]        
ISVOID          [iI][sS][vV][oO][iI][dD]      
LET             [lL][eE][tT]  
LOOP            [lL][oO][oO][pP]    
POOL            [pP][oO][oO][lL]    
THEN            [tT][hH][eE][nN]    
WHILE           [wW][hH][iI][lL][eE]    
CASE            [cC][aA][sS][eE]    
ESAC            [eE][sS][aA][cC]    
NEW             [nN][eE][wW]  
OF              [oO][fF]  
NOT             [nN][oO][tT]  
TRUE            t[rR][uU][eE]    


LETTER          [a-zA-Z_]
DIGIT           [0-9]
WHITESPACE      [ \t]*
DASHCOMMENT     --.*\n


TYPEID          [A-Z]({DIGIT}|{LETTER})*
OBJECTID        [a-z]({DIGIT}|{LETTER})*
INT_CONST       {DIGIT}+

%%

 /*
  * COMMENTED OUT, temp
  * 

 */

 /*
  *  Nested comments
  */
<COMMENT>{
  "*)"              { BEGIN (INITIAL); }
  \n                { curr_lineno++; }
  <<EOF>>           { 
                      cool_yylval.error_msg = "EOF in comment"; 
                      BEGIN (INITIAL); 
                      return (ERROR);
                    }
  .                 {}
}

<DASHCOMMENT>{
  \n                { BEGIN (INITIAL); curr_lineno++; }
  <<EOF>>           { 

                      BEGIN (INITIAL); 
                      
                    }
  .                 {}
}

<STRING>{
  \"                { 
                      *string_buf_ptr++ = '\0';
                      BEGIN (INITIAL);
                      if ((string_buf_ptr - string_buf) > MAX_STR_CONST - 1) {
                          BEGIN (INITIAL);
                          cool_yylval.error_msg = "String constant too long";
                          return (ERROR);
                      }
                      string_buf_ptr = 0;
                      cool_yylval.symbol = stringtable.add_string(string_buf);
                      return (STR_CONST);
                    }
  <<EOF>>           { 
                      cool_yylval.error_msg = "EOF in string constant";
                      BEGIN (INITIAL);
                      return (ERROR);
                    }
  \\\n              { curr_lineno++; }
  \n                { 
                      curr_lineno++;
                      BEGIN (INITIAL);
                      cool_yylval.error_msg = "Unterminated string constant";
                      return (ERROR);
                    }
  \0                { cool_yylval.error_msg = "Null character in string constant"; return (ERROR); }
  \\[^ntbf]         { *string_buf_ptr++ = yytext[1]; }
  \\[n]             { *string_buf_ptr++ = '\n'; }
  \\[t]             { *string_buf_ptr++ = '\t'; }
  \\[b]             { *string_buf_ptr++ = '\b'; }
  \\[f]             { *string_buf_ptr++ = '\f'; }
  .                 { 
                      if ((string_buf_ptr - string_buf) > MAX_STR_CONST - 1) {
                          BEGIN (INITIAL);
                          cool_yylval.error_msg = "String constant too long";
                          return (ERROR);
                      }
                      *string_buf_ptr++ = *yytext;
                    }


}


 /*
  *  The multiple-character operators.
  */
<INITIAL>{
  
  "*)"              { cool_yylval.error_msg = "Unmatched *)"; return (ERROR); }
  "(*"              { BEGIN (COMMENT); }
  "\""              { BEGIN (STRING); string_buf_ptr = string_buf; }
  "--"              { BEGIN (DASHCOMMENT); }

  <<EOF>>           { yyterminate(); }
  
  
  {CLASS}           { return (CLASS); }
  {ELSE}            { return (ELSE); }
  {FI}              { return (FI); }  
  {IF}              { return (IF); }  
  {IN}              { return (IN); }  
  {INHERITS}        { return (INHERITS); }        
  {ISVOID}          { return (ISVOID); }      
  {LET}             { return (LET); }  
  {LOOP}            { return (LOOP); }    
  {POOL}            { return (POOL); }    
  {THEN}            { return (THEN); }    
  {WHILE}           { return (WHILE); }    
  {CASE}            { return (CASE); }    
  {ESAC}            { return (ESAC); }    
  {NEW}             { return (NEW); }  
  {OF}              { return (OF); }  
  {NOT}             { return (NOT); }
  {TRUE}            { cool_yylval.boolean = 1; return (BOOL_CONST); }
  {FALSE}           { cool_yylval.boolean = 0; return (BOOL_CONST); }
  
  {DARROW}		      { return (DARROW); }
  {LE}              { return (LE); }
  "<-"              { return (ASSIGN); }
  "<"               { return '<'; }
  "@"               { return '@'; }
  "~"               { return '~'; }
  "="               { return '='; }
  "."               { return '.'; }
  "-"               { return '-'; }
  ","               { return ','; }
  "+"               { return '+'; }
  "*"               { return '*'; }
  "/"               { return '/'; }
  "}"               { return '}'; }
  "{"               { return '{'; }
  "("               { return '('; }
  ")"               { return ')'; }
  ":"               { return ':'; }
  ";"               { return ';'; }
  "_"               { cool_yylval.error_msg = yytext; return (ERROR); }

  {OBJECTID}        { cool_yylval.symbol = idtable.add_string(yytext); return (OBJECTID); }
  {TYPEID}          { cool_yylval.symbol = idtable.add_string(yytext); return (TYPEID); }
  {INT_CONST}       { cool_yylval.symbol = inttable.add_string(yytext); return (INT_CONST); }


  \n                { curr_lineno++; }
  {WHITESPACE}      {}
}

 /*
  * Keywords are case-insensitive except for the values true and false,
  * which must begin with a lower-case letter.
  * (|)(|)(|)(|)              { return (); }
  */


 /*
  *  String constants (C syntax)
  *  Escape sequence \c is accepted for all characters c. Except for 
  *  \n \t \b \f, the result is c.
  *
  */


%%
