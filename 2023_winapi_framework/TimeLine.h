#pragma once

class TimeLine
{
public:
	TimeLine();
	~TimeLine();
public:
	struct Line
	{
	public:
		int count;	   //반복할 횟수
		float waitTime; //기다릴 시간
		void(*Func); //실행시킬 함수ㄱ
	
	};
public:
	void PlayTrack(const wstring& trackName);
	void UpdateTimeLine();
	vector<std::pair<wstring, Line*>>* GetTrack(wstring trackName);
	void CreateTrack(const wstring& trackName);
	void AddTimeLine(const wstring& trackname, const wstring& lineName, const float& delay,const int& rePeatCount, const void (*func));
	Line* FindTimeLine(const wstring& lineName);
private:
	vector<wstring>* m_TracksName;
	vector<std::pair<wstring, Line*>> m_Track;
	map<wstring, vector<std::pair<wstring, Line*>>> m_TimeLines;
	vector<std::pair<wstring, Line*>>* m_curTrack;
	int curIndex;
	float curTime;
	float m_delay;
	int curRepeatCount;
};

