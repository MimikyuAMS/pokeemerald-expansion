Shockola_Factory_MapScripts::
	.byte 0


RocketGrunt3::
	trainerbattle_single ROCKET_BATTLE_3, RocketF2_Intro, RocketF2_Outro
	msgbox PostBattleRocketF2, MSGBOX_AUTOCLOSE
	waitmessage
	end


RocketGrunt4::
	trainerbattle_single ROCKET_BATTLE_4, RocketM2_Intro, RocketM2_Outro
	msgbox PostBattleRocketM2, MSGBOX_AUTOCLOSE
	waitmessage
	end


RocketF2_Intro::
	.string "This Factory is kinda creepy$"

RocketF2_Outro::
	.string "You scared me!$"

PostBattleRocketF2::
	.string "I want my mom...$"

RocketM2_Intro::
	.string "I am literally the only guy guarding a God here...$"

RocketM2_Outro::
	.string "Oh well, this job sucked anyways$"

PostBattleRocketM2::
	.string "You can proceed...$"
