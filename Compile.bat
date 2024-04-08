@echo off

set FileName=Lexicon-Base

echo Step 1: PACK
	cd pk3
	..\compiler\7za a -r -ssw -mx9 -tzip  ..\%FileName%-New.pk3 *.kvx *.cmp *.x* *.txt *.o *.acs *.png *.wad *.md2 *.md3 *.tga *.mp3 *.pal *.bmp *.map *.lmp *.raw *.mus *.mid *.ogg *.vgz *.wav *.mod *.it *.xm *.s3m *.psm *.pk3 *.gl


echo Step 2: REPLACE
	cd ..
	del %FileName%.pk3
	ren %FileName%-New.pk3 %FileName%.pk3

pause