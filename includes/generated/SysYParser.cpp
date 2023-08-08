
// Generated from SysY.g4 by ANTLR 4.12.0


#include "SysYVisitor.h"

#include "SysYParser.h"


using namespace antlrcpp;
using namespace front;

using namespace antlr4;

namespace {

struct SysYParserStaticData final {
  SysYParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SysYParserStaticData(const SysYParserStaticData&) = delete;
  SysYParserStaticData(SysYParserStaticData&&) = delete;
  SysYParserStaticData& operator=(const SysYParserStaticData&) = delete;
  SysYParserStaticData& operator=(SysYParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag sysyParserOnceFlag;
SysYParserStaticData *sysyParserStaticData = nullptr;

void sysyParserInitialize() {
  assert(sysyParserStaticData == nullptr);
  auto staticData = std::make_unique<SysYParserStaticData>(
    std::vector<std::string>{
      "compUnit", "decl", "constDecl", "bType", "constDef", "constInitVal", 
      "varDecl", "varDef", "initVal", "funcDef", "funcType", "funcFparamList", 
      "funcFparam", "block", "blockItem", "stmt", "exp", "cond", "lVal", 
      "rVal", "primExp", "number", "unaryExp", "unaryOp", "funcRparamList", 
      "funcRparam", "mulExp", "addExp", "relExp", "eqExp", "lAndExp", "lOrExp", 
      "constExp"
    },
    std::vector<std::string>{
      "", "'int'", "'float'", "'void'", "'const'", "'return'", "'if'", "'else'", 
      "'for'", "'while'", "'do'", "'break'", "'continue'", "'('", "')'", 
      "'['", "']'", "'{'", "'}'", "','", "';'", "'\\u003F'", "':'", "'='", 
      "'-'", "'!'", "'~'", "'+'", "'*'", "'/'", "'%'", "'&&'", "'||'", "'=='", 
      "'!='", "'<'", "'<='", "'>'", "'>='"
    },
    std::vector<std::string>{
      "", "Int", "Float", "Void", "Const", "Return", "If", "Else", "For", 
      "While", "Do", "Break", "Continue", "Lparen", "Rparen", "Lbrkt", "Rbrkt", 
      "Lbrace", "Rbrace", "Comma", "Semicolon", "Question", "Colon", "Assign", 
      "Minus", "Exclamation", "Tilde", "Addition", "Multiplication", "Division", 
      "Modulo", "LAND", "LOR", "EQ", "NEQ", "LT", "LE", "GT", "GE", "IntLiteral", 
      "FloatLiteral", "Identifier", "STRING", "WS", "LINE_COMMENT", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,45,388,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,1,0,1,0,5,0,69,8,0,10,0,12,
  	0,72,9,0,1,0,1,0,1,1,1,1,3,1,78,8,1,1,2,1,2,1,2,1,2,1,2,5,2,85,8,2,10,
  	2,12,2,88,9,2,1,2,1,2,1,3,1,3,1,4,1,4,1,4,1,4,1,4,5,4,99,8,4,10,4,12,
  	4,102,9,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,5,5,112,8,5,10,5,12,5,115,9,
  	5,3,5,117,8,5,1,5,3,5,120,8,5,1,6,1,6,1,6,1,6,5,6,126,8,6,10,6,12,6,129,
  	9,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,5,7,138,8,7,10,7,12,7,141,9,7,1,7,1,7,
  	1,7,1,7,1,7,5,7,148,8,7,10,7,12,7,151,9,7,1,7,1,7,3,7,155,8,7,1,8,1,8,
  	1,8,1,8,1,8,5,8,162,8,8,10,8,12,8,165,9,8,3,8,167,8,8,1,8,3,8,170,8,8,
  	1,9,1,9,1,9,1,9,3,9,176,8,9,1,9,1,9,1,9,1,10,1,10,1,11,1,11,1,11,5,11,
  	186,8,11,10,11,12,11,189,9,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	5,12,199,8,12,10,12,12,12,202,9,12,3,12,204,8,12,1,13,1,13,5,13,208,8,
  	13,10,13,12,13,211,9,13,1,13,1,13,1,14,1,14,3,14,217,8,14,1,15,1,15,1,
  	15,1,15,1,15,1,15,3,15,225,8,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,255,8,15,1,15,3,15,258,8,15,1,16,
  	1,16,1,17,1,17,1,18,1,18,1,18,1,18,1,18,5,18,269,8,18,10,18,12,18,272,
  	9,18,1,19,1,19,1,19,1,19,1,19,5,19,279,8,19,10,19,12,19,282,9,19,1,20,
  	1,20,1,20,1,20,1,20,1,20,3,20,290,8,20,1,21,1,21,1,22,1,22,1,22,1,22,
  	3,22,298,8,22,1,22,1,22,1,22,1,22,3,22,304,8,22,1,23,1,23,1,24,1,24,1,
  	24,5,24,311,8,24,10,24,12,24,314,9,24,1,25,1,25,3,25,318,8,25,1,26,1,
  	26,1,26,1,26,1,26,1,26,5,26,326,8,26,10,26,12,26,329,9,26,1,27,1,27,1,
  	27,1,27,1,27,1,27,5,27,337,8,27,10,27,12,27,340,9,27,1,28,1,28,1,28,1,
  	28,1,28,1,28,5,28,348,8,28,10,28,12,28,351,9,28,1,29,1,29,1,29,1,29,1,
  	29,1,29,5,29,359,8,29,10,29,12,29,362,9,29,1,30,1,30,1,30,1,30,1,30,1,
  	30,5,30,370,8,30,10,30,12,30,373,9,30,1,31,1,31,1,31,1,31,1,31,1,31,5,
  	31,381,8,31,10,31,12,31,384,9,31,1,32,1,32,1,32,0,6,52,54,56,58,60,62,
  	33,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,
  	48,50,52,54,56,58,60,62,64,0,8,1,0,1,2,1,0,1,3,1,0,39,40,2,0,24,25,27,
  	27,1,0,28,30,2,0,24,24,27,27,1,0,35,38,1,0,33,34,400,0,70,1,0,0,0,2,77,
  	1,0,0,0,4,79,1,0,0,0,6,91,1,0,0,0,8,93,1,0,0,0,10,119,1,0,0,0,12,121,
  	1,0,0,0,14,154,1,0,0,0,16,169,1,0,0,0,18,171,1,0,0,0,20,180,1,0,0,0,22,
  	182,1,0,0,0,24,190,1,0,0,0,26,205,1,0,0,0,28,216,1,0,0,0,30,257,1,0,0,
  	0,32,259,1,0,0,0,34,261,1,0,0,0,36,263,1,0,0,0,38,273,1,0,0,0,40,289,
  	1,0,0,0,42,291,1,0,0,0,44,303,1,0,0,0,46,305,1,0,0,0,48,307,1,0,0,0,50,
  	317,1,0,0,0,52,319,1,0,0,0,54,330,1,0,0,0,56,341,1,0,0,0,58,352,1,0,0,
  	0,60,363,1,0,0,0,62,374,1,0,0,0,64,385,1,0,0,0,66,69,3,2,1,0,67,69,3,
  	18,9,0,68,66,1,0,0,0,68,67,1,0,0,0,69,72,1,0,0,0,70,68,1,0,0,0,70,71,
  	1,0,0,0,71,73,1,0,0,0,72,70,1,0,0,0,73,74,5,0,0,1,74,1,1,0,0,0,75,78,
  	3,4,2,0,76,78,3,12,6,0,77,75,1,0,0,0,77,76,1,0,0,0,78,3,1,0,0,0,79,80,
  	5,4,0,0,80,81,3,6,3,0,81,86,3,8,4,0,82,83,5,19,0,0,83,85,3,8,4,0,84,82,
  	1,0,0,0,85,88,1,0,0,0,86,84,1,0,0,0,86,87,1,0,0,0,87,89,1,0,0,0,88,86,
  	1,0,0,0,89,90,5,20,0,0,90,5,1,0,0,0,91,92,7,0,0,0,92,7,1,0,0,0,93,100,
  	5,41,0,0,94,95,5,15,0,0,95,96,3,64,32,0,96,97,5,16,0,0,97,99,1,0,0,0,
  	98,94,1,0,0,0,99,102,1,0,0,0,100,98,1,0,0,0,100,101,1,0,0,0,101,103,1,
  	0,0,0,102,100,1,0,0,0,103,104,5,23,0,0,104,105,3,10,5,0,105,9,1,0,0,0,
  	106,120,3,64,32,0,107,116,5,17,0,0,108,113,3,10,5,0,109,110,5,19,0,0,
  	110,112,3,10,5,0,111,109,1,0,0,0,112,115,1,0,0,0,113,111,1,0,0,0,113,
  	114,1,0,0,0,114,117,1,0,0,0,115,113,1,0,0,0,116,108,1,0,0,0,116,117,1,
  	0,0,0,117,118,1,0,0,0,118,120,5,18,0,0,119,106,1,0,0,0,119,107,1,0,0,
  	0,120,11,1,0,0,0,121,122,3,6,3,0,122,127,3,14,7,0,123,124,5,19,0,0,124,
  	126,3,14,7,0,125,123,1,0,0,0,126,129,1,0,0,0,127,125,1,0,0,0,127,128,
  	1,0,0,0,128,130,1,0,0,0,129,127,1,0,0,0,130,131,5,20,0,0,131,13,1,0,0,
  	0,132,139,5,41,0,0,133,134,5,15,0,0,134,135,3,64,32,0,135,136,5,16,0,
  	0,136,138,1,0,0,0,137,133,1,0,0,0,138,141,1,0,0,0,139,137,1,0,0,0,139,
  	140,1,0,0,0,140,155,1,0,0,0,141,139,1,0,0,0,142,149,5,41,0,0,143,144,
  	5,15,0,0,144,145,3,64,32,0,145,146,5,16,0,0,146,148,1,0,0,0,147,143,1,
  	0,0,0,148,151,1,0,0,0,149,147,1,0,0,0,149,150,1,0,0,0,150,152,1,0,0,0,
  	151,149,1,0,0,0,152,153,5,23,0,0,153,155,3,16,8,0,154,132,1,0,0,0,154,
  	142,1,0,0,0,155,15,1,0,0,0,156,170,3,32,16,0,157,166,5,17,0,0,158,163,
  	3,16,8,0,159,160,5,19,0,0,160,162,3,16,8,0,161,159,1,0,0,0,162,165,1,
  	0,0,0,163,161,1,0,0,0,163,164,1,0,0,0,164,167,1,0,0,0,165,163,1,0,0,0,
  	166,158,1,0,0,0,166,167,1,0,0,0,167,168,1,0,0,0,168,170,5,18,0,0,169,
  	156,1,0,0,0,169,157,1,0,0,0,170,17,1,0,0,0,171,172,3,20,10,0,172,173,
  	5,41,0,0,173,175,5,13,0,0,174,176,3,22,11,0,175,174,1,0,0,0,175,176,1,
  	0,0,0,176,177,1,0,0,0,177,178,5,14,0,0,178,179,3,26,13,0,179,19,1,0,0,
  	0,180,181,7,1,0,0,181,21,1,0,0,0,182,187,3,24,12,0,183,184,5,19,0,0,184,
  	186,3,24,12,0,185,183,1,0,0,0,186,189,1,0,0,0,187,185,1,0,0,0,187,188,
  	1,0,0,0,188,23,1,0,0,0,189,187,1,0,0,0,190,191,3,6,3,0,191,203,5,41,0,
  	0,192,193,5,15,0,0,193,200,5,16,0,0,194,195,5,15,0,0,195,196,3,64,32,
  	0,196,197,5,16,0,0,197,199,1,0,0,0,198,194,1,0,0,0,199,202,1,0,0,0,200,
  	198,1,0,0,0,200,201,1,0,0,0,201,204,1,0,0,0,202,200,1,0,0,0,203,192,1,
  	0,0,0,203,204,1,0,0,0,204,25,1,0,0,0,205,209,5,17,0,0,206,208,3,28,14,
  	0,207,206,1,0,0,0,208,211,1,0,0,0,209,207,1,0,0,0,209,210,1,0,0,0,210,
  	212,1,0,0,0,211,209,1,0,0,0,212,213,5,18,0,0,213,27,1,0,0,0,214,217,3,
  	2,1,0,215,217,3,30,15,0,216,214,1,0,0,0,216,215,1,0,0,0,217,29,1,0,0,
  	0,218,219,3,36,18,0,219,220,5,23,0,0,220,221,3,32,16,0,221,222,5,20,0,
  	0,222,258,1,0,0,0,223,225,3,32,16,0,224,223,1,0,0,0,224,225,1,0,0,0,225,
  	226,1,0,0,0,226,258,5,20,0,0,227,258,3,26,13,0,228,229,5,6,0,0,229,230,
  	5,13,0,0,230,231,3,34,17,0,231,232,5,14,0,0,232,233,3,30,15,0,233,258,
  	1,0,0,0,234,235,5,6,0,0,235,236,5,13,0,0,236,237,3,34,17,0,237,238,5,
  	14,0,0,238,239,3,30,15,0,239,240,5,7,0,0,240,241,3,30,15,0,241,258,1,
  	0,0,0,242,243,5,9,0,0,243,244,5,13,0,0,244,245,3,34,17,0,245,246,5,14,
  	0,0,246,247,3,30,15,0,247,258,1,0,0,0,248,249,5,11,0,0,249,258,5,20,0,
  	0,250,251,5,12,0,0,251,258,5,20,0,0,252,254,5,5,0,0,253,255,3,32,16,0,
  	254,253,1,0,0,0,254,255,1,0,0,0,255,256,1,0,0,0,256,258,5,20,0,0,257,
  	218,1,0,0,0,257,224,1,0,0,0,257,227,1,0,0,0,257,228,1,0,0,0,257,234,1,
  	0,0,0,257,242,1,0,0,0,257,248,1,0,0,0,257,250,1,0,0,0,257,252,1,0,0,0,
  	258,31,1,0,0,0,259,260,3,54,27,0,260,33,1,0,0,0,261,262,3,62,31,0,262,
  	35,1,0,0,0,263,270,5,41,0,0,264,265,5,15,0,0,265,266,3,32,16,0,266,267,
  	5,16,0,0,267,269,1,0,0,0,268,264,1,0,0,0,269,272,1,0,0,0,270,268,1,0,
  	0,0,270,271,1,0,0,0,271,37,1,0,0,0,272,270,1,0,0,0,273,280,5,41,0,0,274,
  	275,5,15,0,0,275,276,3,32,16,0,276,277,5,16,0,0,277,279,1,0,0,0,278,274,
  	1,0,0,0,279,282,1,0,0,0,280,278,1,0,0,0,280,281,1,0,0,0,281,39,1,0,0,
  	0,282,280,1,0,0,0,283,284,5,13,0,0,284,285,3,32,16,0,285,286,5,14,0,0,
  	286,290,1,0,0,0,287,290,3,38,19,0,288,290,3,42,21,0,289,283,1,0,0,0,289,
  	287,1,0,0,0,289,288,1,0,0,0,290,41,1,0,0,0,291,292,7,2,0,0,292,43,1,0,
  	0,0,293,304,3,40,20,0,294,295,5,41,0,0,295,297,5,13,0,0,296,298,3,48,
  	24,0,297,296,1,0,0,0,297,298,1,0,0,0,298,299,1,0,0,0,299,304,5,14,0,0,
  	300,301,3,46,23,0,301,302,3,44,22,0,302,304,1,0,0,0,303,293,1,0,0,0,303,
  	294,1,0,0,0,303,300,1,0,0,0,304,45,1,0,0,0,305,306,7,3,0,0,306,47,1,0,
  	0,0,307,312,3,50,25,0,308,309,5,19,0,0,309,311,3,50,25,0,310,308,1,0,
  	0,0,311,314,1,0,0,0,312,310,1,0,0,0,312,313,1,0,0,0,313,49,1,0,0,0,314,
  	312,1,0,0,0,315,318,3,32,16,0,316,318,5,42,0,0,317,315,1,0,0,0,317,316,
  	1,0,0,0,318,51,1,0,0,0,319,320,6,26,-1,0,320,321,3,44,22,0,321,327,1,
  	0,0,0,322,323,10,1,0,0,323,324,7,4,0,0,324,326,3,44,22,0,325,322,1,0,
  	0,0,326,329,1,0,0,0,327,325,1,0,0,0,327,328,1,0,0,0,328,53,1,0,0,0,329,
  	327,1,0,0,0,330,331,6,27,-1,0,331,332,3,52,26,0,332,338,1,0,0,0,333,334,
  	10,1,0,0,334,335,7,5,0,0,335,337,3,52,26,0,336,333,1,0,0,0,337,340,1,
  	0,0,0,338,336,1,0,0,0,338,339,1,0,0,0,339,55,1,0,0,0,340,338,1,0,0,0,
  	341,342,6,28,-1,0,342,343,3,54,27,0,343,349,1,0,0,0,344,345,10,1,0,0,
  	345,346,7,6,0,0,346,348,3,54,27,0,347,344,1,0,0,0,348,351,1,0,0,0,349,
  	347,1,0,0,0,349,350,1,0,0,0,350,57,1,0,0,0,351,349,1,0,0,0,352,353,6,
  	29,-1,0,353,354,3,56,28,0,354,360,1,0,0,0,355,356,10,1,0,0,356,357,7,
  	7,0,0,357,359,3,56,28,0,358,355,1,0,0,0,359,362,1,0,0,0,360,358,1,0,0,
  	0,360,361,1,0,0,0,361,59,1,0,0,0,362,360,1,0,0,0,363,364,6,30,-1,0,364,
  	365,3,58,29,0,365,371,1,0,0,0,366,367,10,1,0,0,367,368,5,31,0,0,368,370,
  	3,58,29,0,369,366,1,0,0,0,370,373,1,0,0,0,371,369,1,0,0,0,371,372,1,0,
  	0,0,372,61,1,0,0,0,373,371,1,0,0,0,374,375,6,31,-1,0,375,376,3,60,30,
  	0,376,382,1,0,0,0,377,378,10,1,0,0,378,379,5,32,0,0,379,381,3,60,30,0,
  	380,377,1,0,0,0,381,384,1,0,0,0,382,380,1,0,0,0,382,383,1,0,0,0,383,63,
  	1,0,0,0,384,382,1,0,0,0,385,386,3,54,27,0,386,65,1,0,0,0,37,68,70,77,
  	86,100,113,116,119,127,139,149,154,163,166,169,175,187,200,203,209,216,
  	224,254,257,270,280,289,297,303,312,317,327,338,349,360,371,382
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  sysyParserStaticData = staticData.release();
}

}

SysYParser::SysYParser(TokenStream *input) : SysYParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

SysYParser::SysYParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  SysYParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *sysyParserStaticData->atn, sysyParserStaticData->decisionToDFA, sysyParserStaticData->sharedContextCache, options);
}

SysYParser::~SysYParser() {
  delete _interpreter;
}

const atn::ATN& SysYParser::getATN() const {
  return *sysyParserStaticData->atn;
}

std::string SysYParser::getGrammarFileName() const {
  return "SysY.g4";
}

const std::vector<std::string>& SysYParser::getRuleNames() const {
  return sysyParserStaticData->ruleNames;
}

const dfa::Vocabulary& SysYParser::getVocabulary() const {
  return sysyParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SysYParser::getSerializedATN() const {
  return sysyParserStaticData->serializedATN;
}


//----------------- CompUnitContext ------------------------------------------------------------------

SysYParser::CompUnitContext::CompUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::CompUnitContext::EOF() {
  return getToken(SysYParser::EOF, 0);
}

std::vector<SysYParser::DeclContext *> SysYParser::CompUnitContext::decl() {
  return getRuleContexts<SysYParser::DeclContext>();
}

SysYParser::DeclContext* SysYParser::CompUnitContext::decl(size_t i) {
  return getRuleContext<SysYParser::DeclContext>(i);
}

std::vector<SysYParser::FuncDefContext *> SysYParser::CompUnitContext::funcDef() {
  return getRuleContexts<SysYParser::FuncDefContext>();
}

SysYParser::FuncDefContext* SysYParser::CompUnitContext::funcDef(size_t i) {
  return getRuleContext<SysYParser::FuncDefContext>(i);
}


size_t SysYParser::CompUnitContext::getRuleIndex() const {
  return SysYParser::RuleCompUnit;
}


std::any SysYParser::CompUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitCompUnit(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::CompUnitContext* SysYParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, SysYParser::RuleCompUnit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 30) != 0)) {
      setState(68);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(66);
        decl();
        break;
      }

      case 2: {
        setState(67);
        funcDef();
        break;
      }

      default:
        break;
      }
      setState(72);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(73);
    match(SysYParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

SysYParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ConstDeclContext* SysYParser::DeclContext::constDecl() {
  return getRuleContext<SysYParser::ConstDeclContext>(0);
}

SysYParser::VarDeclContext* SysYParser::DeclContext::varDecl() {
  return getRuleContext<SysYParser::VarDeclContext>(0);
}


size_t SysYParser::DeclContext::getRuleIndex() const {
  return SysYParser::RuleDecl;
}


std::any SysYParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::DeclContext* SysYParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 2, SysYParser::RuleDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(77);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::Const: {
        enterOuterAlt(_localctx, 1);
        setState(75);
        constDecl();
        break;
      }

      case SysYParser::Int:
      case SysYParser::Float: {
        enterOuterAlt(_localctx, 2);
        setState(76);
        varDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclContext ------------------------------------------------------------------

SysYParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::ConstDeclContext::Const() {
  return getToken(SysYParser::Const, 0);
}

SysYParser::BTypeContext* SysYParser::ConstDeclContext::bType() {
  return getRuleContext<SysYParser::BTypeContext>(0);
}

std::vector<SysYParser::ConstDefContext *> SysYParser::ConstDeclContext::constDef() {
  return getRuleContexts<SysYParser::ConstDefContext>();
}

SysYParser::ConstDefContext* SysYParser::ConstDeclContext::constDef(size_t i) {
  return getRuleContext<SysYParser::ConstDefContext>(i);
}

tree::TerminalNode* SysYParser::ConstDeclContext::Semicolon() {
  return getToken(SysYParser::Semicolon, 0);
}

std::vector<tree::TerminalNode *> SysYParser::ConstDeclContext::Comma() {
  return getTokens(SysYParser::Comma);
}

tree::TerminalNode* SysYParser::ConstDeclContext::Comma(size_t i) {
  return getToken(SysYParser::Comma, i);
}


size_t SysYParser::ConstDeclContext::getRuleIndex() const {
  return SysYParser::RuleConstDecl;
}


std::any SysYParser::ConstDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstDecl(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstDeclContext* SysYParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, SysYParser::RuleConstDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    match(SysYParser::Const);
    setState(80);
    bType();
    setState(81);
    constDef();
    setState(86);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::Comma) {
      setState(82);
      match(SysYParser::Comma);
      setState(83);
      constDef();
      setState(88);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(89);
    match(SysYParser::Semicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BTypeContext ------------------------------------------------------------------

SysYParser::BTypeContext::BTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::BTypeContext::Int() {
  return getToken(SysYParser::Int, 0);
}

tree::TerminalNode* SysYParser::BTypeContext::Float() {
  return getToken(SysYParser::Float, 0);
}


size_t SysYParser::BTypeContext::getRuleIndex() const {
  return SysYParser::RuleBType;
}


std::any SysYParser::BTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBType(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::BTypeContext* SysYParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 6, SysYParser::RuleBType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
    _la = _input->LA(1);
    if (!(_la == SysYParser::Int

    || _la == SysYParser::Float)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDefContext ------------------------------------------------------------------

SysYParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::ConstDefContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

tree::TerminalNode* SysYParser::ConstDefContext::Assign() {
  return getToken(SysYParser::Assign, 0);
}

SysYParser::ConstInitValContext* SysYParser::ConstDefContext::constInitVal() {
  return getRuleContext<SysYParser::ConstInitValContext>(0);
}

std::vector<tree::TerminalNode *> SysYParser::ConstDefContext::Lbrkt() {
  return getTokens(SysYParser::Lbrkt);
}

tree::TerminalNode* SysYParser::ConstDefContext::Lbrkt(size_t i) {
  return getToken(SysYParser::Lbrkt, i);
}

std::vector<SysYParser::ConstExpContext *> SysYParser::ConstDefContext::constExp() {
  return getRuleContexts<SysYParser::ConstExpContext>();
}

SysYParser::ConstExpContext* SysYParser::ConstDefContext::constExp(size_t i) {
  return getRuleContext<SysYParser::ConstExpContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::ConstDefContext::Rbrkt() {
  return getTokens(SysYParser::Rbrkt);
}

tree::TerminalNode* SysYParser::ConstDefContext::Rbrkt(size_t i) {
  return getToken(SysYParser::Rbrkt, i);
}


size_t SysYParser::ConstDefContext::getRuleIndex() const {
  return SysYParser::RuleConstDef;
}


std::any SysYParser::ConstDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstDef(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstDefContext* SysYParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 8, SysYParser::RuleConstDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    match(SysYParser::Identifier);
    setState(100);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::Lbrkt) {
      setState(94);
      match(SysYParser::Lbrkt);
      setState(95);
      constExp();
      setState(96);
      match(SysYParser::Rbrkt);
      setState(102);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(103);
    match(SysYParser::Assign);
    setState(104);
    constInitVal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstInitValContext ------------------------------------------------------------------

SysYParser::ConstInitValContext::ConstInitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::ConstInitValContext::getRuleIndex() const {
  return SysYParser::RuleConstInitVal;
}

void SysYParser::ConstInitValContext::copyFrom(ConstInitValContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ListConstInitValContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::ListConstInitValContext::Lbrace() {
  return getToken(SysYParser::Lbrace, 0);
}

tree::TerminalNode* SysYParser::ListConstInitValContext::Rbrace() {
  return getToken(SysYParser::Rbrace, 0);
}

std::vector<SysYParser::ConstInitValContext *> SysYParser::ListConstInitValContext::constInitVal() {
  return getRuleContexts<SysYParser::ConstInitValContext>();
}

SysYParser::ConstInitValContext* SysYParser::ListConstInitValContext::constInitVal(size_t i) {
  return getRuleContext<SysYParser::ConstInitValContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::ListConstInitValContext::Comma() {
  return getTokens(SysYParser::Comma);
}

tree::TerminalNode* SysYParser::ListConstInitValContext::Comma(size_t i) {
  return getToken(SysYParser::Comma, i);
}

SysYParser::ListConstInitValContext::ListConstInitValContext(ConstInitValContext *ctx) { copyFrom(ctx); }


std::any SysYParser::ListConstInitValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitListConstInitVal(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ScalarConstInitValContext ------------------------------------------------------------------

SysYParser::ConstExpContext* SysYParser::ScalarConstInitValContext::constExp() {
  return getRuleContext<SysYParser::ConstExpContext>(0);
}

SysYParser::ScalarConstInitValContext::ScalarConstInitValContext(ConstInitValContext *ctx) { copyFrom(ctx); }


std::any SysYParser::ScalarConstInitValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitScalarConstInitVal(this);
  else
    return visitor->visitChildren(this);
}
SysYParser::ConstInitValContext* SysYParser::constInitVal() {
  ConstInitValContext *_localctx = _tracker.createInstance<ConstInitValContext>(_ctx, getState());
  enterRule(_localctx, 10, SysYParser::RuleConstInitVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(119);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::Lparen:
      case SysYParser::Minus:
      case SysYParser::Exclamation:
      case SysYParser::Addition:
      case SysYParser::IntLiteral:
      case SysYParser::FloatLiteral:
      case SysYParser::Identifier: {
        _localctx = _tracker.createInstance<SysYParser::ScalarConstInitValContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(106);
        constExp();
        break;
      }

      case SysYParser::Lbrace: {
        _localctx = _tracker.createInstance<SysYParser::ListConstInitValContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(107);
        match(SysYParser::Lbrace);
        setState(116);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 3848475385856) != 0)) {
          setState(108);
          constInitVal();
          setState(113);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SysYParser::Comma) {
            setState(109);
            match(SysYParser::Comma);
            setState(110);
            constInitVal();
            setState(115);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(118);
        match(SysYParser::Rbrace);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

SysYParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::BTypeContext* SysYParser::VarDeclContext::bType() {
  return getRuleContext<SysYParser::BTypeContext>(0);
}

std::vector<SysYParser::VarDefContext *> SysYParser::VarDeclContext::varDef() {
  return getRuleContexts<SysYParser::VarDefContext>();
}

SysYParser::VarDefContext* SysYParser::VarDeclContext::varDef(size_t i) {
  return getRuleContext<SysYParser::VarDefContext>(i);
}

tree::TerminalNode* SysYParser::VarDeclContext::Semicolon() {
  return getToken(SysYParser::Semicolon, 0);
}

std::vector<tree::TerminalNode *> SysYParser::VarDeclContext::Comma() {
  return getTokens(SysYParser::Comma);
}

tree::TerminalNode* SysYParser::VarDeclContext::Comma(size_t i) {
  return getToken(SysYParser::Comma, i);
}


size_t SysYParser::VarDeclContext::getRuleIndex() const {
  return SysYParser::RuleVarDecl;
}


std::any SysYParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::VarDeclContext* SysYParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, SysYParser::RuleVarDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    bType();
    setState(122);
    varDef();
    setState(127);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::Comma) {
      setState(123);
      match(SysYParser::Comma);
      setState(124);
      varDef();
      setState(129);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(130);
    match(SysYParser::Semicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

SysYParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::VarDefContext::getRuleIndex() const {
  return SysYParser::RuleVarDef;
}

void SysYParser::VarDefContext::copyFrom(VarDefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnInitVarDefContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::UnInitVarDefContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

std::vector<tree::TerminalNode *> SysYParser::UnInitVarDefContext::Lbrkt() {
  return getTokens(SysYParser::Lbrkt);
}

tree::TerminalNode* SysYParser::UnInitVarDefContext::Lbrkt(size_t i) {
  return getToken(SysYParser::Lbrkt, i);
}

std::vector<SysYParser::ConstExpContext *> SysYParser::UnInitVarDefContext::constExp() {
  return getRuleContexts<SysYParser::ConstExpContext>();
}

SysYParser::ConstExpContext* SysYParser::UnInitVarDefContext::constExp(size_t i) {
  return getRuleContext<SysYParser::ConstExpContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::UnInitVarDefContext::Rbrkt() {
  return getTokens(SysYParser::Rbrkt);
}

tree::TerminalNode* SysYParser::UnInitVarDefContext::Rbrkt(size_t i) {
  return getToken(SysYParser::Rbrkt, i);
}

SysYParser::UnInitVarDefContext::UnInitVarDefContext(VarDefContext *ctx) { copyFrom(ctx); }


std::any SysYParser::UnInitVarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitUnInitVarDef(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InitVarDefContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::InitVarDefContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

tree::TerminalNode* SysYParser::InitVarDefContext::Assign() {
  return getToken(SysYParser::Assign, 0);
}

SysYParser::InitValContext* SysYParser::InitVarDefContext::initVal() {
  return getRuleContext<SysYParser::InitValContext>(0);
}

std::vector<tree::TerminalNode *> SysYParser::InitVarDefContext::Lbrkt() {
  return getTokens(SysYParser::Lbrkt);
}

tree::TerminalNode* SysYParser::InitVarDefContext::Lbrkt(size_t i) {
  return getToken(SysYParser::Lbrkt, i);
}

std::vector<SysYParser::ConstExpContext *> SysYParser::InitVarDefContext::constExp() {
  return getRuleContexts<SysYParser::ConstExpContext>();
}

SysYParser::ConstExpContext* SysYParser::InitVarDefContext::constExp(size_t i) {
  return getRuleContext<SysYParser::ConstExpContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::InitVarDefContext::Rbrkt() {
  return getTokens(SysYParser::Rbrkt);
}

tree::TerminalNode* SysYParser::InitVarDefContext::Rbrkt(size_t i) {
  return getToken(SysYParser::Rbrkt, i);
}

SysYParser::InitVarDefContext::InitVarDefContext(VarDefContext *ctx) { copyFrom(ctx); }


std::any SysYParser::InitVarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitInitVarDef(this);
  else
    return visitor->visitChildren(this);
}
SysYParser::VarDefContext* SysYParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 14, SysYParser::RuleVarDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(154);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<SysYParser::UnInitVarDefContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(132);
      match(SysYParser::Identifier);
      setState(139);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SysYParser::Lbrkt) {
        setState(133);
        match(SysYParser::Lbrkt);
        setState(134);
        constExp();
        setState(135);
        match(SysYParser::Rbrkt);
        setState(141);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SysYParser::InitVarDefContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(142);
      match(SysYParser::Identifier);
      setState(149);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SysYParser::Lbrkt) {
        setState(143);
        match(SysYParser::Lbrkt);
        setState(144);
        constExp();
        setState(145);
        match(SysYParser::Rbrkt);
        setState(151);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(152);
      match(SysYParser::Assign);
      setState(153);
      initVal();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitValContext ------------------------------------------------------------------

SysYParser::InitValContext::InitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::InitValContext::getRuleIndex() const {
  return SysYParser::RuleInitVal;
}

void SysYParser::InitValContext::copyFrom(InitValContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ScalarInitValContext ------------------------------------------------------------------

SysYParser::ExpContext* SysYParser::ScalarInitValContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::ScalarInitValContext::ScalarInitValContext(InitValContext *ctx) { copyFrom(ctx); }


std::any SysYParser::ScalarInitValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitScalarInitVal(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ListInitValContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::ListInitValContext::Lbrace() {
  return getToken(SysYParser::Lbrace, 0);
}

tree::TerminalNode* SysYParser::ListInitValContext::Rbrace() {
  return getToken(SysYParser::Rbrace, 0);
}

std::vector<SysYParser::InitValContext *> SysYParser::ListInitValContext::initVal() {
  return getRuleContexts<SysYParser::InitValContext>();
}

SysYParser::InitValContext* SysYParser::ListInitValContext::initVal(size_t i) {
  return getRuleContext<SysYParser::InitValContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::ListInitValContext::Comma() {
  return getTokens(SysYParser::Comma);
}

tree::TerminalNode* SysYParser::ListInitValContext::Comma(size_t i) {
  return getToken(SysYParser::Comma, i);
}

SysYParser::ListInitValContext::ListInitValContext(InitValContext *ctx) { copyFrom(ctx); }


std::any SysYParser::ListInitValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitListInitVal(this);
  else
    return visitor->visitChildren(this);
}
SysYParser::InitValContext* SysYParser::initVal() {
  InitValContext *_localctx = _tracker.createInstance<InitValContext>(_ctx, getState());
  enterRule(_localctx, 16, SysYParser::RuleInitVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(169);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::Lparen:
      case SysYParser::Minus:
      case SysYParser::Exclamation:
      case SysYParser::Addition:
      case SysYParser::IntLiteral:
      case SysYParser::FloatLiteral:
      case SysYParser::Identifier: {
        _localctx = _tracker.createInstance<SysYParser::ScalarInitValContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(156);
        exp();
        break;
      }

      case SysYParser::Lbrace: {
        _localctx = _tracker.createInstance<SysYParser::ListInitValContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(157);
        match(SysYParser::Lbrace);
        setState(166);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 3848475385856) != 0)) {
          setState(158);
          initVal();
          setState(163);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SysYParser::Comma) {
            setState(159);
            match(SysYParser::Comma);
            setState(160);
            initVal();
            setState(165);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(168);
        match(SysYParser::Rbrace);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

SysYParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::FuncTypeContext* SysYParser::FuncDefContext::funcType() {
  return getRuleContext<SysYParser::FuncTypeContext>(0);
}

tree::TerminalNode* SysYParser::FuncDefContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

tree::TerminalNode* SysYParser::FuncDefContext::Lparen() {
  return getToken(SysYParser::Lparen, 0);
}

tree::TerminalNode* SysYParser::FuncDefContext::Rparen() {
  return getToken(SysYParser::Rparen, 0);
}

SysYParser::BlockContext* SysYParser::FuncDefContext::block() {
  return getRuleContext<SysYParser::BlockContext>(0);
}

SysYParser::FuncFparamListContext* SysYParser::FuncDefContext::funcFparamList() {
  return getRuleContext<SysYParser::FuncFparamListContext>(0);
}


size_t SysYParser::FuncDefContext::getRuleIndex() const {
  return SysYParser::RuleFuncDef;
}


std::any SysYParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncDefContext* SysYParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 18, SysYParser::RuleFuncDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    funcType();
    setState(172);
    match(SysYParser::Identifier);
    setState(173);
    match(SysYParser::Lparen);
    setState(175);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::Int

    || _la == SysYParser::Float) {
      setState(174);
      funcFparamList();
    }
    setState(177);
    match(SysYParser::Rparen);
    setState(178);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

SysYParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::FuncTypeContext::Void() {
  return getToken(SysYParser::Void, 0);
}

tree::TerminalNode* SysYParser::FuncTypeContext::Int() {
  return getToken(SysYParser::Int, 0);
}

tree::TerminalNode* SysYParser::FuncTypeContext::Float() {
  return getToken(SysYParser::Float, 0);
}


size_t SysYParser::FuncTypeContext::getRuleIndex() const {
  return SysYParser::RuleFuncType;
}


std::any SysYParser::FuncTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncType(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncTypeContext* SysYParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 20, SysYParser::RuleFuncType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 14) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFparamListContext ------------------------------------------------------------------

SysYParser::FuncFparamListContext::FuncFparamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::FuncFparamContext *> SysYParser::FuncFparamListContext::funcFparam() {
  return getRuleContexts<SysYParser::FuncFparamContext>();
}

SysYParser::FuncFparamContext* SysYParser::FuncFparamListContext::funcFparam(size_t i) {
  return getRuleContext<SysYParser::FuncFparamContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::FuncFparamListContext::Comma() {
  return getTokens(SysYParser::Comma);
}

tree::TerminalNode* SysYParser::FuncFparamListContext::Comma(size_t i) {
  return getToken(SysYParser::Comma, i);
}


size_t SysYParser::FuncFparamListContext::getRuleIndex() const {
  return SysYParser::RuleFuncFparamList;
}


std::any SysYParser::FuncFparamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncFparamList(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncFparamListContext* SysYParser::funcFparamList() {
  FuncFparamListContext *_localctx = _tracker.createInstance<FuncFparamListContext>(_ctx, getState());
  enterRule(_localctx, 22, SysYParser::RuleFuncFparamList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    funcFparam();
    setState(187);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::Comma) {
      setState(183);
      match(SysYParser::Comma);
      setState(184);
      funcFparam();
      setState(189);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFparamContext ------------------------------------------------------------------

SysYParser::FuncFparamContext::FuncFparamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::BTypeContext* SysYParser::FuncFparamContext::bType() {
  return getRuleContext<SysYParser::BTypeContext>(0);
}

tree::TerminalNode* SysYParser::FuncFparamContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

std::vector<tree::TerminalNode *> SysYParser::FuncFparamContext::Lbrkt() {
  return getTokens(SysYParser::Lbrkt);
}

tree::TerminalNode* SysYParser::FuncFparamContext::Lbrkt(size_t i) {
  return getToken(SysYParser::Lbrkt, i);
}

std::vector<tree::TerminalNode *> SysYParser::FuncFparamContext::Rbrkt() {
  return getTokens(SysYParser::Rbrkt);
}

tree::TerminalNode* SysYParser::FuncFparamContext::Rbrkt(size_t i) {
  return getToken(SysYParser::Rbrkt, i);
}

std::vector<SysYParser::ConstExpContext *> SysYParser::FuncFparamContext::constExp() {
  return getRuleContexts<SysYParser::ConstExpContext>();
}

SysYParser::ConstExpContext* SysYParser::FuncFparamContext::constExp(size_t i) {
  return getRuleContext<SysYParser::ConstExpContext>(i);
}


size_t SysYParser::FuncFparamContext::getRuleIndex() const {
  return SysYParser::RuleFuncFparam;
}


std::any SysYParser::FuncFparamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncFparam(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncFparamContext* SysYParser::funcFparam() {
  FuncFparamContext *_localctx = _tracker.createInstance<FuncFparamContext>(_ctx, getState());
  enterRule(_localctx, 24, SysYParser::RuleFuncFparam);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    bType();
    setState(191);
    match(SysYParser::Identifier);
    setState(203);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::Lbrkt) {
      setState(192);
      match(SysYParser::Lbrkt);
      setState(193);
      match(SysYParser::Rbrkt);
      setState(200);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SysYParser::Lbrkt) {
        setState(194);
        match(SysYParser::Lbrkt);
        setState(195);
        constExp();
        setState(196);
        match(SysYParser::Rbrkt);
        setState(202);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

SysYParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::BlockContext::Lbrace() {
  return getToken(SysYParser::Lbrace, 0);
}

tree::TerminalNode* SysYParser::BlockContext::Rbrace() {
  return getToken(SysYParser::Rbrace, 0);
}

std::vector<SysYParser::BlockItemContext *> SysYParser::BlockContext::blockItem() {
  return getRuleContexts<SysYParser::BlockItemContext>();
}

SysYParser::BlockItemContext* SysYParser::BlockContext::blockItem(size_t i) {
  return getRuleContext<SysYParser::BlockItemContext>(i);
}


size_t SysYParser::BlockContext::getRuleIndex() const {
  return SysYParser::RuleBlock;
}


std::any SysYParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::BlockContext* SysYParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 26, SysYParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    match(SysYParser::Lbrace);
    setState(209);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3848476441206) != 0)) {
      setState(206);
      blockItem();
      setState(211);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(212);
    match(SysYParser::Rbrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

SysYParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::DeclContext* SysYParser::BlockItemContext::decl() {
  return getRuleContext<SysYParser::DeclContext>(0);
}

SysYParser::StmtContext* SysYParser::BlockItemContext::stmt() {
  return getRuleContext<SysYParser::StmtContext>(0);
}


size_t SysYParser::BlockItemContext::getRuleIndex() const {
  return SysYParser::RuleBlockItem;
}


std::any SysYParser::BlockItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBlockItem(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::BlockItemContext* SysYParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 28, SysYParser::RuleBlockItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(216);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::Int:
      case SysYParser::Float:
      case SysYParser::Const: {
        enterOuterAlt(_localctx, 1);
        setState(214);
        decl();
        break;
      }

      case SysYParser::Return:
      case SysYParser::If:
      case SysYParser::While:
      case SysYParser::Break:
      case SysYParser::Continue:
      case SysYParser::Lparen:
      case SysYParser::Lbrace:
      case SysYParser::Semicolon:
      case SysYParser::Minus:
      case SysYParser::Exclamation:
      case SysYParser::Addition:
      case SysYParser::IntLiteral:
      case SysYParser::FloatLiteral:
      case SysYParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(215);
        stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

SysYParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::StmtContext::getRuleIndex() const {
  return SysYParser::RuleStmt;
}

void SysYParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- WhileStmtContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::WhileStmtContext::While() {
  return getToken(SysYParser::While, 0);
}

tree::TerminalNode* SysYParser::WhileStmtContext::Lparen() {
  return getToken(SysYParser::Lparen, 0);
}

SysYParser::CondContext* SysYParser::WhileStmtContext::cond() {
  return getRuleContext<SysYParser::CondContext>(0);
}

tree::TerminalNode* SysYParser::WhileStmtContext::Rparen() {
  return getToken(SysYParser::Rparen, 0);
}

SysYParser::StmtContext* SysYParser::WhileStmtContext::stmt() {
  return getRuleContext<SysYParser::StmtContext>(0);
}

SysYParser::WhileStmtContext::WhileStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any SysYParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::IfStmtContext::If() {
  return getToken(SysYParser::If, 0);
}

tree::TerminalNode* SysYParser::IfStmtContext::Lparen() {
  return getToken(SysYParser::Lparen, 0);
}

SysYParser::CondContext* SysYParser::IfStmtContext::cond() {
  return getRuleContext<SysYParser::CondContext>(0);
}

tree::TerminalNode* SysYParser::IfStmtContext::Rparen() {
  return getToken(SysYParser::Rparen, 0);
}

SysYParser::StmtContext* SysYParser::IfStmtContext::stmt() {
  return getRuleContext<SysYParser::StmtContext>(0);
}

SysYParser::IfStmtContext::IfStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any SysYParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BlockStmtContext ------------------------------------------------------------------

SysYParser::BlockContext* SysYParser::BlockStmtContext::block() {
  return getRuleContext<SysYParser::BlockContext>(0);
}

SysYParser::BlockStmtContext::BlockStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any SysYParser::BlockStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBlockStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfElseStmtContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::IfElseStmtContext::If() {
  return getToken(SysYParser::If, 0);
}

tree::TerminalNode* SysYParser::IfElseStmtContext::Lparen() {
  return getToken(SysYParser::Lparen, 0);
}

SysYParser::CondContext* SysYParser::IfElseStmtContext::cond() {
  return getRuleContext<SysYParser::CondContext>(0);
}

tree::TerminalNode* SysYParser::IfElseStmtContext::Rparen() {
  return getToken(SysYParser::Rparen, 0);
}

std::vector<SysYParser::StmtContext *> SysYParser::IfElseStmtContext::stmt() {
  return getRuleContexts<SysYParser::StmtContext>();
}

SysYParser::StmtContext* SysYParser::IfElseStmtContext::stmt(size_t i) {
  return getRuleContext<SysYParser::StmtContext>(i);
}

tree::TerminalNode* SysYParser::IfElseStmtContext::Else() {
  return getToken(SysYParser::Else, 0);
}

SysYParser::IfElseStmtContext::IfElseStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any SysYParser::IfElseStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitIfElseStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BreakStmtContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::BreakStmtContext::Break() {
  return getToken(SysYParser::Break, 0);
}

tree::TerminalNode* SysYParser::BreakStmtContext::Semicolon() {
  return getToken(SysYParser::Semicolon, 0);
}

SysYParser::BreakStmtContext::BreakStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any SysYParser::BreakStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBreakStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExpStmtContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::ExpStmtContext::Semicolon() {
  return getToken(SysYParser::Semicolon, 0);
}

SysYParser::ExpContext* SysYParser::ExpStmtContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::ExpStmtContext::ExpStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any SysYParser::ExpStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitExpStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::ReturnStmtContext::Return() {
  return getToken(SysYParser::Return, 0);
}

tree::TerminalNode* SysYParser::ReturnStmtContext::Semicolon() {
  return getToken(SysYParser::Semicolon, 0);
}

SysYParser::ExpContext* SysYParser::ReturnStmtContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::ReturnStmtContext::ReturnStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any SysYParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ContinueStmtContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::ContinueStmtContext::Continue() {
  return getToken(SysYParser::Continue, 0);
}

tree::TerminalNode* SysYParser::ContinueStmtContext::Semicolon() {
  return getToken(SysYParser::Semicolon, 0);
}

SysYParser::ContinueStmtContext::ContinueStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any SysYParser::ContinueStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitContinueStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentStmtContext ------------------------------------------------------------------

SysYParser::LValContext* SysYParser::AssignmentStmtContext::lVal() {
  return getRuleContext<SysYParser::LValContext>(0);
}

tree::TerminalNode* SysYParser::AssignmentStmtContext::Assign() {
  return getToken(SysYParser::Assign, 0);
}

SysYParser::ExpContext* SysYParser::AssignmentStmtContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

tree::TerminalNode* SysYParser::AssignmentStmtContext::Semicolon() {
  return getToken(SysYParser::Semicolon, 0);
}

SysYParser::AssignmentStmtContext::AssignmentStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any SysYParser::AssignmentStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitAssignmentStmt(this);
  else
    return visitor->visitChildren(this);
}
SysYParser::StmtContext* SysYParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 30, SysYParser::RuleStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(257);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<SysYParser::AssignmentStmtContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(218);
      lVal();
      setState(219);
      match(SysYParser::Assign);
      setState(220);
      exp();
      setState(221);
      match(SysYParser::Semicolon);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SysYParser::ExpStmtContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(224);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 3848475254784) != 0)) {
        setState(223);
        exp();
      }
      setState(226);
      match(SysYParser::Semicolon);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<SysYParser::BlockStmtContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(227);
      block();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<SysYParser::IfStmtContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(228);
      match(SysYParser::If);
      setState(229);
      match(SysYParser::Lparen);
      setState(230);
      cond();
      setState(231);
      match(SysYParser::Rparen);
      setState(232);
      stmt();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<SysYParser::IfElseStmtContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(234);
      match(SysYParser::If);
      setState(235);
      match(SysYParser::Lparen);
      setState(236);
      cond();
      setState(237);
      match(SysYParser::Rparen);
      setState(238);
      stmt();
      setState(239);
      match(SysYParser::Else);
      setState(240);
      stmt();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<SysYParser::WhileStmtContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(242);
      match(SysYParser::While);
      setState(243);
      match(SysYParser::Lparen);
      setState(244);
      cond();
      setState(245);
      match(SysYParser::Rparen);
      setState(246);
      stmt();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<SysYParser::BreakStmtContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(248);
      match(SysYParser::Break);
      setState(249);
      match(SysYParser::Semicolon);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<SysYParser::ContinueStmtContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(250);
      match(SysYParser::Continue);
      setState(251);
      match(SysYParser::Semicolon);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<SysYParser::ReturnStmtContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(252);
      match(SysYParser::Return);
      setState(254);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 3848475254784) != 0)) {
        setState(253);
        exp();
      }
      setState(256);
      match(SysYParser::Semicolon);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

SysYParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::AddExpContext* SysYParser::ExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}


size_t SysYParser::ExpContext::getRuleIndex() const {
  return SysYParser::RuleExp;
}


std::any SysYParser::ExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ExpContext* SysYParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 32, SysYParser::RuleExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    addExp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

SysYParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::LOrExpContext* SysYParser::CondContext::lOrExp() {
  return getRuleContext<SysYParser::LOrExpContext>(0);
}


size_t SysYParser::CondContext::getRuleIndex() const {
  return SysYParser::RuleCond;
}


std::any SysYParser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::CondContext* SysYParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 34, SysYParser::RuleCond);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(261);
    lOrExp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LValContext ------------------------------------------------------------------

SysYParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::LValContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

std::vector<tree::TerminalNode *> SysYParser::LValContext::Lbrkt() {
  return getTokens(SysYParser::Lbrkt);
}

tree::TerminalNode* SysYParser::LValContext::Lbrkt(size_t i) {
  return getToken(SysYParser::Lbrkt, i);
}

std::vector<SysYParser::ExpContext *> SysYParser::LValContext::exp() {
  return getRuleContexts<SysYParser::ExpContext>();
}

SysYParser::ExpContext* SysYParser::LValContext::exp(size_t i) {
  return getRuleContext<SysYParser::ExpContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::LValContext::Rbrkt() {
  return getTokens(SysYParser::Rbrkt);
}

tree::TerminalNode* SysYParser::LValContext::Rbrkt(size_t i) {
  return getToken(SysYParser::Rbrkt, i);
}


size_t SysYParser::LValContext::getRuleIndex() const {
  return SysYParser::RuleLVal;
}


std::any SysYParser::LValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitLVal(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::LValContext* SysYParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 36, SysYParser::RuleLVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    match(SysYParser::Identifier);
    setState(270);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::Lbrkt) {
      setState(264);
      match(SysYParser::Lbrkt);
      setState(265);
      exp();
      setState(266);
      match(SysYParser::Rbrkt);
      setState(272);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RValContext ------------------------------------------------------------------

SysYParser::RValContext::RValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::RValContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

std::vector<tree::TerminalNode *> SysYParser::RValContext::Lbrkt() {
  return getTokens(SysYParser::Lbrkt);
}

tree::TerminalNode* SysYParser::RValContext::Lbrkt(size_t i) {
  return getToken(SysYParser::Lbrkt, i);
}

std::vector<SysYParser::ExpContext *> SysYParser::RValContext::exp() {
  return getRuleContexts<SysYParser::ExpContext>();
}

SysYParser::ExpContext* SysYParser::RValContext::exp(size_t i) {
  return getRuleContext<SysYParser::ExpContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::RValContext::Rbrkt() {
  return getTokens(SysYParser::Rbrkt);
}

tree::TerminalNode* SysYParser::RValContext::Rbrkt(size_t i) {
  return getToken(SysYParser::Rbrkt, i);
}


size_t SysYParser::RValContext::getRuleIndex() const {
  return SysYParser::RuleRVal;
}


std::any SysYParser::RValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitRVal(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::RValContext* SysYParser::rVal() {
  RValContext *_localctx = _tracker.createInstance<RValContext>(_ctx, getState());
  enterRule(_localctx, 38, SysYParser::RuleRVal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(273);
    match(SysYParser::Identifier);
    setState(280);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(274);
        match(SysYParser::Lbrkt);
        setState(275);
        exp();
        setState(276);
        match(SysYParser::Rbrkt); 
      }
      setState(282);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimExpContext ------------------------------------------------------------------

SysYParser::PrimExpContext::PrimExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::PrimExpContext::getRuleIndex() const {
  return SysYParser::RulePrimExp;
}

void SysYParser::PrimExpContext::copyFrom(PrimExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PrimRvalExpContext ------------------------------------------------------------------

SysYParser::RValContext* SysYParser::PrimRvalExpContext::rVal() {
  return getRuleContext<SysYParser::RValContext>(0);
}

SysYParser::PrimRvalExpContext::PrimRvalExpContext(PrimExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::PrimRvalExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitPrimRvalExp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrimConstExpContext ------------------------------------------------------------------

SysYParser::NumberContext* SysYParser::PrimConstExpContext::number() {
  return getRuleContext<SysYParser::NumberContext>(0);
}

SysYParser::PrimConstExpContext::PrimConstExpContext(PrimExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::PrimConstExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitPrimConstExp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrimParenExpContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::PrimParenExpContext::Lparen() {
  return getToken(SysYParser::Lparen, 0);
}

SysYParser::ExpContext* SysYParser::PrimParenExpContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

tree::TerminalNode* SysYParser::PrimParenExpContext::Rparen() {
  return getToken(SysYParser::Rparen, 0);
}

SysYParser::PrimParenExpContext::PrimParenExpContext(PrimExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::PrimParenExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitPrimParenExp(this);
  else
    return visitor->visitChildren(this);
}
SysYParser::PrimExpContext* SysYParser::primExp() {
  PrimExpContext *_localctx = _tracker.createInstance<PrimExpContext>(_ctx, getState());
  enterRule(_localctx, 40, SysYParser::RulePrimExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(289);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::Lparen: {
        _localctx = _tracker.createInstance<SysYParser::PrimParenExpContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(283);
        match(SysYParser::Lparen);
        setState(284);
        exp();
        setState(285);
        match(SysYParser::Rparen);
        break;
      }

      case SysYParser::Identifier: {
        _localctx = _tracker.createInstance<SysYParser::PrimRvalExpContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(287);
        rVal();
        break;
      }

      case SysYParser::IntLiteral:
      case SysYParser::FloatLiteral: {
        _localctx = _tracker.createInstance<SysYParser::PrimConstExpContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(288);
        number();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

SysYParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::NumberContext::IntLiteral() {
  return getToken(SysYParser::IntLiteral, 0);
}

tree::TerminalNode* SysYParser::NumberContext::FloatLiteral() {
  return getToken(SysYParser::FloatLiteral, 0);
}


size_t SysYParser::NumberContext::getRuleIndex() const {
  return SysYParser::RuleNumber;
}


std::any SysYParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::NumberContext* SysYParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 42, SysYParser::RuleNumber);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(291);
    _la = _input->LA(1);
    if (!(_la == SysYParser::IntLiteral

    || _la == SysYParser::FloatLiteral)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExpContext ------------------------------------------------------------------

SysYParser::UnaryExpContext::UnaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::UnaryExpContext::getRuleIndex() const {
  return SysYParser::RuleUnaryExp;
}

void SysYParser::UnaryExpContext::copyFrom(UnaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnaryFuncCallExpContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::UnaryFuncCallExpContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

tree::TerminalNode* SysYParser::UnaryFuncCallExpContext::Lparen() {
  return getToken(SysYParser::Lparen, 0);
}

tree::TerminalNode* SysYParser::UnaryFuncCallExpContext::Rparen() {
  return getToken(SysYParser::Rparen, 0);
}

SysYParser::FuncRparamListContext* SysYParser::UnaryFuncCallExpContext::funcRparamList() {
  return getRuleContext<SysYParser::FuncRparamListContext>(0);
}

SysYParser::UnaryFuncCallExpContext::UnaryFuncCallExpContext(UnaryExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::UnaryFuncCallExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitUnaryFuncCallExp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryOpExpContext ------------------------------------------------------------------

SysYParser::UnaryOpContext* SysYParser::UnaryOpExpContext::unaryOp() {
  return getRuleContext<SysYParser::UnaryOpContext>(0);
}

SysYParser::UnaryExpContext* SysYParser::UnaryOpExpContext::unaryExp() {
  return getRuleContext<SysYParser::UnaryExpContext>(0);
}

SysYParser::UnaryOpExpContext::UnaryOpExpContext(UnaryExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::UnaryOpExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitUnaryOpExp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryToPrimExpContext ------------------------------------------------------------------

SysYParser::PrimExpContext* SysYParser::UnaryToPrimExpContext::primExp() {
  return getRuleContext<SysYParser::PrimExpContext>(0);
}

SysYParser::UnaryToPrimExpContext::UnaryToPrimExpContext(UnaryExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::UnaryToPrimExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitUnaryToPrimExp(this);
  else
    return visitor->visitChildren(this);
}
SysYParser::UnaryExpContext* SysYParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 44, SysYParser::RuleUnaryExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(303);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<SysYParser::UnaryToPrimExpContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(293);
      primExp();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SysYParser::UnaryFuncCallExpContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(294);
      match(SysYParser::Identifier);
      setState(295);
      match(SysYParser::Lparen);
      setState(297);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 8246521765888) != 0)) {
        setState(296);
        funcRparamList();
      }
      setState(299);
      match(SysYParser::Rparen);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<SysYParser::UnaryOpExpContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(300);
      unaryOp();
      setState(301);
      unaryExp();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOpContext ------------------------------------------------------------------

SysYParser::UnaryOpContext::UnaryOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::UnaryOpContext::Addition() {
  return getToken(SysYParser::Addition, 0);
}

tree::TerminalNode* SysYParser::UnaryOpContext::Minus() {
  return getToken(SysYParser::Minus, 0);
}

tree::TerminalNode* SysYParser::UnaryOpContext::Exclamation() {
  return getToken(SysYParser::Exclamation, 0);
}


size_t SysYParser::UnaryOpContext::getRuleIndex() const {
  return SysYParser::RuleUnaryOp;
}


std::any SysYParser::UnaryOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitUnaryOp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::UnaryOpContext* SysYParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 46, SysYParser::RuleUnaryOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(305);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 184549376) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncRparamListContext ------------------------------------------------------------------

SysYParser::FuncRparamListContext::FuncRparamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::FuncRparamContext *> SysYParser::FuncRparamListContext::funcRparam() {
  return getRuleContexts<SysYParser::FuncRparamContext>();
}

SysYParser::FuncRparamContext* SysYParser::FuncRparamListContext::funcRparam(size_t i) {
  return getRuleContext<SysYParser::FuncRparamContext>(i);
}

std::vector<tree::TerminalNode *> SysYParser::FuncRparamListContext::Comma() {
  return getTokens(SysYParser::Comma);
}

tree::TerminalNode* SysYParser::FuncRparamListContext::Comma(size_t i) {
  return getToken(SysYParser::Comma, i);
}


size_t SysYParser::FuncRparamListContext::getRuleIndex() const {
  return SysYParser::RuleFuncRparamList;
}


std::any SysYParser::FuncRparamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncRparamList(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncRparamListContext* SysYParser::funcRparamList() {
  FuncRparamListContext *_localctx = _tracker.createInstance<FuncRparamListContext>(_ctx, getState());
  enterRule(_localctx, 48, SysYParser::RuleFuncRparamList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(307);
    funcRparam();
    setState(312);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::Comma) {
      setState(308);
      match(SysYParser::Comma);
      setState(309);
      funcRparam();
      setState(314);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncRparamContext ------------------------------------------------------------------

SysYParser::FuncRparamContext::FuncRparamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::FuncRparamContext::getRuleIndex() const {
  return SysYParser::RuleFuncRparam;
}

void SysYParser::FuncRparamContext::copyFrom(FuncRparamContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StringAsRparamContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::StringAsRparamContext::STRING() {
  return getToken(SysYParser::STRING, 0);
}

SysYParser::StringAsRparamContext::StringAsRparamContext(FuncRparamContext *ctx) { copyFrom(ctx); }


std::any SysYParser::StringAsRparamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitStringAsRparam(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExpAsRparamContext ------------------------------------------------------------------

SysYParser::ExpContext* SysYParser::ExpAsRparamContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::ExpAsRparamContext::ExpAsRparamContext(FuncRparamContext *ctx) { copyFrom(ctx); }


std::any SysYParser::ExpAsRparamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitExpAsRparam(this);
  else
    return visitor->visitChildren(this);
}
SysYParser::FuncRparamContext* SysYParser::funcRparam() {
  FuncRparamContext *_localctx = _tracker.createInstance<FuncRparamContext>(_ctx, getState());
  enterRule(_localctx, 50, SysYParser::RuleFuncRparam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(317);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::Lparen:
      case SysYParser::Minus:
      case SysYParser::Exclamation:
      case SysYParser::Addition:
      case SysYParser::IntLiteral:
      case SysYParser::FloatLiteral:
      case SysYParser::Identifier: {
        _localctx = _tracker.createInstance<SysYParser::ExpAsRparamContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(315);
        exp();
        break;
      }

      case SysYParser::STRING: {
        _localctx = _tracker.createInstance<SysYParser::StringAsRparamContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(316);
        match(SysYParser::STRING);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulExpContext ------------------------------------------------------------------

SysYParser::MulExpContext::MulExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::MulExpContext::getRuleIndex() const {
  return SysYParser::RuleMulExp;
}

void SysYParser::MulExpContext::copyFrom(MulExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MulTwoExpContext ------------------------------------------------------------------

SysYParser::MulExpContext* SysYParser::MulTwoExpContext::mulExp() {
  return getRuleContext<SysYParser::MulExpContext>(0);
}

SysYParser::UnaryExpContext* SysYParser::MulTwoExpContext::unaryExp() {
  return getRuleContext<SysYParser::UnaryExpContext>(0);
}

tree::TerminalNode* SysYParser::MulTwoExpContext::Multiplication() {
  return getToken(SysYParser::Multiplication, 0);
}

tree::TerminalNode* SysYParser::MulTwoExpContext::Division() {
  return getToken(SysYParser::Division, 0);
}

tree::TerminalNode* SysYParser::MulTwoExpContext::Modulo() {
  return getToken(SysYParser::Modulo, 0);
}

SysYParser::MulTwoExpContext::MulTwoExpContext(MulExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::MulTwoExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitMulTwoExp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulToUnaryExpContext ------------------------------------------------------------------

SysYParser::UnaryExpContext* SysYParser::MulToUnaryExpContext::unaryExp() {
  return getRuleContext<SysYParser::UnaryExpContext>(0);
}

SysYParser::MulToUnaryExpContext::MulToUnaryExpContext(MulExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::MulToUnaryExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitMulToUnaryExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::MulExpContext* SysYParser::mulExp() {
   return mulExp(0);
}

SysYParser::MulExpContext* SysYParser::mulExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, parentState);
  SysYParser::MulExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, SysYParser::RuleMulExp, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<MulToUnaryExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(320);
    unaryExp();
    _ctx->stop = _input->LT(-1);
    setState(327);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MulTwoExpContext>(_tracker.createInstance<MulExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleMulExp);
        setState(322);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(323);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 1879048192) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(324);
        unaryExp(); 
      }
      setState(329);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AddExpContext ------------------------------------------------------------------

SysYParser::AddExpContext::AddExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::AddExpContext::getRuleIndex() const {
  return SysYParser::RuleAddExp;
}

void SysYParser::AddExpContext::copyFrom(AddExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AddToMulExpContext ------------------------------------------------------------------

SysYParser::MulExpContext* SysYParser::AddToMulExpContext::mulExp() {
  return getRuleContext<SysYParser::MulExpContext>(0);
}

SysYParser::AddToMulExpContext::AddToMulExpContext(AddExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::AddToMulExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitAddToMulExp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddTwoExpContext ------------------------------------------------------------------

SysYParser::AddExpContext* SysYParser::AddTwoExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}

SysYParser::MulExpContext* SysYParser::AddTwoExpContext::mulExp() {
  return getRuleContext<SysYParser::MulExpContext>(0);
}

tree::TerminalNode* SysYParser::AddTwoExpContext::Addition() {
  return getToken(SysYParser::Addition, 0);
}

tree::TerminalNode* SysYParser::AddTwoExpContext::Minus() {
  return getToken(SysYParser::Minus, 0);
}

SysYParser::AddTwoExpContext::AddTwoExpContext(AddExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::AddTwoExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitAddTwoExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::AddExpContext* SysYParser::addExp() {
   return addExp(0);
}

SysYParser::AddExpContext* SysYParser::addExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, parentState);
  SysYParser::AddExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 54;
  enterRecursionRule(_localctx, 54, SysYParser::RuleAddExp, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<AddToMulExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(331);
    mulExp(0);
    _ctx->stop = _input->LT(-1);
    setState(338);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<AddTwoExpContext>(_tracker.createInstance<AddExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleAddExp);
        setState(333);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(334);
        _la = _input->LA(1);
        if (!(_la == SysYParser::Minus

        || _la == SysYParser::Addition)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(335);
        mulExp(0); 
      }
      setState(340);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelExpContext ------------------------------------------------------------------

SysYParser::RelExpContext::RelExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::RelExpContext::getRuleIndex() const {
  return SysYParser::RuleRelExp;
}

void SysYParser::RelExpContext::copyFrom(RelExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- RelToAddExpContext ------------------------------------------------------------------

SysYParser::AddExpContext* SysYParser::RelToAddExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}

SysYParser::RelToAddExpContext::RelToAddExpContext(RelExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::RelToAddExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitRelToAddExp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelTwoExpContext ------------------------------------------------------------------

SysYParser::RelExpContext* SysYParser::RelTwoExpContext::relExp() {
  return getRuleContext<SysYParser::RelExpContext>(0);
}

SysYParser::AddExpContext* SysYParser::RelTwoExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}

tree::TerminalNode* SysYParser::RelTwoExpContext::LT() {
  return getToken(SysYParser::LT, 0);
}

tree::TerminalNode* SysYParser::RelTwoExpContext::GT() {
  return getToken(SysYParser::GT, 0);
}

tree::TerminalNode* SysYParser::RelTwoExpContext::LE() {
  return getToken(SysYParser::LE, 0);
}

tree::TerminalNode* SysYParser::RelTwoExpContext::GE() {
  return getToken(SysYParser::GE, 0);
}

SysYParser::RelTwoExpContext::RelTwoExpContext(RelExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::RelTwoExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitRelTwoExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::RelExpContext* SysYParser::relExp() {
   return relExp(0);
}

SysYParser::RelExpContext* SysYParser::relExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, parentState);
  SysYParser::RelExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, SysYParser::RuleRelExp, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<RelToAddExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(342);
    addExp(0);
    _ctx->stop = _input->LT(-1);
    setState(349);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<RelTwoExpContext>(_tracker.createInstance<RelExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleRelExp);
        setState(344);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(345);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 515396075520) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(346);
        addExp(0); 
      }
      setState(351);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqExpContext ------------------------------------------------------------------

SysYParser::EqExpContext::EqExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::EqExpContext::getRuleIndex() const {
  return SysYParser::RuleEqExp;
}

void SysYParser::EqExpContext::copyFrom(EqExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- EqTwoExpContext ------------------------------------------------------------------

SysYParser::EqExpContext* SysYParser::EqTwoExpContext::eqExp() {
  return getRuleContext<SysYParser::EqExpContext>(0);
}

SysYParser::RelExpContext* SysYParser::EqTwoExpContext::relExp() {
  return getRuleContext<SysYParser::RelExpContext>(0);
}

tree::TerminalNode* SysYParser::EqTwoExpContext::EQ() {
  return getToken(SysYParser::EQ, 0);
}

tree::TerminalNode* SysYParser::EqTwoExpContext::NEQ() {
  return getToken(SysYParser::NEQ, 0);
}

SysYParser::EqTwoExpContext::EqTwoExpContext(EqExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::EqTwoExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitEqTwoExp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqToRelExpContext ------------------------------------------------------------------

SysYParser::RelExpContext* SysYParser::EqToRelExpContext::relExp() {
  return getRuleContext<SysYParser::RelExpContext>(0);
}

SysYParser::EqToRelExpContext::EqToRelExpContext(EqExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::EqToRelExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitEqToRelExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::EqExpContext* SysYParser::eqExp() {
   return eqExp(0);
}

SysYParser::EqExpContext* SysYParser::eqExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, parentState);
  SysYParser::EqExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 58;
  enterRecursionRule(_localctx, 58, SysYParser::RuleEqExp, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<EqToRelExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(353);
    relExp(0);
    _ctx->stop = _input->LT(-1);
    setState(360);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<EqTwoExpContext>(_tracker.createInstance<EqExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleEqExp);
        setState(355);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(356);
        _la = _input->LA(1);
        if (!(_la == SysYParser::EQ

        || _la == SysYParser::NEQ)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(357);
        relExp(0); 
      }
      setState(362);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LAndExpContext ------------------------------------------------------------------

SysYParser::LAndExpContext::LAndExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::LAndExpContext::getRuleIndex() const {
  return SysYParser::RuleLAndExp;
}

void SysYParser::LAndExpContext::copyFrom(LAndExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LAndToEqExpContext ------------------------------------------------------------------

SysYParser::EqExpContext* SysYParser::LAndToEqExpContext::eqExp() {
  return getRuleContext<SysYParser::EqExpContext>(0);
}

SysYParser::LAndToEqExpContext::LAndToEqExpContext(LAndExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::LAndToEqExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitLAndToEqExp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LAndTwoExpContext ------------------------------------------------------------------

SysYParser::LAndExpContext* SysYParser::LAndTwoExpContext::lAndExp() {
  return getRuleContext<SysYParser::LAndExpContext>(0);
}

tree::TerminalNode* SysYParser::LAndTwoExpContext::LAND() {
  return getToken(SysYParser::LAND, 0);
}

SysYParser::EqExpContext* SysYParser::LAndTwoExpContext::eqExp() {
  return getRuleContext<SysYParser::EqExpContext>(0);
}

SysYParser::LAndTwoExpContext::LAndTwoExpContext(LAndExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::LAndTwoExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitLAndTwoExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::LAndExpContext* SysYParser::lAndExp() {
   return lAndExp(0);
}

SysYParser::LAndExpContext* SysYParser::lAndExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, parentState);
  SysYParser::LAndExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 60;
  enterRecursionRule(_localctx, 60, SysYParser::RuleLAndExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<LAndToEqExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(364);
    eqExp(0);
    _ctx->stop = _input->LT(-1);
    setState(371);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<LAndTwoExpContext>(_tracker.createInstance<LAndExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleLAndExp);
        setState(366);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(367);
        match(SysYParser::LAND);
        setState(368);
        eqExp(0); 
      }
      setState(373);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LOrExpContext ------------------------------------------------------------------

SysYParser::LOrExpContext::LOrExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::LOrExpContext::getRuleIndex() const {
  return SysYParser::RuleLOrExp;
}

void SysYParser::LOrExpContext::copyFrom(LOrExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LOrToLandExpContext ------------------------------------------------------------------

SysYParser::LAndExpContext* SysYParser::LOrToLandExpContext::lAndExp() {
  return getRuleContext<SysYParser::LAndExpContext>(0);
}

SysYParser::LOrToLandExpContext::LOrToLandExpContext(LOrExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::LOrToLandExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitLOrToLandExp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LOrTwoExpContext ------------------------------------------------------------------

SysYParser::LOrExpContext* SysYParser::LOrTwoExpContext::lOrExp() {
  return getRuleContext<SysYParser::LOrExpContext>(0);
}

tree::TerminalNode* SysYParser::LOrTwoExpContext::LOR() {
  return getToken(SysYParser::LOR, 0);
}

SysYParser::LAndExpContext* SysYParser::LOrTwoExpContext::lAndExp() {
  return getRuleContext<SysYParser::LAndExpContext>(0);
}

SysYParser::LOrTwoExpContext::LOrTwoExpContext(LOrExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::LOrTwoExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitLOrTwoExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::LOrExpContext* SysYParser::lOrExp() {
   return lOrExp(0);
}

SysYParser::LOrExpContext* SysYParser::lOrExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, parentState);
  SysYParser::LOrExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 62;
  enterRecursionRule(_localctx, 62, SysYParser::RuleLOrExp, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<LOrToLandExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(375);
    lAndExp(0);
    _ctx->stop = _input->LT(-1);
    setState(382);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<LOrTwoExpContext>(_tracker.createInstance<LOrExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleLOrExp);
        setState(377);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(378);
        match(SysYParser::LOR);
        setState(379);
        lAndExp(0); 
      }
      setState(384);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConstExpContext ------------------------------------------------------------------

SysYParser::ConstExpContext::ConstExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::AddExpContext* SysYParser::ConstExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}


size_t SysYParser::ConstExpContext::getRuleIndex() const {
  return SysYParser::RuleConstExp;
}


std::any SysYParser::ConstExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstExpContext* SysYParser::constExp() {
  ConstExpContext *_localctx = _tracker.createInstance<ConstExpContext>(_ctx, getState());
  enterRule(_localctx, 64, SysYParser::RuleConstExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(385);
    addExp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool SysYParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 26: return mulExpSempred(antlrcpp::downCast<MulExpContext *>(context), predicateIndex);
    case 27: return addExpSempred(antlrcpp::downCast<AddExpContext *>(context), predicateIndex);
    case 28: return relExpSempred(antlrcpp::downCast<RelExpContext *>(context), predicateIndex);
    case 29: return eqExpSempred(antlrcpp::downCast<EqExpContext *>(context), predicateIndex);
    case 30: return lAndExpSempred(antlrcpp::downCast<LAndExpContext *>(context), predicateIndex);
    case 31: return lOrExpSempred(antlrcpp::downCast<LOrExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SysYParser::mulExpSempred(MulExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::addExpSempred(AddExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::relExpSempred(RelExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::eqExpSempred(EqExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void SysYParser::initialize() {
  ::antlr4::internal::call_once(sysyParserOnceFlag, sysyParserInitialize);
}
