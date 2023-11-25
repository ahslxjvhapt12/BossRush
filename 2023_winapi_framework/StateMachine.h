#pragma once
class Object;
class State;
//template<class T>

class StateMachine
{
public:
	StateMachine();
	~StateMachine();
public:
	void Update();
	void Render(HDC _dc);
public:
	void SetOnwer(Object* _owner) { m_pOwner = _owner; }
	Object* GetObj() const { return m_pOwner; }
	void AddState(const wstring& _stateName, State* _state);
	void ChangeState(const wstring& _stateName);
	State* FindState(const wstring& _stateName);
private:
	Object* m_pOwner;
	map<wstring, State*> m_mapState;
	State* m_pCurState;
};