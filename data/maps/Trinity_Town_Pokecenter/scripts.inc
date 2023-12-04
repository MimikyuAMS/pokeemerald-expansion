Trinity_Town_Pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Trinity_PokemonCenter_OnTransition
	.byte 0


Trinity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_TRINITY_TOWN
	end


NurseJoy::
	lockall
	faceplayer
	msgbox NurseJoy_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NurseJoy_1
	msgbox NurseJoy_Text_2, MSGBOX_NPC
	return

NurseJoy_1:
	incrementgamestat GAME_STAT_USED_POKECENTER
	special HealPlayerParty
	msgbox NurseJoy_Text_1
	waitmessage
	releaseall
	end


Trinity_Clerk::
	lockall
	faceplayer
	message Trinity_Clerk_Text_0
	waitmessage
	pokemart TrinityMart
	msgbox Trinity_Clerk_Text_1
	releaseall
	end


 

.align 2
TrinityMart::
	.2byte ITEM_ULTRA_BALL
    .2byte ITEM_FULL_RESTORE
    .2byte ITEM_REVIVE
	.2byte ITEM_NONE
	releaseall
	end

NurseJoy_Text_0:
	.string "Would you like me to heal your party?$"

NurseJoy_Text_1:
	.string "Come again soon.$"

NurseJoy_Text_2:
	.string "Have a nice day$"

Trinity_Clerk_Text_0:
	.string "Hi, I sell various items.$"

Trinity_Clerk_Text_1:
	.string "Thanks for your purchase!$"
