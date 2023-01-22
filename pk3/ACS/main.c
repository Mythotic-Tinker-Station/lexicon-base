#import "../../compiler/lib/zcommon.bcs"
#library "MAIN"

#if 1

int acronym_list[] =
{
	"EPIC",
	"EPC2",
	"MAYH",
	"SHIT",
	"CORE",
	"DBP1",
	"DBP2",
	"DBP3",
	"CCH1",
	"CCH2",
	"CCH3",
	"CCH4",
	"D2RL",
	"HEBO",
	"JPCP",
	"3HA1",
	"3HA2",
	"3HA3",
	"D2RD",
};

// This script runs on map load(should have a unique name for each expansion set
// you do not need to edit this script, only the variables above
Script "LEXICON_BASE_EXPANSION" Open
{
	for(int i = 0; i < lengthof(acronym_list); i++)
	{
		ACS_NamedExecuteWithResult("Lexicon_AddMapSet", acronym_list[i]);
	}
}

#endif


