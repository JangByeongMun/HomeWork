#pragma once
#include <list>
#include "GameBlock.h"
// Ό³Έν :
class Body;
class Head : public GameBlock
{
public:
	// constrcuter destructer
	Head();
	~Head();

	// delete Function
	Head(const Head& _Other) = delete;
	Head(Head&& _Other) noexcept = delete;
	Head& operator=(const Head& _Other) = delete;
	Head& operator=(Head&& _Other) noexcept = delete;

protected:
	bool CrashBody(const ConsoleVector* _vector) const override;
	void Render() override;
	void Update() override;
	void OverLap(ConsoleObject* _Other) override;

private:
	std::list<Body*> AllBody;
	std::list<ConsoleVector*> BeforeVector;

	void BodySetPos();
	void CheckBodyCrash();
};

