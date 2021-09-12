#pragma once


class TextGameInfo
{
public:
	//각각 직업들 초기 스탯
	class Rogue
	{
	public:
		const static int iMP = 5;
		const static int iAttack = 5;
		const static int iHP = 100;
		const static int iDefence = 1;
		const static int iavoidance = 3;
	};
	
	class Worrier
	{
	public:
		const static int iHP = 150;
		const static int iMP = 3;
		const static int iAttack = 3;
		const static int iDefence = 2;
		const static int iavoidance = 5;	
	};
	
	
	class Mage
	{
	public:
		const static int iHP = 100;
		const static int iMP = 15;
		const static int iAttack = 10;
		const static int iDefence = 2;
		const static int iavoidance = 5;
	};


	//각각 몬스터 초기 스탯
	class Ogre
	{
	public:
		const static int iHP = 15;
		const static int iMP = 3;
		const static int iAttack = 3;
		const static int iDefence = 2;
		const static int iavoidance = 3;
	};

	class Goblin
	{
	public:
		const static int iMP = 5;
		const static int iAttack = 5;
		const static int iHP = 10;
		const static int iDefence = 1;
		const static int iavoidance = 3;
	};

	class Oak
	{
	public:
		const static int iHP = 10;
		const static int iMP = 15;
		const static int iAttack = 8;
		const static int iDefence = 1;
		const static int iavoidance = 5;
	};



	//각각 무기들 초기스탯

	class OneHandedSword {
	public: 
		const static int itype = 1;
		const static int iAttack = 5;
		const static int iUseStamina = 5;
		const static int iUsemana = 1;
	};

	class TwoHandedSword {
	public:
		const static int itype = 2;
		const static int iAttack = 10;
		const static int iUseStamina = 10;
		const static int iUsemana = 2;
	};

	class ShortSword {
	public:
		const static int itype = 3;
		const static int iAttack = 10;
		const static int iUseStamina = 15;
		const static int iUsemana = 1;
	};

	class Niddle {
	public:
		const static int itype = 4;
		const static int iAttack = 13;
		const static int iUseStamina = 13;
		const static int iUsemana = 2;
	};


	class Staff {
	public:
		const static int itype = 5;
		const static int iAttack = 15;
		const static int iUseStamina = 10;
		const static int iUsemana = 15;
	};

	class Wand {
	public:
		const static int itype = 6;
		const static int iAttack = 20;
		const static int iUseStamina = 20;
		const static int iUsemana = 20;
	};


	//포션 초기 스탯
	class potion
	{
	public:
		const static int iHealHP = 10;
		const static int iHealMP = 10;
	};


	//각각 방어구 초기 스탯
	class LightArmor
	{
	public:
		const static int itype = 1;
		const static int iArmorDefence = 5;
		const static int iAvoidance = 3;
	};

	class HeavyArmor
	{
	public:
		const static int itype = 2;
		const static int iArmorDefence = 10;
		const static int iavoidance = 1;
	};
	
};

