Trinity_Town_Pokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Trinity_PokemonCenter_OnTransition
	.byte 0


Trinity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_TRINITY_TOWN
	end


NurseJoy::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
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

Trinity_Clerk_Text_0:
	.string "Hi, I sell various items.$"

Trinity_Clerk_Text_1:
	.string "Thanks for your purchase!$"
