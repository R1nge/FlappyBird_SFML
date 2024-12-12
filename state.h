#pragma once
class State
{
public:
	virtual void Enter();
	virtual void Update();
	virtual void Exit();
protected:
	bool _entering;
	bool _exiting;
};