#pragma once


class TextGameInfo
{
public:
	class Rogue
	{
	public:
		const static int iMP = 5;
		const static int iAttack = 5;
		const static int iHP = 10;
		const static int iDefence = 1;
		const static int iavoidance = 3;
	};
	
	class Worrier
	{
	public:
		const static int iHP = 15;
		const static int iMP = 3;
		const static int iAttack = 3;
		const static int iDefence = 2;
		const static int iavoidance = 5;	
	};

	class Mage
	{
	public:
		const static int iHP = 8;
		const static int iMP = 12;
		const static int iAttack = 8;
		const static int iDefence = 2;
		const static int iavoidance = 1;		
	};

	class OneHandSword {
		const static int iname = 1;
	};
	class TwoHandSword {
		const static int iname = 2;
	};
	class ShortSword {
		const static int iname = 3;
	};
	class Niddle {
		const static int iname = 4;
	};
	class staff {
		const static int iname = 5;
	};
	class wand {
		const static int iname = 6;
	};
};

