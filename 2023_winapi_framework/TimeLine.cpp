#include "pch.h"
#include "TimeLine.h"
#include "TimeMgr.h"

TimeLine::TimeLine()
	: m_curLine(nullptr)
	, curTime(0)
	, curIndex(0)
	, curRepeatCount(0)
{
}

TimeLine::~TimeLine()
{
}

void TimeLine::RePlayTimeLine()
{
}

void TimeLine::UpdateTimeLine()
{
	if(curIndex == 0 && curRepeatCount == 0)
		curRepeatCount = FindTimeLine(m_TimeIndex[curIndex])->count;

	if (FindTimeLine(m_TimeIndex[curIndex]) == nullptr)
		return;

	curTime += fDT;
	if(curTime >= FindTimeLine(m_TimeIndex[curIndex])->waitTime)
	{
		FindTimeLine(m_TimeIndex[curIndex])->Func;
		curRepeatCount--;
		curTime = 0;
		if(curRepeatCount <= 0)
		{
			curIndex++;
			curRepeatCount = FindTimeLine(m_TimeIndex[curIndex])->count;
		}
	}
}

void TimeLine::AddTimeLine(const wstring& name, const int& waitTime, const int& rePeatCount, const void(*func))
{
	Line* line = FindTimeLine(name);
	if (line != nullptr)
		return;

	line = new Line;
	if(rePeatCount <= 0)
		line->count = 1;
	else
		line->count = rePeatCount;
	line->waitTime = waitTime;
	line->Func = &func;
	m_TimeIndex.push_back(name);
	m_TimeLines.insert({name, line});
}

TimeLine::Line* TimeLine::FindTimeLine(const wstring& name)
{
	map<wstring, Line*>::iterator iter = m_TimeLines.find(name);
	if (iter == m_TimeLines.end())
		return nullptr;
	return iter->second;
}
