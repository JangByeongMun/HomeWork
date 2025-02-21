#pragma once
#include <map>
#include <list>
#include <string>
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineString.h>

// ���� :
template<typename ResType>
class GameEngineRes : public GameEngineNameObject
{

public:
	// constrcuter destructer
	GameEngineRes() {}
	~GameEngineRes() {}

	// delete Function
	GameEngineRes(const GameEngineRes& _Other) = delete;
	GameEngineRes(GameEngineRes&& _Other) noexcept = delete;
	GameEngineRes& operator=(const GameEngineRes& _Other) = delete;
	GameEngineRes& operator=(GameEngineRes&& _Other) noexcept = delete;

	static ResType* Find(const std::string& _Name)
	{
		std::string UpperName = GameEngineString::ToUpperReturn(_Name);

		typename std::map<std::string, ResType*>::iterator Iter =  NamedRes.find(UpperName);

		if (NamedRes.end() == Iter)
		{
			return nullptr;
		}
		
		return Iter->second;
	}

	static void ResourcesDestroy() 
	{
		for (auto& Res : UnNamedRes)
		{
			delete Res;
		}

		for (auto& Res : NamedRes)
		{
			delete Res.second;
		}
	}

protected:
	static std::map<std::string, ResType*> NamedRes;
	static std::list<ResType*> UnNamedRes;

private:

};

template<typename ResType>
std::map<std::string, ResType*> GameEngineRes<ResType>::NamedRes;

template<typename ResType>
std::list<ResType*> GameEngineRes<ResType>::UnNamedRes;

