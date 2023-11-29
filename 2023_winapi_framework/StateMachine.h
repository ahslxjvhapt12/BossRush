#pragma once
class Object;
class State;

class StateMachine
{
public:
	StateMachine();
	~StateMachine();
public:
	void Update();
	void Render(HDC _dc);
public:
	const Object* GetObj() { return m_pOwner; }
	void AddState(const wstring& _stateName, State* _state);
	void ChangeState(const wstring& _stateName);
	State* FindState(const wstring& _stateName);
private:
	map<wstring, State*> m_mapState;
	Object* m_pOwner;
	friend class Object;
	State* m_pCurState;
};