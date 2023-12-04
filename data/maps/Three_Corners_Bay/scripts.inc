Three_Corners_Bay_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Three_Corners_Bay_On_Transition
	.byte 0


Three_Corners_Bay_On_Transition::
	goto_if_set FLAG_CAUGHT_RAIKOU, Three_Corners_Bay_On_Transition_4
Three_Corners_Bay_On_Transition_1:
	end

Three_Corners_Bay_On_Transition_2:
	removeobject 1
	setflag FLAG_LEGENDARY_BEASTS_CAUGHT_TRAP
	goto Three_Corners_Bay_On_Transition_1

Three_Corners_Bay_On_Transition_3:
	goto_if_set FLAG_CAUGHT_SUICUNE, Three_Corners_Bay_On_Transition_2
	goto Three_Corners_Bay_On_Transition_1

Three_Corners_Bay_On_Transition_4:
	goto_if_set FLAG_CAUGHT_ENTEI, Three_Corners_Bay_On_Transition_3
	goto Three_Corners_Bay_On_Transition_1


RocketGuard::
	lockall
	faceplayer
	msgbox RocketGuard_Text_0
	waitmessage
	releaseall
	return


RocketGuard_Text_0:
	.string "Scram Kid!$"
