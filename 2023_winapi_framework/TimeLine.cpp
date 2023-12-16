#include "pch.h"
#include "TimeLine.h"
#include "TimeMgr.h"

TimeLine::TimeLine()
	: curTime(0)
	, curIndex(0)
	, curRepeatCount(0)
{
}

TimeLine::~TimeLine()
{
}

void TimeLine::PlayTrack(const wstring& trackName)
{
	m_curTrack = GetTrack(trackName);
	curIndex = 0;
	m_delay = m_curTrack->at(0).second->waitTime;
	curRepeatCount = m_curTrack->at(0).second->count;
}

void TimeLine::UpdateTimeLine()
{
	if (m_curTrack == nullptr || m_curTrack->size() < curIndex)
		return;
	
	curTime += fDT;

	if(curTime > m_delay)
	{
		m_curTrack->at(curIndex).second->Func;
		curRepeatCount--;
		if(curRepeatCount <= 0)
		{
			++curIndex;
			m_delay = m_curTrack->at(curIndex).second->waitTime;
			curRepeatCount = m_curTrack->at(curIndex).second->count;
		}
	}
}

vector<std::pair<wstring, TimeLine::Line*>>*TimeLine::GetTrack(wstring trackName)
{
	map<wstring, vector<std::pair<wstring, Line*>>>::iterator iter = m_TimeLines.find(trackName);
	if (iter == m_TimeLines.end())
		return nullptr;
	return &(iter->second);
}

void TimeLine::CreateTrack(const wstring& trackName)
{
	vector<std::pair<wstring, Line*>>* track = new vector<std::pair<wstring, Line*>>;
	m_TimeLines.insert({trackName, *track});
	m_TracksName->push_back(trackName);
}

void TimeLine::AddTimeLine(const wstring& trackname, const wstring& lineName, const float& delay, const int& rePeatCount, const void(*func))
{
	vector<std::pair<wstring, TimeLine::Line*>>* track = GetTrack(trackname);
	if (track->size() <= 0)
		return;

	Line* line = FindTimeLine(lineName);
	if (line != nullptr)
		return;

	line = new Line;
	line->count = (rePeatCount <= 0 ? 1 : rePeatCount);
	line->waitTime = delay;
	line->Func = &func;
	track->push_back(std::make_pair(lineName, line));
}

TimeLine::Line* TimeLine::FindTimeLine(const wstring& lineName)
{
	Line* Findline = nullptr;
	for(auto line : m_Track)
		if (line.first == lineName)
			Findline = line.second;

	if (Findline == nullptr)
		return nullptr;
	
	return Findline;
}
