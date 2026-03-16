#pragma once
#include <forward_list>
#include "Observer.h"

class Subject {
public:
	virtual inline void AddObserver(Observer* observer) { m_observers.push_front(observer); }
	virtual inline void RemoveObserver(Observer* observer) { m_observers.remove(observer); }

protected:
	virtual inline void Notify() {
		for (Observer* observer : m_observers) {
			observer->OnNotify();
		}
	}

private:
	std::forward_list<Observer*> m_observers;
};