<STRING>{
	"\"" 			{
						if(string_buf_ptr - string_buf > MAX_STR_CONST - 1){
							*string_buf = '\0';
							cool_yylval.error_msg = "String constant too long";
							/* */
							BEGIN(INITIAL);
							return ERROR;
						}
						*string_buf_ptr = '\0';
						cool_yylval.symbol = stringtable.add_string(string_buf);
						BEGIN(INITIAL);
						return STR_CONST;	
					}
	"\\n" 			{ *string_buf_ptr++ = '\n'; }
	"\\t" 			{ *string_buf_ptr++ = '\t'; }
	"\\b" 			{ *string_buf_ptr++ = '\b'; }
	"\\f" 			{ *string_buf_ptr++ = '\f'; }
	"\\"[^\0] 		{ *string_buf_ptr++ = yytext[1]; }
	.				{ *string_buf_ptr++ = *yytext; }
}


  "\""                       { BEGIN STRING; }

\n                { curr_lineno++; }
  (e|E)(l|L)(s|S)(e|E)    { return (ELSE); }

  t(r|R)(u|U)(e|E)                      { cool_yylval.boolean = 1; return (BOOL_CONST); }



TYPEID          [A-Z][{DIGIT}{LETTER}]*
OBJECTID        [a-z][{DIGIT}{LETTER}]*