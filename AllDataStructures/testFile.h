class thing
{
public:
	static int test;
};

class otherThing : thing
{
	void Kill()
	{
		test = 5;
	}
};