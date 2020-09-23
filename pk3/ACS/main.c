#import "../../compiler/lib/zcommon.bcs"
#library "MAIN"

#if 1
#define ACRONYM_COUNT 1

int acronym_list[ACRONYM_COUNT] =
{
	"EPIC",
	"EPC2"
};

// This script runs on map load(should have a unique name for each expansion set
Script "LEXICON_BASE_EXPANSION" Open
{
	for(int i = 0; i < ACRONYM_COUNT; i++)
	{
		ACS_NamedExecuteWithResult("Lexicon_AddMapSet", 0, acronym_list[i]);
		ACS_NamedExecuteWithResult("Lexicon_AddMapSet", 1, acronym_list[i]);
	}
}

#endif