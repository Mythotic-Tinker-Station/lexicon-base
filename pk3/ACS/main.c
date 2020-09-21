#import "../../compiler/lib/zcommon.bcs"
#library "MAIN"



// This script runs on map load(should have a unique name for each expansion set
Script "LEXICON_BASE_EXPANSION" Open
{
	// only run on the hub map
	if(GetLevelInfo(LEVELINFO_LEVELNUM) == 99)
	{
		// tell lexicon to add the mapset with acronym "DOOM"
		ACS_NamedExecute("Lexicon_AddMapSet", 0, "EPIC");
	}
}
