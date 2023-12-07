MeteorFalls_B1F_3R_MapScripts::
	.byte 0


JirachiEncounter::
	lockall
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_JIRACHI, 30
	special BattleSetup_StartLegendaryBattle
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq JirachiEncounter_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq JirachiEncounter_3
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq JirachiEncounter_4
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq JirachiEncounter_5
JirachiEncounter_1:
	waitmessage
	releaseall
	return

JirachiEncounter_2:
	call CaughtJirachi
	goto JirachiEncounter_1

JirachiEncounter_3:
	call WonJirachi
	goto JirachiEncounter_1

JirachiEncounter_4:
	call RanAwayJirachi
	goto JirachiEncounter_1

JirachiEncounter_5:
	call RanAwayJirachi
	goto JirachiEncounter_1


CaughtJirachi::
	fadescreen FADE_TO_BLACK
	removeobject 1
	setflag FLAG_CAUGHT_JIRACHI
	fadescreen FADE_FROM_BLACK
	return


RanAwayJirachi::
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAwayJirachi_Text_0
	return


WonJirachi::
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAwayJirachi_Text_0
	return


RanAwayJirachi_Text_0:
	.string "Jirachi wants to battle again!$"
