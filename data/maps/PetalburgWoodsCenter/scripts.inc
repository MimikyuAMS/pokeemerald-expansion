PetalburgWoodsCenter_MapScripts::
	.byte 0


CelebiEncounter::
	lockall
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_CELEBI, 30
	special BattleSetup_StartLegendaryBattle
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq CelebiEncounter_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CelebiEncounter_3
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq CelebiEncounter_4
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq CelebiEncounter_5
CelebiEncounter_1:
	waitmessage
	releaseall
	return

CelebiEncounter_2:
	call CaughtCelebi
	goto CelebiEncounter_1

CelebiEncounter_3:
	call WonCelebi
	goto CelebiEncounter_1

CelebiEncounter_4:
	call RanAwayCelebi
	goto CelebiEncounter_1

CelebiEncounter_5:
	call RanAwayCelebi
	goto CelebiEncounter_1


CaughtCelebi::
	fadescreen FADE_TO_BLACK
	removeobject 1
	setflag FLAG_CAUGHT_CELEBI
	fadescreen FADE_FROM_BLACK
	return


RanAwayCelebi::
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAwayCelebi_Text_0
	return


WonCelebi::
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAwayCelebi_Text_0
	return


RanAwayCelebi_Text_0:
	.string "Celebi wants to battle again!$"
