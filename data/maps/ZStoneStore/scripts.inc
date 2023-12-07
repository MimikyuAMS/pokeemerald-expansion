ZStoneStore_MapScripts::
	.byte 0


ZClerk::
	lockall
	faceplayer
	message ZClerk_Text_0
	waitmessage
	pokemart ZShop
	msgbox ZClerk_Text_1
	releaseall
	end


 

.align 2
ZShop::
	.2byte ITEM_BUGINIUM_Z
	.2byte ITEM_DARKINIUM_Z
	.2byte ITEM_DRAGONIUM_Z
	.2byte ITEM_ELECTRIUM_Z
	.2byte ITEM_FAIRIUM_Z
	.2byte ITEM_FIGHTINIUM_Z
	.2byte ITEM_FIRIUM_Z
	.2byte ITEM_FLYINIUM_Z
	.2byte ITEM_GHOSTIUM_Z
	.2byte ITEM_GRASSIUM_Z
	.2byte ITEM_GROUNDIUM_Z
	.2byte ITEM_ICIUM_Z
	.2byte ITEM_NORMALIUM_Z
	.2byte ITEM_POISONIUM_Z
	.2byte ITEM_PSYCHIUM_Z
	.2byte ITEM_ROCKIUM_Z
	.2byte ITEM_STEELIUM_Z
	.2byte ITEM_WATERIUM_Z
	.2byte ITEM_ALORAICHIUM_Z
	.2byte ITEM_DECIDIUM_Z
	.2byte ITEM_EEVIUM_Z
	.2byte ITEM_INCINIUM_Z
	.2byte ITEM_KOMMONIUM_Z
	.2byte ITEM_LYCANIUM_Z
	.2byte ITEM_MEWNIUM_Z
	.2byte ITEM_MIMIKIUM_Z
	.2byte ITEM_PIKANIUM_Z
	.2byte ITEM_PRIMARIUM_Z
	.2byte ITEM_SNORLIUM_Z
	.2byte ITEM_NONE
	releaseall
	end

ZClerk_Text_0:
	.string "Wanna unlock the hidden potential\n of your pokemon?$"

ZClerk_Text_1:
	.string "Thanks for your patronage$"
