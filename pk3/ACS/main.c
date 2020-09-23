#import "../../compiler/lib/zcommon.bcs"
#library "MAIN"

#if 1

#define ACRONYM_COUNT 3

int acronym_list[ACRONYM_COUNT] =
{
	"EPIC",
	"EPC2",
	"MAYH",
};

// This script runs on map load(should have a unique name for each expansion set
// you do not need to edit this script, only the variables above
Script "LEXICON_BASE_EXPANSION" Open
{
	for(int i = 0; i < ACRONYM_COUNT; i++)
	{
		ACS_NamedExecuteWithResult("Lexicon_AddMapSet", acronym_list[i]);
	}
}

#endif