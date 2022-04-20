#include <iostream>
using namespace std;

class Color
{
public:
	virtual string NameOfColor() = 0;
};
class Blue : public Color
{
public:
	string NameOfColor()
	{
		return "Blue ";
	}
};
class Red : public Color
{
public:
	string NameOfColor()
	{
		return "Red ";
	}
};
class Yellow : public Color
{
public:
	string NameOfColor()
	{
		return "Yellow ";
	}
};
class Green : public Color
{
public:
	string NameOfColor()
	{
		return "Green ";
	}
};
class Purple : public Color
{
public:
	string NameOfColor()
	{
		return "Purple ";
	}
};


class Figure
{
protected:
	Color* color;
public:
	Figure(Color* color) : color{color}{}
	~Figure()
	{
		delete color;
	}
	virtual string NameOfFigure()
	{
		return this->color->NameOfColor() + "figure";
	}
};
class Cube : public Figure
{
public:
	Cube(Color* color):Figure(color){}
	string NameOfFigure()
	{
		return this->color->NameOfColor() + "cube";
	}
};
class Pyramid : public Figure
{
public:
	Pyramid(Color* color) :Figure(color) {}
	string NameOfFigure()
	{
		return this->color->NameOfColor() + "pyramid";
	}
};
class Cylinder : public Figure
{
public:
	Cylinder(Color* color) :Figure(color) {}
	string NameOfFigure()
	{
		return this->color->NameOfColor() + "cylinder";
	}
};
class Ball : public Figure
{
public:
	Ball(Color* color) :Figure(color) {}
	string NameOfFigure()
	{
		return this->color->NameOfColor() + "ball";
	}
};
class Prism : public Figure
{
public:
	Prism(Color* color) :Figure(color) {}
	string NameOfFigure()
	{
		return this->color->NameOfColor() + "prism";
	}
};

void main()
{
	int clr;
	cout << "What color will your figure be? (1 - blue, 2 - red, 3 - yellow, 4 - green, 5 - purple)\n";
	cin >> clr;
	Color* color;
	switch (clr)
	{
	case 1:
		color = new Blue;
		break;
	case 2:
		color = new Red;
		break;
	case 3:
		color = new Yellow;
		break;
	case 4:
		color = new Green;
		break;
	case 5:
		color = new Purple;
		break;
	default:
		cout << "Incorrect number\n";
		return;
	}
	int fgr;
	cout << "What shape will your figure have? (1 - cube, 2 - pyramid, 3 - cylinder, 4 - ball, 5 - prism)\n";
	cin >> fgr;
	Figure* figure;
	switch (fgr)
	{
	case 1:
		figure = new Cube(color);
		break;
	case 2:
		figure = new Pyramid(color);
		break;
	case 3:
		figure = new Cylinder(color);
		break;
	case 4:
		figure = new Ball(color);
		break;
	case 5:
		figure = new Prism(color);
		break;
	default:
		cout << "Incorrect number\n";
		return;
	}
	cout << figure->NameOfFigure() << "\n";
}