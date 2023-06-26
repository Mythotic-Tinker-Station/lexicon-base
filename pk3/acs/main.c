#import "../../compiler/lib/zcommon.bcs"
#library "MAIN"

#if 1

// edit these
int expansion_name = "Base";
int mapset_list[] =
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

// This script runs on map load(should have a unique name for each expansion set)
// you do not need to edit this script, only the variables above
Script "LEXICON_EXPANSION_SV" Open
{
    ACS_NamedExecuteWithResult("Lexicon_AddExpansion", expansion_name);
	for(int i = 0; i < mapset_list.length(); i++)
	{
		ACS_NamedExecuteWithResult("Lexicon_AddMapSet", mapset_list[i]);
	}
}

#endif


