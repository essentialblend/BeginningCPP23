
export module box;

import std;

export class Box
{
public:
	Box() = default; 

	Box(double length, double width, double height)
		: m_length{ std::max(length,width) }
		, m_width{ std::min(length,width) }
		, m_height{ height }
	{}

	double volume() const
	{
		return m_length * m_width * m_height;
	}
	

	// Getters
	double getLength() const { return m_length; }
	double getWidth() const { return m_width; }
	double getHeight() const { return m_height; }

	// Comparison operators.
	std::partial_ordering operator<=>(const Box& aBox) const
	{
		return volume() <=> aBox.volume();
	}

	std::partial_ordering operator<=>(double value) const
	{
		return volume() <=> value;
	}

	bool operator==(const Box& aBox) const = default;

	bool operator==(double otherVolume) const
	{
		return volume() == otherVolume;
	}

	// Arithmetic operators.
	Box& operator+=(const Box& aBox)
	{
		m_length = std::max(m_length, aBox.m_length);
		m_width = std::max(m_width, aBox.m_width);
		m_height += aBox.m_height;

		return *this;
	}

	Box operator+(const Box& aBox) const
	{
		Box temp{ *this };
		temp += aBox;

		return temp;
	}

	Box& operator*=(double scaleFac)
	{
		m_length *= scaleFac;
		m_width *= scaleFac;
		m_height *= scaleFac;

		return *this;
	}

	Box operator*(double scaleFac) const
	{
		Box temp{ *this };

		temp *= scaleFac;

		return temp;
	}

	Box& operator/=(double div)
	{
		m_length /= div;
		m_width /= div;
		m_height /= div;

		return *this;
	}

	Box operator/(double div)
	{
		Box temp{ *this };
		
		temp /= div;

		return temp;
	}

	// Unaries.
	bool operator!() const { return volume() == 0; }

	// Friends.
	friend std::string to_string(const Box& box);

private:
	double m_length{ 1.0 };
	double m_width{ 1.0 };
	double m_height{ 1.0 };
};

// Non-member operator overloads
export Box operator*(double scaleFac, const Box& box)
{
	return box * scaleFac;
}

// Friends
export std::string to_string(const Box& box)
{
	return std::format("Box({:.1f},{:.1f},{:.1f})",
		box.m_length, box.m_width, box.m_height);
}
