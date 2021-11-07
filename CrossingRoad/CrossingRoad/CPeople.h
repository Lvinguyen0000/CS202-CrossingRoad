#pragma once
#include "CVehicle.h"
#include "CAnimal.h"


class CPeople {
	private:
		int mX, mY;
		bool mState; //Trang thai song chet
	public:
		CPeople();
		void Up(int);
		void Left(int);
		void Right(int);
		void Down(int);
		bool isImpact(const CVehicle*&);
		bool isImpact(const CAnimal*&);
		bool isFinish();
		bool isDead();
};




