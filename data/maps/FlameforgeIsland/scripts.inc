FlameforgeIsland_MapScripts::
	.byte 0


EnteiEncounter::
	lockall
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ENTEI, 60
	special BattleSetup_StartLegendaryBattle
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq EnteiEncounter_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EnteiEncounter_3
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EnteiEncounter_4
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EnteiEncounter_5
EnteiEncounter_1:
	waitmessage
	releaseall
	return

EnteiEncounter_2:
	call CaughtEntei
	goto EnteiEncounter_1

EnteiEncounter_3:
	call WonEntei
	goto EnteiEncounter_1

EnteiEncounter_4:
	call RanAwayEntei
	goto EnteiEncounter_1

EnteiEncounter_5:
	call RanAwayEntei
	goto EnteiEncounter_1


CaughtEntei::
	fadescreen FADE_TO_BLACK
	removeobject 1
	setflag FLAG_CAUGHT_ENTEI
	fadescreen FADE_FROM_BLACK
	return


RanAwayEntei::
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAwayEntei_Text_0
	return


WonEntei::
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAwayEntei_Text_0
	return


RanAwayEntei_Text_0:
	.string "Entei wants to battle again!$"
