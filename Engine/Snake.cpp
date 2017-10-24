#include "Snake.h"
#include <assert.h>

Snake::Snake( const Location& loc )
{
	segments.emplace_back(loc);
		
	/*for( int i = 0; i < nSegmentsMax; ++i )
	{
		segments[i].InitBody( bodyColors[i % nBodyColors] );
	}

	segments[0].InitHead( loc );*/
}

void Snake::MoveBy( const Location& delta_loc )
{
	for( size_t i = segments.size() - 1; i > 0; --i )
	{
		segments[i].Follow( segments[i - 1] );
	}
	segments.front().MoveBy( delta_loc );
}

Location Snake::GetNextHeadLocation( const Location& delta_loc ) const
{
	Location l( segments[0].GetLocation() );
	l.Add( delta_loc );
	return l;
}

void Snake::GrowAndMoveBy( const Location& delta_loc )
{
	/*if( nSegments < nSegmentsMax )
	{
		++nSegments;
	}*/
	segments.emplace_back(bodyColors[segments.size() % nBodyColors]);
	MoveBy( delta_loc );
}

void Snake::Draw( Board & brd ) const
{
	for (const Segment& e : segments) {
		e.Draw(brd);
	}
	/*for( int i = 0; i < nSegments; ++i )
	{
		segments[i].Draw( brd );
	}*/
}

bool Snake::IsInTileExceptEnd( const Location& target ) const
{
	for( int i = 0; i < segments.size()-1; ++i )
	{
		if( segments[i].GetLocation() == target )
		{
			return true;
		}
	}
	return false;
}

bool Snake::IsInTile( const Location& target ) const
{
	for (Segment e : segments) {
		if (e.GetLocation() == target)
		{
			return true;
		}
	}
	//for( int i = 0; i < nSegments; ++i )  //range based here
	//{
	//	if( segments[i].GetLocation() == target )
	//	{
	//		return true;
	//	}
	//}
	return false;
}

size_t Snake::GetLength() const
{
	return segments.size();
}

//void Snake::Segment::InitHead( const Location& in_loc )
//{
//	loc = in_loc;
//	c = Snake::headColor;
//}
//
//void Snake::Segment::InitBody( Color c_in )
//{
//	c = c_in;
//}

Snake::Segment::Segment(const Location & _loc)
{
	loc = _loc;
	c = Snake::headColor;
}

Snake::Segment::Segment(Color c_in)
{
	c = c_in;
}

void Snake::Segment::Follow( const Segment& next )
{
	loc = next.loc;
}

void Snake::Segment::MoveBy( const Location& delta_loc )
{
	assert( abs( delta_loc.x ) + abs( delta_loc.y ) == 1 );
	loc.Add( delta_loc );
}

void Snake::Segment::Draw( Board& brd ) const
{
	brd.DrawCell( loc,c );
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
