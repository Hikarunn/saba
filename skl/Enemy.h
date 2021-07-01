#pragma once
namespace Battle {

	class Player;
	class Enemy
	{
		Player* player_;
		int life_ = 100;
	public:
		void OnDamage(int damage);
		void Attack();
	};
}
