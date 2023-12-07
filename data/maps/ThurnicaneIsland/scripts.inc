ThurnicaneIsland_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, ThurnicaneIsland_On_Tranisition
	.byte 0


ThurnicaneIsland_On_Tranisition::
	goto_if_set FLAG_CAUGHT_RAIKOU, ThurnicaneIsland_On_Tranisition_1
	return

ThurnicaneIsland_On_Tranisition_1:
	removeobject 1
	end


RaikouEncounter::
	lockall
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_RAIKOU, 60
	special BattleSetup_StartLegendaryBattle
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq RaikouEncounter_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq RaikouEncounter_3
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq RaikouEncounter_4
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq RaikouEncounter_5
RaikouEncounter_1:
	waitmessage
	releaseall
	return

RaikouEncounter_2:
	call Caught
	goto RaikouEncounter_1

RaikouEncounter_3:
	call Won
	goto RaikouEncounter_1

RaikouEncounter_4:
	call RanAway
	goto RaikouEncounter_1

RaikouEncounter_5:
	call RanAway
	goto RaikouEncounter_1


Caught::
	fadescreen FADE_TO_BLACK
	setflag FLAG_CAUGHT_RAIKOU
	removeobject 1
	fadescreen FADE_FROM_BLACK
	return


RanAway::
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAway_Text_0
	return


Won::
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	delay 20
	msgbox RanAway_Text_0
	return


RanAway_Text_0:
	.string "Raikou wants to battle again!$"
