MimikyusRoom_MapScripts::
	.byte 0


RocketAiden::
	lockall
	faceplayer
	trainerbattle_single ROCKET_AIDEN, Aiden_Intro, Aiden_Outro
	msgbox PostBattleAiden, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setflag FLAG_AIDEN_DEFEATED
	removeobject 1
	fadescreen FADE_FROM_BLACK
	releaseall
	end


Aiden_Intro::
	.string "So... you finally found me, \n I must congratulate \p you, making it this far... eh... \n Listen, I am the creator \p I am AMS, otherwise known as Aiden. \n But enough monologing, LET'S BATTLE!$"

Aiden_Outro::
	.string "How unfortunate... I lost to the \n likes of a child like my old boss$"

PostBattleAiden::
	.string "Congrats, you have beat the game,\n not that you'd know that, \p I will leave this island alone now, \n but I will return!$"
