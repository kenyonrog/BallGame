#pragma once
#include <functional>

class Observer {
public:
	virtual ~Observer() = default;
	virtual void OnNotify() = 0;
};

using callback = std::function<void()>;
class CallbackObserver : public Observer {
public:
	CallbackObserver(callback func) {
		m_callbackFunc = func;
	}
	void OnNotify() override {
		m_callbackFunc();
	}

	callback m_callbackFunc;
};