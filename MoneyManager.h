#pragma once

class MoneyManager {
public:
	inline MoneyManager(int defaultMoney) {
		m_money = defaultMoney;
	}

	inline int GetMoney() { return m_money; }
	inline int AddMoney(int amount) { m_money += amount; return m_money; }
	inline int SubtractMoney(int amount) { m_money -= amount; return m_money; }

private:
	int m_money;
};