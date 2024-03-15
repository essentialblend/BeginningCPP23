export module Point;

export class Point
{
public:
	// Constructors.
	Point() = default;
	Point(const Point& p) = default;

	Point(float x, float y) : memX{ x }, memY{ y } {}

	// Getters / Setters
	float getX() const { return memX; }
	float getY() const { return memY; }

	void setX(float x) { memX = x; }
	void setY(float y) { memY = y; }

	void setXY(float x, float y)
	{
		memX = x;
		memY = y;
	}

private:
	float memX{};
	float memY{};
};