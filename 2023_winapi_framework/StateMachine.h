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
	void ChangeRandomState();
private:
	map<wstring, State*> m_mapState;
	vector<wstring> m_stateNames;
	Object* m_pOwner;
	friend class Object;
	State* m_pCurState;
	wstring m_pCurStateName;
};