#pragma once
class Object;
class State
{
public:
	State();
	virtual~State();
public:
	void SteOwner(Object* _owner) {m_pOwner = _owner;}
public:
	virtual void OnEnter();
	virtual void OnExit();
	virtual void Update();
	virtual void Render(HDC _dc);
public:
	Object* m_pOwner;
};

