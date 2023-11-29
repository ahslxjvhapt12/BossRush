#pragma once
class Object;
class State
{
public:
	State();
	virtual~State();
public:
	Object* GetOwner() 
	{
		return m_pOwner;
	}
public:
	virtual void OnEnter();
	virtual void OnExit();
	virtual void Update();
	virtual void Render(HDC _dc);
private:
	Object* m_pOwner;
	friend class StateMachine;
};

