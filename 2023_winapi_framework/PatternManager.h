#pragma once
class PatternManager
{
public:
	PatternManager();
	~PatternManager();
public:
	struct Pattern
	{
	public:
		float delay;
		void(*func);
	};
};

