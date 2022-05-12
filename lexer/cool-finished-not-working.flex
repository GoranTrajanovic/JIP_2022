/*
 *  The scanner definition for COOL.
 */

/*
 *  Stuff enclosed in %{ %} in the first section is copied verbatim to the
 *  output, so headers and global definitions are placed here to be visible
 * to the code in the file.  Don't remove anything that was here initially
 */
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

int comm=0;
int string_length;



%}



/*
 * Define names for regular expressions here.
 */
whitespace [\f\r\t\v\n]


DASHCOMMENT --.*\n
INT		[0-9]+
ALPHANUMERIC	[a-zA-Z0-9_]
TYPEID		[A-Z]{ALPHANUMERIC}*
OBJECTID	[a-z]{ALPHANUMERIC}*

INVALID		"`"|"!"|"#"|"$"|"%"|"^"|"&"|"_"|"["|"]"|"|"|[\\]|">"|"?"

DARROW		=>
LE		<=
ASSIGN		<-
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
TRUE            [tT][rR][uU][eE]




OPEN_PAREN    \(
CLOSE_PAREN   \)
SEMI_COLON    ;
COMMA	      ,
COLON	      :
TIMES	      "*"
PLUS	      "+"
MINUS	      "-"
SLASH	      "/"
EQUAL	      "="
OPEN_BRACKET	 "{"
CLOSE_BRACKET	 "}"
INF		 "<"
INF_EQ		 <=
DOT		 "."
TILDA		 "~"
AT		 "@"



%x COMMENT
%x STRING
%x ESCAPE
%x S_LINE_COMMENT






%%




 /*
  *  Nested comments
  */


--.*			{}

"(*"			{
				comm++;
				BEGIN(COMMENT);
				
								
			}
<COMMENT>"(*"		comm++;
<COMMENT>.{}
<COMMENT>\n{curr_lineno++;}
<COMMENT>"*)"{
					if(comm>0){
					comm--;}
					if(comm==0){
						BEGIN(INITIAL);
					}
				
			}

<COMMENT><<EOF>>{
				BEGIN(INITIAL);
					if(comm>0){
					cool_yylval.error_msg = "EOF in comment";
					comm=0;
					return ERROR;
				}
			
}
"*)"{
				cool_yylval.error_msg = "Unmatched *)";
				BEGIN(INITIAL);
				return ERROR;
			}
<DASHCOMMENT>{curr_lineno++;}




<S_LINE_COMMENT>.
<S_LINE_COMMENT>\n{
			curr_lineno++;
			BEGIN(INITIAL);
}
/*
  *  The multiple-character operators.
  */
"=>"{return DARROW;}
"<="{return LE; }
"<-"{return ASSIGN;}


{OPEN_PAREN}{ return '('; }
{CLOSE_PAREN}{ return ')'; }
{COMMA}{ return ','; }
{SEMI_COLON}{ return ';'; }
{COLON}{ return ':'; }
{TIMES}{ return '*'; }
{PLUS}{ return '+'; }
{MINUS}{ return '-'; }
{SLASH}{ return '/'; }
{EQUAL}{ return '='; }
{OPEN_BRACKET}{ return '{'; }
{CLOSE_BRACKET}{ return '}'; }
{INF}{ return '<'; }
{DOT}{ return '.'; }
{TILDA}{ return '~'; }
{AT}{ return '@'; }



/*
  * Keywords are case-insensitive except for the values true and false,
  * which must begin with a lower-case letter.
  */

(?i:class){return CLASS;}
(?i:else){return ELSE;}
(?i:fi)          {return FI;}
(?i:if)		 {return IF;}
(?i:in)          {return IN;}
(?i:inherits)    {return INHERITS;}
(?i:let)         {return LET;}
(?i:loop)        {return LOOP;}
(?i:pool)	 {return POOL;}
(?i:then)        {return THEN;}
(?i:while)       {return WHILE;}
(?i:case)        {return CASE;}
(?i:esac)	 {return ESAC;}	
(?i:of)          return OF;
(?i:darrow)      return DARROW;
(?i:new)         return NEW;
(?i:isvoid)      return ISVOID;
(?i:str_const)   return STR_CONST;
(?i:int_const)   return INT_CONST;
(?i:bool_const)  return BOOL_CONST;
(?i:typeid)      return TYPEID;
(?i:objectid)	 return OBJECTID;	
(?i:assign)      return ASSIGN;
(?i:not)         return NOT;
(?i:le)          return LE;
(?i:error)       return ERROR;
(?i:let_stmt)    return LET_STMT;
			




(t)(?i:rue){
			cool_yylval.boolean = true;
			return BOOL_CONST;
		}
(f)(?i:alse){
			cool_yylval.boolean = false;
			return BOOL_CONST;
		}	


{INT}{
			cool_yylval.symbol = inttable.add_string(yytext);
			return INT_CONST;
		}

	

{TYPEID}{
			cool_yylval.symbol = idtable.add_string(yytext);
			return TYPEID;
		}

{OBJECTID}{
			cool_yylval.symbol = idtable.add_string(yytext);
			return OBJECTID;
		}



{INVALID}{
			cool_yylval.error_msg = yytext;
			return ERROR;
		}


 /*
  *  String constants (C syntax)
  *  Escape sequence \c is accepted for all characters c. Except for 
  *  \n \t \b \f, the result is c.
  *
  */




"\""			{
				BEGIN(STRING);
				string_buf_ptr = string_buf;
			}

<STRING>\0	{
				*string_buf = '\0';
				cool_yylval.error_msg = "String contains null character";
				BEGIN(ESCAPE);
				return ERROR;
			}


<STRING>"\""		{
				if(string_buf_ptr - string_buf > MAX_STR_CONST-1){
					*string_buf = '\0';
					cool_yylval.error_msg = "String constant too long";
					BEGIN(ESCAPE);
					return ERROR;
				}
				*string_buf_ptr = '\0';
				cool_yylval.symbol = stringtable.add_string(string_buf);
				BEGIN(INITIAL);
				return STR_CONST;
			}
<STRING>\n		{
				cool_yylval.error_msg = "Unterminated string constant";
				*string_buf = '\0';
				curr_lineno++;
				BEGIN(INITIAL);
				
				return ERROR;
				
			}


<STRING><<EOF>>		{
				
				cool_yylval.error_msg = "EOF in string constant";
				BEGIN(INITIAL);
				return ERROR;
			}




<STRING>"\\n"		{*string_buf_ptr++ = '\n';}
<STRING>"\\t"		{*string_buf_ptr++ = '\t';}
<STRING>"\\b"		{*string_buf_ptr++ = '\b';}
<STRING>"\\f"		{*string_buf_ptr++ = '\f';}
<STRING>"\\"[^\0]	{*string_buf_ptr++= yytext[1];}
<STRING>.		{*string_buf_ptr++= *yytext;}

   



<ESCAPE>[\n|"]		BEGIN(INITIAL);
<ESCAPE>[^\n|"]

\n		curr_lineno++;
[ \f\r\t\v]	{}

.		{
			cool_yylval.error_msg=yytext;
			return ERROR;
		}

%%
