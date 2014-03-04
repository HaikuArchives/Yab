%{
/*

    YABASIC ---  a simple Basic Interpreter
    written by Marc-Oliver Ihm 1995-2004
    homepage: www.yabasic.de

    FLEX part
     
    This file is part of yabasic and may be copied only 
    under the terms of either the Artistic License or 
    the GNU General Public License (GPL), both of which 
    can be found at www.yabasic.de

*/

#include <string.h>
#undef WINDOWS

#include "bison.h"       /* get tokens from BISON */
#ifndef YABASIC_INCLUDED
#include "yabasic.h"     /* definitions of yabasic */
#endif
extern int main_lineno; /* defined in yabasic.bison: line number of main file */
extern int mylineno; /* defined in yabasic.bison: line number of main file */
int import_lib(char *); /* import library */

#define MAX_INCLUDE_DEPTH 5
#define MAX_INCLUDE_NUMBER 100
static YY_BUFFER_STATE include_stack[MAX_INCLUDE_DEPTH]; /* stack for included libraries */
int include_stack_ptr; /* current position in libfile_stack */
struct libfile_name *libfile_stack[MAX_INCLUDE_DEPTH]; /* stack for library file names */
int libfile_chain_length=0; /* length of libfile_chain */
struct libfile_name *libfile_chain[MAX_INCLUDE_NUMBER]; /* list of all library file names */
struct libfile_name *currlib; /* current libfile as relevant to bison */
int inlib; /* true, while in library */
int fi_pending=0; /* true, if within a short if */
int flex_line=0; /* line number counted in flex */
%}

WS [ \t\f\r\v]
NAME ([A-Za-z_][A-za-z0-9_]*\.[A-Za-z_][A-za-z0-9_]*)|([A-Za-z_][A-za-z0-9_]*)

%option noyywrap
%x PRELNO
%x PASTLNO
%x IMPORT
%x IMPORT_DONE

%%
<<EOF>> {
  if (--include_stack_ptr<0) {
    return tEOPROG;
  } else {
    if (!is_bound) {
      yy_delete_buffer(YY_CURRENT_BUFFER);
      yy_switch_to_buffer(include_stack[include_stack_ptr]);
    }
    flex_line+=yylval.sep=-1;
    return tSEP;
  }
}

{WS}+ {BEGIN(INITIAL);}     /* ignore whitespace */

^{WS}*/[0-9]+ {BEGIN(PRELNO);return tLABEL;}
<PRELNO>[0-9]+ {
  BEGIN(PASTLNO);
  yylval.symbol=(char *)my_strdup(yytext);
  return tSYMBOL;
}
<PASTLNO>.* {BEGIN(INITIAL);flex_line+=yylval.sep=0;yyless(0);return tSEP;}
<PASTLNO>\n {if (fi_pending) {fi_pending--;yyless(0);return tENDIF;}BEGIN(INITIAL);flex_line+=yylval.sep=1;return tSEP;}

\n\n {if (fi_pending) {fi_pending--;yyless(0);return tENDIF;}if (interactive && !inlib) {return tEOPROG;} else {flex_line+=yylval.sep=2;return tSEP;}}
\n {if (fi_pending) {fi_pending--;yyless(0);return tENDIF;}flex_line+=yylval.sep=1;return tSEP;}
: {if (fi_pending && check_compat) error_with_line(WARNING,"short-if has changed in version 2.71",flex_line);flex_line+=yylval.sep=0;return tSEP;}

REM{WS}+.* {flex_line+=yylval.sep=0;return tSEP;}  /* comments span 'til end of line */
\/\/.* {flex_line+=yylval.sep=0;return tSEP;}  /* comments span 'til end of line */
REM\n {if (fi_pending) {fi_pending--;yyless(0);return tENDIF;}flex_line+=yylval.sep=1;return tSEP;}
REM {yymore();}

IMPORT {BEGIN(IMPORT);}
<IMPORT>{WS}+{NAME} {if (!import_lib(yytext)) return 0;BEGIN(IMPORT_DONE);return tIMPORT;}
<IMPORT_DONE>(.|\n) {if (yytext[0]=='\n' && fi_pending) {fi_pending--;yyless(0);return tENDIF;}BEGIN(INITIAL);yyless(0);flex_line+=yylval.sep=0;return tSEP;}

((DOCU|DOC|DOCUMENTATION)({WS}+.*)?) {
  char *where=strpbrk(yytext," \t\r\f\v");
  yylval.docu=(char *)my_strdup(where ? where+1 : NULL);
  return tDOCU;
}

^#.*\n {flex_line+=yylval.sep=1;return tSEP;} /* '#' as first character may introduce comments too */
^'.*\n {flex_line+=yylval.sep=1;return tSEP;} /* ' as first character may introduce comments too */

EXECUTE return tEXECUTE;
"EXECUTE$" return tEXECUTE2;
COMPILE return tCOMPILE;
RUNTIME_CREATED_SUB return tRUNTIME_CREATED_SUB;
END{WS}+SUB return tENDSUB;
END{WS}+IF return tENDIF;
END-IF return tENDIF;
END{WS}+WHILE return tWEND;
END-WHILE return tWEND;
END{WS}+SWITCH return tSEND;
END-SWITCH return tSEND;
END{WS}+"SWITCH$" return tSEND;
END-"SWITCH$" return tSEND;
EXPORT return tEXPORT;
ERROR return tERROR;
FOR return tFOR;
BREAK return tBREAK;
SWITCH return tSWITCH;
CASE return tCASE;
DEFAULT return tDEFAULT;
LOOP return tLOOP;
DO return tDO;
TO return tTO;
AS return tAS;
READING return tREADING;
WRITING return tWRITING;
STEP return tSTEP;
NEXT return tNEXT;
WHILE return tWHILE;
WEND return tWEND;
REPEAT return tREPEAT;
UNTIL return tUNTIL;
GOTO return tGOTO;
GOSUB return tGOSUB;
SUB return tSUB;
SUBROUTINE return tSUB;
LOCAL return tLOCAL;
STATIC return tSTATIC;
ON return tON;
INTERRUPT return tINTERRUPT;
CONTINUE return tCONTINUE;
LABEL return tLABEL;
IF return tIF;
THEN return tTHEN;
ELSE return tELSE;
ELSIF return tELSIF;
ELSEIF return tELSIF;
ENDIF return tENDIF;
FI return tENDIF;
OPEN return tOPEN;
CLOSE return tCLOSE;
SEEK return tSEEK;
TELL return tTELL;
PRINT return tPRINT;
USING return tUSING;
REVERSE return tREVERSE;
COLOR return tCOLOUR;
COLOUR return tCOLOUR;
\? return tPRINT;
INPUT return tINPUT;
RETURN return tRETURN;
DIM return tDIM;
REDIM return tDIM;
END return tEND;
EXIT return tEXIT;
READ return tREAD;
DATA return tDATA;
RESTORE return tRESTORE;
AND return tAND;
OR return tOR;
NOT return tNOT;
EOR return tEOR;
XOR return tEOR;
WINDOW return tWINDOW;
PRINTER return tPRINTER;
SETUP return tSETUP;
PUTSCREEN return tPUTCHAR;
"GETSCREEN$" return tGETCHAR;
NEW return tNEW;
WAIT return tWAIT;
PAUSE return tWAIT;
SLEEP return tWAIT;
BELL return tBELL;
BEEP return tBELL;
LET return tLET;
ARRAYDIM return tARDIM;
ARRAYDIMENSION return tARDIM;
ARRAYSIZE return tARSIZE;
NUMPARAM(S)?({WS}*\({WS}*\))? {yylval.symbol=(char *)my_strdup("numparams"); return tSYMBOL;}
BIND return tBIND;
SET return tSET;

LOCALIZE return tLOCALIZE;
BUTTON return tBUTTON;
ALERT return tALERT;
MENU return tMENU;
CHECKBOX return tCHECKBOX;
RADIOBUTTON return tRADIOBUTTON;
TEXTCONTROL return tTEXTCONTROL;
LISTBOX return tLISTBOX;
DROPBOX return tDROPBOX;
ADD return tADD;
REMOVE return tREMOVE;
TEXT return tTEXT;
RECT return tRECT;
DRAW return tDRAW;
FLUSH return tFLUSH;
FILEPANEL return tFILEPANEL;
LAYOUT return tLAYOUT;
TEXTEDIT return tTEXTEDIT;
COUNT return tCOUNT;
VIEW return tVIEW;
BOXVIEW return tBOXVIEW;
TABVIEW return tTABVIEW;
ELLIPSE return tELLIPSE;
DOT return tDOT;
LINE return tLINE;
CURVE return tCURVE;
CIRCLE return tCIRCLE;
CLEAR return tCLEAR;
TEXT return tTEXT;
RECT return tRECT;
SLIDER return tSLIDER;
OPTION return tOPTION;
DROPZONE return tDROPZONE;
COLORCONTROL return tCOLORCONTROL;
TREEBOX return tTREEBOX;
SORT return tSORT;
TOOLTIP return tTOOLTIP;
COLUMNBOX return tCOLUMNBOX;
COLUMN return tCOLUMN;
CLIPBOARD return tCLIPBOARD;
COPY return tCOPY;
SUBMENU return tSUBMENU;
KEYBOARD return tKEYBOARD;
SELECT return tSELECT;
CALENDAR return tCALENDAR;
SCROLLBAR return tSCROLLBAR;
COLLAPSE return tCOLLAPSE;
EXPAND return tEXPAND;
SOUND return tSOUND;
PLAY return tPLAY;
STOP return tSTOP;
SPLITVIEW return tSPLITVIEW;
STACKVIEW return tSTACKVIEW;
TEXTURL return tTEXTURL;
SPINCONTROL return tSPINCONTROL;
POPUPMENU return tPOPUPMENU;
SEND return tMSEND;
MESSAGE return tNUMMESSAGE;
THREAD return tTHREAD;
BITMAP return tBITMAP;
CANVAS return tCANVAS;
SHORTCUT return tSHORTCUT;
SAVE return tSAVE;
ISCOMPUTERON return tISCOMPUTERON;
SCREENSHOT return tSCREENSHOT;
STATUSBAR return tSTATUSBAR;
LAUNCH return tLAUNCH;
ATTRIBUTE return tATTRIBUTE;

"PASTE$" return tPASTE;
IMAGE return tIMAGE;
SVG return tSVG;
"MESSAGE$" return tMESSAGE;
"TRANSLATE$" return tTRANSLATE;
"GET$" return tGET;
MOUSE return tMOUSE;
ISMOUSEIN return tISMOUSEIN;
GET return tGETNUM;

SIN return tSIN;
ASIN return tASIN;
COS return tCOS;
ACOS return tACOS;
TAN return tTAN;
ATAN return tATAN;
EXP return tEXP;
LOG return tLOG;
SQRT return tSQRT;
SQR return tSQR;
INT return tINT;
FRAC return tFRAC;
ABS return tABS;
SIG return tSIG;
MOD return tMOD;
RAN return tRAN;
MIN return tMIN;
MAX return tMAX;
"LEFT$" return tLEFT;
"RIGHT$" return tRIGHT;
"MID$" return tMID;
"LOWER$" return tLOWER;
"UPPER$" return tUPPER;
"LTRIM$" return tLTRIM;
"RTRIM$" return tRTRIM;
"TRIM$" return tTRIM;
INSTR return tINSTR;
RINSTR return tRINSTR;
LEN return tLEN;
VAL return tVAL;
EOF return tMYEOF;
"STR$" return tSTR;
"INKEY$" return tINKEY;
"CHR$" return tCHR;
ASC return tASC;
"HEX$" return tHEX;
"BIN$" return tBIN;
DEC return tDEC;
AT return tAT;
@ return tAT;
SCREEN return tSCREEN;
"SYSTEM$" return tSYSTEM;
SYSTEM return tSYSTEM2;
"DATE$" return tDATE;
"TIME$" return tTIME;
PEEK return tPEEK;
"PEEK$" return tPEEK2;
POKE return tPOKE;
TOKEN return tTOKEN;
"TOKEN$" return tTOKENALT;
SPLIT return tSPLIT;
"SPLIT$" return tSPLITALT;
GLOB return tGLOB;
"^" return tPOW;
"**" return tPOW;

"<>" return tNEQ;
"<=" return tLEQ;
">=" return tGEQ;
"=" return tEQU;
"<" return tLTN;
">" return tGTN;
"!" return tNOT;

[-+*/:(),.;] {return yytext[0];}

[0-9]+ {
  yylval.digits=(char *)my_strdup(yytext);
  return tDIGITS;
}

(([0-9]+|([0-9]*\.[0-9]*))([eE][-+]?[0-9]+)?) {
  { double d;
    sscanf(yytext,"%lg",&d);
    yylval.fnum=d;
    return tFNUM;
  }
}

pi {yylval.fnum=3.1415926535897932;return tFNUM;}
euler {yylval.fnum=2.7182818284590452;return tFNUM;}
TRUE {yylval.fnum=1; return tFNUM;}
FALSE {yylval.fnum=0; return tFNUM;}

{NAME} {
  yylval.symbol=(char *)my_strdup(yytext);
  return tSYMBOL;
}

 /* Symbols with a trailing $-sign are treated special */
{NAME}\$ {
  yylval.symbol=(char *)my_strdup(yytext);
  return tSTRSYM;
}

\"[^"]*(\"|\n) {
  int cnt;
  if (yytext[yyleng-1]=='\n' && fi_pending) {fi_pending--;yyless(0);return tENDIF;}
  if (yytext[yyleng-1]=='\n') {
  	yylval.string=NULL;
  	return tSTRING;
  }
  for(cnt=0;yytext[yyleng-cnt-2]=='\\';cnt++) ;
  if (cnt%2) {
  	yyless(yyleng-1);
	yymore();
  } else {
	yylval.string=(char *)my_strdup(yytext+1);
	*(yylval.string+yyleng-2)='\0';
	replace(yylval.string);
	return tSTRING;
  }
}


. {if (isprint(yytext[0])) return yytext[0]; else return ' ';}

%%
void yyerror(char *msg)
{
  int i,j;
  
  sprintf(string,"%s at %n",msg,&j);
  if (*yytext=='\n' || *yytext=='\0') {
    sprintf(string+j,"end of line");
  } else {
    i=0;
    string[j++]='\"';
    while(yytext[i]) {
      if (isprint(yytext[i])) string[j++]=yytext[i++];
      else {
	sprintf(string+j,"0x%02x",yytext[i]);
	j+=4;
	break;
      }
    }
    string[j++]='\"';
    string[j]='\0';
  }
  error(ERROR,string);		
  return;
}


void open_main(FILE *file,char *explicit,char *main_file_name) /* open main file */
{
  include_stack_ptr=0;
  
  if (explicit) 
    include_stack[include_stack_ptr]=yy_scan_string(explicit);
  else
    include_stack[include_stack_ptr]=yy_create_buffer(file,YY_BUF_SIZE);
  libfile_stack[include_stack_ptr]=new_file(main_file_name,"main");
  libfile_chain[libfile_chain_length++]=libfile_stack[include_stack_ptr];
  if (!explicit) yy_switch_to_buffer(include_stack[include_stack_ptr]);
  currlib=libfile_stack[0];
  inlib=FALSE;
  
  return;
}

void open_string(char *cmd) /* open string with commands */
{
  yy_switch_to_buffer(yy_scan_string(cmd));
}


int import_lib(char *name) /* import library */
{
  char *full;
  static int end_of_import=FALSE;

  if (!*name) name=pop(stSTRING)->pointer;
  while(isspace(*name)) name++;

  if (!strcmp(name,"__END_OF_IMPORT")) end_of_import=TRUE;
  if (end_of_import) return TRUE;

  /* start line numbers anew */
  libfile_stack[include_stack_ptr]->lineno=mylineno;
 
  include_stack_ptr++;
  if (include_stack_ptr>=MAX_INCLUDE_DEPTH) {
    sprintf(string,"Could not import '%s': nested too deep",name);
    error(ERROR,string);
    return FALSE;
  }

  if (is_bound) {
    full=name;
  } else {
    yyin=open_library(name,&full,FALSE);
    if (!yyin) return FALSE;
    yy_switch_to_buffer(yy_create_buffer(yyin,YY_BUF_SIZE));
    include_stack[include_stack_ptr]=YY_CURRENT_BUFFER;
  }
  libfile_stack[include_stack_ptr]=new_file(full,NULL);
  libfile_chain[libfile_chain_length++]=libfile_stack[include_stack_ptr];
  if (libfile_chain_length>=MAX_INCLUDE_NUMBER) {
    sprintf(string,"Cannot import more than %d libraries",MAX_INCLUDE_NUMBER);
    error(ERROR,string);
    return FALSE;
  }
  if (!libfile_stack[include_stack_ptr]) {
    sprintf(string,"library '%s' has already been imported",full);
    error(ERROR,string);
    return FALSE;
  } 

  if (infolevel>=NOTE && !is_bound) {
    sprintf(string,"importing from file '%s'",full);
    error(NOTE,string);
  }
  return TRUE;
}


FILE *open_library(char *name,char **fullreturn,int without) /* search and open a library */
{
  static char full[200];
  char unquoted[200];
  char *p;
  FILE *lib;
  int i;
  char *trail;

  if (fullreturn) *fullreturn=full;

  for(p=name;strchr(" \"'`",*p);p++) if (!*p) break;
  strncpy(unquoted,p,200);
  for(;!strchr(" \"'`",*p);p++) if (!*p) break;
  if (*p) unquoted[p-name-2]='\0';
  name=unquoted;
  if (strchr(name,'.')) {
    sprintf(string,"library name '%s' contains '.'",name);
    error(ERROR,string);
    return NULL;
  }
  if (!strcmp(name,"main")) {
    if (is_bound) return NULL;
    error(ERROR,"invalid library name 'main'");
    return NULL;
  }

  /* search local */
  trail=".yab";
  for(i=0;i<2;i++) {
    strcpy(full,name);
    if (!strchr(full,'.')) strcat(full,trail);
    lib=fopen(full,"r");
    if (lib) return lib;
    trail="";
    if (!without) break;
  }
  
  /* search in global location */
  trail=".yab";
  for(i=0;i<2;i++) {
    strcpy(full,library_path);
    if (full[0] && !strchr("\\/",full[strlen(full)-1])) {
#ifdef UNIX
      strcat(full,"/");
#else
      strcat(full,"\\");
#endif
    }     
    strcat(full,name);
    if (!strchr(full,'.')) strcat(full,trail);
    lib=fopen(full,"r");
    if (lib) return lib;
    trail="";
    if (!without) break;
  }

  sprintf(string,"couldn't open library '%s'",full);
  error(ERROR,string);
  return NULL;
}


void switchlib(void) /* switch library, called by bison */
{
  if (include_stack_ptr<0) return;
  if (infolevel>=DEBUG) {
    sprintf(string,"switching from '%s' to '%s'",currlib->s,libfile_stack[include_stack_ptr]->s);
    error(DEBUG,string);
  }
  currlib=libfile_stack[include_stack_ptr];
  mylineno=currlib->lineno;
  inlib=(include_stack_ptr>0);
}


