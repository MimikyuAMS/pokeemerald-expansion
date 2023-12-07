SnowcloakCaverns_MapScripts::
	.byte 0


RocketGrunt7::
	trainerbattle_single ROCKET_BATTLE_7, RocketM4_Intro, RocketM4_Outro
	msgbox PostBattleRocketM4, MSGBOX_AUTOCLOSE
	end


RocketM4_Intro::
	.string "It is cold here, too cold...$"

RocketM4_Outro::
	.string "Suicune lives here, I am a terrible guard$"

PostBattleRocketM4::
	.string "You can proceed...$"
