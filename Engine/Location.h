#pragma once

class Location
{
public:
	void Add( const Location& val )
	{
		x += val.x;
		y += val.y;
	}
	bool operator==( const Location& rhs ) const
	{
		return x == rhs.x && y == rhs.y;
	}
	bool operator!=(const Location& rhs)const {
		return !(*this == rhs);  //what's the diff if we say: return *this != rhs; Oh, maybe because we haven't defined != yet!???
	}
	Location operator-() const{
		return { -x, -y };
	}
	int x;
	int y;
};