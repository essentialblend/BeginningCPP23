/*Ex 15-6: Start from the Shape and Circle classes we used earlier to introduce abstract classes. Create one more Shape derivative, Rectangle, that has a width and a height. Introduce an extra function called perimeter() that computes a shape’s perimeter. Define a main() program that starts by filling a polymorphic vector<> with a number of Shapes (a hard-coded list of Shapes is fine; there’s no need to generate them randomly). Next, you should print out the total sum of their areas and perimeters, scale all Shapes with a factor 1.5, and then print out these same sums again. of course, you haven’t forgotten what you learned in the first half of this book, so you shouldn’t put all code inside main() itself. Define the appropriate amount of helper functions!

  Hint: For a circle with radius r, the perimeter (or circumference) is computed using the formula 2πr.*/

export module Shape;

import std;

import Point;

export class Shape
{
public:
	Shape() = default;
	Shape(const Shape&) = default;
	Shape& operator=(const Shape&) = default;
	virtual ~Shape() = default;
	
	Shape(const Point& pos) : pMemPos{ pos } {}

	virtual double computeArea() const = 0;
	virtual double computePerimeter() const = 0;
	virtual void scaleShape(double) = 0;

	virtual void moveShape(const Point& pos) { pMemPos = pos; }
private:
	Point pMemPos{};
};

export class Rectangle : public Shape
{
public:
	Rectangle() = default;
	Rectangle(const Rectangle&) = default;
	Rectangle& operator=(const Rectangle&) = default;

	Rectangle(const Point& pos, float l, float w ) : Shape{ pos }, memL{ l }, memW{ w } {}

	double computeArea() const override
	{
		return memL * memW;
	}

	double computePerimeter() const override
	{
		return (2 * (memL * memW));
	}

	// Static.
	void scaleShape(double fac) override
	{
		memL *= fac;
		memW *= fac;
	}

	~Rectangle() override = default;

private:
	float memL{};
	float memW{};
};

export class Circle : public Shape
{
public:
	Circle() = default;
	Circle(const Circle&) = default;
	Circle& operator=(const Circle&) = default;

	Circle(float rad, const Point& pos) : Shape{ pos }, memRad{ rad } {}

	double computeArea() const override
	{
		return (std::numbers::pi * (memRad * memRad));
	}

	double computePerimeter() const override
	{
		return (2 * std::numbers::pi * memRad);
	}

	// Static.
	void scaleShape(double fac) override
	{
		memRad *= fac;
	}

	~Circle() override = default;

private:
	float memRad{};
};