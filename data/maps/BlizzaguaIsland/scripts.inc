BlizzaguaIsland_MapScripts::
	.byte 0


SuicuneEncounter::
	lockall
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_SUICUNE, 60
	special BattleSetup_StartLegendaryBattle
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq SuicuneEncounter_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq SuicuneEncounter_3
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq SuicuneEncounter_4
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq SuicuneEncounter_5
SuicuneEncounter_1:
	waitmessage
	releaseall
	return

SuicuneEncounter_2:
	call CaughtSuicune
	goto SuicuneEncounter_1

SuicuneEncounter_3:
	call WonSuicune
	goto SuicuneEncounter_1

SuicuneEncounter_4:
	call RanAwaySuicune
	goto SuicuneEncounter_1

SuicuneEncounter_5:
	call RanAwaySuicune
	goto SuicuneEncounter_1


CaughtSuicune::
	fadescreen FADE_TO_BLACK
	removeobject 1
	setflag FLAG_CAUGHT_SUICUNE
	fadescreen FADE_FROM_BLACK
	return


RanAwaySuicune::
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAwaySuicune_Text_0
	return


WonSuicune::
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAwaySuicune_Text_0
	return


RanAwaySuicune_Text_0:
	.string "Suicune wants to battle again!$"
