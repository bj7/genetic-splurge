/*this is a header file containing data for use by the compiler*/
#ifndef COMP_H_INCLUDE
#define COMP_H_INCLUDE
#include "uthash.h"

typedef enum{
    INTEGER,
    FLOAT,
    BOOLEAN,
	PROC,
}DATATYPES;

typedef enum{
	FALSE, //0
	TRUE,	//1
}BOOLTYPE;

typedef struct {
    char* name;
    int type;
    int lineno;
    int offset;
    UT_hash_handle hh;
}SymbolTableEntry;

SymbolTableEntry *symbolTableGetEntry(SymbolTableEntry **symbol_table, char* key);

void symbolTableAddEntry(SymbolTableEntry **symbol_table, SymbolTableEntry *entry);

#endif
