#pragma once
class CObstacle
{
private:
	int mX, mY;
public:
	bool direction = true;
	virtual void Move(int, int);
	virtual bool DIRECTION();

	void setX(int x) {
		mX = x;
	}
	void setY(int y) {
		mY = y;
	}

	int getX() {
		return mX;
	}
	int getY() {
		return mY;
	}

};

