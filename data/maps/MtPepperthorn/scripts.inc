MtPepperthorn_MapScripts::
	.byte 0


RocketGrunt5::
	trainerbattle_single ROCKET_BATTLE_5, RocketF3_Intro, RocketF3_Outro
	msgbox PostBattleRocketF2, MSGBOX_AUTOCLOSE
	waitmessage
	end


RocketGrunt6::
	trainerbattle_single ROCKET_BATTLE_6, RocketM3_Intro, RocketM3_Outro
	msgbox PostBattleRocketM3, MSGBOX_AUTOCLOSE
	waitmessage
	end


RocketF3_Intro::
	.string "It is very hot here...$"

RocketF3_Outro::
	.string "Why was I positioned here and not in Johto...$"

PostBattleRocketF3::
	.string "Aiden was an Admin before he led the Trinity Branch$"

RocketM3_Intro::
	.string "Entei, known to cause eruptions when it barks\n it will help us in our mission$"

RocketM3_Outro::
	.string "How unfortunate that you are going to steal it$"

PostBattleRocketM3::
	.string "You can proceed...$"
