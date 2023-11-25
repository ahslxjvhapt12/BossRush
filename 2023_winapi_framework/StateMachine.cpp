#include "pch.h"
#include "StateMachine.h"
#include "State.h"

StateMachine::StateMachine()
	:m_pCurState(nullptr)
	,m_pOwner(nullptr)
{
}

StateMachine::~StateMachine()
{
	map<wstring, State*>::iterator iter;
	for (iter = m_mapState.begin(); iter != m_mapState.end(); ++iter)
	{
		if (iter->second != nullptr)
			delete iter->second;
	}
	m_mapState.clear();
}

void StateMachine::Update()
{
	if(nullptr != m_pCurState)
		m_pCurState->Update();
}

void StateMachine::Render(HDC _dc)
{
	if (nullptr != m_pCurState)
		m_pCurState->Render(_dc);
}

void StateMachine::AddState(const wstring& _stateName, State* _state)
{
	State* pState = FindState(_stateName);
	if (pState != nullptr)
		return;
	
	_state->SteOwner(m_pOwner);
	m_mapState.insert({ _stateName, _state });
}

void StateMachine::ChangeState(const wstring& _stateName)
{
	State* pState = FindState(_stateName);
	if (pState != nullptr)
		return;

	m_pCurState->OnExit();
	m_pCurState = pState;
	m_pCurState->OnEnter();
}

State* StateMachine::FindState(const wstring& _stateName)
{
	map<wstring, State*>::iterator iter = m_mapState.find(_stateName);
	if (iter == m_mapState.end())
		return nullptr;
	return iter->second;
}
