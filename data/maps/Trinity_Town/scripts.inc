Trinity_Town_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Trinity_Town_On_Tranisition
	.byte 0


Trinity_Town_On_Tranisition::
	goto_if_unset FLAG_LEGENDARY_BEASTS_CAUGHT_TRAP, Trinity_Town_On_Tranisition_2
	goto_if_set FLAG_LEGENDARY_BEASTS_CAUGHT_TRAP, Trinity_Town_On_Tranisition_3
	goto_if_set FLAG_LEGENDARY_BEASTS_CAUGHT_TRAP, Trinity_Town_On_Tranisition_5
Trinity_Town_On_Tranisition_1:
	end

Trinity_Town_On_Tranisition_2:
	call HideGuard
	goto Trinity_Town_On_Tranisition_1

Trinity_Town_On_Tranisition_3:
	clearflag FLAG_HIDE_ROCKET_GUARD
	goto Trinity_Town_On_Tranisition_1

Trinity_Town_On_Tranisition_4:
	call HideRocket
	goto Trinity_Town_On_Tranisition_1

Trinity_Town_On_Tranisition_5:
	goto_if_set FLAG_AIDEN_DEFEATED, Trinity_Town_On_Tranisition_4
	goto Trinity_Town_On_Tranisition_1


HideGuard::
	removeobject 6
	setflag FLAG_HIDE_ROCKET_GUARD
	end


HideRocket::
	removeobject 4
	removeobject 5
	removeobject 6
	setflag FLAG_HIDE_ROCKET_GUARD
	end


Trinity_Village_Elder1::
	lockall
	faceplayer
	goto_if_set FLAG_AIDEN_DEFEATED, Trinity_Village_Elder1_1
	msgbox Trinity_Village_Elder1_Text_1
	releaseall
	end

Trinity_Village_Elder1_1:
	msgbox Trinity_Village_Elder1_Text_0
	return


Trinity_Kid1::
	lockall
	faceplayer
	msgbox Trinity_Kid1_Text_0
	releaseall
	end


Trinity_Kid2::
	lockall
	faceplayer
	msgbox Trinity_Kid2_Text_0
	releaseall
	end


Trinity_Sign::
	lockall
	msgbox Trinity_Sign_Text_0
	releaseall
	end


Rocket_Grunt1::
	trainerbattle_single ROCKET_BATTLE_1, RocketF1_Intro, RocketF1_Outro
	msgbox PostBattleRocketF1, MSGBOX_AUTOCLOSE
	waitmessage
	end


RocketGuard2::
	lockall
	faceplayer
	msgbox RocketGuard2_Text_0
	releaseall
	end


RocketGrunt2::
	trainerbattle_single ROCKET_BATTLE_2, RocketM1_Intro, RocketM1_Outro
	msgbox PostBattleRocketM1, MSGBOX_AUTOCLOSE
	waitmessage
	end


Trinity_Village_Elder1_Text_0:
	.string "Thank you, you have saved us$"

Trinity_Village_Elder1_Text_1:
	.string "Those Team Rocket Grunts... \n They are destroying the island's \p ecosystem!$"

Trinity_Kid1_Text_0:
	.string "I love playing in the Tidepool!$"

Trinity_Kid2_Text_0:
	.string "I once got pinched by a Krabby, \n it hurt!$"

Trinity_Sign_Text_0:
	.string "Trinity Rock, The Sacred Triangle$"

RocketGuard2_Text_0:
	.string "Sorry mate, the boss wants \n to see ya. \p Check out that island I was at in the Bay.$"

RocketF1_Intro::
	.string "Man, being posted right at the \n edge of this Town blows...$"

RocketF1_Outro::
	.string "Actually, losing to you blows more$"

PostBattleRocketF1::
	.string "Buzz off will you? I already lost \n to another child a few years ago!$"

RocketM1_Intro::
	.string "The ocean is nice, it reminds me of home...$"

RocketM1_Outro::
	.string "Even when I lose, one thing remains true...$"

PostBattleRocketM1::
	.string "The ocean is serene...$"
