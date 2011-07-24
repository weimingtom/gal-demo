#pragma once

class FPOINT
{
public:
	FPOINT(){x = 0.0; y = 0.0;}
	FPOINT(float _x, float _y){x = _x; y = _y;}
	float x;
	float y;

friend FPOINT operator +(FPOINT, float);
friend FPOINT operator +(float, FPOINT);
friend FPOINT operator -(FPOINT, float);
friend FPOINT operator -(float, FPOINT);
friend FPOINT operator +(FPOINT, FPOINT);
friend FPOINT operator -(FPOINT, FPOINT);
};

inline FPOINT operator +(FPOINT p, float off)
{
	return FPOINT(p.x + off, p.y + off);
}

inline FPOINT operator +(float off, FPOINT p)
{
	return p + off;
}

inline FPOINT operator -(FPOINT p , float off)
{
	return FPOINT(p.x - off, p.y - off);
}

inline FPOINT operator -(float off, FPOINT p)
{
	return p - off;
}
inline FPOINT operator +(FPOINT p1, FPOINT p2)
{
	return FPOINT(p1.x + p2.x, p1.y + p1.y);
}
inline FPOINT operator -(FPOINT p1, FPOINT p2)
{
	return FPOINT(p1.x - p2.x, p1.y - p2.y);
}