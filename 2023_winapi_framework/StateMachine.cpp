#include "pch.h"
#include "StateMachine.h"
#include "State.h"

StateMachine::StateMachine()
	:m_pCurState(nullptr)
	,m_pOwner(nullptr)
	, m_stateNames{}
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
	if(m_pCurState != nullptr)
		m_pCurState->Update();
}

void StateMachine::Render(HDC _dc)
{
	if (m_pCurState != nullptr)
		m_pCurState->Render(_dc);
}


void StateMachine::AddState(const wstring& _stateName, State* _state)
{
	State* pState = FindState(_stateName);
	if (pState != nullptr)
		return;

	m_stateNames.push_back(_stateName);
	pState = _state;
	pState->m_pOwner = m_pOwner;
	m_mapState.insert({ _stateName, pState });
	if (m_pCurState == nullptr)
		ChangeState(_stateName);
}

void StateMachine::ChangeState(const wstring& _stateName)
{
	State* pState = FindState(_stateName);
	if (pState == nullptr)
		return;
	if(m_pCurState != nullptr)
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

void StateMachine::ChangeRandomState()
{
	int size = m_stateNames.size() + 1;
	wstring _stateName = m_stateNames[rand() % size];
	

	while (true)
	{
		_stateName = m_stateNames[rand() % size];
		if (_stateName != m_pCurStateName)
			break;
	}

	ChangeState(_stateName);
}
