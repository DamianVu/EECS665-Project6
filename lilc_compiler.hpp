#ifndef __LILC_COMPILER_HPP__
#define __LILC_COMPILER_HPP__ 1

#include <string>
#include <cstddef>
#include <istream>

#include "lilc_scanner.hpp"
#include "tokens.hpp"
#include "ast.hpp"
#include "grammar.hh"
#include "symbol_table.hpp"

namespace LILC{

class LilC_Compiler{
public:
   LilC_Compiler() = default;

   virtual ~LilC_Compiler();

   void setASTRoot(ProgramNode * root){ this->astRoot = root; }
   ProgramNode * getASTRoot(){ return this->astRoot; }

   void scan( const char * const filename, const char * outfile);
   bool parse( const char * const filename );
   void unparse(const char * const outF);
   bool nameAnalysis( const char * const filename );
   bool typeAnalysis( const char * const filename );
   bool codeGen(const char * const inFile, 
	const char * const outFile);
private:
   LILC::LilC_Parser  *parser  = nullptr;
   LILC::LilC_Scanner *scanner = nullptr;
   ProgramNode * astRoot = nullptr;
   SymbolTable * symbolTable = nullptr;
};

} /* end namespace */
#endif /* END __LILC_DRIVER_HPP__ */
