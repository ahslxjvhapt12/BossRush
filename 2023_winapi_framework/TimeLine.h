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
		int count; //�ݺ��� Ƚ��
		int waitTime; //��ٸ� �ð�
		void(*Func); //�����ų �Լ�
	};
public:
	void RePlayTimeLine();
	void UpdateTimeLine();
	void AddTimeLine(const wstring& name, const int& waitTime,const int& rePeatCount, const void (*func));
	void RemoveTimeLine();
	Line* FindTimeLine(const wstring& name);
private:
	vector<wstring> m_TimeIndex;
	map<wstring, Line*> m_TimeLines;
	Line* m_curLine;
	float curTime;
	int curIndex;
	int curRepeatCount;
};

